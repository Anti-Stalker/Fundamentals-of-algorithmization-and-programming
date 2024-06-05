#ifndef SOUNDANALYZER_H
#define SOUNDANALYZER_H
#include <QObject>
#include <QVector>
#include <QAudioFormat>
#include <QAudioInput>
#include <QChart>
#include <QChartView>
#include <QLineSeries>
#include <QValueAxis>
#include <QAudioDevice>
#include <QAudioDecoder>
#include <QAudioBuffer>

class SoundAnalyzer: public QObject
{
    Q_OBJECT
public:
    SoundAnalyzer(QObject* parent = nullptr);
    void FFTAnalysis(double *AVal, double *FTvl, int Nvl, int Nft);
};
#endif // SOUNDANALYZER_H
