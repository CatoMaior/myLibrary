CC=gcc
BUILD_DIR=build
SRC_DIR=src
DOCS_HTML=docs/html/index.html
DOCS_PDF=docs/docs.pdf
SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
HEADS=$(wildcard *.h)
LIB=$(BUILD_DIR)/myLibrary.lib
TESTING=$(BUILD_DIR)/testing

all: $(BUILD_DIR) $(OBJS) $(LIB) $(DOCS_HTML) $(DOCS_PDF) $(TESTING)

lib: $(BUILD_DIR) $(OBJS) $(LIB)

docs: $(DOCS_HTML)

pdf: $(DOCS_PDF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) 

$(TESTING): testing.c
	$(CC) testing.c -o $(EXAMPLES) $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/errors.h
	$(CC) -c $< -o $@

$(LIB): $(OBJS) $(BUILD_DIR)
	ar rcs $@ $(OBJS)

$(DOCS_HTML): $(HEADS)
	doxygen

$(DOCS_PDF): $(HEADS)
	make -C docs/latex
	mv docs/latex/refman.pdf docs/docs.pdf
