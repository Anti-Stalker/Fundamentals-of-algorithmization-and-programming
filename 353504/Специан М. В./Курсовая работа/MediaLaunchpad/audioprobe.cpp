#include "audioprobe.h"
#include <QAudioFormat>

AudioProbe::AudioProbe(QObject *parent) : QIODevice(parent)
{
    open(QIODevice::ReadOnly);
}

qint64 AudioProbe::readData(char *data, qint64 maxlen)
{
    Q_UNUSED(data)
    Q_UNUSED(maxlen)
    return 0;
}

qint64 AudioProbe::writeData(const char *data, qint64 len)
{
    const qint16 *samples = reinterpret_cast<const qint16*>(data);
    qint64 numSamples = len / sizeof(qint16);
    QVector<double> amplitudes(numSamples);

    for (int i = 0; i < numSamples; ++i) {
         for (int i = 0; i < numSamples; ++i) {
            amplitudes[i] = static_cast<double>(samples[i]);
        }

        emit spectrumUpdated(amplitudes);

        return len;
    }
}
