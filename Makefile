###########################################################################
#                                                                         #
#   Makefile                                                              #
#                                                                         #
#   Projet de synthèse de L3                                              #
#                                                                         #
###########################################################################

###########################################################################
################################ ARGUMENTS ################################
###########################################################################

# Arguments pour l'exécution du programme
MAIN_ARGS = 800 600 data/gecko/faces.txt 0
TEST_ARGS =


###########################################################################
################################ LIBRAIRIES ###############################
###########################################################################

# Winsock
WINSOCK_LIB = -lws2_32

# OpenGL
OPENGL_LIB = lib/libglfw3dll.a -lopengl32


###########################################################################
############################## EXECUTABLES ################################
###########################################################################

# Nom des exécutables
MAIN_EXEC = projet-synthese.exe
JAVA_EXEC = Main
TEST_EXEC = tests.exe


###########################################################################
############################### COMPILATEUR ###############################
###########################################################################

# Compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I$(INC_DIR) -I$(OPENGL_INCLUDE_DIR)
TEST_CXXFLAGS = -Wall -Wextra -std=c++14 -I$(INC_DIR) -I$(GTEST_INCLUDE_DIR)


###########################################################################
############################### OPTIONS ###################################
###########################################################################

# Flags de compilation
LDFLAGS =
LDLIBS = $(WINSOCK_LIB) $(OPENGL_LIB)
TEST_LDFLAGS = $(LDFLAGS) -L$(GTEST_LIB_DIR) -lgtest -lgtest_main


###########################################################################
################################ FONCTIONS ################################
###########################################################################

# Fonction permettant de récuperer tous les fichiers d'un dossier et de ses sous-dossiers
rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))

# Fonction permettant de créer un dossier
define MKDIR
@if not exist "$(subst /,\,$(patsubst %/,%,$(1)))" mkdir "$(subst /,\,$(patsubst %/,%,$(1)))"
endef

# Fonction permettant de nettoyer un dossier
define CLEAN_DIR
@if exist "$(subst /,\,$(patsubst %/,%,$(1)))" ( \
    del /q "$(subst /,\,$(patsubst %/,%,$(1)))\*" && \
    for /d %%x in ("$(subst /,\,$(patsubst %/,%,$(1)))\*") do rd /s /q "%%x" )
endef

# Fonction permettant de supprimer un fichier
define DELETE_FILE
@if exist "$(subst /,\,$(patsubst %/,%,$(1)))" (del /q "$(subst /,\,$(patsubst %/,%,$(1)))")
endef


###########################################################################
################################ DOSSIERS #################################
###########################################################################

# Dossiers C++
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin
TEST_DIR = tests

# Dossiers Java
JAVA_SRC_DIR = java/src
JAVA_BIN_DIR = java/bin

# Dossiers OpenGL
OPENGL_INCLUDE_DIR = include/opengl/modele
OPENGL_SRC_DIR = src/opengl/modele

# Dossiers Google Test
GTEST_INCLUDE_DIR = "C:\Program Files\googletest\googletest\include"
GTEST_LIB_DIR = "C:\Program Files\googletest\build\lib"


###########################################################################
################################ FICHIERS #################################
###########################################################################

# Fichiers C++
SRC_FILES := $(call rwildcard,$(SRC_DIR)/,*.cpp)
TEST_FILES := $(call rwildcard,$(TEST_DIR)/,*.cpp)

# Fichiers Java
JAVA_FILES := $(call rwildcard,$(JAVA_SRC_DIR)/,*.java)

# Fichiers C
GLAD_FILE = $(OPENGL_SRC_DIR)/glad/glad.c

# Chemins vers les exécutables
MAIN_PROG = $(BIN_DIR)/$(MAIN_EXEC)
TEST_PROG = $(BIN_DIR)/$(TEST_EXEC)


###########################################################################
################################# OBJETS ##################################
###########################################################################

# Objets C++
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_FILES))

# Objets C
GLAD_OBJ = $(OBJ_DIR)/opengl/modele/glad/glad.o

###########################################################################
############################### COMPILATION ###############################
###########################################################################

# Edition des liens des fichiers objets
$(MAIN_PROG): $(OBJS) $(GLAD_OBJ)
	$(call MKDIR, $(BIN_DIR))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(call MKDIR,$(dir $@))
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Edition des liens des fichiers objets de test
$(TEST_PROG): $(OBJS) $(TEST_OBJS)
	$(call MKDIR,$(BIN_DIR))
	$(CXX) $(TEST_CXXFLAGS) -o $@ $(filter-out $(OBJ_DIR)/main.o, $^) $(TEST_LDFLAGS) $(LDLIBS)

# Compilation des fichiers objets de test
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(call MKDIR,$(dir $@))
	$(CXX) $(TEST_CXXFLAGS) -c -o $@ $<

# Compilation de glad
$(GLAD_OBJ): $(GLAD_FILE)
	$(call MKDIR,$(dir $@))
	$(CXX) $(CXXFLAGS) -c -o $@ $<

###########################################################################
################################ COMMANDES ################################
###########################################################################

.PHONY: all rebuild run test javac run-java clean delete deletetest cleanall docs help

all: $(MAIN_PROG) javac

rebuild: clean all

run:
	$(MAIN_PROG) $(MAIN_ARGS)

test: $(TEST_PROG)
	$(TEST_PROG) $(TEST_ARGS)

javac:
	$(call MKDIR,$(JAVA_BIN_DIR))
	javac -d $(JAVA_BIN_DIR) $(JAVA_FILES)

run-java:
	java -cp $(JAVA_BIN_DIR) src.$(JAVA_EXEC)

clean:
	$(call CLEAN_DIR, $(OBJ_DIR))
	$(call CLEAN_DIR, $(BIN_DIR))
	$(call CLEAN_DIR, $(JAVA_BIN_DIR))

delete:
	$(call DELETE_FILE, $(MAIN_PROG))

deletetest:
	$(call DELETE_FILE, $(TEST_PROG))

cleanall: clean

docs:
	doxygen Doxyfile

help:
	@echo "Usage: make [all|rebuild|run|test|javac|run-java|clean|delete|deletetest|cleanall|docs]"

###########################################################################