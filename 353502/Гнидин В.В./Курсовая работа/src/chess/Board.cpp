//
// Created by volodya-petarda on 3/15/24.
//

#include "Board.h"

Board::Board() {
    for(int i = 0; i < 2; i++){
        isDoubleMove[i] = new bool[8];
        for(int j = 0; j < 8; j++){
            isDoubleMove[i][j] = false;
        }
    }
    field = new int*[8];
    for(int i = 0; i < 8; i++){
        field[i] = new int[8];
        for(int j = 0; j < 8; j++){
            field[i][j] = 0;
        }
    }
    for(int i = 0; i < 8; i++){
        field[1][i] = 1;
        field[6][i] = 1 + 6;
    }
    field[0][0] = 2;
    field[0][7] = 2;
    field[7][0] = 2 + 6;
    field[7][7] = 2 + 6;
    field[0][2] = 3;
    field[0][5] = 3;
    field[7][2] = 3 + 6;
    field[7][5] = 3 + 6;
    field[0][1] = 4;
    field[0][6] = 4;
    field[7][1] = 4 + 6;
    field[7][6] = 4 + 6;
    field[0][3] = 5;
    field[7][3] = 5 + 6;
    field[0][4] = 6;
    field[7][4] = 6 + 6;
}

void Board::move(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';

    if(isWhiteMove){
        for(int i = 0; i < 8; i++){
            isDoubleMove[0][i] = false;
        }
    }
    else{
        for(int i = 0; i < 8; i++){
            isDoubleMove[1][i] = false;
        }
    }

    if(field[y1][x1] == 1 || field[y1][x1] == 7){
        if(isWhiteMove){
            if(y2 - y1 == 2){
                isDoubleMove[0][x1] = true;
            }
        }
        else{
            if(y1 - y2 == 2){
                isDoubleMove[1][x1] = true;
            }
        }
    }

    if(field[y1][x1] == 2 || field[y1][x1] == 8){
        if(isWhiteMove) {
            if(y1 == 0 && x1 == 0) {
                isLongWhiteCastled = true;
            }
            if(y1 == 0 && x1 == 7){
                isShortWhiteCastled = true;
            }
        }
        if(!isWhiteMove) {
            if(y1 == 7 && x1 == 0){
                isLongBlackCastled = true;
            }
            if(y1 == 7 && x1 == 7){
                isShortBlackCastled = true;
            }
        }
    }
    if(field[y1][x1] == 6 || field[y1][x1] == 12){
        if(isWhiteMove){
            isShortWhiteCastled = true;
            isLongWhiteCastled = true;
            if(x2 - x1 == 2){
                field[0][7] = 0;
                field[0][5] = 2;
            }
            else if(x1 - x2 == 2){
                field[0][0] = 0;
                field[0][3] = 2;
            }
        }
        else{
            isShortBlackCastled = true;
            isLongBlackCastled = true;
            if(x2 - x1 == 2){
                field[7][7] = 0;
                field[7][5] = 8;
            }
            else if(x1 - x2 == 2){
                field[7][0] = 0;
                field[7][3] = 8;
            }
        }
    }
    if(isWhiteMove && y2 == 5 && isDoubleMove[1][x2] && field[y1][x1] == 1){
        if(field[y2 - 1][x2] != 7){
            std::cout<<"failed en passant1\n";
        }
        field[y2 - 1][x2] = 0;
    }
    if(!isWhiteMove && y2 == 2 && isDoubleMove[0][x2] && field[y1][x1] == 7){
        if(field[y2 + 1][x2] != 1){
            std::cout<<"failed en passant2\n";
        }
        field[y2 + 1][x2] = 0;
    }
    int t = field[y1][x1];
    if(uci.size() == 5){
        if(isWhiteMove){
            if(uci[4] == 'q')
                t = 5;
            else if(uci[4] == 'n')
                t = 4;
            else if(uci[4] == 'b')
                t = 3;
            else if(uci[4] == 'r')
                t = 2;
            else {
                std::cout<<uci << " unknown figure\n";
            }
        }
        else{
            if(uci[4] == 'q')
                t = 11;
            else if(uci[4] == 'n')
                t = 10;
            else if(uci[4] == 'b')
                t = 9;
            else if(uci[4] == 'r')
                t = 8;
            else {
                std::cout<<uci << " unknown figure\n";
            }
        }
    }
    field[y1][x1] = 0;
    field[y2][x2] = t;
    if(y2 == 0 || y2 == 7){
        if(field[y2][x2] == 1)
            field[y2][x2] = 5;
        if(field[y2][x2] == 7){
            field[y2][x2] = 11;
        }
    }
    isWhiteMove = !isWhiteMove;
}

void Board::printBoard() {
    for(int i = 7; i >= 0; i--){
        for(int j = 0; j < 8; j++){
            std::cout<<field[i][j]<<'\t';
        }
        std::cout<<'\n';
    }
    std::cout<<'\n';
}

float *Board::encodeBoard() {
    auto *code = new float[788];
    for(int i = 0; i < 788; i++){
        code[i] = 0;
    }
    if(isWhiteMove){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(field[i][j] == 0)
                    continue;
                int pos = (field[i][j] - 1) * (64) + i * 8 + j;
                code[pos] = 1;
            }
        }
        for(int i = 0; i < 8; i++){
            if(isDoubleMove[0][i] == 0)
                continue;
            int pos = 64 * 12 + i;
            code[pos] = 1;
        }
        for(int i = 0; i < 8; i++){
            if(isDoubleMove[1][i] == 0)
                continue;
            int pos = 64 * 12 + 8 + i;
            code[pos] = 1;
        }
        if(!isShortWhiteCastled){
            code[784] = 1;
        }
        if(!isLongWhiteCastled){
            code[785] = 1;
        }
        if(!isShortBlackCastled){
            code[786] = 1;
        }
        if(!isLongBlackCastled){
            code[787] = 1;
        }
    }
    else{
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(field[i][j] == 0)
                    continue;
                int fig = field[i][j];
                if(fig <= 6)
                    fig += 6;
                else
                    fig -= 6;
                int ti = 7 - i;
                int tj = 7 - j;


                int pos = (fig - 1) * (64) + ti * 8 + tj;
                code[pos] = 1;
            }
        }

        for(int i = 0; i < 8; i++){
            int ti = 7 - i;
            if(isDoubleMove[1][ti] == 0)
                continue;
            int pos = 64 * 12 + ti;
            code[pos] = 1;
        }
        for(int i = 0; i < 8; i++){
            int ti = 7 - i;
            if(isDoubleMove[0][ti] == 0)
                continue;
            int pos = 64 * 12 + 8 + ti;
            code[pos] = 1;
        }
        if(!isShortBlackCastled){
            code[784] = 1;
        }
        if(!isLongBlackCastled){
            code[785] = 1;
        }
        if(!isShortWhiteCastled){
            code[786] = 1;
        }
        if(!isLongWhiteCastled){
            code[787] = 1;
        }
    }
    return code;
}

std::string Board::numberToUci(int num) {
    if(num < 4096){
        std::string res = "";
        for(int i = 0; i < 4; i++){
            int t =  num % 8;
            num /= 8;
            if(i % 2 == 0){
                res += ('a' + t);
            }
            else{
                res += ('1' + t);
            }
        }
        return res;
    }
    num -= 4096;
    char c;
    int val = num / 22;
    if(val == 0)
        c = 'q';
    else if(val == 1)
        c = 'n';
    else if(val == 2)
        c = 'b';
    else if(val == 3)
        c = 'r';
    num %= 22;
    num ++;
    val = num / 3;
    std::string res = "";
    res += ('a' + val);
    res += std::to_string(7);
    num %= 3;
    res += (res[0] + (num - 1));
    res += std::to_string(8);
    res += c;
    return res;
}

std::string Board::reverseUci(std::string uci) {
    uci[0] = ('a' + (7 - (uci[0] - 'a')));
    uci[1] = ('1' + (7 - (uci[1] - '1')));
    uci[2] = ('a' + (7 - (uci[2] - 'a')));
    uci[3] = ('1' + (7 - (uci[3] - '1')));
    return uci;
}

int Board::uciToNumber(std::string uci) {
    for(int i = 0; i < 4184; i++){
        if(uci == numberToUci(i))
            return i;
    }
}

std::string Board::partNumToPartUci(int num) {
    std::string res = "a1";
    res[1] = ('1' + num % 8);
    num /= 8;
    res[0] = ('a' + num);
    return res;
}

int Board::partUciPartToPartInt(std::string uci) {
    int res = 0;
    res += (uci[0] - 'a') * 8;
    res += (uci[1] - '1');
    return res;
}

Board::~Board() {
    for(int i = 0; i < 8; i++)
        delete[] field[i];
    delete[] field;
    delete[] isDoubleMove[0];
    delete[] isDoubleMove[1];
}

bool Board::isPossibleMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';
    if(field[y1][x1] == 0)
        return false;
    if(field[y1][x1] == 1 || field[y1][x1] == 7){
        if(!isValidPawnMove(uci))
            return false;
    }
    if(field[y1][x1] == 2 || field[y1][x1] == 8){
        if(!isValidRookMove(uci))
            return false;
    }
    if(field[y1][x1] == 3 || field[y1][x1] == 9){
        if(!isValidBishopMove(uci))
            return false;
    }
    if(field[y1][x1] == 4 || field[y1][x1] == 10){
        if(!isValidKnightMove(uci))
            return false;
    }
    if(field[y1][x1] == 5 || field[y1][x1] == 11){
        if(!isValidQueenMove(uci))
            return false;
    }
    if(field[y1][x1] == 6 || field[y1][x1] == 12){
        if(!isValidKingMove(uci))
            return false;
    }
    if(!isValidAfterMove(uci))
        return false;
    return true;
}

bool Board::isValidPawnMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';
    if(isWhiteMove && field[y1][x1] != 1){
        return false;
    }
    if(!isWhiteMove && field[y1][x1] != 7){
        return false;
    }
    if(abs(y1 - y2) > 2 || abs(y1 - y2) == 0) {
        return false;
    }
    if(abs(x1 - x2) > 1){
        return false;
    }
    else if(abs(y1 - y2) == 2){
        if(abs(x1 - x2) != 0)
            return false;
        if(isWhiteMove) {
            if (y1 == 1 && y2 == 3 && field[2][x2] == 0 && field[3][x2] == 0) {
                return true;
            } else {
                return false;
            }
        }
        else{
            if(y1 == 6 && y2 == 4 && field[5][x2] == 0 && field[4][x2] == 0){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else if(abs(x1 - x2) == 1){
        if(isWhiteMove){
            if(y2 - y1 != 1)
                return false;
            if(field[y2][x2] >= 7 || (y2 == 5 && isDoubleMove[1][x2])){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            if(y2 - y1 != -1)
                return false;
            if(field[y2][x2] <= 6 && field[y2][x2] != 0 || (y2 == 2 && isDoubleMove[0][x2])){
                return true;
            }
            else{
                return false;
            }
        }
    }
    else if(abs(x1 - x2) == 0){
        if(isWhiteMove){
            if(y2 - y1 != 1) {
                return false;
            }
            if(field[y2][x2] != 0) {
                return false;
            }
            else {
                return true;
            }
        }
        else{
            if(y2 - y1 != -1){
                return false;
            }
            if(field[y2][x2] != 0){
                return false;
            }
            else{
                return true;
            }
        }
    }
}

bool Board::isValidKnightMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';
    int d1 = abs(x1 - x2);
    int d2 = abs(y1 - y2);
    if(isWhiteMove && field[y1][x1] != 4)
        return false;
    if(!isWhiteMove && field[y1][x1] != 10)
        return false;

    if(std::max(d1, d2) != 2 || std::min(d1, d2) != 1)
        return false;

    if(isWhiteMove){
        if(field[y2][x2] == 0 || field[y2][x2] >= 7)
            return true;
        return false;
    }
    else{
        if(field[y2][x2] == 0 || field[y2][x2] <= 6)
            return true;
        return false;
    }
}

bool Board::isValidRookMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if(isWhiteMove && field[y1][x1] != 2)
        return false;
    if(!isWhiteMove && field[y1][x1] != 8)
        return false;

    if(std::min(dx, dy) != 0 || std::max(dx, dy) == 0)
        return false;

    if(dx == 0){
        if(y2 > y1){
            for(int i = y1 + 1; i < y2; i++){
                if(field[i][x1] != 0)
                    return false;
            }
        }
        else{
            for(int i = y2 + 1; i < y1; i++){
                if(field[i][x1] != 0)
                    return false;
            }
        }
    }
    if(dy == 0){
        if(x2 > x1){
            for(int i = x1 + 1; i < x2; i++){
                if(field[y1][i] != 0)
                    return false;
            }
        }
        else{
            for(int i = x2 + 1; i < x1; i++){
                if(field[y1][i] != 0)
                    return false;
            }
        }
    }

    if(isWhiteMove){
        if(field[y2][x2] >= 1 && field[y2][x2] <= 6)
            return false;
    }
    else{
        if(field[y2][x2] >= 7 && field[y2][x2] <= 12)
            return false;
    }

    return true;
}

bool Board::isValidBishopMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if(isWhiteMove && field[y1][x1] != 3)
        return false;
    if(!isWhiteMove && field[y1][x1] != 9)
        return false;

    if(dx != dy)
        return false;

    if(y2 > y1 && x2 > x1){
        for(int i = 1; i < dx; i++){
            if(field[y1 + i][x1 + i] != 0)
                return false;
        }
    }
    if(y2 > y1 && x2 < x1){
        for(int i = 1; i < dx; i++){
            if(field[y1 + i][x1 - i] != 0)
                return false;
        }
    }
    if(y2 < y1 && x2 > x1){
        for(int i = 1; i < dx; i++){
            if(field[y1 - i][x1 + i] != 0)
                return false;
        }
    }
    if(y2 < y1 && x2 < x1){
        for(int i = 1; i < dx; i++){
            if(field[y1 - i][x1 - i] != 0)
                return false;
        }
    }

    if(isWhiteMove){
        if(field[y2][x2] >= 1 && field[y2][x2] <= 6)
            return false;
    }
    else{
        if(field[y2][x2] >= 7 && field[y2][x2] <= 12)
            return false;
    }
    return true;
}

bool Board::isValidQueenMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';

    if(isWhiteMove && field[y1][x1] != 5)
        return false;
    if(!isWhiteMove && field[y1][x1] != 11)
        return false;

    field[y1][x1] -= 2;
    bool b1 = isValidBishopMove(uci);
    field[y1][x1] += 2;
    field[y1][x1] -= 3;
    bool b2 = isValidRookMove(uci);
    field[y1][x1] += 3;
    if(b1 || b2)
        return true;
    return false;
}

bool Board::isValidKingMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';

    if(isWhiteMove && field[y1][x1] != 6)
        return false;
    if(!isWhiteMove && field[y1][x1] != 12)
        return false;

    if(uci == "e1c1" && isWhiteMove && !isLongWhiteCastled){
        for(int d = 1; d <= 3; d++)
            if(field[y1][x1 - d] != 0 || isUnderAttack(y1, x1 - d + 1, false))
                return false;
        return true;
    }
    if(uci == "e1g1" && isWhiteMove && !isShortWhiteCastled){
        for(int d = 1; d <= 2; d++)
            if(field[y1][x1 + d] != 0 || isUnderAttack(y1, x1 + d - 1, false))
                return false;
        return true;
    }
    if(uci == "e8c8" && !isWhiteMove && !isLongBlackCastled){
        for(int d = 1; d <= 3; d++)
            if(field[y1][x1 - d] != 0 || isUnderAttack(y1, x1 - d + 1, true))
                return false;
        return true;
    }
    if(uci == "e8g8" && !isWhiteMove && !isShortBlackCastled){
        for(int d = 1; d <= 2; d++)
            if(field[y1][x1 + d] != 0 || isUnderAttack(y1, x1 + d - 1, true))
                return false;
        return true;
    }

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    if(std::max(dx, dy) != 1)
        return false;

    if(isWhiteMove){
        if(field[y2][x2] >= 1 && field[y2][x2] <= 6)
            return false;
    }
    else{
        if(field[y2][x2] >= 7 && field[y2][x2] <= 12)
            return false;
    }
    return true;
}

bool Board::isUnderAttack(int y, int x, bool isUnderWhite) {
    int enemyKnight, enemyRook, enemyBishop, enemyQueen, enemyPawn, enemyKing;
    if(isUnderWhite) {
        enemyPawn = 1;
        enemyRook = 2;
        enemyBishop = 3;
        enemyKnight = 4;
        enemyQueen = 5;
        enemyKing = 6;
    }
    else {
        enemyPawn = 7;
        enemyRook = 8;
        enemyBishop = 9;
        enemyKnight = 10;
        enemyQueen = 11;
        enemyKing = 12;
    }

    for(int z1 = -1; z1 <= 1; z1 += 2){
        for(int z2 = -1; z2 <= 1; z2 += 2){
            int ny, nx;
            ny = y + z1 * 2;
            nx = x + z2 * 1;
            if(ny >= 0 && ny <= 7 && nx >= 0 && nx <= 7 && field[ny][nx] == enemyKnight){
                return true;
            }
            ny = y + z1 * 1;
            nx = x + z2 * 2;
            if(ny >= 0 && ny <= 7 && nx >= 0 && nx <= 7 && field[ny][nx] == enemyKnight){
                return true;
            }
        }
    }
    for(int z1 = -1; z1 <= 1; z1 += 2){
        for(int z2 = -1; z2 <= 1; z2 += 2){
            for(int d = 1;;d++){
                int ny, nx;
                ny = y + d * z1;
                nx = x;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyRook){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
            for(int d = 1;;d++){
                int ny, nx;
                ny = y;
                nx = x + d * z2;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyRook){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
        }
    }

    for(int z1 = -1; z1 <= 1; z1 += 2){
        for(int z2 = -1; z2 <= 1; z2 += 2){
            for(int d = 1;;d++){
                int ny, nx;
                ny = y + d * z1;
                nx = x + d * z2;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyBishop){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
        }
    }

    for(int z1 = -1; z1 <= 1; z1 += 2){
        for(int z2 = -1; z2 <= 1; z2 += 2){
            for(int d = 1;;d++){
                int ny, nx;
                ny = y + d * z1;
                nx = x + d * z2;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyQueen){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
            for(int d = 1;;d++){
                int ny, nx;
                ny = y + d * z1;
                nx = x;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyQueen){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
            for(int d = 1;;d++){
                int ny, nx;
                ny = y;
                nx = x + d * z2;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyQueen){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
        }
    }

    for(int z1 = -1; z1 <= 1; z1 += 2){
        for(int z2 = -1; z2 <= 1; z2 += 2){
            for(int d = 1; d <= 1;d++){
                int ny, nx;
                ny = y + d * z1;
                nx = x + d * z2;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyKing){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
            for(int d = 1; d <= 1 ;d++){
                int ny, nx;
                ny = y + d * z1;
                nx = x;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyKing){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
            for(int d = 1; d <= 1;d++){
                int ny, nx;
                ny = y;
                nx = x + d * z2;
                if(ny < 0 || ny > 7 || nx < 0 || nx > 7)
                    break;
                if(field[ny][nx] == enemyKing){
                    return true;
                }
                if(field[ny][nx] != 0)
                    break;
            }
        }
    }

    for(int z = -1; z <= 1; z += 2) {
        if (isUnderWhite) {
            int nx = x + z;
            int ny = y - 1;
            if(ny >= 0 && ny <= 7 && nx >= 0 && nx <= 7 && field[ny][nx] == enemyPawn){
                return true;
            }
        }
        else{
            int nx = x + z;
            int ny = y + 1;
            if(ny >= 0 && ny <= 7 && nx >= 0 && nx <= 7 && field[ny][nx] == enemyPawn){
                return true;
            }
        }
    }

    return false;
}

Board::Board(const Board &board) : Board(){
    this->isWhiteMove = board.isWhiteMove;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            this->field[i][j] = board.field[i][j];
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 8; j++){
            this->isDoubleMove[i][j] = board.isDoubleMove[i][j];
        }
    }
    this->isShortBlackCastled = board.isShortBlackCastled;
    this->isLongBlackCastled = board.isLongBlackCastled;
    this->isShortWhiteCastled = board.isShortWhiteCastled;
    this->isLongWhiteCastled = board.isLongWhiteCastled;
}

bool Board::isValidAfterMove(std::string uci) {
    int x1 = uci[0] - 'a';
    int y1 = uci[1] - '1';
    int x2 = uci[2] - 'a';
    int y2 = uci[3] - '1';

    Board tboard(*this);
    tboard.move(uci);
    int y, x;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((isWhiteMove && tboard.field[i][j] == 6) || (!isWhiteMove && tboard.field[i][j] == 12)){
                y = i;
                x = j;
                break;
            }
        }
    }

    if(tboard.isUnderAttack(y, x, !isWhiteMove)){
        return false;
    }
    return true;
}

//0-not ended
//1-white win
//2-black win
//3-draw
int Board::isEnd() {
    for(int i = 0; i < 64 * 64; i++){
        if(isPossibleMove(numberToUci(i))){
            return 0;
        }
    }
    bool isAttacked = false;
    int y, x;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((isWhiteMove && field[i][j] == 6) || (!isWhiteMove && field[i][j] == 12)){
                y = i;
                x = j;
                break;
            }
        }
    }
    if(isUnderAttack(y, x, !isWhiteMove)){
        isAttacked = true;
    }
    if(!isAttacked)
        return 3;
    if(isAttacked && !isWhiteMove)
        return 1;
    if(isAttacked && isWhiteMove)
        return 2;
}

int **Board::getField() {
    return field;
}

bool Board::getIsWhiteMove() {
    return isWhiteMove;
}

Board::Board(std::string fen) : Board(){
    int ind = 0;
    int y = 7, x = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            field[i][j] = 0;
        }
    }
    for(;;ind++){
        char c = fen[ind];
        if(c == ' '){
            ind++;
            break;
        }
        if(c == '/'){
            y--;
            x = 0;
            continue;
        }
        if(c >= '1' && c <= '8'){
            x += (c - '0');
            continue;
        }
        if(c == 'P'){
            field[y][x] = 1;
        }
        if(c == 'R'){
            field[y][x] = 2;
        }
        if(c == 'B'){
            field[y][x] = 3;
        }
        if(c == 'N'){
            field[y][x] = 4;
        }
        if(c == 'Q'){
            field[y][x] = 5;
        }
        if(c == 'K'){
            field[y][x] = 6;
        }
        if(c == 'p'){
            field[y][x] = 7;
        }
        if(c == 'r'){
            field[y][x] = 8;
        }
        if(c == 'b'){
            field[y][x] = 9;
        }
        if(c == 'n'){
            field[y][x] = 10;
        }
        if(c == 'q'){
            field[y][x] = 11;
        }
        if(c == 'k'){
            field[y][x] = 12;
        }
        x++;
    }
    char move = fen[ind];
    if(move == 'w')
        isWhiteMove = true;
    else
        isWhiteMove = false;
    ind += 2;
    for(;;ind++){
        char c = fen[ind];
        if(c == ' '){
            ind++;
            break;
        }

        if(c == 'Q'){
            isLongWhiteCastled = false;
        }
        if(c == 'K'){
            isShortWhiteCastled = false;
        }
        if(c == 'q'){
            isLongBlackCastled = false;
        }
        if(c == 'k'){
            isShortBlackCastled = false;
        }
    }
    char en = fen[ind];
    if(en == '-')
        return;
    x = (en - 'a');
    if(isWhiteMove){
        isDoubleMove[1][x] = true;
    }
    else{
        isDoubleMove[0][x] = true;
    }
}

float *Board::extendedEncodeBoard() {
    auto *code = new float[1122];
    for(int i = 0; i < 1122; i++){
        code[i] = 0;
    }
    if(isWhiteMove){
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(field[i][j] == 0)
                    continue;
                int pos = (field[i][j] - 1) * (64) + i * 8 + j;
                code[pos] = 1;
            }
        }
        for(int i = 0; i < 8; i++){
            if(isDoubleMove[0][i] == 0)
                continue;
            int pos = 64 * 12 + i;
            code[pos] = 1;
        }
        for(int i = 0; i < 8; i++){
            if(isDoubleMove[1][i] == 0)
                continue;
            int pos = 64 * 12 + 8 + i;
            code[pos] = 1;
        }
        if(!isShortWhiteCastled){
            code[784] = 1;
        }
        if(!isLongWhiteCastled){
            code[785] = 1;
        }
        if(!isShortBlackCastled){
            code[786] = 1;
        }
        if(!isLongBlackCastled){
            code[787] = 1;
        }
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(field[i][j] == 0)
                    continue;
                int pos1 = 788 + i * 8 + j;
                int pos2 = pos1 + 64;
                int pos3 = pos2 + 64;
                code[pos1] = 1;
                if(field[i][j] <= 6)
                    code[pos2] = 1;
                if(field[i][j] > 6)
                    code[pos3] = 1;
            }
        }
        std::vector<int> figuresCnt(12, 0);
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(field[i][j] == 0)
                    continue;
                figuresCnt[field[i][j] - 1]++;
            }
        }
        for(int i = 0; i < 12; i++){
            code[980 + i] = figuresCnt[i];
        }

        code[992] = isKingUnderAttack(false);
        code[993] = isKingUnderAttack(true);

        for(int i = 0; i < 64; i++){
            if(isUnderAttack(i / 8, i % 8, false)) {
                code[994 + i] = true;
            }
        }
        for(int i = 0; i < 64; i++){
            if(isUnderAttack(i / 8, i % 8, true)) {
                code[1058 + i] = true;
            }
        }
    }
    else{
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(field[i][j] == 0)
                    continue;
                int fig = field[i][j];
                if(fig <= 6)
                    fig += 6;
                else
                    fig -= 6;
                int ti = 7 - i;
                int tj = 7 - j;


                int pos = (fig - 1) * (64) + ti * 8 + tj;
                code[pos] = 1;
            }
        }

        for(int i = 0; i < 8; i++){
            int ti = 7 - i;
            if(isDoubleMove[1][ti] == 0)
                continue;
            int pos = 64 * 12 + ti;
            code[pos] = 1;
        }
        for(int i = 0; i < 8; i++){
            int ti = 7 - i;
            if(isDoubleMove[0][ti] == 0)
                continue;
            int pos = 64 * 12 + 8 + ti;
            code[pos] = 1;
        }
        if(!isShortBlackCastled){
            code[784] = 1;
        }
        if(!isLongBlackCastled){
            code[785] = 1;
        }
        if(!isShortWhiteCastled){
            code[786] = 1;
        }
        if(!isLongWhiteCastled){
            code[787] = 1;
        }


        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(field[i][j] == 0)
                    continue;
                int fig = field[i][j];
                if(fig <= 6)
                    fig += 6;
                else
                    fig -= 6;
                int ti = 7 - i;
                int tj = 7 - j;

                int pos1 = 788 + ti * 8 + tj;
                int pos2 = pos1 + 64;
                int pos3 = pos2 + 64;
                code[pos1] = 1;
                if(fig <= 6)
                    code[pos2] = 1;
                if(fig > 6)
                    code[pos3] = 1;
            }
        }

        std::vector<int> figuresCnt(12, 0);
        for(int i = 7; i >= 0; i--){
            for(int j = 7; j >= 0; j--){
                if(field[i][j] == 0)
                    continue;
                int fig = field[i][j];
                if(fig <= 6)
                    fig += 6;
                else
                    fig -= 6;
                figuresCnt[fig - 1]++;
            }
        }

        for(int i = 0; i < 12; i++){
            code[980 + i] = figuresCnt[i];
        }

        code[992] = isKingUnderAttack(true);
        code[993] = isKingUnderAttack(false);

        for(int i = 0; i < 64; i++){
            if(isUnderAttack(i / 8, i % 8, true)) {
                code[994 + (63 - i)] = true;
            }
        }
        for(int i = 0; i < 64; i++){
            if(isUnderAttack(i / 8, i % 8, false)) {
                code[1058 + (63 - i)] = true;
            }
        }
    }
    return code;

}

bool Board::isKingUnderAttack(bool isUnderWhite) {
    int y, x;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(isUnderWhite){
                if(field[i][j] == 12){
                    y = i;
                    x = j;
                }
            }
            else{
                if(field[i][j] == 6){
                    y = i;
                    x = j;
                }
            }
        }
    }

    return isUnderAttack(y, x, isUnderWhite);
}

unsigned long long Board::hashBoard() {
    float *code = extendedEncodeBoard();
    unsigned long long result = 0, curKey = 1;
    const unsigned long long KEY = 17;
    for(int i = 0; i < 1122; i++){
        result += curKey * ((unsigned long long)(code[i] + 0.01f));
        curKey *= KEY;
    }
    delete[] code;
    return result;
}

