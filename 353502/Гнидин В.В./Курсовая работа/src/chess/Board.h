//
// Created by volodya-petarda on 3/15/24.
//

#ifndef NEURALNETWORK_BOARD_H
#define NEURALNETWORK_BOARD_H
#include <iostream>
#include <vector>

class Board {
//P = 1, R = 2, B = 3, N = 4, Q = 5, K = 6
public:
    Board();
    Board(Board const &board);
    Board(std::string fen);
    ~Board();
    void move(std::string uci);
    void printBoard();
    float *encodeBoard();
    float *extendedEncodeBoard();
    static std::string numberToUci(int num);
    static int uciToNumber(std::string uci);
    static std::string reverseUci(std::string uci);
    static std::string partNumToPartUci(int num);
    static int partUciPartToPartInt(std::string uci);
    bool isPossibleMove(std::string uci);
    int isEnd();
    bool getIsWhiteMove();
    int** getField();
    unsigned long long hashBoard();
private:
    bool isValidPawnMove(std::string uci);
    bool isValidKnightMove(std::string uci);
    bool isValidRookMove(std::string uci);
    bool isValidBishopMove(std::string uci);
    bool isValidQueenMove(std::string uci);
    bool isValidKingMove(std::string uci);
    bool isValidAfterMove(std::string uci);
    bool isUnderAttack(int y, int x, bool isUnderWhite);
    bool isKingUnderAttack(bool isUnderWhite);
    bool isWhiteMove = true;
    int **field;
    bool *isDoubleMove[2];
    bool isShortWhiteCastled = false, isLongWhiteCastled = false, isShortBlackCastled = false, isLongBlackCastled = false;
};


#endif //NEURALNETWORK_BOARD_H
