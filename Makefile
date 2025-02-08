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

MAIN_ARGS = 

###########################################################################
############################### DIRECTORIES ###############################
###########################################################################

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

###########################################################################
################################## FILES ##################################
###########################################################################

# Source files
SRC_FILES = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/geometrie/Vecteur2D.cpp \
	$(SRC_DIR)/formes/Forme.cpp \
	$(SRC_DIR)/formes/Segment.cpp \
	$(SRC_DIR)/formes/Triangle.cpp \
	$(SRC_DIR)/formes/Cercle.cpp \
	$(SRC_DIR)/formes/Polygone.cpp \
	$(SRC_DIR)/formes/Groupe.cpp \
	$(SRC_DIR)/design_patterns/visiteur/VisiteurForme.cpp \
	$(SRC_DIR)/design_patterns/visiteur/VisiteurDessinerTCP.cpp \
	$(SRC_DIR)/design_patterns/visiteur/VisiteurSauvegarderTXT.cpp \
	$(SRC_DIR)/design_patterns/cor/ChargeurForme.cpp \
	$(SRC_DIR)/design_patterns/cor/ChargeurFormeCOR.cpp \
	$(SRC_DIR)/design_patterns/cor/ChargeurFormeCORSegment.cpp \
	$(SRC_DIR)/design_patterns/cor/ChargeurFormeCORTriangle.cpp \
	$(SRC_DIR)/design_patterns/cor/ChargeurFormeCORCercle.cpp \
	$(SRC_DIR)/design_patterns/cor/ChargeurFormeCORPolygone.cpp \

###########################################################################
############################### EXECUTABLES ###############################
###########################################################################

MAIN_EXEC = projet-synthese

###########################################################################
############################ COMPILER AND FLAGS ###########################
###########################################################################

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I$(INCLUDE_DIR)

###########################################################################
####################### OS DETECTION AND VARIABLES ########################
###########################################################################

# Detect the operating system
ifeq ($(OS),Windows_NT)
	RM = del /Q /S
	RM_DIR = rmdir /Q /S
	MKDIR = mkdir
	PROGRAM = $(BIN_DIR)\$(MAIN_EXEC).exe
else
	RM = rm -f
	RM_DIR = rm -rf
	MKDIR = mkdir -p
	PROGRAM = $(BIN_DIR)/$(MAIN_EXEC)
endif

# Commands
ifeq ($(OS),Windows_NT)
	MEMOCHECK_CMD = @echo Memory check is not supported on Windows.
	CLEAN_CMD = if exist "$(OBJ_DIR)" ($(RM) "$(OBJ_DIR)\*" > NUL 2>&1) && FOR /D %%p IN ("$(OBJ_DIR)\*") DO $(RM_DIR) %%p > NUL 2>&1
	DELETE_CMD = if exist "$(PROGRAM)" $(RM) "$(PROGRAM)" > NUL 2>&1
	CLEANALL_CMD = if exist "$(OBJ_DIR)" (if exist "$(BIN_DIR)" ($(RM_DIR) "$(OBJ_DIR)" & $(RM_DIR) "$(BIN_DIR)") else ($(RM_DIR) "$(OBJ_DIR)")) else (if exist "$(BIN_DIR)" ($(RM_DIR) "$(BIN_DIR)"))
else
	MEMOCHECK_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(PROGRAM)
	CLEAN_CMD = $(RM_DIR) $(OBJ_DIR)/*
	DELETE_CMD = $(RM) $(PROGRAM)
	CLEANALL_CMD = $(RM_DIR) $(OBJ_DIR) $(BIN_DIR)
endif

MKDIR_BIN = $(if $(filter Windows_NT, $(OS)), if not exist $(BIN_DIR) mkdir $(subst /,\\,$(BIN_DIR)), mkdir -p $(BIN_DIR))
MKDIR_OBJ = $(if $(filter Windows_NT, $(OS)), if not exist $(dir $@) mkdir $(subst /,\\,$(dir $@)), mkdir -p $(dir $@))

###########################################################################
############################### OBJECT FILES ##############################
###########################################################################

SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES)))

###########################################################################
################################## RULES ##################################
###########################################################################

# Compile the source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Link the object files
$(PROGRAM): $(SRC_OBJ_FILES) $(OBJ_DIR)/main.o
	@$(MKDIR_BIN)
ifeq ($(OS), Windows_NT)
	@chcp 65001 >nul 2>&1
	$(CXX) $^ -o $@ -lws2_32
else
	$(CXX) $^ -o $@
endif

###########################################################################
################################ COMMANDS #################################
###########################################################################

.PHONY: all clean delete cleanall docs

# Default rule
all: clean delete $(PROGRAM)

# Command to run the program
run: clean $(PROGRAM)
	$(PROGRAM) $(MAIN_ARGS)

# Command to run the memory check on the program
memorycheck: clean $(PROGRAM)
	$(MEMOCHECK_CMD) $(MAIN_ARGS)

# Command to clean the object files
clean:
	$(CLEAN_CMD)

# Command to delete the program executable
delete:
	$(DELETE_CMD)

# Command to clean all files
cleanall:
	$(CLEANALL_CMD)

# Command to generate the documentation
docs:
	doxygen Doxyfile