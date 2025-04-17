#include <gtest/gtest.h>

#include <stdexcept>

#include "S21_matrix_oop.h"

TEST(Constructor, Default) {
  S21Matrix temp;

  EXPECT_EQ(temp.getRows(), 3);
  EXPECT_EQ(temp.getCols(), 3);
}

TEST(Constructor, GoodMatrix) {
  S21Matrix temp(1, 5);

  EXPECT_EQ(temp.getRows(), 1);
  EXPECT_EQ(temp.getCols(), 5);
}

TEST(Constructor, GoodMatrix2) {
  S21Matrix temp(5, 1);

  EXPECT_EQ(temp.getRows(), 5);
  EXPECT_EQ(temp.getCols(), 1);
}

TEST(Constructor, BadMatrix) {
  EXPECT_THROW(S21Matrix temp(0, 5), std::invalid_argument);
}

TEST(Constructor, BadMatrix2) {
  EXPECT_THROW(S21Matrix temp(5, 0), std::invalid_argument);
}

TEST(Constructor, BadMatrix3) {
  EXPECT_THROW(S21Matrix temp(0, 0), std::invalid_argument);
}

TEST(Constructor, BadMatrix4) {
  EXPECT_THROW(S21Matrix temp(-2, 5), std::invalid_argument);
}

TEST(Constructor, BadMatrix5) {
  EXPECT_THROW(S21Matrix temp(5, -2), std::invalid_argument);
}

TEST(Constructor, BadMatrix6) {
  EXPECT_THROW(S21Matrix temp(-2, -2), std::invalid_argument);
}

TEST(Constructor, Copy) {
  S21Matrix temp(3, 6);
  S21Matrix copy(temp);

  EXPECT_EQ(copy.getRows(), 3);
  EXPECT_EQ(copy.getCols(), 6);
  EXPECT_TRUE(temp.EqMatrix(copy));
}

TEST(Constructor, Move) {
  S21Matrix temp(3, 6);
  S21Matrix copy(temp);
  S21Matrix move(std::move(temp));

  EXPECT_TRUE(move.EqMatrix(copy));
  EXPECT_EQ(move.getRows(), 3);
  EXPECT_EQ(move.getCols(), 6);
  EXPECT_EQ(temp.getMatrix(), nullptr);
  EXPECT_EQ(temp.getRows(), 0);
  EXPECT_EQ(temp.getCols(), 0);
}

TEST(Operations, EqMatrix) {
  S21Matrix test;
  S21Matrix test2;

  EXPECT_TRUE(test.EqMatrix(test2));
}

TEST(Operations, EqMatrix2) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);

  EXPECT_FALSE(test.EqMatrix(test2));
  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Operations, EqMatrix3) {
  S21Matrix test(3, 4);
  S21Matrix test2(3, 5);

  EXPECT_FALSE(test.EqMatrix(test2));
}

TEST(Operations, EqMatrix4) {
  S21Matrix test(4, 3);
  S21Matrix test2(5, 3);

  EXPECT_FALSE(test.EqMatrix(test2));
}

TEST(Operations, EqMatrix5) {
  S21Matrix test(3, 4);
  S21Matrix test2(5, 6);

  EXPECT_FALSE(test.EqMatrix(test2));
}

TEST(Operations, SumMatrix) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{9, 8, 7};
  value2[1] = new double[3]{6, 5, 4};
  value2[2] = new double[3]{3, 2, 1};
  test2.setMatrix(value2, 3, 3);
  S21Matrix result(3, 3);
  double** value3 = new double*[3];
  value3[0] = new double[3]{10, 10, 10};
  value3[1] = new double[3]{10, 10, 10};
  value3[2] = new double[3]{10, 10, 10};
  result.setMatrix(value3, 3, 3);
  test.SumMatrix(test2);

  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2;
  delete[] value3;
}

TEST(Operations, SumMatrix2) {
  S21Matrix test(3, 4);
  S21Matrix test2(3, 3);

  EXPECT_THROW(test.SumMatrix(test2), std::invalid_argument);
}

TEST(Operations, SumMatrix3) {
  S21Matrix test(3, 3);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test.SumMatrix(test2), std::invalid_argument);
}

TEST(Operations, SumMatrix4) {
  S21Matrix test(3, 4);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test.SumMatrix(test2), std::invalid_argument);
}

TEST(Operations, SubMatrix) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{9, 8, 7};
  value2[1] = new double[3]{6, 5, 4};
  value2[2] = new double[3]{3, 2, 1};
  test2.setMatrix(value2, 3, 3);
  S21Matrix result(3, 3);
  double** value3 = new double*[3];
  value3[0] = new double[3]{-8, -6, -4};
  value3[1] = new double[3]{-2, 0, 2};
  value3[2] = new double[3]{4, 6, 8};
  result.setMatrix(value3, 3, 3);
  test.SubMatrix(test2);

  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2;
  delete[] value3;
}

TEST(Operations, SubMatrix2) {
  S21Matrix test(3, 4);
  S21Matrix test2(3, 3);

  EXPECT_THROW(test.SubMatrix(test2), std::invalid_argument);
}

TEST(Operations, SubMatrix3) {
  S21Matrix test(3, 3);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test.SubMatrix(test2), std::invalid_argument);
}

TEST(Operations, SubMatrix4) {
  S21Matrix test(3, 4);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test.SubMatrix(test2), std::invalid_argument);
}

TEST(Operations, MulNumber) {
  S21Matrix test(3, 3);
  S21Matrix result(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{2, 4, 6};
  value2[1] = new double[3]{8, 10, 12};
  value2[2] = new double[3]{14, 16, 18};
  result.setMatrix(value2, 3, 3);
  test.MulNumber(2);

  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operations, MulMatrix) {
  S21Matrix test(3, 3);
  S21Matrix test2(4, 5);

  EXPECT_THROW(test.MulMatrix(test2), std::invalid_argument);
}

TEST(Operations, MulMatrix2) {
  S21Matrix test(2, 3);
  S21Matrix test2(3, 3);
  S21Matrix result(2, 3);
  double** value = new double*[2];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  test.setMatrix(value, 2, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{7, 8, 9};
  value2[1] = new double[3]{1, 2, 3};
  value2[2] = new double[3]{4, 5, 6};
  test2.setMatrix(value2, 3, 3);
  double** value3 = new double*[2];
  value3[0] = new double[3]{21, 27, 33};
  value3[1] = new double[3]{57, 72, 87};
  result.setMatrix(value3, 2, 3);
  test.MulMatrix(test2);

  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 2; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2[2];
  delete[] value2;
  delete[] value3;
}

TEST(Operations, Transpose) {
  S21Matrix test(3, 3);
  S21Matrix result(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{1, 4, 7};
  value2[1] = new double[3]{2, 5, 8};
  value2[2] = new double[3]{3, 6, 9};
  result.setMatrix(value2, 3, 3);
  test = test.Transpose();
  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operations, CalcComplements) {
  S21Matrix test(3, 4);

  EXPECT_THROW(test.CalcComplements(), std::invalid_argument);
}

TEST(Operations, CalcComplements2) {
  S21Matrix test(4, 3);

  EXPECT_THROW(test.CalcComplements(), std::invalid_argument);
}

TEST(Operations, CalcComplements3) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{0, 4, 2};
  value[2] = new double[3]{5, 2, 1};
  test.setMatrix(value, 3, 3);
  S21Matrix result(3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{0, 10, -20};
  value2[1] = new double[3]{4, -14, 8};
  value2[2] = new double[3]{-8, -2, 4};
  result.setMatrix(value2, 3, 3);
  test = test.CalcComplements();

  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operations, CalcComplements4) {
  S21Matrix test(1, 1);
  test = test.CalcComplements();

  EXPECT_EQ(test(0, 0), 1);
}

TEST(Operations, CalcComplements5) {
  S21Matrix temp(2, 2);
  double** value = new double*[2];
  value[0] = new double[2]{1, 2};
  value[1] = new double[2]{3, 4};
  temp.setMatrix(value, 2, 2);
  temp = temp.CalcComplements();

  EXPECT_EQ(temp(0, 0), 4);
  EXPECT_EQ(temp(0, 1), -3);
  EXPECT_EQ(temp(1, 0), -2);
  EXPECT_EQ(temp(1, 1), 1);
  for (int i = 0; i < 2; i++) delete[] value[i];
  delete[] value;
}

TEST(Operations, Determinant) {
  S21Matrix test(2, 3);

  EXPECT_THROW(test.Determinant(), std::invalid_argument);
}

TEST(Operations, Determinant2) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);

  EXPECT_EQ(test.Determinant(), 0);
  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Operations, Determinant3) {
  S21Matrix test(4, 4);
  double** value = new double*[4];
  value[0] = new double[4]{3, 7, 2, -1};
  value[1] = new double[4]{-2, 3, 48, -15};
  value[2] = new double[4]{1, 2, 22, 15};
  value[3] = new double[4]{11, 15, -102, -15};
  test.setMatrix(value, 4, 4);

  EXPECT_EQ(test.Determinant(), -4176);
  for (int i = 0; i < 4; i++) delete[] value[i];
  delete[] value;
}

TEST(Operations, Determinant4) {
  S21Matrix test(1, 1);

  EXPECT_EQ(test.Determinant(), test(0, 0));
}

TEST(Operations, InverseMatrix) {
  S21Matrix test(2, 3);

  EXPECT_THROW(test.InverseMatrix(), std::invalid_argument);
}

TEST(Operations, InverseMatrix2) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);

  EXPECT_THROW(test.InverseMatrix(), std::invalid_argument);
  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Operations, InverseMatrix3) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{2, 5, 7};
  value[1] = new double[3]{6, 3, 4};
  value[2] = new double[3]{5, -2, -3};
  test.setMatrix(value, 3, 3);
  S21Matrix result(3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{1, -1, 1};
  value2[1] = new double[3]{-38, 41, -34};
  value2[2] = new double[3]{27, -29, 24};
  result.setMatrix(value2, 3, 3);
  test = test.InverseMatrix();

  EXPECT_TRUE(test.EqMatrix(result));
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operators, Sum) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{9, 8, 7};
  value2[1] = new double[3]{6, 5, 4};
  value2[2] = new double[3]{3, 2, 1};
  test2.setMatrix(value2, 3, 3);
  S21Matrix result(3, 3);
  double** value3 = new double*[3];
  value3[0] = new double[3]{10, 10, 10};
  value3[1] = new double[3]{10, 10, 10};
  value3[2] = new double[3]{10, 10, 10};
  result.setMatrix(value3, 3, 3);
  test = test + test2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2;
  delete[] value3;
}

TEST(Operators, Sum2) {
  S21Matrix test(3, 4);
  S21Matrix test2(3, 3);

  EXPECT_THROW(test + test2, std::invalid_argument);
}

TEST(Operators, Sum3) {
  S21Matrix test(3, 3);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test + test2, std::invalid_argument);
}

TEST(Operators, Sum4) {
  S21Matrix test(3, 4);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test + test2, std::invalid_argument);
}

TEST(Operators, Sum5) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{9, 8, 7};
  value2[1] = new double[3]{6, 5, 4};
  value2[2] = new double[3]{3, 2, 1};
  test2.setMatrix(value2, 3, 3);
  S21Matrix result(3, 3);
  double** value3 = new double*[3];
  value3[0] = new double[3]{10, 10, 10};
  value3[1] = new double[3]{10, 10, 10};
  value3[2] = new double[3]{10, 10, 10};
  result.setMatrix(value3, 3, 3);
  test += test2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2;
  delete[] value3;
}

TEST(Operators, Sub) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{9, 8, 7};
  value2[1] = new double[3]{6, 5, 4};
  value2[2] = new double[3]{3, 2, 1};
  test2.setMatrix(value2, 3, 3);
  S21Matrix result(3, 3);
  double** value3 = new double*[3];
  value3[0] = new double[3]{-8, -6, -4};
  value3[1] = new double[3]{-2, 0, 2};
  value3[2] = new double[3]{4, 6, 8};
  result.setMatrix(value3, 3, 3);
  test = test - test2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2;
  delete[] value3;
}

TEST(Operators, Sub2) {
  S21Matrix test(3, 4);
  S21Matrix test2(3, 3);

  EXPECT_THROW(test - test2, std::invalid_argument);
}

TEST(Operators, Sub3) {
  S21Matrix test(3, 3);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test - test2, std::invalid_argument);
}

TEST(Operators, Sub4) {
  S21Matrix test(3, 4);
  S21Matrix test2(4, 3);

  EXPECT_THROW(test - test2, std::invalid_argument);
}

TEST(Operators, Sub5) {
  S21Matrix test(3, 3);
  S21Matrix test2(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{9, 8, 7};
  value2[1] = new double[3]{6, 5, 4};
  value2[2] = new double[3]{3, 2, 1};
  test2.setMatrix(value2, 3, 3);
  S21Matrix result(3, 3);
  double** value3 = new double*[3];
  value3[0] = new double[3]{-8, -6, -4};
  value3[1] = new double[3]{-2, 0, 2};
  value3[2] = new double[3]{4, 6, 8};
  result.setMatrix(value3, 3, 3);
  test -= test2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2;
  delete[] value3;
}

TEST(Operators, MulNumber) {
  S21Matrix test(3, 3);
  S21Matrix result(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{2, 4, 6};
  value2[1] = new double[3]{8, 10, 12};
  value2[2] = new double[3]{14, 16, 18};
  result.setMatrix(value2, 3, 3);
  test = test * 2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operators, MulNumber2) {
  S21Matrix test(3, 3);
  S21Matrix result(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{2, 4, 6};
  value2[1] = new double[3]{8, 10, 12};
  value2[2] = new double[3]{14, 16, 18};
  result.setMatrix(value2, 3, 3);
  test *= 2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operators, MulNumber3) {
  S21Matrix test(3, 3);
  S21Matrix result(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{2, 4, 6};
  value2[1] = new double[3]{8, 10, 12};
  value2[2] = new double[3]{14, 16, 18};
  result.setMatrix(value2, 3, 3);
  test = 2 * test;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 3; i++) {
    delete[] value[i];
    delete[] value2[i];
  }
  delete[] value;
  delete[] value2;
}

TEST(Operators, MulMatrix) {
  S21Matrix test(3, 3);
  S21Matrix test2(4, 5);

  EXPECT_THROW(test * test2, std::invalid_argument);
}

TEST(Operators, MulMatrix2) {
  S21Matrix test(2, 3);
  S21Matrix test2(3, 3);
  S21Matrix result(2, 3);
  double** value = new double*[2];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  test.setMatrix(value, 2, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{7, 8, 9};
  value2[1] = new double[3]{1, 2, 3};
  value2[2] = new double[3]{4, 5, 6};
  test2.setMatrix(value2, 3, 3);
  double** value3 = new double*[2];
  value3[0] = new double[3]{21, 27, 33};
  value3[1] = new double[3]{57, 72, 87};
  result.setMatrix(value3, 2, 3);
  test = test * test2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 2; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2[2];
  delete[] value2;
  delete[] value3;
}

TEST(Operators, MulMatrix3) {
  S21Matrix test(2, 3);
  S21Matrix test2(3, 3);
  S21Matrix result(2, 3);
  double** value = new double*[2];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  test.setMatrix(value, 2, 3);
  double** value2 = new double*[3];
  value2[0] = new double[3]{7, 8, 9};
  value2[1] = new double[3]{1, 2, 3};
  value2[2] = new double[3]{4, 5, 6};
  test2.setMatrix(value2, 3, 3);
  double** value3 = new double*[2];
  value3[0] = new double[3]{21, 27, 33};
  value3[1] = new double[3]{57, 72, 87};
  result.setMatrix(value3, 2, 3);
  test *= test2;

  EXPECT_TRUE(test == result);
  for (int i = 0; i < 2; i++) {
    delete[] value[i];
    delete[] value2[i];
    delete[] value3[i];
  }
  delete[] value;
  delete[] value2[2];
  delete[] value2;
  delete[] value3;
}

TEST(Operators, Eq) {
  S21Matrix test(2, 3);
  S21Matrix test2(3, 3);

  EXPECT_FALSE(test == test2);

  test = test2;

  EXPECT_TRUE(test == test2);
}

TEST(Operators, parenthesis) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);

  EXPECT_EQ(test(1, 1), 5);
  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Operators, parenthesis2) {
  S21Matrix test(3, 3);

  EXPECT_THROW(test(5, 1), std::out_of_range);
}

TEST(Operators, parenthesis3) {
  S21Matrix test(3, 3);

  EXPECT_THROW(test(1, 5), std::out_of_range);
}

TEST(Accesors, getRows) {
  S21Matrix test(3, 5);

  EXPECT_EQ(test.getRows(), 3);
}

TEST(Accesors, getCols) {
  S21Matrix test(3, 5);

  EXPECT_EQ(test.getCols(), 5);
}

TEST(Accesors, getElement) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);

  EXPECT_EQ(test.getElement(1, 1), 5);
  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Accesors, getElement2) {
  S21Matrix test(3, 3);

  EXPECT_THROW(test.getElement(15, 24), std::out_of_range);
}

TEST(Accesors, getElement3) {
  S21Matrix test(3, 3);

  EXPECT_THROW(test.getElement(2, 15), std::out_of_range);
}

TEST(Mutators, setRows) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  test.setRows(5);
  EXPECT_EQ(test.getRows(), 5);
  EXPECT_EQ(test.getElement(4, 1), 0);
  EXPECT_EQ(test.getElement(1, 1), 5);

  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Mutators, setRows2) {
  S21Matrix test(3, 3);

  EXPECT_THROW(test.setRows(-2), std::out_of_range);
}

TEST(Mutators, setRows3) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  test.setRows(2);
  EXPECT_EQ(test.getRows(), 2);
  EXPECT_EQ(test.getElement(1, 1), 5);

  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Mutators, setCols) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  test.setCols(5);
  EXPECT_EQ(test.getCols(), 5);
  EXPECT_EQ(test.getElement(1, 1), 5);
  EXPECT_EQ(test.getElement(0, 4), 0);

  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

TEST(Mutators, setCols2) {
  S21Matrix test(3, 3);

  EXPECT_THROW(test.setCols(-2), std::out_of_range);
}

TEST(Mutators, setCols3) {
  S21Matrix test(3, 3);
  double** value = new double*[3];
  value[0] = new double[3]{1, 2, 3};
  value[1] = new double[3]{4, 5, 6};
  value[2] = new double[3]{7, 8, 9};
  test.setMatrix(value, 3, 3);
  test.setCols(2);
  EXPECT_EQ(test.getCols(), 2);
  EXPECT_EQ(test.getElement(1, 1), 5);

  for (int i = 0; i < 3; i++) delete[] value[i];
  delete[] value;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
