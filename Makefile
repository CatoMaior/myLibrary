CC=gcc
DOCS_HTML=docs/html/index.html
DOCS_PDF=docs/docs.pdf
SRCS=$(wildcard src/*.c)
OBJS=$(patsubst src/%.c,bin/%.o,$(SRCS))
HEADS=$(wildcard *.h)
LIB=bin/myLibrary.lib

all: $(OBJS) $(LIB) $(DOCS_HTML) $(DOCS_PDF) examples

lib: $(OBJS) $(LIB)

docs: $(DOCS_HTML)

pdf: $(DOCS_PDF)

examples: examples.c
	$(CC) $^ -o bin/$@ $(LIB)

bin/%.o: src/%.c
	$(CC) -c $^ -o $@

$(LIB): $(OBJS)
	ar rcs "$@" $(OBJS)

$(DOCS_HTML): $(HEADS)
	doxygen

$(DOCS_PDF): $(HEADS)
	make -C docs/latex
	mv docs/latex/refman.pdf docs/docs.pdf
