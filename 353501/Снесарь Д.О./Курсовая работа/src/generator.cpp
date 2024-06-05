#include "generator.h"

using namespace std;

string Generator::getGrid()
{
    string s = "";
    for(int row_num=0; row_num<9; ++row_num)
    {
        for(int col_num=0; col_num<9; ++col_num)
        {
            s = s + to_string(grid[row_num][col_num]);
        }
    }

    return s;
}




int genRandNum(int maxLimit)
{
    return rand()%maxLimit;
}



bool FindUnassignedLocation(int grid[9][9], int &row, int &col)
{
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }

    return false;
}

bool UsedInRow(int grid[9][9], int row, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool UsedInCol(int grid[9][9], int col, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (grid[row][col] == num)
            return true;
    }

    return false;
}

bool UsedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
        }
    }

    return false;
}

bool isSafe(int grid[9][9], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) && !UsedInBox(grid, row - row%3 , col - col%3, num);
}




void Generator::fillEmptyDiagonalBox(int idx)
{
    int start = idx*3;
    random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            this->grid[start+i][start+j] = guessNum[i*3+j];
        }
    }
}

void Generator::createSeed()
{

    this->fillEmptyDiagonalBox(0);
    this->fillEmptyDiagonalBox(1);
    this->fillEmptyDiagonalBox(2);


    this->solveGrid();

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            this->solnGrid[i][j] = this->grid[i][j];
        }
    }
}




Generator::Generator()
{

    // initialize difficulty level
    this->difficultyLevel = 0;

    // Randomly shuffling the array of removing grid positions
    for(int i=0;i<81;i++)
    {
        this->gridPos[i] = i;
    }

    random_shuffle(this->gridPos, (this->gridPos) + 81, genRandNum);

    // Randomly shuffling the guessing number array
    for(int i=0;i<9;i++)
    {
        this->guessNum[i]=i+1;
    }

    random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            this->grid[i][j]=0;
        }
    }

    grid_status = true;
}



Generator::Generator(string grid_str, bool row_major)
{
    if(grid_str.length() != 81)
    {
        grid_status=false;
        return;
    }


    for(int i=0; i<81; ++i)
    {
        int curr_num = grid_str[i]-'0';
        if(!((curr_num == 0) || (curr_num > 0 && curr_num < 10)))
        {
            grid_status=false;
            return;
        }

        if(row_major) grid[i/9][i%9] = curr_num;
        else          grid[i%9][i/9] = curr_num;
    }

    for (int col_num=0; col_num<9; ++col_num)
    {
        bool nums[10]={false};
        for (int row_num=0; row_num<9; ++row_num)
        {
            int curr_num = grid[row_num][col_num];
            if(curr_num!=0 && nums[curr_num]==true)
            {
                grid_status=false;
                return;
            }
            nums[curr_num] = true;
        }
    }

    for (int row_num=0; row_num<9; ++row_num)
    {
        bool nums[10]={false};
        for (int col_num=0; col_num<9; ++col_num)
        {
            int curr_num = grid[row_num][col_num];
            if(curr_num!=0 && nums[curr_num]==true)
            {
                grid_status=false;
                return;
            }
            nums[curr_num] = true;
        }
    }

    for (int block_num=0; block_num<9; ++block_num)
    {
        bool nums[10]={false};
        for (int cell_num=0; cell_num<9; ++cell_num)
        {
            int curr_num = grid[((int)(block_num/3))*3 + (cell_num/3)][((int)(block_num%3))*3 + (cell_num%3)];
            if(curr_num!=0 && nums[curr_num]==true)
            {
                grid_status=false;
                return;
            }
            nums[curr_num] = true;
        }
    }

    for(int i=0;i<9;i++)
    {
        this->guessNum[i]=i+1;
    }

    random_shuffle(this->guessNum, (this->guessNum) + 9, genRandNum);

    grid_status = true;
}




bool Generator::verifyGridStatus()
{
    return grid_status;
}

void Generator::printGrid(QVector<QVector<int>>& field, QVector<QVector<int>>& ans)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(grid[i][j] == 0)
              field[i][j] = -1;
            else
                field[i][j] =grid[i][j];
                ans[i][j] = solnGrid[i][j];
        }
    }

    qDebug()<<"\nDifficulty of current sudoku(0 being easiest): "<<this->difficultyLevel;

}

bool Generator::solveGrid()
{
    int row, col;


    if (!FindUnassignedLocation(this->grid, row, col))
        return true; // success!

    for (int num = 0; num < 9; num++)
    {

        if (isSafe(this->grid, row, col, this->guessNum[num]))
        {

            this->grid[row][col] = this->guessNum[num];


            if (solveGrid())
                return true;


            this->grid[row][col] = 0;
        }
    }

    return false;
}



void Generator::countSoln(int &number)
{
    int row, col;

    if(!FindUnassignedLocation(this->grid, row, col))
    {
        number++;
        return ;
    }


    for(int i=0;i<9 && number<2;i++)
    {
        if( isSafe(this->grid, row, col, this->guessNum[i]) )
        {
            this->grid[row][col] = this->guessNum[i];
            countSoln(number);
        }

        this->grid[row][col] = 0;
    }

}




void Generator::genPuzzle()
{
    for(int i=0;i<81;i++)
    {
        int x = (this->gridPos[i])/9;
        int y = (this->gridPos[i])%9;
        int temp = this->grid[x][y];
        this->grid[x][y] = 0;


        int check=0;
        countSoln(check);
        if(check!=1)
        {
            this->grid[x][y] = temp;
        }
    }
}




void Generator::printSVG(string path="")
{
    string fileName = path + "svgHead.txt";
    ifstream file1(fileName.c_str());
    stringstream svgHead;
    svgHead << file1.rdbuf();

    ofstream outFile("puzzle.svg");
    outFile << svgHead.rdbuf();

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(this->grid[i][j]!=0)
            {
                int x = 50*j + 16;
                int y = 50*i + 35;

                stringstream text;
                text<<"<text x=\""<<x<<"\" y=\""<<y<<"\" style=\"font-weight:bold\" font-size=\"30px\">"<<this->grid[i][j]<<"</text>\n";

                outFile << text.rdbuf();
            }
        }
    }

    outFile << "<text x=\"50\" y=\"500\" style=\"font-weight:bold\" font-size=\"15px\">Difficulty Level (0 being easiest): "                  <<this->difficultyLevel<<"</text>\n";
    outFile << "</svg>";

}



int Generator::branchDifficultyScore()
{
    int emptyPositions = -1;
    int tempGrid[9][9];
    int sum=0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            tempGrid[i][j] = this->grid[i][j];
        }
    }

    while(emptyPositions!=0)
    {
        vector<vector<int> > empty;

        for(int i=0;i<81;i++)
        {
            if(tempGrid[(int)(i/9)][(int)(i%9)] == 0)
            {
                vector<int> temp;
                temp.push_back(i);

                for(int num=1;num<=9;num++)
                {
                    if(isSafe(tempGrid,i/9,i%9,num))
                    {
                        temp.push_back(num);
                    }
                }

                empty.push_back(temp);
            }

        }

        if(empty.size() == 0)
        {
            qDebug()<<"Hello: "<<sum;
            return sum;
        }

        int minIndex = 0;

        int check = empty.size();
        for(int i=0;i<check;i++)
        {
            if(empty[i].size() < empty[minIndex].size())
                minIndex = i;
        }

        int branchFactor=empty[minIndex].size();
        int rowIndex = empty[minIndex][0]/9;
        int colIndex = empty[minIndex][0]%9;

        tempGrid[rowIndex][colIndex] = this->solnGrid[rowIndex][colIndex];
        sum = sum + ((branchFactor-2) * (branchFactor-2)) ;

        emptyPositions = empty.size() - 1;
    }

    return sum;

}

int Generator::getDifficulty()
{
    return difficultyLevel;
}

void Generator::genGetInfo(QVector<QVector<int>> &field, QVector<QVector<int>> &ans, int &difficulty, int lvlReaded)
{

    QString filename = "/home/user/SudokuGameDev/randomLevels.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);

        for(int i = 0; i < lvlReaded * 21; i++){
            in.readLine();
        }

        // Читаем уровень сложности

        int diff;
        in >> diff;
        difficulty = diff;
        difficultyLevel = diff;



        // Читаем поле и ответы
        int a = 0, b = 0;
        for (int i = 0; i < 91; i++)
        {
            char ch;
            in >> ch;
            if (ch == '_')
            {
                field[b][a] = -1;
                a++;
                if (a > 8)
                {
                    a = 0;
                    b++;
                }
            }
            else if (std::isdigit(ch))
            {
                field[b][a] = ch - '0';
                a++;
                if (a > 8)
                {
                    a = 0;
                    b++;
                }
            }
            qDebug() << ch;
        }

        a = 0;
        b = 0;
        for (int i = 0; i < 91; i++)
        {
            char ch;
            in >> ch;
            if (ch == '_')
            {
                ans[b][a] = -1;
                a++;
                if (a > 8)
                {
                    a = 0;
                    b++;
                }
            }
            else if (std::isdigit(ch))
            {
                ans[b][a] = ch - '0';
                a++;
                if (a > 8)
                {
                    a = 0;
                    b++;
                }
            }
            qDebug() << ch;
        }

        file.close();

        qDebug() << "Прочитано из файла randomLevels.txt:\n";
    }
    else
    {
        qDebug() << "Не удалось открыть файл randomLevels.txt для чтения.";
    }

}

void Generator::calculateDifficulty()
{
    int B = branchDifficultyScore();
    int emptyCells = 0;

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(this->grid[i][j] == 0)
                emptyCells++;
        }
    }

    this->difficultyLevel = B*100 + emptyCells;
}

