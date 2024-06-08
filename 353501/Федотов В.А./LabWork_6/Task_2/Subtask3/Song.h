#include <QString>

const int MAX_TITLE_LENGTH = 128;
const int RATING_VALUES_LENGTH = 3;

struct Song {
    int releaseYear;
    double duration;
    bool isInstrumental;
    char title[MAX_TITLE_LENGTH] = "";
    int ratingValues[RATING_VALUES_LENGTH];
};