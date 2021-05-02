CC=gcc
BUILD_DIR=build
SRC_DIR=src
DOCS_HTML=docs/html/index.html
DOCS_PDF=docs/docs.pdf
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
HEADS=$(wildcard *.h)
LIB=$(BUILD_DIR)/myLibrary.lib
EXAMPLES=$(BUILD_DIR)/examples

all: $(BUILD_DIR) $(OBJS) $(LIB) $(DOCS_HTML) $(DOCS_PDF) $(EXAMPLES)

lib: $(BUILD_DIR) $(OBJS) $(LIB)

docs: $(DOCS_HTML)

pdf: $(DOCS_PDF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) 

$(EXAMPLES): examples.c
	$(CC) examples.c -o $(EXAMPLES) $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $^ -o $@

$(LIB): $(OBJS) $(BUILD_DIR)
	ar rcs $@ $(OBJS)

$(DOCS_HTML): $(HEADS)
	doxygen

$(DOCS_PDF): $(HEADS)
	make -C docs/latex
	mv docs/latex/refman.pdf docs/docs.pdf
