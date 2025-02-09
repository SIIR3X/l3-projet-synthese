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
TEST_ARGS =

###########################################################################
################################ LIBRARIES ################################
###########################################################################

# Google Test
GTEST_INCLUDE_DIR = "C:\Program Files\googletest\googletest\include"
GTEST_LIB_DIR = "C:\Program Files\googletest\build\lib"

###########################################################################
############################### DIRECTORIES ###############################
###########################################################################

INCLUDE_DIR = include
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
JAVA_SRC_DIR = java/src
JAVA_BIN_DIR = java/bin
TEST_DIR = tests

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
	$(SRC_DIR)/graphique/Viewport.cpp \
	$(SRC_DIR)/utils/Utils.cpp \

# Test files
TEST_SRC_FILES = \
	$(TEST_DIR)/geometrie/Vecteur2DTest.cpp \
	$(TEST_DIR)/formes/CercleTest.cpp \
	$(TEST_DIR)/formes/SegmentTest.cpp \
	$(TEST_DIR)/formes/TriangleTest.cpp \
	$(TEST_DIR)/formes/PolygoneTest.cpp \
	$(TEST_DIR)/formes/GroupeTest.cpp \
	$(TEST_DIR)/graphique/ViewportTest.cpp \

###########################################################################
############################### EXECUTABLES ###############################
###########################################################################

MAIN_EXEC = projet-synthese
JAVA_EXEC = src.controller.serverManager
TEST_EXEC = test-projet-synthese

###########################################################################
############################ COMPILER AND FLAGS ###########################
###########################################################################

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I$(INCLUDE_DIR)

TEST_CXXFLAGS = -Wall -Wextra -std=c++14 -I$(GTEST_INCLUDE_DIR) -I$(INCLUDE_DIR)
TEST_LDFLAGS = -L$(GTEST_LIB_DIR) -lgtest_main -lgtest -lpthread

###########################################################################
####################### OS DETECTION AND VARIABLES ########################
###########################################################################

# Detect the operating system
ifeq ($(OS),Windows_NT)
	RM = del /Q /S
	RM_DIR = rmdir /Q /S
	MKDIR = mkdir
	PROGRAM = $(BIN_DIR)\$(MAIN_EXEC).exe
	TEST_PROGRAM = $(BIN_DIR)\$(TEST_EXEC).exe
else
	RM = rm -f
	RM_DIR = rm -rf
	MKDIR = mkdir -p
	PROGRAM = $(BIN_DIR)/$(MAIN_EXEC)
	TEST_PROGRAM = $(BIN_DIR)/$(TEST_EXEC)
endif

# Commands
ifeq ($(OS),Windows_NT)
	MEMORYCHECK_CMD = @echo Memory check is not supported on Windows.
	MEMORYCHECK_TEST_CMD = @echo Memory check is not supported on Windows.
	CLEAN_CMD = if exist "$(OBJ_DIR)" ($(RM) "$(OBJ_DIR)\*" > NUL 2>&1) && FOR /D %%p IN ("$(OBJ_DIR)\*") DO $(RM_DIR) %%p > NUL 2>&1
	DELETE_CMD = if exist "$(PROGRAM)" $(RM) "$(PROGRAM)" > NUL 2>&1
	CLEANALL_CMD = if exist "$(OBJ_DIR)" $(RM_DIR) "$(OBJ_DIR)" > NUL 2>&1 && if exist "$(BIN_DIR)" $(RM_DIR) "$(BIN_DIR)" > NUL 2>&1 && if exist "$(JAVA_BIN_DIR)" $(RM_DIR) "$(JAVA_BIN_DIR)" > NUL 2>&1
else
	MEMORYCHECK_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(PROGRAM)
	MEMORYCHECK_TEST_CMD = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes $(TEST_PROGRAM)
	CLEAN_CMD = $(RM_DIR) $(OBJ_DIR)/*
	DELETE_CMD = $(RM) $(PROGRAM)
	CLEANALL_CMD = $(RM_DIR) $(OBJ_DIR) $(BIN_DIR) $(JAVA_BIN_DIR)
endif

MKDIR_BIN = $(if $(filter Windows_NT, $(OS)), if not exist $(BIN_DIR) mkdir $(subst /,\\,$(BIN_DIR)), mkdir -p $(BIN_DIR))
MKDIR_OBJ = $(if $(filter Windows_NT, $(OS)), if not exist $(dir $@) mkdir $(subst /,\\,$(dir $@)), mkdir -p $(dir $@))
MKDIR_JAVA_BIN = $(if $(filter Windows_NT, $(OS)), if not exist $(JAVA_BIN_DIR) mkdir $(subst /,\\\\,$(JAVA_BIN_DIR)), mkdir -p $(JAVA_BIN_DIR))

###########################################################################
############################### OBJECT FILES ##############################
###########################################################################

SRC_OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(filter-out $(SRC_DIR)/main.cpp, $(SRC_FILES)))

rwildcard = $(foreach d,$(wildcard $1*),$(call rwildcard,$d/,$2)) $(wildcard $1$2)
JAVA_SOURCES := $(filter %.java, $(call rwildcard, $(JAVA_SRC_DIR)/, *.java))

TEST_OBJ_FILES = $(patsubst $(TEST_DIR)/%.cpp, $(OBJ_DIR)/$(TEST_DIR)/%.o, $(TEST_SRC_FILES))

###########################################################################
################################## RULES ##################################
###########################################################################

# Compile the source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(MKDIR_OBJ)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile the test files
$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	@$(MKDIR_OBJ)
	$(CXX) $(TEST_CXXFLAGS) -c $< -o $@

# Link the object files
$(PROGRAM): $(SRC_OBJ_FILES) $(OBJ_DIR)/main.o
	@$(MKDIR_BIN)
ifeq ($(OS), Windows_NT)
	@chcp 65001 >nul 2>&1
	$(CXX) $^ -o $@ -lws2_32
else
	$(CXX) $^ -o $@
endif

# Link the test object files
$(TEST_PROGRAM): $(SRC_OBJ_FILES) $(TEST_OBJ_FILES)
	@$(MKDIR_BIN)
	$(CXX) $^ -o $@ $(TEST_LDFLAGS)

###########################################################################
################################ COMMANDS #################################
###########################################################################

.PHONY: all run memorycheck javac run-java clean delete cleanall docs

# Default rule
all: clean delete $(PROGRAM)

# Command to run the program
run: clean $(PROGRAM)
	$(PROGRAM) $(MAIN_ARGS)

# Command to run the tests
test: clean $(TEST_PROGRAM)
	$(TEST_PROGRAM) $(TEST_ARGS)

# Command to run the memory check on the program
memorycheck: clean $(PROGRAM)
	$(MEMORYCHECK_CMD) $(MAIN_ARGS)

# Command to run the memory check on the tests
memorycheck-test: clean $(TEST_PROGRAM)
	$(MEMORYCHECK_TEST_CMD) $(TEST_ARGS)

# Command to compile the Java files
javac:
	@$(MKDIR_JAVA_BIN)
	javac -d $(JAVA_BIN_DIR) $(JAVA_SOURCES)

# Command to run the Java program
run-java: javac
	java -cp $(JAVA_BIN_DIR) $(JAVA_EXEC)

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