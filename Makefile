CC=gcc
BUILD_DIR=build
SRC_DIR=src
DOCS_HTML=docs/html/index.html
DOCS_PDF=docs/docs.pdf
SRCS=$(wildcard $(SRC_DIR)/*.c)
INT_HEADS=$(wildcard $(SRC_DIR)/*.h)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
HEADS=$(wildcard *.h)
LIB=$(BUILD_DIR)/myLibrary.lib
TEST_SRC=tests.c
TESTS_FILE=$(BUILD_DIR)/tests

all: $(BUILD_DIR) $(OBJS) $(LIB) $(TESTS_FILE) $(DOCS_HTML) $(DOCS_PDF)

lib: $(BUILD_DIR) $(OBJS) $(LIB)

docs: $(DOCS_HTML)

pdf: $(DOCS_PDF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) 

$(TESTS_FILE): $(BUILD_DIR) $(OBJS) $(LIB) $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $(TESTS_FILE) $(LIB)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(INT_HEADS)
	$(CC) -c $< -o $@

$(LIB): $(OBJS)
	ar rcs $@ $(OBJS)

$(DOCS_HTML): $(HEADS)
	doxygen

$(DOCS_PDF): $(HEADS)
	make -C docs/latex
	mv docs/latex/refman.pdf docs/docs.pdf
