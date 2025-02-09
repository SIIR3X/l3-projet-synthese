# Projet de synthèse de L3


## Installation

### Dépendances

🔹**Requises**

- **Système Windows ou Linux**
- **MinGW Make**/**Make**
- **GCC** (avec support C++11)

🔹**Optionnelles**

- **Valgrind** (sous Linux)
- **Doxygen**
- **JSDoc**
- **GoogleTest**

### Compilation

Pour compiler le projet, il suffit de lancer la commande `make` dans le répertoire du projet.

## Makefile

Voici la liste des commandes disponibles dans le Makefile :

- `make` : Compile le projet
- `make run` : Compile le projet et le lance
- `make memorycheck` : Compile le projet et le lance avec valgrind (sous Linux)
- `make test` : Compile le projet et lance les tests
- `make memorychecktest` : Compile le projet et lance les tests avec valgrind (sous Linux)
- `make javac` : Compile les fichiers Java
- `make run-java` : Compile les fichiers Java et les lance
- `make clean` : Supprime les fichiers compilés (.o et .class)
- `make delete` : Supprime les exécutables
- `make cleanall` : Supprime les fichiers compilés et les exécutables
- `make doc` : Génère la documentation
- `make help` : Affiche la liste des commandes disponibles