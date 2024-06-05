#include "MatrixFunctions.h"
#include "pch.h"

using namespace System;
using namespace System::Windows::Forms;


bool IsMatrixConsistent(int rows1, int columns1, int rows2, int columns2) {
    return (columns1 == rows2);
}

bool IsMatrixJoint(int rows1, int columns1, int rows2, int columns2) {
    return (rows1 == rows2 && columns1 == columns2);
}

double FindDet(int rows, int columns, double** matrix)
{

    if (rows == 1)
    {
        return matrix[0][0];
    }

    double determinant = 0;
    int sign = 1;

    for (int i = 0; i < columns; i++)
    {
        int subRows = rows - 1;
        int subColumns = columns - 1;
        double** subMatrix = new double* [subRows];

        for (int j = 0; j < subRows; j++)
        {
            subMatrix[j] = new double[subColumns];
        }

        int subMatrixRow = 0;
        for (int j = 1; j < rows; j++)
        {
            int subMatrixColumn = 0;
            for (int k = 0; k < columns; k++)
            {
                if (k != i)
                {
                    subMatrix[subMatrixRow][subMatrixColumn++] = matrix[j][k];
                }
            }
            subMatrixRow++;
        }

        double subDeterminant = FindDet(subRows, subColumns, subMatrix);

        determinant += sign * matrix[0][i] * subDeterminant;

        for (int j = 0; j < subRows; j++)
        {
            delete[] subMatrix[j];
        }
        delete[] subMatrix;

        sign *= -1;
    }

    return determinant;
}

double** InverseMatrix(int rows, int columns, double** matrix, double determinant) {
    double** adjMatrix = new double* [rows];
    for (int i = 0; i < rows; i++) {
        adjMatrix[i] = new double[columns];
        for (int j = 0; j < columns; j++) {
            int sign = ((i + j) % 2 == 0) ? 1 : -1;
            int subRows = rows - 1;
            int subColumns = columns - 1;
            double** subMatrix = new double* [subRows];
            for (int k = 0; k < subRows; k++) {
                subMatrix[k] = new double[subColumns];
            }
            int subMatrixRow = 0;
            for (int k = 0; k < rows; k++) {
                if (k != i) {
                    int subMatrixColumn = 0;
                    for (int l = 0; l < columns; l++) {
                        if (l != j) {
                            subMatrix[subMatrixRow][subMatrixColumn++] = matrix[k][l];
                        }
                    }
                    subMatrixRow++;
                }
            }
            double subDeterminant = FindDet(subRows, subColumns, subMatrix);
            adjMatrix[i][j] = sign * subDeterminant / determinant;
            for (int k = 0; k < subRows; k++) {
                delete[] subMatrix[k];
            }
            delete[] subMatrix;
        }
    }

    return adjMatrix;
}


double** SumMatrices(int rows, int columns, double** matrix1, double** matrix2) {
    double** result = new double* [rows];

    for (int i = 0; i < rows; ++i) {
        result[i] = new double[columns];
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

double** SubstractMatrices(int rows, int columns, double** matrix1, double** matrix2) {
    double** result = new double* [rows];

    for (int i = 0; i < rows; ++i) {
        result[i] = new double[columns];
        for (int j = 0; j < columns; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }

    return result;
}


double** MultiplyMatrices(int rows1, int rowcol, int columns2, double** matrix1, double** matrix2) {
    double** result = new double* [rows1];
    for (int i = 0; i < rows1; ++i) {
        result[i] = new double[columns2];
        for (int j = 0; j < columns2; ++j) {
            double sum = 0.0;
            for (int k = 0; k < rowcol; ++k) {
                sum += matrix1[i][k] * matrix2[k][j];
            }
            result[i][j] = sum;
        }
    }
    return result;
}

double** MultiplyNumOnMatrix(int rows2, int columns2, double** matrix1, double** matrix2) {

    double** result = new double* [rows2];
    for (int i = 0; i < rows2; ++i) {
        result[i] = new double[columns2];
        for (int j = 0; j < columns2; ++j) {
            result[i][j] = matrix1[0][0] * matrix2[i][j];
        }
    }
    return result;
}