#ifndef QRSEGMENT_H
#define QRSEGMENT_H


#include <cstdint>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <mode.h>
#include <bitbuffer.h>
#include <QVector>

using std::int8_t;
using std::uint8_t;
using std::size_t;
//using std::QVector;

class QrSegment
{
public:
    static QrSegment createByteSegment(const QVector<std::uint8_t>&);
    static QrSegment createNumericSegment(const QChar*);
    static QrSegment createAlphanumericSegment(const QChar*);
public:
    static QVector<QrSegment> buildSegments(const QChar*);
    static QrSegment makeEci(long assignVal);
public:
    static bool isNumericFormat(const QChar*);
    static bool isAlphanumericFormat(const QChar*);
private:
    const Mode *mode;
    int numChars;
    QVector<bool> data;
public:
    QrSegment(const Mode &md, int numCh, const QVector<bool>&);
    QrSegment(const Mode &md, int numCh, QVector<bool>&&);
    const Mode &getMode() const;
    int getNumChars() const;
    const QVector<bool> &getData() const;
    static int getTotalBits(const QVector<QrSegment>&, int);
};

#endif // QRSEGMENT_H
