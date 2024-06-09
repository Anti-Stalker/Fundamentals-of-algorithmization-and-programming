#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QString>
#include <QVector>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>


namespace Ui {
class keyboard;
}

class keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit keyboard(QWidget *parent = nullptr);
    ~keyboard();

    void setSymbols();
    void setLocale(int n);
    int curLocale = 0;
    bool isCaps = false;
    bool isShift = false;

public slots:
    void handleButtonClicked();
    void keyPressEventK(QKeyEvent *event) /*override*/;
public:
    enum Locale{fra, ger, ara, bel, heb, chn};
    Ui::keyboard *ui;
    const QMap<int, int> keyCodeNum =
        {
            {49, 0},
            {10, 1},
            {11, 2},
            {12, 3},
            {13, 4},
            {14, 5},
            {15, 6},
            {16, 7},
            {17, 8},
            {18, 9},
            {19, 10},
            {20, 11},
            {21, 12},
            {24, 13},
            {25, 14},
            {26, 15},
            {27, 16},
            {28, 17},
            {29, 18},
            {30, 19},
            {31, 20},
            {32, 21},
            {33, 22},
            {34, 23},
            {35, 24},
            {51, 25},
            {38, 26},
            {39, 27},
            {40, 28},
            {41, 29},
            {42, 30},
            {43, 31},
            {44, 32},
            {45, 33},
            {46, 34},
            {47, 35},
            {48, 36},
            {52, 37},
            {53, 38},
            {54, 39},
            {55, 40},
            {56, 41},
            {57, 42},
            {58, 43},
            {59, 44},
            {60, 45},
            {61, 46},

            {62, 47},
            {65, 48},
            {66, 49},
        };

    QMap<int, QPushButton*> buttonsMap;

    QVector<QVector<QMap<int, QString>>> keyText;
    void initSymbols(){
        keyText.resize(7);
        for (auto & i:keyText) {
            i.resize(4);
        }
        keyText[0][0][49] = "^";
        keyText[0][0][10]  = "1";
        keyText[0][0][11]  = "2";
        keyText[0][0][12]  = "3";
        keyText[0][0][13]  = "4";
        keyText[0][0][14]  = "5";
        keyText[0][0][15]  = "6";
        keyText[0][0][16]  = "7";
        keyText[0][0][17]  = "8";
        keyText[0][0][18] = "9";
        keyText[0][0][19] = "0";
        keyText[0][0][20] = "ß";
        keyText[0][0][21] = "´";

        keyText[0][0][24] = "q";
        keyText[0][0][25] = "w";
        keyText[0][0][26] = "e";
        keyText[0][0][27] = "r";
        keyText[0][0][28] = "t";
        keyText[0][0][29] = "z";
        keyText[0][0][30] = "u";
        keyText[0][0][31] = "i";
        keyText[0][0][32] = "o";
        keyText[0][0][33] = "p";
        keyText[0][0][34] = "ü";
        keyText[0][0][35] = "+";
        keyText[0][0][51] = "#";

        keyText[0][0][66] = "caps";
        keyText[0][0][38] = "a";
        keyText[0][0][39] = "s";
        keyText[0][0][40] = "d";
        keyText[0][0][41] = "f";
        keyText[0][0][42] = "g";
        keyText[0][0][43] = "h";
        keyText[0][0][44] = "j";
        keyText[0][0][45] = "k";
        keyText[0][0][46] = "l";
        keyText[0][0][47] = "ö";
            keyText[0][0][48] = "ä";

            keyText[0][0][50] = "shift";
        keyText[0][0][52] = "y";
        keyText[0][0][53] = "x";
        keyText[0][0][54] = "c";
        keyText[0][0][55] = "v";
        keyText[0][0][56] = "b";
        keyText[0][0][57] = "n";
        keyText[0][0][58] = "m";
        keyText[0][0][59] = ",";
        keyText[0][0][60] = ".";
        keyText[0][0][61] = "-";
        keyText[0][0][62] = "shift";

        keyText[0][0][65] = "space";

        keyText[0][1][49] = "°";
            keyText[0][1][10] = "!";
        keyText[0][1][11] = "\"";
        keyText[0][1][12] = "§";
            keyText[0][1][13] = "$";
        keyText[0][1][14] = "%";
        keyText[0][1][15] = "&&";
        keyText[0][1][16] = "/";
        keyText[0][1][17] = "(";
        keyText[0][1][18] = ")";
        keyText[0][1][19] = "=";
        keyText[0][1][20] = "?";
        keyText[0][1][21] = "`";

        keyText[0][1][24] = "Q";
        keyText[0][1][25] = "W";
        keyText[0][1][26] = "E";
        keyText[0][1][27] = "R";
        keyText[0][1][28] = "T";
        keyText[0][1][29] = "Y";
        keyText[0][1][30] = "U";
        keyText[0][1][31] = "I";
        keyText[0][1][32] = "O";
        keyText[0][1][33] = "P";
        keyText[0][1][34] = "{";
        keyText[0][1][35] = "}";
        keyText[0][1][51] = "|";

        keyText[0][1][66] = "caps";
        keyText[0][1][38] = "A";
        keyText[0][1][39] = "S";
        keyText[0][1][40] = "D";
        keyText[0][1][41] = "F";
        keyText[0][1][42] = "G";
        keyText[0][1][43] = "H";
        keyText[0][1][44] = "J";
        keyText[0][1][45] = "K";
        keyText[0][1][46] = "L";
        keyText[0][1][47] = "Ö";
            keyText[0][1][48] = "Ä";

            keyText[0][1][50] = "shift";
        keyText[0][1][52] = "Y";
        keyText[0][1][53] = "X";
        keyText[0][1][54] = "C";
        keyText[0][1][55] = "V";
        keyText[0][1][56] = "B";
        keyText[0][1][57] = "N";
        keyText[0][1][58] = "M";
        keyText[0][1][59] = ";";
        keyText[0][1][60] = ":";
        keyText[0][1][61] = "_";
        keyText[0][1][62] = "shift";

        keyText[0][1][65] = "space";

        keyText[0][2][49] = "^";
        keyText[0][2][10] = "1";
        keyText[0][2][11] = "2";
        keyText[0][2][12] = "3";
        keyText[0][2][13] = "4";
        keyText[0][2][14] = "5";
        keyText[0][2][15] = "6";
        keyText[0][2][16] = "7";
        keyText[0][2][17] = "8";
        keyText[0][2][18] = "9";
        keyText[0][2][19] = "0";
        keyText[0][2][20] = "ẞ";
        keyText[0][2][21] = "´";

            keyText[0][2][24] = "Q";
        keyText[0][2][25] = "W";
        keyText[0][2][26] = "E";
        keyText[0][2][27] = "R";
        keyText[0][2][28] = "T";
        keyText[0][2][29] = "Z";
        keyText[0][2][30] = "U";
        keyText[0][2][31] = "I";
        keyText[0][2][32] = "O";
        keyText[0][2][33] = "P";
        keyText[0][2][34] = "Ü";
            keyText[0][2][35] = "+";
        keyText[0][2][51] = "#";

        keyText[0][2][66] = "caps";
        keyText[0][2][38] = "A";
        keyText[0][2][39] = "S";
        keyText[0][2][40] = "D";
        keyText[0][2][41] = "F";
        keyText[0][2][42] = "G";
        keyText[0][2][43] = "H";
        keyText[0][2][44] = "J";
        keyText[0][2][45] = "K";
        keyText[0][2][46] = "L";
        keyText[0][2][47] = "Ö";
            keyText[0][2][48] = "Ä";

            keyText[0][2][50] = "shift";
        keyText[0][2][52] = "Y";
        keyText[0][2][53] = "X";
        keyText[0][2][54] = "C";
        keyText[0][2][55] = "V";
        keyText[0][2][56] = "B";
        keyText[0][2][57] = "N";
        keyText[0][2][58] = "M";
        keyText[0][2][59] = ",";
        keyText[0][2][60] = ".";
        keyText[0][2][61] = "-";
        keyText[0][2][62] = "shift";

        keyText[0][2][65] = "space";

        keyText[0][3][49] = "°";
            keyText[0][3][10] = "!";
        keyText[0][3][11] = "\"";
        keyText[0][3][12] = "§";
            keyText[0][3][13] = "$";
        keyText[0][3][14] = "%";
        keyText[0][3][15] = "&&";
        keyText[0][3][16] = "/";
        keyText[0][3][17] = "(";
        keyText[0][3][18] = ")";
        keyText[0][3][19] = "=";
        keyText[0][3][20] = "?";
        keyText[0][3][21] = "`";

        keyText[0][3][24] = "q";
        keyText[0][3][25] = "w";
        keyText[0][3][26] = "e";
        keyText[0][3][27] = "r";
        keyText[0][3][28] = "t";
        keyText[0][3][29] = "z";
        keyText[0][3][30] = "u";
        keyText[0][3][31] = "i";
        keyText[0][3][32] = "o";
        keyText[0][3][33] = "p";
        keyText[0][3][34] = "ü";
            keyText[0][3][35] = "*";
        keyText[0][3][51] = "'";

        keyText[0][3][66] = "caps";
        keyText[0][3][38] = "a";
        keyText[0][3][39] = "s";
        keyText[0][3][40] = "d";
        keyText[0][3][41] = "f";
        keyText[0][3][42] = "g";
        keyText[0][3][43] = "h";
        keyText[0][3][44] = "j";
        keyText[0][3][45] = "k";
        keyText[0][3][46] = "l";
        keyText[0][3][47] = "ö";
            keyText[0][3][48] = "ä";

            keyText[0][3][50] = "shift";
        keyText[0][3][52] = "y";
        keyText[0][3][53] = "x";
        keyText[0][3][54] = "c";
        keyText[0][3][55] = "v";
        keyText[0][3][56] = "b";
        keyText[0][3][57] = "n";
        keyText[0][3][58] = "m";
        keyText[0][3][59] = ";";
        keyText[0][3][60] = ":";
        keyText[0][3][61] = "_";
        keyText[0][3][62] = "shift";

        keyText[0][3][65] = "space";

        keyText[1][0][49] = "²";
            keyText[1][0][10] =  "&&";
        keyText[1][0][11] =  "é";
            keyText[1][0][12] =  "\"";
        keyText[1][0][13] =  "'";
        keyText[1][0][14] =  "(";
        keyText[1][0][15] =  "-";
        keyText[1][0][16] =  "è";
            keyText[1][0][17] =  "_";
        keyText[1][0][18] = "ç";
            keyText[1][0][19] = "à";
            keyText[1][0][20] = ")";
        keyText[1][0][21] = "=";

        keyText[1][0][24] = "a";
        keyText[1][0][25] = "z";
        keyText[1][0][26] = "e";
        keyText[1][0][27] = "r";
        keyText[1][0][28] = "t";
        keyText[1][0][29] = "y";
        keyText[1][0][30] = "u";
        keyText[1][0][31] = "i";
        keyText[1][0][32] = "o";
        keyText[1][0][33] = "p";
        keyText[1][0][34] = "^";
        keyText[1][0][35] = "$";
        keyText[1][0][51] = "*";

        keyText[1][0][66] = "caps";
        keyText[1][0][38] = "q";
        keyText[1][0][39] = "s";
        keyText[1][0][40] = "d";
        keyText[1][0][41] = "f";
        keyText[1][0][42] = "g";
        keyText[1][0][43] = "h";
        keyText[1][0][44] = "j";
        keyText[1][0][45] = "k";
        keyText[1][0][46] = "l";
        keyText[1][0][47] = "m";
        keyText[1][0][48] = "ù";

            keyText[1][0][50] = "shift";
        keyText[1][0][52] = "w";
        keyText[1][0][53] = "x";
        keyText[1][0][54] = "c";
        keyText[1][0][55] = "v";
        keyText[1][0][56] = "b";
        keyText[1][0][57] = "n";
        keyText[1][0][58] = ",";
        keyText[1][0][59] = ";";
        keyText[1][0][60] = ":";
        keyText[1][0][61] = "!";
        keyText[1][0][62] = "shift";

        keyText[1][0][65] = "space";

        keyText[1][1][49] = "~";
        keyText[1][1][10] = "1";
        keyText[1][1][11] = "2";
        keyText[1][1][12] = "3";
        keyText[1][1][13] = "4";
        keyText[1][1][14] = "5";
        keyText[1][1][15] = "6";
        keyText[1][1][16] = "7";
        keyText[1][1][17] = "8";
        keyText[1][1][18] = "9";
        keyText[1][1][19] = "0";
        keyText[1][1][20] = "°";
            keyText[1][1][21] = "+";

        keyText[1][1][24] = "A";
        keyText[1][1][25] = "Z";
        keyText[1][1][26] = "E";
        keyText[1][1][27] = "R";
        keyText[1][1][28] = "T";
        keyText[1][1][29] = "Y";
        keyText[1][1][30] = "U";
        keyText[1][1][31] = "I";
        keyText[1][1][32] = "O";
        keyText[1][1][33] = "P";
        keyText[1][1][34] = "¨";
            keyText[1][1][35] = "£";
            keyText[1][1][51] = "µ";

            keyText[1][1][66] = "caps";
        keyText[1][1][38] = "Q";
        keyText[1][1][39] = "S";
        keyText[1][1][40] = "D";
        keyText[1][1][41] = "F";
        keyText[1][1][42] = "G";
        keyText[1][1][43] = "H";
        keyText[1][1][44] = "J";
        keyText[1][1][45] = "K";
        keyText[1][1][46] = "L";
        keyText[1][1][47] = "M";
        keyText[1][1][48] = "%";

        keyText[1][1][50] = "shift";
        keyText[1][1][52] = "W";
        keyText[1][1][53] = "X";
        keyText[1][1][54] = "C";
        keyText[1][1][55] = "V";
        keyText[1][1][56] = "B";
        keyText[1][1][57] = "N";
        keyText[1][1][58] = "?";
        keyText[1][1][59] = ".";
        keyText[1][1][60] = "/";
        keyText[1][1][61] = "§";
            keyText[1][1][62] = "shift";

        keyText[1][1][65] = "space";

        keyText[1][2][49] = "²";
            keyText[1][2][10] = "&&";
        keyText[1][2][11] = "É";
            keyText[1][2][12] = "\"";
        keyText[1][2][13] = "'";
        keyText[1][2][14] = "(";
        keyText[1][2][15] = "-";
        keyText[1][2][16] = "È";
            keyText[1][2][17] = "_";
        keyText[1][2][18] = "Ç";
            keyText[1][2][19] = "À";
            keyText[1][2][20] = ")";
        keyText[1][2][21] = "=";

        keyText[1][2][24] = "A";
        keyText[1][2][25] = "Z";
        keyText[1][2][26] = "E";
        keyText[1][2][27] = "R";
        keyText[1][2][28] = "T";
        keyText[1][2][29] = "Y";
        keyText[1][2][30] = "U";
        keyText[1][2][31] = "I";
        keyText[1][2][32] = "O";
        keyText[1][2][33] = "P";
        keyText[1][2][34] = "^";
        keyText[1][2][35] = "$";
        keyText[1][2][51] = "*";

        keyText[1][2][66] = "caps";
        keyText[1][2][38] = "Q";
        keyText[1][2][39] = "S";
        keyText[1][2][40] = "D";
        keyText[1][2][41] = "F";
        keyText[1][2][42] = "G";
        keyText[1][2][43] = "H";
        keyText[1][2][44] = "J";
        keyText[1][2][45] = "K";
        keyText[1][2][46] = "L";
        keyText[1][2][47] = "M";
        keyText[1][2][48] = "Ù";

            keyText[1][2][50] = "shift";
        keyText[1][2][52] = "W";
        keyText[1][2][53] = "X";
        keyText[1][2][54] = "C";
        keyText[1][2][55] = "V";
        keyText[1][2][56] = "B";
        keyText[1][2][57] = "N";
        keyText[1][2][58] = ",";
        keyText[1][2][59] = ";";
        keyText[1][2][60] = ":";
        keyText[1][2][61] = "!";
        keyText[1][2][62] = "shift";

        keyText[1][2][65] = "space";

        keyText[1][3][49] = "~";
        keyText[1][3][10] = "1";
        keyText[1][3][11] = "2";
        keyText[1][3][12] = "3";
        keyText[1][3][13] = "4";
        keyText[1][3][14] = "5";
        keyText[1][3][15] = "6";
        keyText[1][3][16] = "7";
        keyText[1][3][17] = "8";
        keyText[1][3][18] = "9";
        keyText[1][3][19] = "0";
        keyText[1][3][20] = "°";
            keyText[1][3][21] = "+";

        keyText[1][3][24] = "a";
        keyText[1][3][25] = "z";
        keyText[1][3][26] = "e";
        keyText[1][3][27] = "r";
        keyText[1][3][28] = "t";
        keyText[1][3][29] = "y";
        keyText[1][3][30] = "u";
        keyText[1][3][31] = "i";
        keyText[1][3][32] = "o";
        keyText[1][3][33] = "p";
        keyText[1][3][34] = "¨";
            keyText[1][3][35] = "£";
            keyText[1][3][51] = "";

        keyText[1][3][66] = "caps";
        keyText[1][3][38] = "q";
        keyText[1][3][39] = "s";
        keyText[1][3][40] = "d";
        keyText[1][3][41] = "f";
        keyText[1][3][42] = "g";
        keyText[1][3][43] = "h";
        keyText[1][3][44] = "j";
        keyText[1][3][45] = "k";
        keyText[1][3][46] = "l";
        keyText[1][3][47] = "m";
        keyText[1][3][48] = "%";

        keyText[1][3][50] = "shift";
        keyText[1][3][52] = "w";
        keyText[1][3][53] = "x";
        keyText[1][3][54] = "c";
        keyText[1][3][55] = "v";
        keyText[1][3][56] = "b";
        keyText[1][3][57] = "n";
        keyText[1][3][58] = "?";
        keyText[1][3][59] = ".";
        keyText[1][3][60] = "/";
        keyText[1][3][61] = "§";
            keyText[1][3][62] = "shift";

        keyText[1][3][65] = "space";

        keyText[2][0][49] = "ذ";
            keyText[2][0][10]=  "1";
        keyText[2][0][11]=  "2";
        keyText[2][0][12]=  "3";
        keyText[2][0][13]=  "4";
        keyText[2][0][14]=  "5";
        keyText[2][0][15]=  "6";
        keyText[2][0][16]=  "7";
        keyText[2][0][17]=  "8";
        keyText[2][0][18] = "9";
        keyText[2][0][19] = "0";
        keyText[2][0][20] = "-";
        keyText[2][0][21] = "=";

        keyText[2][0][24] = "ض";
            keyText[2][0][25] = "ص";
            keyText[2][0][26] = "ث";
            keyText[2][0][27] = "ق";
            keyText[2][0][28] = "ف";
            keyText[2][0][29] = "غ";
            keyText[2][0][30] = "ع";
            keyText[2][0][31] = "ه";
            keyText[2][0][32] = "خ";
            keyText[2][0][33] = "ح";
            keyText[2][0][34] = "ج";
            keyText[2][0][35] = "د";
            keyText[2][0][51] = "\\";

        keyText[2][0][66] = "caps";
        keyText[2][0][38] = "ش";
            keyText[2][0][39] = "س";
            keyText[2][0][40] = "ي";
            keyText[2][0][41] = "ب";
            keyText[2][0][42] = "ل";
            keyText[2][0][43] = "ا";
            keyText[2][0][44] = "ت";
            keyText[2][0][45] = "ن";
            keyText[2][0][46] = "م";
            keyText[2][0][47] = "ك";
            keyText[2][0][48] = "ط";

            keyText[2][0][50] = "shift";
        keyText[2][0][52] = "ئ";
            keyText[2][0][53] = "ء";
            keyText[2][0][54] = "ؤ";
            keyText[2][0][55] = "ر";
            keyText[2][0][56] = "ﻻ";
        keyText[2][0][57] = "ى";
            keyText[2][0][58] = "ة";
            keyText[2][0][59] = "و";
            keyText[2][0][60] = "ز";
            keyText[2][0][61] = "ظ";
            keyText[2][0][62] = "shift";

        keyText[2][0][65] = "space";

        keyText[2][1][49] = "ّ";
            keyText[2][1][10] = "!";
        keyText[2][1][11] = "@";
        keyText[2][1][12] = "#";
        keyText[2][1][13] = "$";
        keyText[2][1][14] = "%";
        keyText[2][1][15] = "^";
        keyText[2][1][16] = "&&";
        keyText[2][1][17] = "*";
        keyText[2][1][18] = ")";
        keyText[2][1][19] = "(";
        keyText[2][1][20] = "_";
        keyText[2][1][21] = "+";

        keyText[2][1][24] = "َّ";
        keyText[2][1][25] = "ً";
            keyText[2][1][26] = "ُ";
            keyText[2][1][27] = "ٌ";
            keyText[2][1][28] = "ﻹ";
        keyText[2][1][29] = "إ";
            keyText[2][1][30] = "`";
        keyText[2][1][31] = "÷";
            keyText[2][1][32] = "×";
            keyText[2][1][33] = "؛";
            keyText[2][1][34] = "<";
        keyText[2][1][35] = ">";
        keyText[2][1][51] = "…";

        keyText[2][1][66] = "caps";
        keyText[2][1][38] = "ِ";
            keyText[2][1][39] = "ٍ";
            keyText[2][1][40] = "]";
        keyText[2][1][41] = "[";
        keyText[2][1][42] = "ﻷ";
        keyText[2][1][43] = "أ";
            keyText[2][1][44] = "ـ";
            keyText[2][1][45] = "،";
            keyText[2][1][46] = "/";
        keyText[2][1][47] = ":";
        keyText[2][1][48] = "\"";

        keyText[2][1][50] = "shift";
        keyText[2][1][52] = "~";
        keyText[2][1][53] = "ْ";
            keyText[2][1][54] = "}";
        keyText[2][1][55] = "{";
        keyText[2][1][56] = "ﻵ";
        keyText[2][1][57] = "آ";
            keyText[2][1][58] = "'";
        keyText[2][1][59] = ",";
        keyText[2][1][60] = ".";
        keyText[2][1][61] = "؟";
            keyText[2][1][62] = "shift";

        keyText[2][1][65] = "space";

        keyText[2][2][49] = "ذ";
            keyText[2][2][10] = "1";
        keyText[2][2][11] = "2";
        keyText[2][2][12] = "3";
        keyText[2][2][13] = "4";
        keyText[2][2][14] = "5";
        keyText[2][2][15] = "6";
        keyText[2][2][16] = "7";
        keyText[2][2][17] = "8";
        keyText[2][2][18] = "9";
        keyText[2][2][19] = "0";
        keyText[2][2][20] = "-";
        keyText[2][2][21] = "=";

        keyText[2][2][24] = "ض";
            keyText[2][2][25] = "ص";
            keyText[2][2][26] = "ث";
            keyText[2][2][27] = "ق";
            keyText[2][2][28] = "ف";
            keyText[2][2][29] = "غ";
            keyText[2][2][30] = "ع";
            keyText[2][2][31] = "ه";
            keyText[2][2][32] = "خ";
            keyText[2][2][33] = "ح";
            keyText[2][2][34] = "ج";
            keyText[2][2][35] = "د";
            keyText[2][2][51] = "\\";

        keyText[2][2][66] = "caps";
        keyText[2][2][38] = "ش";
            keyText[2][2][39] = "س";
            keyText[2][2][40] = "ي";
            keyText[2][2][41] = "ب";
            keyText[2][2][42] = "ل";
            keyText[2][2][43] = "ا";
            keyText[2][2][44] = "ت";
            keyText[2][2][45] = "ن";
            keyText[2][2][46] = "م";
            keyText[2][2][47] = "ك";
            keyText[2][2][48] = "ط";

            keyText[2][2][50] = "shift";
        keyText[2][2][52] = "ئ";
            keyText[2][2][53] = "ء";
            keyText[2][2][54] = "ؤ";
            keyText[2][2][55] = "ر";
            keyText[2][2][56] = "ﻻ";
        keyText[2][2][57] = "ى";
            keyText[2][2][58] = "ة";
            keyText[2][2][59] = "و";
            keyText[2][2][60] = "ز";
            keyText[2][2][61] = "ظ";
            keyText[2][2][62] = "shift";

        keyText[2][2][65] = "space";

        keyText[2][3][49] = "ّ";
            keyText[2][3][10] = "!";
        keyText[2][3][11] = "@";
        keyText[2][3][12] = "#";
        keyText[2][3][13] = "$";
        keyText[2][3][14] = "%";
        keyText[2][3][15] = "^";
        keyText[2][3][16] = "&&";
        keyText[2][3][17] = "*";
        keyText[2][3][18] = ")";
        keyText[2][3][19] = "(";
        keyText[2][3][20] = "_";
        keyText[2][3][21] = "+";

        keyText[2][3][24] = "َ";
            keyText[2][3][25] = "ً";
            keyText[2][3][26] = "ُ";
            keyText[2][3][27] = "ٌ";
            keyText[2][3][28] = "ﻹ";
        keyText[2][3][29] = "إ";
            keyText[2][3][30] = "`";
        keyText[2][3][31] = "÷";
            keyText[2][3][32] = "×";
            keyText[2][3][33] = "؛";
            keyText[2][3][34] = "<";
        keyText[2][3][35] = ">";
        keyText[2][3][51] = "…";

        keyText[2][3][66] = "caps";
        keyText[2][3][38] = "ِ";
            keyText[2][3][39] = "ٍٍ";
        keyText[2][3][40] = "]";
        keyText[2][3][41] = "[";
        keyText[2][3][42] = "ﻷ";
        keyText[2][3][43] = "أ";
            keyText[2][3][44] = "ـ";
            keyText[2][3][45] = "،";
            keyText[2][3][46] = "/";
        keyText[2][3][47] = ":";
        keyText[2][3][48] = "\"";

        keyText[2][3][50] = "shift";
        keyText[2][3][52] = "~";
        keyText[2][3][53] = "ْ";
            keyText[2][3][54] = "}";
        keyText[2][3][55] = "{";
        keyText[2][3][56] = "ﻵ";
        keyText[2][3][57] = "آ";
            keyText[2][3][58] = "'";
        keyText[2][3][59] = ",";
        keyText[2][3][60] = ".";
        keyText[2][3][61] = "؟";
            keyText[2][3][62] = "shift";

        keyText[2][3][65] = "space";

        keyText[3][0][49] = "`";
        keyText[3][0][10]=  "1";
        keyText[3][0][11]=  "2";
        keyText[3][0][12]=  "3";
        keyText[3][0][13]=  "4";
        keyText[3][0][14]=  "5";
        keyText[3][0][15]=  "6";
        keyText[3][0][16]=  "7";
        keyText[3][0][17]=  "8";
        keyText[3][0][18] = "9";
        keyText[3][0][19] = "0";
        keyText[3][0][20] = "-";
        keyText[3][0][21] = "=";

        keyText[3][0][24] = "q";
        keyText[3][0][25] = "w";
        keyText[3][0][26] = "e";
        keyText[3][0][27] = "r";
        keyText[3][0][28] = "t";
        keyText[3][0][29] = "y";
        keyText[3][0][30] = "u";
        keyText[3][0][31] = "i";
        keyText[3][0][32] = "o";
        keyText[3][0][33] = "p";
        keyText[3][0][34] = "[";
        keyText[3][0][35] = "]";
        keyText[3][0][51] = "\\";

        keyText[3][0][66] = "caps";
        keyText[3][0][38] = "a";
        keyText[3][0][39] = "s";
        keyText[3][0][40] = "d";
        keyText[3][0][41] = "f";
        keyText[3][0][42] = "g";
        keyText[3][0][43] = "h";
        keyText[3][0][44] = "j";
        keyText[3][0][45] = "k";
        keyText[3][0][46] = "l";
        keyText[3][0][47] = ";";
        keyText[3][0][48] = "'";

        keyText[3][0][50] = "shift";
        keyText[3][0][52] = "z";
        keyText[3][0][53] = "x";
        keyText[3][0][54] = "c";
        keyText[3][0][55] = "v";
        keyText[3][0][56] = "b";
        keyText[3][0][57] = "n";
        keyText[3][0][58] = "m";
        keyText[3][0][59] = ",";
        keyText[3][0][60] = ".";
        keyText[3][0][61] = "/";
        keyText[3][0][62] = "shift";

        keyText[3][0][65] = "space";

        keyText[3][1][49] = "~";
        keyText[3][1][10] = "!";
        keyText[3][1][11] = "@";
        keyText[3][1][12] = "#";
        keyText[3][1][13] = "$";
        keyText[3][1][14] = "%";
        keyText[3][1][15] = "^";
        keyText[3][1][16] = "&&";
        keyText[3][1][17] = "*";
        keyText[3][1][18] = "(";
        keyText[3][1][19] = ")";
        keyText[3][1][20] = "_";
        keyText[3][1][21] = "+";

        keyText[3][1][24] = "Q";
        keyText[3][1][25] = "W";
        keyText[3][1][26] = "E";
        keyText[3][1][27] = "R";
        keyText[3][1][28] = "T";
        keyText[3][1][29] = "Y";
        keyText[3][1][30] = "U";
        keyText[3][1][31] = "I";
        keyText[3][1][32] = "O";
        keyText[3][1][33] = "P";
        keyText[3][1][34] = "{";
        keyText[3][1][35] = "}";
        keyText[3][1][51] = "|";

        keyText[3][1][66] = "caps";
        keyText[3][1][38] = "A";
        keyText[3][1][39] = "S";
        keyText[3][1][40] = "D";
        keyText[3][1][41] = "F";
        keyText[3][1][42] = "G";
        keyText[3][1][43] = "H";
        keyText[3][1][44] = "J";
        keyText[3][1][45] = "K";
        keyText[3][1][46] = "L";
        keyText[3][1][47] = ":";
        keyText[3][1][48] = "\"";

        keyText[3][1][50] = "shift";
        keyText[3][1][52] = "Z";
        keyText[3][1][53] = "X";
        keyText[3][1][54] = "C";
        keyText[3][1][55] = "V";
        keyText[3][1][56] = "B";
        keyText[3][1][57] = "N";
        keyText[3][1][58] = "M";
        keyText[3][1][59] = "<";
        keyText[3][1][60] = ">";
        keyText[3][1][61] = "?";
        keyText[3][1][62] = "shift";

        keyText[3][1][65] = "space";

        keyText[3][2][49] = "`";
        keyText[3][2][10] = "1";
        keyText[3][2][11] = "2";
        keyText[3][2][12] = "3";
        keyText[3][2][13] = "4";
        keyText[3][2][14] = "5";
        keyText[3][2][15] = "6";
        keyText[3][2][16] = "7";
        keyText[3][2][17] = "8";
        keyText[3][2][18] = "9";
        keyText[3][2][19] = "0";
        keyText[3][2][20] = "-";
        keyText[3][2][21] = "=";

        keyText[3][2][24] = "Q";
        keyText[3][2][25] = "W";
        keyText[3][2][26] = "E";
        keyText[3][2][27] = "R";
        keyText[3][2][28] = "T";
        keyText[3][2][29] = "Y";
        keyText[3][2][30] = "U";
        keyText[3][2][31] = "I";
        keyText[3][2][32] = "O";
        keyText[3][2][33] = "P";
        keyText[3][2][34] = "[";
        keyText[3][2][35] = "]";
        keyText[3][2][51] = "\\";

        keyText[3][2][66] = "caps";
        keyText[3][2][38] = "A";
        keyText[3][2][39] = "S";
        keyText[3][2][40] = "D";
        keyText[3][2][41] = "F";
        keyText[3][2][42] = "G";
        keyText[3][2][43] = "H";
        keyText[3][2][44] = "J";
        keyText[3][2][45] = "K";
        keyText[3][2][46] = "L";
        keyText[3][2][47] = ";";
        keyText[3][2][48] = "'";

        keyText[3][2][50] = "shift";
        keyText[3][2][52] = "Z";
        keyText[3][2][53] = "X";
        keyText[3][2][54] = "C";
        keyText[3][2][55] = "V";
        keyText[3][2][56] = "B";
        keyText[3][2][57] = "N";
        keyText[3][2][58] = "M";
        keyText[3][2][59] = ",";
        keyText[3][2][60] = ".";
        keyText[3][2][61] = "/";
        keyText[3][2][62] = "shift";

        keyText[3][2][65] = "space";

        keyText[3][3][49] = "~";
        keyText[3][3][10] = "!";
        keyText[3][3][11] = "@";
        keyText[3][3][12] = "#";
        keyText[3][3][13] = "$";
        keyText[3][3][14] = "%";
        keyText[3][3][15] = "^";
        keyText[3][3][16] = "&&";
        keyText[3][3][17] = "*";
        keyText[3][3][18] = "(";
        keyText[3][3][19] = ")";
        keyText[3][3][20] = "_";
        keyText[3][3][21] = "+";

        keyText[3][3][24] = "q";
        keyText[3][3][25] = "w";
        keyText[3][3][26] = "e";
        keyText[3][3][27] = "r";
        keyText[3][3][28] = "t";
        keyText[3][3][29] = "y";
        keyText[3][3][30] = "u";
        keyText[3][3][31] = "i";
        keyText[3][3][32] = "o";
        keyText[3][3][33] = "p";
        keyText[3][3][34] = "{";
        keyText[3][3][35] = "}";
        keyText[3][3][51] = "|";

        keyText[3][3][66] = "caps";
        keyText[3][3][38] = "a";
        keyText[3][3][39] = "s";
        keyText[3][3][40] = "d";
        keyText[3][3][41] = "f";
        keyText[3][3][42] = "g";
        keyText[3][3][43] = "h";
        keyText[3][3][44] = "j";
        keyText[3][3][45] = "k";
        keyText[3][3][46] = "l";
        keyText[3][3][47] = ":";
        keyText[3][3][48] = "\"";

        keyText[3][3][50] = "shift";
        keyText[3][3][52] = "z";
        keyText[3][3][53] = "x";
        keyText[3][3][54] = "c";
        keyText[3][3][55] = "v";
        keyText[3][3][56] = "b";
        keyText[3][3][57] = "n";
        keyText[3][3][58] = "m";
        keyText[3][3][59] = "<";
        keyText[3][3][60] = ">";
        keyText[3][3][61] = "?";
        keyText[3][3][62] = "shift";

        keyText[3][3][65] = "space";


        keyText[4][0][49] = "ё";
            keyText[4][0][10]=  "1";
        keyText[4][0][11]=  "2";
        keyText[4][0][12]=  "3";
        keyText[4][0][13]=  "4";
        keyText[4][0][14]=  "5";
        keyText[4][0][15]=  "6";
        keyText[4][0][16]=  "7";
        keyText[4][0][17]=  "8";
        keyText[4][0][18] = "9";
        keyText[4][0][19] = "0";
        keyText[4][0][20] = "-";
        keyText[4][0][21] = "=";

        keyText[4][0][24] = "й";
            keyText[4][0][25] = "ц";
            keyText[4][0][26] = "у";
            keyText[4][0][27] = "к";
            keyText[4][0][28] = "е";
            keyText[4][0][29] = "н";
            keyText[4][0][30] = "г";
            keyText[4][0][31] = "ш";
            keyText[4][0][32] = "ў";
            keyText[4][0][33] = "з";
            keyText[4][0][34] = "х";
            keyText[4][0][35] = "'";
        keyText[4][0][51] = "\\";

        keyText[4][0][66] = "caps";
        keyText[4][0][38] = "ф";
            keyText[4][0][39] = "ы";
            keyText[4][0][40] = "в";
            keyText[4][0][41] = "а";
            keyText[4][0][42] = "п";
            keyText[4][0][43] = "р";
            keyText[4][0][44] = "о";
            keyText[4][0][45] = "л";
            keyText[4][0][46] = "д";
            keyText[4][0][47] = "ж";
            keyText[4][0][48] = "э";

            keyText[4][0][50] = "shift";
        keyText[4][0][52] = "я";
            keyText[4][0][53] = "ч";
            keyText[4][0][54] = "с";
            keyText[4][0][55] = "м";
            keyText[4][0][56] = "і";
            keyText[4][0][57] = "т";
            keyText[4][0][58] = "ь";
            keyText[4][0][59] = "б";
            keyText[4][0][60] = "ю";
            keyText[4][0][61] = ".";
        keyText[4][0][62] = "shift";

        keyText[4][0][65] = "space";

        keyText[4][1][49] = "Ё";
            keyText[4][1][10] = "!";
        keyText[4][1][11] = "\"";
        keyText[4][1][12] = "№";
        keyText[4][1][13] = ";";
        keyText[4][1][14] = "%";
        keyText[4][1][15] = ":";
        keyText[4][1][16] = "?";
        keyText[4][1][17] = "*";
        keyText[4][1][18] = "(";
        keyText[4][1][19] = ")";
        keyText[4][1][20] = "_";
        keyText[4][1][21] = "+";

        keyText[4][1][24] = "Й";
            keyText[4][1][25] = "Ц";
            keyText[4][1][26] = "У";
            keyText[4][1][27] = "К";
            keyText[4][1][28] = "Е";
            keyText[4][1][29] = "Н";
            keyText[4][1][30] = "Г";
            keyText[4][1][31] = "Ш";
            keyText[4][1][32] = "Ў";
            keyText[4][1][33] = "З";
            keyText[4][1][34] = "Х";
            keyText[4][1][35] = "'";
        keyText[4][1][51] = "/";

        keyText[4][1][66] = "caps";
        keyText[4][1][38] = "Ф";
            keyText[4][1][39] = "Ы";
            keyText[4][1][40] = "В";
            keyText[4][1][41] = "А";
            keyText[4][1][42] = "П";
            keyText[4][1][43] = "Р";
            keyText[4][1][44] = "О";
            keyText[4][1][45] = "Л";
            keyText[4][1][46] = "Д";
            keyText[4][1][47] = "Ж";
            keyText[4][1][48] = "Э";

            keyText[4][1][50] = "shift";
        keyText[4][1][52] = "Я";
            keyText[4][1][53] = "Ч";
            keyText[4][1][54] = "С";
            keyText[4][1][55] = "М";
            keyText[4][1][56] = "І";
            keyText[4][1][57] = "Т";
            keyText[4][1][58] = "Ь";
            keyText[4][1][59] = "Б";
            keyText[4][1][60] = "Ю";
            keyText[4][1][61] = ".";
        keyText[4][1][62] = "shift";

        keyText[4][1][65] = "space";

        keyText[4][2][49] = "Ё";
            keyText[4][2][10] = "1";
        keyText[4][2][11] = "2";
        keyText[4][2][12] = "3";
        keyText[4][2][13] = "4";
        keyText[4][2][14] = "5";
        keyText[4][2][15] = "6";
        keyText[4][2][16] = "7";
        keyText[4][2][17] = "8";
        keyText[4][2][18] = "9";
        keyText[4][2][19] = "0";
        keyText[4][2][20] = "-";
        keyText[4][2][21] = "=";

        keyText[4][2][24] = "Й";
            keyText[4][2][25] = "Ц";
            keyText[4][2][26] = "У";
            keyText[4][2][27] = "К";
            keyText[4][2][28] = "Е";
            keyText[4][2][29] = "Н";
            keyText[4][2][30] = "Г";
            keyText[4][2][31] = "Ш";
            keyText[4][2][32] = "Ў";
            keyText[4][2][33] = "З";
            keyText[4][2][34] = "Х";
            keyText[4][2][35] = "'";
        keyText[4][2][51] = "\\";

        keyText[4][2][66] = "caps";
        keyText[4][2][38] = "Ф";
            keyText[4][2][39] = "Ы";
            keyText[4][2][40] = "В";
            keyText[4][2][41] = "А";
            keyText[4][2][42] = "П";
            keyText[4][2][43] = "Р";
            keyText[4][2][44] = "О";
            keyText[4][2][45] = "Л";
            keyText[4][2][46] = "Д";
            keyText[4][2][47] = "Ж";
            keyText[4][2][48] = "Э";

            keyText[4][2][50] = "shift";
        keyText[4][2][52] = "Я";
            keyText[4][2][53] = "Ч";
            keyText[4][2][54] = "С";
            keyText[4][2][55] = "М";
            keyText[4][2][56] = "І";
            keyText[4][2][57] = "Т";
            keyText[4][2][58] = "Ь";
            keyText[4][2][59] = "Б";
            keyText[4][2][60] = "Ю";
            keyText[4][2][61] = ".";
        keyText[4][2][62] = "shift";

        keyText[4][2][65] = "space";

        keyText[4][3][49] = "ё";
            keyText[4][3][10] = "!";
        keyText[4][3][11] = "\"";
        keyText[4][3][12] = "№";
        keyText[4][3][13] = ";";
        keyText[4][3][14] = "%";
        keyText[4][3][15] = ":";
        keyText[4][3][16] = "?";
        keyText[4][3][17] = "*";
        keyText[4][3][18] = "(";
        keyText[4][3][19] = ")";
        keyText[4][3][20] = "_";
        keyText[4][3][21] = "+";

        keyText[4][3][24] = "й";
            keyText[4][3][25] = "ц";
            keyText[4][3][26] = "у";
            keyText[4][3][27] = "к";
            keyText[4][3][28] = "е";
            keyText[4][3][29] = "н";
            keyText[4][3][30] = "г";
            keyText[4][3][31] = "ш";
            keyText[4][3][32] = "ў";
            keyText[4][3][33] = "з";
            keyText[4][3][34] = "х";
            keyText[4][3][35] = "'";
        keyText[4][3][51] = "/";

        keyText[4][3][66] = "caps";
        keyText[4][3][38] = "ф";
            keyText[4][3][39] = "ы";
            keyText[4][3][40] = "в";
            keyText[4][3][41] = "а";
            keyText[4][3][42] = "п";
            keyText[4][3][43] = "р";
            keyText[4][3][44] = "о";
            keyText[4][3][45] = "л";
            keyText[4][3][46] = "д";
            keyText[4][3][47] = "ж";
            keyText[4][3][48] = "э";

            keyText[4][3][50] = "shift";
        keyText[4][3][52] = "я";
            keyText[4][3][53] = "ч";
            keyText[4][3][54] = "с";
            keyText[4][3][55] = "м";
            keyText[4][3][56] = "і";
            keyText[4][3][57] = "т";
            keyText[4][3][58] = "ь";
            keyText[4][3][59] = "б";
            keyText[4][3][60] = "ю";
            keyText[4][3][61] = ",";
        keyText[4][3][62] = "shift";

        keyText[4][3][65] = "space";

        keyText[5][0][49] = ";";
        keyText[5][0][10]=  "1";
        keyText[5][0][11]=  "2";
        keyText[5][0][12]=  "3";
        keyText[5][0][13]=  "4";
        keyText[5][0][14]=  "5";
        keyText[5][0][15]=  "6";
        keyText[5][0][16]=  "7";
        keyText[5][0][17]=  "8";
        keyText[5][0][18] = "9";
        keyText[5][0][19] = "0";
        keyText[5][0][20] = "-";
        keyText[5][0][21] = "=";

        keyText[5][0][24] = "/";
        keyText[5][0][25] = "'";
        keyText[5][0][26] = "ק";
            keyText[5][0][27] = "ר";
            keyText[5][0][28] = "א";
            keyText[5][0][29] = "ט";
            keyText[5][0][30] = "ו";
            keyText[5][0][31] = "ן";
            keyText[5][0][32] = "ם";
            keyText[5][0][33] = "פ";
            keyText[5][0][34] = "]";
        keyText[5][0][35] = "[";
        keyText[5][0][51] = "\\";

        keyText[5][0][66] = "caps";
        keyText[5][0][38] = "ש";
            keyText[5][0][39] = "ד";
            keyText[5][0][40] = "ג";
            keyText[5][0][41] = "כ";
            keyText[5][0][42] = "ע";
            keyText[5][0][43] = "י";
            keyText[5][0][44] = "ח";
            keyText[5][0][45] = "ל";
            keyText[5][0][46] = "ך";
            keyText[5][0][47] = "ף";
            keyText[5][0][48] = ",";

        keyText[5][0][50] = "shift";
        keyText[5][0][52] = "ז";
            keyText[5][0][53] = "ס";
            keyText[5][0][54] = "ב";
            keyText[5][0][55] = "ה";
            keyText[5][0][56] = "נ";
            keyText[5][0][57] = "מ";
            keyText[5][0][58] = "צ";
            keyText[5][0][59] = "ת";
            keyText[5][0][60] = "ץ";
            keyText[5][0][61] = ".";
        keyText[5][0][62] = "shift";

        keyText[5][0][65] = "space";

        keyText[5][1][49] = "~";
        keyText[5][1][10] = "!";
        keyText[5][1][11] = "@";
        keyText[5][1][12] = "#";
        keyText[5][1][13] = "$";
        keyText[5][1][14] = "%";
        keyText[5][1][15] = "^";
        keyText[5][1][16] = "&&";
        keyText[5][1][17] = "*";
        keyText[5][1][18] = "(";
        keyText[5][1][19] = ")";
        keyText[5][1][20] = "_";
        keyText[5][1][21] = "+";

        keyText[5][1][24] = "Q";
        keyText[5][1][25] = "W";
        keyText[5][1][26] = "E";
        keyText[5][1][27] = "R";
        keyText[5][1][28] = "T";
        keyText[5][1][29] = "Y";
        keyText[5][1][30] = "U";
        keyText[5][1][31] = "I";
        keyText[5][1][32] = "O";
        keyText[5][1][33] = "P";
        keyText[5][1][34] = "}";
        keyText[5][1][35] = "{";
        keyText[5][1][51] = "|";

        keyText[5][1][66] = "caps";
        keyText[5][1][38] = "A";
        keyText[5][1][39] = "S";
        keyText[5][1][40] = "D";
        keyText[5][1][41] = "F";
        keyText[5][1][42] = "G";
        keyText[5][1][43] = "H";
        keyText[5][1][44] = "J";
        keyText[5][1][45] = "K";
        keyText[5][1][46] = "L";
        keyText[5][1][47] = ":";
        keyText[5][1][48] = "\"";

        keyText[5][1][50] = "shift";
        keyText[5][1][52] = "Z";
        keyText[5][1][53] = "X";
        keyText[5][1][54] = "C";
        keyText[5][1][55] = "V";
        keyText[5][1][56] = "B";
        keyText[5][1][57] = "N";
        keyText[5][1][58] = "M";
        keyText[5][1][59] = ">";
        keyText[5][1][60] = "<";
        keyText[5][1][61] = "?";
        keyText[5][1][62] = "shift";

        keyText[5][1][65] = "space";

        keyText[5][2][49] = ";";
        keyText[5][2][10] = "1";
        keyText[5][2][11] = "2";
        keyText[5][2][12] = "3";
        keyText[5][2][13] = "4";
        keyText[5][2][14] = "5";
        keyText[5][2][15] = "6";
        keyText[5][2][16] = "7";
        keyText[5][2][17] = "8";
        keyText[5][2][18] = "9";
        keyText[5][2][19] = "0";
        keyText[5][2][20] = "-";
        keyText[5][2][21] = "=";

        keyText[5][2][24] = "Q";
        keyText[5][2][25] = "W";
        keyText[5][2][26] = "E";
        keyText[5][2][27] = "R";
        keyText[5][2][28] = "T";
        keyText[5][2][29] = "Y";
        keyText[5][2][30] = "U";
        keyText[5][2][31] = "I";
        keyText[5][2][32] = "O";
        keyText[5][2][33] = "P";
        keyText[5][2][34] = "]";
        keyText[5][2][35] = "[";
        keyText[5][2][51] = "\\";

        keyText[5][2][66] = "caps";
        keyText[5][2][38] = "A";
        keyText[5][2][39] = "S";
        keyText[5][2][40] = "D";
        keyText[5][2][41] = "F";
        keyText[5][2][42] = "G";
        keyText[5][2][43] = "H";
        keyText[5][2][44] = "J";
        keyText[5][2][45] = "K";
        keyText[5][2][46] = "L";
        keyText[5][2][47] = ";";
        keyText[5][2][48] = "'";

        keyText[5][2][50] = "shift";
        keyText[5][2][52] = "Z";
        keyText[5][2][53] = "X";
        keyText[5][2][54] = "C";
        keyText[5][2][55] = "V";
        keyText[5][2][56] = "B";
        keyText[5][2][57] = "N";
        keyText[5][2][58] = "M";
        keyText[5][2][59] = ">";
        keyText[5][2][60] = "<";
        keyText[5][2][61] = ".";
        keyText[5][2][62] = "shift";

        keyText[5][2][65] = "space";

        keyText[5][3][49] = "~";
        keyText[5][3][10] = "!";
        keyText[5][3][11] = "@";
        keyText[5][3][12] = "#";
        keyText[5][3][13] = "$";
        keyText[5][3][14] = "%";
        keyText[5][3][15] = "^";
        keyText[5][3][16] = "&&";
        keyText[5][3][17] = "*";
        keyText[5][3][18] = "(";
        keyText[5][3][19] = ")";
        keyText[5][3][20] = "_";
        keyText[5][3][21] = "+";

        keyText[5][3][24] = "/";
        keyText[5][3][25] = "'";
        keyText[5][3][26] = "ק";
            keyText[5][3][27] = "ר";
            keyText[5][3][28] = "א";
            keyText[5][3][29] = "ט";
            keyText[5][3][30] = "ו";
            keyText[5][3][31] = "ן";
            keyText[5][3][32] = "ם";
            keyText[5][3][33] = "פ";
            keyText[5][3][34] = "}";
        keyText[5][3][35] = "{";
        keyText[5][3][51] = "|";

        keyText[5][3][66] = "caps";
        keyText[5][3][38] = "ש";
            keyText[5][3][39] = "ד";
            keyText[5][3][40] = "ג";
            keyText[5][3][41] = "כ";
            keyText[5][3][42] = "ע";
            keyText[5][3][43] = "י";
            keyText[5][3][44] = "ח";
            keyText[5][3][45] = "ל";
            keyText[5][3][46] = "ך";
            keyText[5][3][47] = "ף";
            keyText[5][3][48] = "\"";

        keyText[5][3][50] = "shift";
        keyText[5][3][52] = "ז";
            keyText[5][3][53] = "ס";
            keyText[5][3][54] = "ב";
            keyText[5][3][55] = "ה";
            keyText[5][3][56] = "נ";
            keyText[5][3][57] = "מ";
            keyText[5][3][58] = "צ";
            keyText[5][3][59] = "ת";
            keyText[5][3][60] = "ץ";
            keyText[5][3][61] = "?";
        keyText[5][3][62] = "shift";

        keyText[5][3][65] = "space";

        keyText[6][0][49] = "`";
        keyText[6][0][10]=  "1";
        keyText[6][0][11]=  "2";
        keyText[6][0][12]=  "3";
        keyText[6][0][13]=  "4";
        keyText[6][0][14]=  "5";
        keyText[6][0][15]=  "6";
        keyText[6][0][16]=  "7";
        keyText[6][0][17]=  "8";
        keyText[6][0][18] = "9";
        keyText[6][0][19] = "0";
        keyText[6][0][20] = "-";
        keyText[6][0][21] = "=";

        keyText[6][0][24] = "q";
        keyText[6][0][25] = "w";
        keyText[6][0][26] = "e";
        keyText[6][0][27] = "r";
        keyText[6][0][28] = "t";
        keyText[6][0][29] = "y";
        keyText[6][0][30] = "u";
        keyText[6][0][31] = "i";
        keyText[6][0][32] = "o";
        keyText[6][0][33] = "p";
        keyText[6][0][34] = "【";
        keyText[6][0][35] = "】";
        keyText[6][0][51] = "、";

        keyText[6][0][66] = "caps";
        keyText[6][0][38] = "a";
        keyText[6][0][39] = "s";
        keyText[6][0][40] = "d";
        keyText[6][0][41] = "f";
        keyText[6][0][42] = "g";
        keyText[6][0][43] = "h";
        keyText[6][0][44] = "j";
        keyText[6][0][45] = "k";
        keyText[6][0][46] = "l";
        keyText[6][0][47] = "；";
        keyText[6][0][48] = "‘";

        keyText[6][0][50] = "shift";
        keyText[6][0][52] = "z";
        keyText[6][0][53] = "x";
        keyText[6][0][54] = "c";
        keyText[6][0][55] = "v";
        keyText[6][0][56] = "b";
        keyText[6][0][57] = "n";
        keyText[6][0][58] = "m";
        keyText[6][0][59] = "，";
        keyText[6][0][60] = "。";
        keyText[6][0][61] = "/";
        keyText[6][0][62] = "shift";

        keyText[6][0][65] = "space";

        keyText[6][1][49] = "～";
        keyText[6][1][10] = "！";
        keyText[6][1][11] = "@";
        keyText[6][1][12] = "#";
        keyText[6][1][13] = "￥";
        keyText[6][1][14] = "%";
        keyText[6][1][15] = "…";
        keyText[6][1][16] = "&&";
        keyText[6][1][17] = "*";
        keyText[6][1][18] = "（";
        keyText[6][1][19] = "）";
        keyText[6][1][20] = "——";
        keyText[6][1][21] = "+";

        keyText[6][1][24] = "Q";
        keyText[6][1][25] = "W";
        keyText[6][1][26] = "E";
        keyText[6][1][27] = "R";
        keyText[6][1][28] = "T";
        keyText[6][1][29] = "Y";
        keyText[6][1][30] = "U";
        keyText[6][1][31] = "I";
        keyText[6][1][32] = "O";
        keyText[6][1][33] = "P";
        keyText[6][1][34] = "『";
        keyText[6][1][35] = "』";
        keyText[6][1][51] = "|";

        keyText[6][1][66] = "caps";
        keyText[6][1][38] = "A";
        keyText[6][1][39] = "S";
        keyText[6][1][40] = "D";
        keyText[6][1][41] = "F";
        keyText[6][1][42] = "G";
        keyText[6][1][43] = "H";
        keyText[6][1][44] = "J";
        keyText[6][1][45] = "K";
        keyText[6][1][46] = "L";
        keyText[6][1][47] = "：";
        keyText[6][1][48] = "“";

        keyText[6][1][50] = "shift";
        keyText[6][1][52] = "Z";
        keyText[6][1][53] = "X";
        keyText[6][1][54] = "C";
        keyText[6][1][55] = "V";
        keyText[6][1][56] = "B";
        keyText[6][1][57] = "N";
        keyText[6][1][58] = "M";
        keyText[6][1][59] = "《";
        keyText[6][1][60] = "》";
        keyText[6][1][61] = "？";
        keyText[6][1][62] = "shift";

        keyText[6][1][65] = "space";

        keyText[6][2][49] = "`";
        keyText[6][2][10] = "1";
        keyText[6][2][11] = "2";
        keyText[6][2][12] = "3";
        keyText[6][2][13] = "4";
        keyText[6][2][14] = "5";
        keyText[6][2][15] = "6";
        keyText[6][2][16] = "7";
        keyText[6][2][17] = "8";
        keyText[6][2][18] = "9";
        keyText[6][2][19] = "0";
        keyText[6][2][20] = "-";
        keyText[6][2][21] = "=";

        keyText[6][2][24] = "Q";
        keyText[6][2][25] = "W";
        keyText[6][2][26] = "E";
        keyText[6][2][27] = "R";
        keyText[6][2][28] = "T";
        keyText[6][2][29] = "Y";
        keyText[6][2][30] = "U";
        keyText[6][2][31] = "I";
        keyText[6][2][32] = "O";
        keyText[6][2][33] = "P";
        keyText[6][2][34] = "【";
        keyText[6][2][35] = "】";
        keyText[6][2][51] = "、";

        keyText[6][2][66] = "caps";
        keyText[6][2][38] = "A";
        keyText[6][2][39] = "S";
        keyText[6][2][40] = "D";
        keyText[6][2][41] = "F";
        keyText[6][2][42] = "G";
        keyText[6][2][43] = "H";
        keyText[6][2][44] = "J";
        keyText[6][2][45] = "K";
        keyText[6][2][46] = "L";
        keyText[6][2][47] = "；";
        keyText[6][2][48] = "’";

        keyText[6][2][50] = "shift";
        keyText[6][2][52] = "Z";
        keyText[6][2][53] = "X";
        keyText[6][2][54] = "C";
        keyText[6][2][55] = "V";
        keyText[6][2][56] = "B";
        keyText[6][2][57] = "N";
        keyText[6][2][58] = "M";
        keyText[6][2][59] = "，";
        keyText[6][2][60] = "。";
        keyText[6][2][61] = "/";
        keyText[6][2][62] = "shift";

        keyText[6][2][65] = "space";

        keyText[6][3][49] = "～";
        keyText[6][3][10] = "！";
        keyText[6][3][11] = "@";
        keyText[6][3][12] = "#";
        keyText[6][3][13] = "￥";
        keyText[6][3][14] = "%";
        keyText[6][3][15] = "…";
        keyText[6][3][16] = "&&";
        keyText[6][3][17] = "*";
        keyText[6][3][18] = "（";
        keyText[6][3][19] = "）";
        keyText[6][3][20] = "——";
        keyText[6][3][21] = "+";

        keyText[6][3][24] = "q";
        keyText[6][3][25] = "w";
        keyText[6][3][26] = "e";
        keyText[6][3][27] = "r";
        keyText[6][3][28] = "t";
        keyText[6][3][29] = "y";
        keyText[6][3][30] = "u";
        keyText[6][3][31] = "i";
        keyText[6][3][32] = "o";
        keyText[6][3][33] = "p";
        keyText[6][3][34] = "『";
        keyText[6][3][35] = "』";
        keyText[6][3][51] = "|";

        keyText[6][3][66] = "caps";
        keyText[6][3][38] = "a";
        keyText[6][3][39] = "s";
        keyText[6][3][40] = "d";
        keyText[6][3][41] = "f";
        keyText[6][3][42] = "g";
        keyText[6][3][43] = "h";
        keyText[6][3][44] = "j";
        keyText[6][3][45] = "k";
        keyText[6][3][46] = "l";
        keyText[6][3][47] = "：";
        keyText[6][3][48] = "”";

        keyText[6][3][50] = "shift";
        keyText[6][3][52] = "z";
        keyText[6][3][53] = "x";
        keyText[6][3][54] = "c";
        keyText[6][3][55] = "v";
        keyText[6][3][56] = "b";
        keyText[6][3][57] = "n";
        keyText[6][3][58] = "m";
        keyText[6][3][59] = "《";
        keyText[6][3][60] = "》";
        keyText[6][3][61] = "？";
        keyText[6][3][62] = "shift";

        keyText[6][3][65] = "space";
    }
};

#endif // KEYBOARD_H
