
all: clean s21_matrix.a test gcov_report

clean:
	rm -rf s21_matrix_oop.o
	rm -rf s21_matrix_oop.a
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	clear

test:
	g++ -Wall -Wextra -Werror -std=c++17 -o test test.cpp s21_matrix_oop.cpp --coverage -lgtest -lgtest_main
	./test

gcov_report: 
	gcovr
	gcovr --html-details -o report.html
	open report.html

s21_matrix.a:
	g++ -c s21_matrix_oop.cpp -o s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o

clang:
	cp ../materials/linters/.clang-format ./.
	clang-format -i *.cpp
	clang-format -i *.h
	rm -rf .clang-format
	