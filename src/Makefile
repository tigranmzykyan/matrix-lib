FLAGS=-Werror -Wextra -Wall
SOURCE=$(wildcard sourceFiles/*.c)
GCOV=-fprofile-arcs -ftest-coverage
UNIT=$(wildcard unit_tests/*.c)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
    LCHECK=$(shell pkg-config --cflags --libs check)
else ifeq ($(filter Ubuntu, $(OS)), Ubuntu)
	LCHECK=-lcheck -lsubunit -lm
else ifeq ($(filter Manjaro, $(OS)), Manjaro)
    LCHECK=-lcheck -lm
else
    LCHECK=-lcheck -lm
endif

OBJ_DIR=obj
GCD_DIR=gcdFiles
REP_DIR=report_html
OBJ_FILES=$(patsubst sourceFiles/%.c,$(OBJ_DIR)/%.o,$(SOURCE))

all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJ_FILES)
	ar rc s21_matrix.a $(OBJ_FILES)

$(OBJ_DIR)/%.o: sourceFiles/%.c | $(OBJ_DIR)
	gcc $(FLAGS) -c $< -o $@

test: s21_matrix.a
	gcc $(FLAGS) $(UNIT) s21_matrix.a -o s21_matrix_test $(LCHECK)
	./s21_matrix_test

gcov_report: s21_matrix.a
	gcc $(FLAGS) $(UNIT) $(SOURCE) -o s21_matrix_test $(LCHECK) $(GCOV)
	./s21_matrix_test
	mkdir -p $(REP_DIR)
	lcov --capture --directory . --output-file $(REP_DIR)/report.info
	genhtml $(REP_DIR)/report.info -o $(REP_DIR)
	mkdir -p $(GCD_DIR)
	mv *.gcda *.gcno $(GCD_DIR)
	open report_html/index.html

rebuild: clean all

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(GCD_DIR) $(REP_DIR) *.info s21_matrix_test s21_matrix.a $(OBJ_DIR)


#.PHONY: all test gcov_report rebuild clean
