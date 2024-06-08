#include "bel.h"


void Bel::change_bel(QPushButton **a,QString bel,QPushButton **aa)
{
    a=aa;
    a[0]->setText(bel[38]);
    a[15]->setText(bel[10]);
    a[16]->setText(bel[24]);
    a[17]->setText(bel[20]);
    a[18]->setText(bel[11]);
    a[19]->setText(bel[5]);
    a[20]->setText(bel[14]);
    a[21]->setText(bel[3]);
    a[22]->setText(bel[26]);
    a[23]->setText(bel[21]);
    a[24]->setText(bel[8]);
    a[25]->setText(bel[23]);
    a[26]->setText("'");
    a[29]->setText(bel[22]);
    a[30]->setText(bel[27]);
    a[31]->setText(bel[2]);
    a[32]->setText(bel[0]);
    a[33]->setText(bel[16]);
    a[34]->setText(bel[17]);
    a[35]->setText(bel[15]);
    a[36]->setText(bel[12]);
    a[37]->setText(bel[4]);
    a[38]->setText(bel[7]);
    a[39]->setText(bel[29]);
    a[42]->setText(bel[31]);
    a[43]->setText(bel[25]);
    a[44]->setText(bel[18]);
    a[45]->setText(bel[13]);
    a[46]->setText(bel[9]);
    a[47]->setText(bel[19]);
    a[48]->setText(bel[28]);
    a[49]->setText(bel[1]);
    a[50]->setText(bel[30]);
    a[51]->setText(",");
}
std::vector <QString> Bel::read_bel()
{
    std::vector <QString> a;
    QFile file("/Users/daryastasiuk/Documents/BSUIR/ОАиП(2 term)/BelarusianWords.txt");
    QTextStream in(&file);
    file.open(QIODevice::ReadOnly);
    while(!in.atEnd())
    {
        a.push_back(in.readLine());
    }
    file.close();
    return a;
}
