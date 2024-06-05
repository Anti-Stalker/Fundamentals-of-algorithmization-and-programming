#pragma once

bool IsMatrixConsistent(int rows1, int columns1, int rows2, int columns2);
bool IsMatrixJoint(int rows1, int columns1, int rows2, int columns2);
double FindDet(int rows, int columns, double** matrix);
double** InverseMatrix(int rows, int columns, double** matrix, double determinant);
double** SumMatrices(int rows, int columns, double** matrix1, double** matrix2);
double** SubstractMatrices(int rows, int columns, double** matrix1, double** matrix2);
double** MultiplyMatrices(int rows1, int rowcol, int columns2, double** matrix1, double** matrix2);
double** MultiplyNumOnMatrix(int rows2, int columns2, double** matrix1, double** matrix2);