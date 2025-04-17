#include "s21_matrix_oop.h"

// constructors
S21Matrix::S21Matrix() {  // без аргумментов
  rows_ = 3;
  cols_ = 3;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }
}
S21Matrix::S21Matrix(int rows, int cols) {  // строки и столбцы
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Number of rows and columns must be positive");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = 0.0;
    }
  }
}
S21Matrix::S21Matrix(const S21Matrix& other) {  // копировать в новую матрицу
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = new double*[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    std::copy(other.matrix_[i], other.matrix_[i] + cols_, matrix_[i]);
  }
}
S21Matrix::S21Matrix(S21Matrix&& other) {  // перенести в новую матрицу
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}
// destructor
S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
};
// operatoins
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      }
    }
  }
  return true;
}
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] += other.matrix_[i][j];
      }
    }
  } else {
    throw std::invalid_argument("Matrix size are different");
  }
}
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  } else {
    throw std::invalid_argument("Matrix size are different");
  }
}
void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Matrix sizes are wrong");
  }
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  if (cols_ != other.cols_) {
    if (other.cols_ > cols_) {
      for (int i = 0; i < rows_; i++) {
        double* newRow = new double[other.cols_];
        std::copy(matrix_[i], matrix_[i] + cols_, newRow);
        std::fill(newRow + cols_, newRow + other.cols_, 0.0);
        delete[] matrix_[i];
        matrix_[i] = newRow;
      }
    } else if (other.cols_ < cols_) {
      for (int i = 0; i < rows_; i++) {
        double* newRow = new double[other.cols_];
        std::copy(matrix_[i], matrix_[i] + other.cols_, newRow);
        delete[] matrix_[i];
        matrix_[i] = newRow;
      }
    }
    cols_ = other.cols_;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = result.matrix_[i][j];
    }
  }
}
S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = matrix_[j][i];
    }
  }
  return result;
}
S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not a square matrix");
  }
  S21Matrix result(rows_, cols_);
  if (rows_ != 1) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix temp(rows_ - 1, cols_ - 1);
        getMinor(*this, temp, i, j);
        result.matrix_[i][j] = getDet(temp) * pow(-1, i + j);
      }
    }
  } else
    result.matrix_[0][0] = 1;
  return result;
}
double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not a square matrix");
  }
  if (rows_ == 1) {
    return matrix_[0][0];
  } else {
    return getDet(*this);
  }
}
S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ != cols_) {
    throw std::invalid_argument("Not a square matrix");
  }
  double temp_det = Determinant();
  if (std::fabs(temp_det) < 1e-7) {
    throw std::invalid_argument("Wrong matrix");
  }
  S21Matrix temp_comp = CalcComplements();
  S21Matrix temp_transp = temp_comp.Transpose();
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[i][j] = temp_transp.matrix_[i][j] / temp_det;
    }
  }
  return result;
}
// operators
S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix result = *this;
  result += other;
  return result;
}
S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix result = *this;
  result -= other;
  return result;
}
S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix result = *this;
  result *= other;
  return result;
}
S21Matrix S21Matrix::operator*(const double other) const {
  S21Matrix result = *this;
  result *= other;
  return result;
}
S21Matrix operator*(double temp, const S21Matrix& other) {
  return other * temp;
}
bool S21Matrix::operator==(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (matrix_[i][j] != other.matrix_[i][j]) {
        return false;
      };
    }
  }
  return true;
}
S21Matrix S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double*[rows_];
    for (int i = 0; i < rows_; i++) {
      matrix_[i] = new double[cols_];
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
  return *this;
}
S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}
S21Matrix S21Matrix::operator*=(const double other) {
  MulNumber(other);
  return *this;
}
double S21Matrix::operator()(int row, int col) {
  if (row < 0 || row >= rows_) {
    throw std::out_of_range("Row index is outside the matrix");
  }
  if (col < 0 || col >= cols_) {
    throw std::out_of_range("Column index is outside the matrix");
  }
  return matrix_[row][col];
}
// acessors
int S21Matrix::getRows() const { return rows_; }
int S21Matrix::getCols() const { return cols_; }
double** S21Matrix::getMatrix() const { return matrix_; }
double S21Matrix::getElement(int i, int j) const {
  if (i < 0 || i >= rows_) {
    throw std::out_of_range("Row index is outside the matrix");
  }
  if (j < 0 || j >= cols_) {
    throw std::out_of_range("Column index is outside the matrix");
  }
  return matrix_[i][j];
}
// mutators
void S21Matrix::setRows(int rows) {
  if (rows < 1) {
    throw std::out_of_range("Index < 1");
  }
  if (rows > rows_) {
    double** newMatrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
      newMatrix[i] = new double[cols_];
      if (i < rows_) {
        std::copy(matrix_[i], matrix_[i] + cols_, newMatrix[i]);
      } else {
        std::fill(newMatrix[i], newMatrix[i] + cols_, 0.0);
      }
    }
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = newMatrix;
  } else if (rows < rows_) {
    double** newMatrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
      newMatrix[i] = matrix_[i];
    }
    for (int i = rows; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    matrix_ = newMatrix;
  }
  rows_ = rows;
}
void S21Matrix::setCols(int cols) {
  if (cols < 1) {
    throw std::out_of_range("Index < 1");
  }
  if (cols > cols_) {
    for (int i = 0; i < rows_; i++) {
      double* newRow = new double[cols];
      std::copy(matrix_[i], matrix_[i] + cols_, newRow);
      std::fill(newRow + cols_, newRow + cols, 0.0);
      delete[] matrix_[i];
      matrix_[i] = newRow;
    }
  } else if (cols < cols_) {
    for (int i = 0; i < rows_; i++) {
      double* newRow = new double[cols];
      std::copy(matrix_[i], matrix_[i] + cols, newRow);
      delete[] matrix_[i];
      matrix_[i] = newRow;
    }
  }
  cols_ = cols;
}
// other
void S21Matrix::getMinor(S21Matrix other, S21Matrix& temp, int row, int col) {
  for (int i = 0, temp_row = 0; i < other.rows_; i++) {
    if (i != row) {
      for (int j = 0, temp_col = 0; j < other.cols_; j++) {
        if (j != col) {
          temp.matrix_[temp_row][temp_col] = other.matrix_[i][j];
          temp_col++;
        } else
          continue;
      }
      temp_row++;
    } else
      continue;
  }
}
double S21Matrix::getDet(S21Matrix& temp) {
  double res = 0.0;
  if (temp.rows_ == 1) {
    res = temp.matrix_[0][0];
  } else if (temp.rows_ == 2) {
    res = temp.matrix_[0][0] * temp.matrix_[1][1] -
          temp.matrix_[0][1] * temp.matrix_[1][0];
  } else if (temp.rows_ == 3) {
    res = temp.matrix_[0][0] * temp.matrix_[1][1] * temp.matrix_[2][2] +
          temp.matrix_[0][1] * temp.matrix_[1][2] * temp.matrix_[2][0] +
          temp.matrix_[0][2] * temp.matrix_[1][0] * temp.matrix_[2][1] -
          temp.matrix_[0][2] * temp.matrix_[1][1] * temp.matrix_[2][0] -
          temp.matrix_[0][0] * temp.matrix_[1][2] * temp.matrix_[2][1] -
          temp.matrix_[0][1] * temp.matrix_[1][0] * temp.matrix_[2][2];
  } else {
    S21Matrix tempMat(temp.rows_ - 1, temp.cols_ - 1);
    int sign = 1;
    for (int i = 0; i < temp.rows_; i++) {
      getMinor(temp, tempMat, 0, i);
      res += sign * temp.matrix_[0][i] * getDet(tempMat);
      sign *= -1;
    }
  }
  return res;
}
// void S21Matrix::randfillmatrix()
//   {
//     for(int i = 0; i < rows_; i++)
//     {
//       for(int j = 0; j < cols_; j++)
//       {
//         matrix_[i][j] = rand() % 9 +0;
//       }
//     }
//   };
void S21Matrix::setMatrix(double** values, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    std::copy(values[i], values[i] + cols, matrix_[i]);
  }
  rows_ = rows;
  cols_ = cols;
}
// void S21Matrix::print()
//   {
//     for(int i = 0; i < rows_; i++)
//     {
//         for(int j = 0; j < cols_; j++)
//         {
//           std::cout << matrix_[i][j] << " ";
//         }
//         std::cout << "\n";
//     }
//   };