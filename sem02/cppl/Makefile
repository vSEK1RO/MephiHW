-l = 
-lt = -lgtest

CC = g++
CFLAGS = -Wall -Wextra -Werror -Wno-unused-parameter\
	-fsanitize=address,undefined -O0 -g
OBJS =
TESTS = ArraySequence ListSequence DynamicArray LinkedList\
	UniquePointer Polynom

LIB = cppl

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
LIBDIR = lib
TESTDIR = test
DIRS = ${OBJDIR} ${LIBDIR} ${BINDIR}

ifneq (${OBJS},)
build: ${DIRS} ${LIBDIR}/lib${LIB}.a ${BINDIR}/lib${LIB}.so

${DIRS}:
	mkdir $@

${OBJDIR}/%.o: ${SRCDIR}/%.cpp ${INCDIR}/${LIB}/%
	${CC} -o $@ -c $< -I${INCDIR} ${-l} ${CFLAGS}

${BINDIR}/lib${LIB}.so: ${patsubst %, ${OBJDIR}/%.o, ${OBJS}}
	${CC} -shared -o $@ $^ 

${LIBDIR}/lib${LIB}.a: ${patsubst %, ${OBJDIR}/%.o, ${OBJS}}
	ar rcs $@ $^
endif
${TESTDIR}: ${patsubst %, ${TESTDIR}/%.exe, ${TESTS}}
	${patsubst %, ./${TESTDIR}/%.exe;, ${TESTS}}

${TESTDIR}/%.exe: ${TESTDIR}/%.cpp
	${CC} -o $@ $^ -I${INCDIR} -L${LIBDIR} ${-lt} ${CFLAGS}

clean:
	rm ${OBJDIR}/*.o ${LIBDIR}/*.a ${BINDIR}/*.so */*.exe