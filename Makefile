CC=gcc
DOCS_HTML=docs/html/index.html
DOCS_PDF=docs/docs.pdf
SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c,bin/%.o,$(SRCS))
HEADS=$(wildcard *.h)
LIB=bin/myLibrary.lib

all: $(OBJS) $(LIB) $(DOCS_HTML) $(DOCS_PDF) bin/examples

lib: $(OBJS) $(LIB)

docs: $(DOCS_HTML)

pdf: $(DOCS_PDF)

bin/examples: examples.c
	mkdir -p bin
	$(CC) $^ -o $@ $(LIB)

bin/%.o: src/%.c
	mkdir -p bin
	$(CC) -c $^ -o $@

$(LIB): $(OBJS)
	ar rcs "$@" $(OBJS)

$(DOCS_HTML): $(HEADS)
	doxygen

$(DOCS_PDF): $(HEADS)
	make -C docs/latex
	mv docs/latex/refman.pdf docs/docs.pdf
