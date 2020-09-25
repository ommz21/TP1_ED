# == VARIAVEIS ===
# ================
CC=g++ 
CFLAGS=-g -Wall -Wextra
EXEC=./tp1
TMPOUT=tp1.testresult
MEM_LEAK=valgrind --leak-check=full --track-origins=yes --show-reachable=yes 

# === REGRAS =====
# ================
$(EXEC): main.cc celula.o aguarda.o combate.o avariada.o
	$(CC) $(CFLAGS) main.cc celula.o aguarda.o combate.o avariada.o -o $(EXEC)

celula.o: headers/celula.o
	$(CC) $(CFLAGS) -c headers/celula.cc -o celula.o
aguarda.o: headers/aguarda.o
	$(CC) $(CFLAGS) -c headers/aguarda.cc -o aguarda.o
combate.o: headers/combate.o
	$(CC) $(CFLAGS) -c headers/combate.cc -o combate.o
avariada.o: headers/avariada.o
	$(CC) $(CFLAGS) -c headers/avariada.cc -o avariada.o

all: $(EXEC)
	$(EXEC)
test: $(EXEC)
	@bash run_tests.sh $(EXEC) $(TMPOUT)
memcheck: $(EXEC) # Execucao usando valgrind para verificar se o codigo possui algum leak de memoria
	$(MEM_LEAK)$(EXEC)
clean: # remove todos os arquivos temporarios que forem gerados pela compilacao
	rm -rf celula.o aguarda.o combate.o avariada.o tp1 headers/celula.o headers/aguarda.o headers/combate.o headers/avariada.o