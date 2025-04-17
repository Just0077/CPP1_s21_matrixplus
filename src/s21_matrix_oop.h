#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP

// #include <algorithm>
#include <cmath>
#include <iostream>
// #include <vector>

class S21Matrix {
 private:
  int rows_;
  int cols_;
  double** matrix_;

 public:
  // constructors
  S21Matrix();                    // без аргументов
  S21Matrix(int rows, int cols);  // строки и столбцы
  S21Matrix(const S21Matrix& other);  // копировать в новую матрицу
  S21Matrix(S21Matrix&& other);  // перенести в новую матрицу

  // destructor
  ~S21Matrix();

  // operatoins
  bool EqMatrix(const S21Matrix& other);   // сравнить матрицы
  void SumMatrix(const S21Matrix& other);  // сложить матрицы
  void SubMatrix(const S21Matrix& other);  // вычесть ммамтрицы
  void MulNumber(const double num);        // умножить на число
  void MulMatrix(const S21Matrix& other);  // умножить на матрицу
  S21Matrix Transpose();  // новая транспонированная матрица из текущей
  S21Matrix
  CalcComplements();  // матрица алгебраических дополнений текущей матрицы
  double Determinant();  // определитель текущей матрицы
  S21Matrix InverseMatrix();  // обратная матрица

  // operators
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double other) const;
  friend S21Matrix operator*(double temp, const S21Matrix& other);
  bool operator==(const S21Matrix& other) const;
  S21Matrix operator=(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double other);
  double operator()(int row, int col);

  // acessors
  int getRows() const;
  int getCols() const;
  double** getMatrix() const;
  double getElement(int i, int j) const;

  // mutators
  void setRows(int rows);
  void setCols(int cols);

  // other
  //  void randfillmatrix();
  void setMatrix(double** values, int rows, int cols);
  // void print();
 private:
  void getMinor(S21Matrix other, S21Matrix& temp, int row, int col);
  double getDet(S21Matrix& temp);
};
#endif