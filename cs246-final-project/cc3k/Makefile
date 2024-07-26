# Universal makefile for single C++ program
#
# Use gcc flag -MMD (user) or -MD (user/system) to generate dependencies among source files.
# Use make default rules for commonly used file-name suffixes and make variables names.
#
# % make [ a.out ]

########## Variables ##########

CXX = g++-11					# compiler
CXXFLAGS = -IDisplay -IGame -IGame/Factory -IGame/Floor -IGame/Floor/Cell -IGame/GameObject/Enemy -IGame/GameObject/Item -IGame/GameObject/Item/Potion -IGame/GameObject/Item/Treasure -IGame/GameObject/Player -IGame/Handler -IGame/Handler/Effects -IGame/MapFiles -std=c++20 -g -Wall -Werror=vla -MMD			# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

VPATH = Display:Game:Game/Factory:Game/Floor:Game/Floor/Cell:Game/GameObject/Enemy:Game/GameObject/Item:Game/GameObject/Item/Potion:Game/GameObject/Item/Treasure:Game/GameObject/Player:Game/Handler:Game/Handler/Effects:Game/MapFiles
SOURCES = $(wildcard *.cc)			# source files (*.cc)
OBJECTS = ${SOURCES:.cc=.o}			# object files forming executable
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"
EXEC = cc3k					# executable name

########## Targets ##########

.PHONY : clean					# not file names

${EXEC} : ${OBJECTS}				# link step
	${CXX} ${CXXFLAGS} $^ -o $@		# additional object files before $^

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

# make implicitly generates rules to compile C++ files that generate .o files

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
