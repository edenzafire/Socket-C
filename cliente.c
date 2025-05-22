// ========================== cliente.c ==========================
#include "cliente.h"

int main() {
    int cliente_fd;
    struct sockaddr_in endereco_servidor;
    char buffer[TAM_BUFFER];

    cliente_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (cliente_fd < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    endereco_servidor.sin_family = AF_INET;
    endereco_servidor.sin_port = htons(PORTA);
    inet_pton(AF_INET, "127.0.0.1", &endereco_servidor.sin_addr);

    if (connect(cliente_fd, (struct sockaddr*)&endereco_servidor, sizeof(endereco_servidor)) < 0) {
        perror("Erro ao conectar ao servidor");
        exit(EXIT_FAILURE);
    }

    printf("\033[1;36mConectado ao servidor! Digite mensagens:\033[0m\n");

    while (1) {
        printf("\033[1;33mVocê: \033[0m");
        fgets(buffer, TAM_BUFFER, stdin);
        send(cliente_fd, buffer, strlen(buffer), 0);

        memset(buffer, 0, TAM_BUFFER);
        int bytes = read(cliente_fd, buffer, TAM_BUFFER);
        if (bytes <= 0) break;
        printf("\033[1;32mServidor: %s\033[0m\n", buffer);
    }

    close(cliente_fd);
    return 0;
}

