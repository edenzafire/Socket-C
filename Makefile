CC = gcc
CFLAGS = -Wall -g

# Arquivos objeto do servidor
OBJ_SERVIDOR = servidor.o servidor_funcoes.o

# Arquivos objeto do cliente
OBJ_CLIENTE = cliente.o

# Executáveis
SERVIDOR = servidor
CLIENTE = cliente

all: $(SERVIDOR) $(CLIENTE)

# Compilar servidor
$(SERVIDOR): $(OBJ_SERVIDOR)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar cliente
$(CLIENTE): $(OBJ_CLIENTE)
	$(CC) $(CFLAGS) -o $@ $^

# Compilar servidor.o
servidor.o: servidor.c servidor.h
	$(CC) $(CFLAGS) -c servidor.c

# Compilar servidor_funcoes.o
servidor_funcoes.o: servidor_funcoes.c servidor.h
	$(CC) $(CFLAGS) -c servidor_funcoes.c

# Compilar cliente.o
cliente.o: cliente.c cliente.h
	$(CC) $(CFLAGS) -c cliente.c

# Limpar arquivos compilados
clean:
	rm -f *.o $(SERVIDOR) $(CLIENTE)
