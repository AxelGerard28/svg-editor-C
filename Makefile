# === Configuration ===
CC = gcc
CFLAGS = -std=c99 -Wall -Wextra -Werror -IFormes

# Fichiers sources et objets
SRC = mainprojet.c \
	Formes/Cercle/cercle.c \
	Formes/Rectangle/rectangle.c \
	Formes/Carre/carre.c \
	Formes/Ellipse/ellipse.c \
	Formes/Ligne/ligne.c \
	Formes/Enchlignes/enchlignes.c \
	Formes/Polygone/polygone.c \
	Formes/Trajectoire/trajectoire.c \
	Formes/Groupe/groupe.c

OBJ = $(SRC:.c=.o)

# Nom de l'exécutable
EXEC = main

# === Règles ===

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