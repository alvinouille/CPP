/bin/ls
microshell
microshell.c
microshell.o
out.res
test.sh

/bin/cat microshell.c
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

# define NOTHING 0
# define PV ';'
# define PIPE '|'
# define STOPTAB -5
# define EXEC 0
# define SYSTEM 1

typedef struct s_list
{
    char *path;
    char **tab;
    char **env;
    char    next_op;
    char    old_op;
    int     old_pfd;
    int     pid;
    int pfd[2];
}   t_list;


int ft_strlen(char *str)
{
    int i = 0;
    if (!str)
        return 0;
    while (str[i])
        i++;
    return i;
}

void    error_manage(int error, char *str, t_list *list)
{
    int i = 0;
    if (error == SYSTEM)
        write(2, "error: fatal\n", 13);
    else if (error == EXEC)
    {
        write(2, "error: cannot execute ", 22);
        write(2, str, ft_strlen(str));
        write(2, "\n", 1);
    }
    free(list->path);
    while (i < 1000)
    {
        free(list->tab[i]);
        i++;
    }
    free(list->tab[i]);
    free(list);
    exit(0);
}

char    *ft_strdup(char *src)
{
    int i = 0;
    char    *dest;

    while (src[i])
        i++;
    dest = malloc(sizeof(char) * i + 1);
    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char    **alloc_tab(char **av, int ac, int *i)
{
    int j = 0;
    char    **tab;

    tab = malloc(sizeof(char *) * 1000);
    while ((*i < ac) && av[*i][0] != PIPE && av[*i][0] != PV)
    {
        tab[j] = ft_strdup(av[*i]);
        (*i)++;
        j++;
    }
    tab[j] = NULL;
    return (tab);
}

t_list    *prepa(char **av, int ac, int *i, t_list *cmd)
{
    // int j = 0;
    cmd->path = ft_strdup(av[*i]);
    // printf("path = %s \n", cmd->path);
    cmd->tab = alloc_tab(av, ac, i);
    // while (cmd->tab[j])
        // printf("tab = %s \n", cmd->tab[j++]);
    if (cmd->next_op)
        cmd->old_op = cmd->next_op;
    else
        cmd->old_op = NOTHING;
    if (*i < ac)
    {
        cmd->next_op = av[*i][0];
        (*i)++;
    }
    else
        cmd->next_op = NOTHING;
    // printf("next op = %c \n", cmd->next_op);
    // printf("old op = %c \n", cmd->old_op);
    return (cmd);
}

void    redirection(t_list *cmd)
{
    if (cmd->next_op == PIPE)
        dup2(cmd->pfd[1], STDOUT_FILENO);
    if (cmd->old_op == PIPE)
        dup2(cmd->old_pfd, STDIN_FILENO);
}

void    closing(t_list *cmd)
{
    if (cmd->next_op == PIPE || cmd->old_op == PIPE)
    {
        if (cmd->next_op == PIPE)
        {
            close(cmd->pfd[0]);
            close(cmd->pfd[1]);
        }
        if (cmd->old_op == PIPE)
            close(cmd->old_pfd);
    }
}
void    pipex(t_list *cmd)
{
    if (cmd->next_op == PIPE)
    {
        if (pipe(cmd->pfd) == -1)
            error_manage(SYSTEM, NULL, cmd);
    }
    if (cmd->next_op != PIPE && cmd->old_op != PIPE && strcmp(cmd->tab[0], "cd") == 0)
    {
        if (!cmd->tab[1] || cmd->tab[2])
            write(2, "error: cd: bad arguments\n", 25);
        else if (chdir(cmd->tab[1]) != 0)
        {
            write(2, "error: cd: cannot change directory to ", 38);
            write(2, cmd->tab[1], ft_strlen(cmd->tab[1]));
            write(2, "\n", 1);
        }
        cmd->pid = STOPTAB;
        return ;
    }
    cmd->pid = fork();
    if (!cmd->pid)
    {
        redirection(cmd);
        closing(cmd);
        if (execve(cmd->path, cmd->tab, cmd->env) == -1)
            error_manage(EXEC, cmd->path, cmd);
    }
    if (cmd->old_op == PIPE)
        close(cmd->old_pfd);
    if (cmd->next_op == PIPE)
    {
        cmd->old_pfd = cmd->pfd[0];
        close(cmd->pfd[1]);
    }
}

int main(int ac, char **av, char **env)
{
    int i = 1;
    t_list *cmd;
    int     nb;

    cmd = malloc(sizeof(t_list));
    cmd->next_op = NOTHING;
    cmd->env = env;
    cmd->old_pfd = 0;
    nb = 0;
    int *pi;
    pi = malloc(sizeof (int) * 1000);
    while (i < ac)
    {
        if (av[i][0] != PIPE && av[i][0] != PV)
        {
            prepa(av, ac, &i, cmd);
            pipex(cmd);
            pi[nb] = cmd->pid;
            nb++;
        }
        else
            i++;
    }
    i = 0;
    while (i < nb)
    {
        if (pi[i] != -5)
            waitpid(pi[i], NULL, 0);
        i++;
    }
    free(pi);
    free(cmd);
    if (TEST)		// not needed in exam, but necessary if you want to use this tester:
		while (1);
}
/bin/ls microshell.c
microshell.c

/bin/ls salut

;

; ;

; ; /bin/echo OK
OK

; ; /bin/echo OK ;
OK

; ; /bin/echo OK ; ;
OK

; ; /bin/echo OK ; ; ; /bin/echo OK
OK
OK

/bin/ls | /usr/bin/grep microshell
microshell
microshell.c
microshell.o

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro
microshell
microshell.c
microshell.o

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro
microshell
microshell.c
microshell.o

/bin/ls | /usr/bin/grep microshell | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep micro | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell | /usr/bin/grep shell
microshell
microshell.c
microshell.o

/bin/ls ewqew | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo

dernier

/bin/ls | /usr/bin/grep micro | /bin/cat -n ; /bin/echo dernier ; /bin/echo ftest ;
dernier
ftest
     1	microshell
     2	microshell.c
     3	microshell.o

/bin/echo ftest ; /bin/echo ftewerwerwerst ; /bin/echo werwerwer ; /bin/echo qweqweqweqew ; /bin/echo qwewqeqrtregrfyukui ;
ftewerwerwerst
ftest
werwerwer
qweqweqweqew
qwewqeqrtregrfyukui

/bin/ls ftest ; /bin/ls ; /bin/ls werwer ; /bin/ls microshell.c ; /bin/ls subject.fr.txt ;
leaks.res
microshell
microshell.c
microshell.o
out.res
test.sh
microshell.c

/bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ; /bin/ls | /usr/bin/grep micro ;
microshell
microshell.c
microshell.o
microshell
microshell.c
microshell.o
microshell
microshell.c
microshell.o
microshell
microshell.c
microshell.o

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b ; /bin/cat subject.fr.txt ;

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt ;

/bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep w ; /bin/cat subject.fr.txt

/bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt

; /bin/cat subject.fr.txt ; /bin/cat subject.fr.txt | /usr/bin/grep a | /usr/bin/grep b | /usr/bin/grep z ; /bin/cat subject.fr.txt

blah | /bin/echo OK
OK

blah | /bin/echo OK ;
OK

