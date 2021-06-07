CC=gcc
WCC=x86_64-w64-mingw32-gcc
BUILD_DIR=build
SRC_DIR=src
DOCS_HTML=docs/html/index.html
DOCS_PDF=docs/docs.pdf
SRCS=$(wildcard $(SRC_DIR)/*.c)
INT_HEADS=$(wildcard $(SRC_DIR)/*.h)
OBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%_Linux.o,$(SRCS))
WOBJS=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%_Windows.o,$(SRCS))
HEADS=$(wildcard *.h)
LIB=$(BUILD_DIR)/myLibrary_Linux.lib
WLIB=$(BUILD_DIR)/myLibrary_Windows.lib
TEST_SRC=tests.c
TESTS_FILE=$(BUILD_DIR)/tests

all: $(BUILD_DIR) $(OBJS) $(WOBJS) $(LIB) $(WLIB) $(TESTS_FILE) $(DOCS_HTML) $(DOCS_PDF)

lib: $(BUILD_DIR) $(OBJS) $(WOBJS) $(LIB) $(WLIB)

docs: $(DOCS_HTML)

pdf: $(DOCS_PDF)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR) 

$(TESTS_FILE): $(BUILD_DIR) $(OBJS) $(WOBJS) $(LIB) $(WLIB) $(TEST_SRC)
	$(CC) $(TEST_SRC) -o $(TESTS_FILE)_Linux $(LIB)
	$(WCC) $(TEST_SRC) -o $(TESTS_FILE)_windows $(WLIB)

$(BUILD_DIR)/%_Linux.o: $(SRC_DIR)/%.c $(INT_HEADS)
	$(CC) -c $< -o $@

$(BUILD_DIR)/%_Windows.o: $(SRC_DIR)/%.c $(INT_HEADS)
	$(WCC) -c $< -o $@

$(LIB): $(OBJS)
	ar rcs $@ $(OBJS)

$(WLIB): $(WOBJS)
	ar rcs $@ $(WOBJS)

$(DOCS_HTML): $(HEADS) Doxyfile mainPage.md
	doxygen

$(DOCS_PDF): $(HEADS)
	make -C docs/latex
	mv docs/latex/refman.pdf docs/docs.pdf
