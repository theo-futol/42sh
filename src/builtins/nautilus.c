/*
** EPITECH PROJECT, 2025
** Minishell
** File description:
** Nautilus !!!
*/

#include "minishell.h"

char *get_ip()
{
    return search_env_var(shell()->local_env, "IP");
}

int get_port()
{
    return atoi(search_env_var(shell()->local_env, "PORT"));
}

int set_port(char **av)
{
    int port = get_nbr(av[3]);
    char *value = NULL;

    if (port <= 0 || port > 65536) {
        dprintf(2, "Invalid port\n");
        return 1;
    }
    asprintf(&value, "PORT=%s", av[3]);
    if (!value)
        return 1;
    delete_in_list(&shell()->local_env, "PORT", is_key_var);
    push_to_list(&shell()->local_env, value);
    return 0;
}

int set_ip(char **av)
{
    unsigned char buf[sizeof(struct in6_addr)] = {0};
    char *value = NULL;

    if (inet_pton(AF_INET, av[3], buf) != 1) {
        dprintf(2, "Invalid IP\n");
        return 1;
    }
    asprintf(&value, "IP=%s", av[3]);
    if (!value)
        return 1;
    delete_in_list(&shell()->local_env, "IP", is_key_var);
    push_to_list(&shell()->local_env, value);
    return 0;
}

int edit_params(int ac, char **av)
{
    if (ac > 3 && !strcmp(av[2], "port"))
        return set_port(av);
    if (ac > 3 && !strcmp(av[2], "ip"))
        return set_ip(av);
    dprintf(2, "Invalid parameters\n");
    return 1;
}

struct sockaddr_in *init_srv(int port)
{
    struct sockaddr_in *srv = malloc(sizeof(struct sockaddr_in));
    
    if (!srv)
        return NULL;
    srv->sin_family = AF_INET;
    srv->sin_port   = htons(port);
    return srv;
}

int init_sock(int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in *srv = init_srv(port);
    char *ip = get_ip();

    if (sock == -1) {
        perror("socket");
        return -1;
    }
    if (inet_pton(AF_INET, ip, &srv->sin_addr) != 1) {
        perror("inet_pton");
        return -1;
    }
    if (connect(sock, (struct sockaddr*)srv, sizeof(*srv)) == -1) {
        perror("connect");
        return -1;
    }
    free(ip);
    return sock;
}

struct sockaddr_in *init_addr(int port)
{
    struct sockaddr_in *addr = malloc(sizeof(struct sockaddr_in));

    if (!addr)
        return NULL;
    addr->sin_family      = AF_INET;
    addr->sin_addr.s_addr = htonl(INADDR_ANY);
    addr->sin_port        = htons(port);
    return addr;
}

int start(int port)
{
    int srv = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in *addr = init_addr(port);
    int yes = 1;

    if (!addr || srv == -1)
        return -1;
    setsockopt(srv, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
    if (bind(srv, (struct sockaddr *)addr, sizeof(*addr)) == -1)
        return -1;
    if (listen(srv, 10) == -1)
        return -1;
    free(addr);
    return srv;
}

void print_recv(int cli_fd)
{
    FILE *fd = fdopen(cli_fd, "r");
    ssize_t n = 0;
    char *buf = NULL;
    size_t size = 0;

    do {
        n = getline(&buf, &size, fd);
        if (n <= 0)
            continue;
        printf("%s", buf);
        free(buf);
        buf = NULL;
    } while (n > 0);
    fclose(fd);
}

int start_listening()
{
    int port = get_port();
    int srv = start(port);
    struct sockaddr_in cli = {0};
    socklen_t len = sizeof(cli);
    int cli_fd = 0;
    char ip[INET_ADDRSTRLEN] = {0};

    if (srv == -1)
        return 84;
    if (isatty(1))
        printf("Listening on port %d …\n", port);
    while (1) {
        cli_fd = accept(srv, (struct sockaddr *)&cli, &len);
        if (cli_fd == -1)
            continue;
        inet_ntop(AF_INET, &cli.sin_addr, ip, sizeof ip);
        if (isatty(1))
            printf("\nConnection from %s:%d\n", ip, ntohs(cli.sin_port));
        print_recv(cli_fd);
        close(cli_fd);
    }
    return 0;
}

int start_sending()
{
    int port = get_port();
    int sock = init_sock(port);
    char *buff = NULL;
    size_t size = 0;

    if (sock == -1)
        return 84;
    printf("Please enter your message\n");
    while (1) {
        printf("> ");
        if (getline(&buff, &size, stdin) <= 0)
            return 84;
        if (strcmp(buff, "quit\n") == 0) {
            printf("Quitting...\n");
            break;
        }
        if (send(sock, buff, strlen(buff), 0) <= 0)
            return 84;
        free(buff);
        buff = NULL;
        printf("Message sent !\n");
    }
    shutdown(sock, SHUT_WR);
    close(sock);
    return 0;
}

int print_help()
{
    dprintf(2, "./nautilus [\"set\", \"listen\", \"-h\"] [\"ip\", \"port\"] [\"{IP | PORT}\"]\n");
    return 1;
}

int nautilus(int ac, char **av, llist_t **env_vars)
{
    (void)env_vars;
    if (ac > 1 && !strcmp(av[1], "-h"))
        return print_help();
    if (ac > 1 && !strcmp(av[1], "set"))
        return edit_params(ac, av);
    if (ac > 1 && !strcmp(av[1], "listen"))
        return start_listening();
    if (ac == 1)
        return start_sending();
    dprintf(2, "Invalid parameters\n");
    return 1;
}