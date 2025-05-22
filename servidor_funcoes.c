// servidor_funcoes.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>     // sleep e usleep
#include <arpa/inet.h>
#include <sys/socket.h>
#include "servidor.h"

void print_lento(const char* texto, useconds_t delay) {
    for (int i = 0; texto[i] != '\0'; i++) {
        putchar(texto[i]);
        fflush(stdout);
        usleep(delay); // microssegundos (1s = 1000000)
    }
}

void tela_boas_vindas() {
    printf("\033[1;32m");
    printf("===============================================\n");
    printf("        BEM-VINDO AO TERMINAL DO SERVIDOR       \n");
    printf("              PROJETO: TCP CHAT                 \n");
    printf("===============================================\n");
    printf("\033[0m");

    printf("\033[1;36m");
    printf("          ___________________________\n");
    printf("         |                           |\n");
    printf("         |      HACKER SCREEN        |\n");
    printf("         |      [::] CONNECTED       |\n");
    printf("         |___________________________|\n");
    printf("         |  ______     _________     |\n");
    printf("         | |      |   |         |    |\n");
    printf("         | | CPU  |   |  RAM    |    |\n");
    printf("         | |______|   |_________|    |\n");
    printf("         |___________________________|\n");
    printf("             /                 \\\n");
    printf("            /___________________\\\n");
    printf("            |   ___     ___    |\n");
    printf("            |  |___|   |___|   |\n");
    printf("            |__________________|\n");
    printf("            /                  \\ \n");
    printf("           /                    \\ \n");
    printf("          -----------------------\\ \n");
    printf("\033[0m\n");
    print_lento("\033[1;33m> Servidor inicializando...\033[0m\n", 50000);
    sleep(1);
    print_lento("\033[1;32m> OK: Sistema carregado.\033[0m\n", 50000);
    sleep(1);
}

int criar_socket() {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }
    return fd;
}

void configurar_endereco(struct sockaddr_in* endereco) {
    endereco->sin_family = AF_INET;
    endereco->sin_addr.s_addr = INADDR_ANY;
    endereco->sin_port = htons(PORTA);
}

void bindar_socket(int socket_fd, struct sockaddr_in* endereco) {
    if (bind(socket_fd, (struct sockaddr*)endereco, sizeof(*endereco)) < 0) {
        perror("Erro no bind");
        exit(EXIT_FAILURE);
    }
}

void escutar(int socket_fd) {
    if (listen(socket_fd, 10) < 0) {
        perror("Erro no listen");
        exit(EXIT_FAILURE);
    }
    printf("\033[1;34mServidor escutando na porta %d...\033[0m\n", PORTA);
}

void lidar_com_cliente(int cliente_fd) {
    char buffer[TAM_BUFFER];
    while (1) {
        memset(buffer, 0, TAM_BUFFER);
        int bytes = read(cliente_fd, buffer, TAM_BUFFER);
        if (bytes <= 0) break;
        printf("\033[1;32mCliente: %s\033[0m\n", buffer);
        send(cliente_fd, buffer, strlen(buffer), 0);
    }
    close(cliente_fd);
}
