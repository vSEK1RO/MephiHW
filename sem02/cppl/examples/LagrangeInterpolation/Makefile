### Change -I -L -l vars for your dependencies locations
DEPSDIR = ../../..
DEPS = cppl
-I = ${patsubst %, -I${DEPSDIR}/%/include, ${DEPS}}
-L = ${patsubst %, -L${DEPSDIR}/%/lib, ${DEPS}}
-l = -lsfml-graphics -lsfml-window -lsfml-system
### Read upper

CC = g++
DBG = gdb
CFLAGS = -Wall -Wextra -Werror -O0 -g -Wno-unused-parameter
OBJS = Ui Graph

INCDIR = include
SRCDIR = src
OBJDIR = obj
BINDIR = bin
DIRS = ${OBJDIR} ${BINDIR} ${INCDIR}

TARGET = ${SRCDIR}/main.cpp

build: ${DIRS} ${BINDIR}/app.exe

${DIRS}:
	mkdir $@

${BINDIR}/app.exe: ${patsubst %, ${OBJDIR}/%.o, ${OBJS}} ${TARGET}
	${CC} -o $@ $^ ${-I} ${-L} ${-l} ${CFLAGS}

run: build
	./${BINDIR}/app.exe

${DBG}: ${BINDIR}/app.exe
	gdb $^

${OBJDIR}/%.o: ${SRCDIR}/%.cpp ${INCDIR}/%.hpp
	${CC} -o $@ -c $< ${-I} ${CFLAGS}

clean:
	rm obj/*.o
	rm */*.exe