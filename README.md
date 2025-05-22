# 💬 Socket-C

Um simples sistema de chat cliente-servidor em C, utilizando sockets TCP. Suporta múltiplos clientes simultaneamente, com mensagens coloridas no terminal e estrutura modular.

---

## 🚀 Funcionalidades

- ✅ Servidor com suporte a múltiplas conexões (via `fork`)
- ✅ Cliente que envia e recebe mensagens do servidor
- ✅ Echo server (o servidor retorna a mensagem recebida)
- ✅ Terminal colorido para melhor visualização
- ✅ Código modular: dividido em `.c` e `.h` separados

---

## 📁 Estrutura de Arquivos

.
├── cliente.c # Código principal do cliente
├── cliente.h # Header do cliente
├── servidor.c # Código principal do servidor
├── servidor.h # Header do servidor
├── servidor_Funcoes.c # Funções auxiliares do servidor
├── Includes/ # (No momento não há inclusões adicionais)
✍️ Autor
Feito com dedicação por [Seu Nome Aqui].├── Makefile # Compilação automatizada
├── README.md # Este arquivo
└── LICENSE # Licença do projeto (ex: MIT) 

---

## 🛠️ Compilação e Execução

### 🔧 Compilar
Use o `make` para compilar o projeto:

```bash
make

▶️ Executar
Em um terminal, rode o servidor:

./servidor

. Em outro terminal, rode o cliente:

./cliente

Você pode rodar vários clientes ao mesmo tempo!

🧽 Limpar os arquivos compilados
make clean

📜 Licença
Este projeto está sob a licença MIT. Veja o arquivo LICENSE para mais detalhes.


✍️ Autor
Feito com dedicação por [Éden Zafire].









