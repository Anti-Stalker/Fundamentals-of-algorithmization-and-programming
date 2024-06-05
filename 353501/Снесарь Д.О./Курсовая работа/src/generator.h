#ifndef GENERATOR_H
#define GENERATOR_H

#include <QVector>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <QThread>
#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QMutexLocker>
#include <QObject>

class Generator : public QObject
{
   Q_OBJECT
    private:
        int grid[9][9];
        int solnGrid[9][9];
        int guessNum[9];
        int gridPos[81];
        int difficultyLevel = 0;
        bool grid_status;

    public:
        Generator();
        Generator(std::string, bool row_major=true);
        void fillEmptyDiagonalBox(int);
        void createSeed();
        void printGrid(QVector<QVector<int>>& field, QVector<QVector<int>>& ans);
        bool solveGrid();
        std::string getGrid();
        void countSoln(int &number);
        void genPuzzle();
        bool verifyGridStatus();
        void printSVG(std::string);
        void calculateDifficulty();
        int  branchDifficultyScore();
        int getDifficulty();
        void genGetInfo(QVector<QVector<int>>& field, QVector<QVector<int>>& ans, int& difficulty, int lvlReaded);

};

#endif // GENERATOR_H
