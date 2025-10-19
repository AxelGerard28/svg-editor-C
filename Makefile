# === Configuration ===
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -IFormes

# Fichiers sources et objets
SRC = mainprojet.c \
	Formes/Liste/liste.c \
	Formes/Create/create.c \
	Formes/Shapes/shapes.c

OBJ = $(SRC:.c=.o)

# Nom de l'exécutable
EXEC = main

# Compilation complète
build: $(EXEC)

# Création de l'exécutable à partir des .o
$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

# Compilation individuelle des .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers compilés
clean:
	rm -f $(OBJ) $(EXEC)