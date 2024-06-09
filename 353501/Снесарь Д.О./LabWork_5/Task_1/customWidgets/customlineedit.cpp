#include "customlineedit.h"

customLineEdit::customLineEdit(QWidget *parent)
    : QTextEdit(parent)
{

    setStyleSheet("color: gray;");
    setFont(QFont("", 50));
    setReadOnly(true);
    //setEnabled(false);
    setFocusPolicy(Qt::StrongFocus);

    initSymbols();

    strCorr.resize(this->toPlainText().size());
    for(int i = 0; i < strCorr.size(); i++)
        strCorr[i] = 0;
    posI = 0;
    correctS = 0;
}

void customLineEdit::loadLevel()
{
    setText(currTest);


    strCorr.resize(this->toPlainText().size());
    for(int i = 0; i < strCorr.size(); i++)
        strCorr[i] = 0;
    posI = 0;
    correctS = 0;
}

void customLineEdit::loadLevel(int n)
{
    correctS = 0;
    this->setPlainText("");
    currTest="";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открытие"), "//", tr("Текстовые документы (*.txt)"));
    QFile openedFile(fileName);
    QTextStream in(&openedFile);

    if (!openedFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    if (in.atEnd())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Пустой файл!"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }


    while (!in.atEnd())
        currTest.append(in.readLine());
   /* if (!checkTest())
    {
        QMessageBox::critical(0,tr("Ошибка"),tr("Недопустимые символы!"),QMessageBox::Ok|QMessageBox::NoButton);
        currTest = {};
        return;
    }*/

    QMessageBox::information(0,tr("Успех"),tr("Тестовый текст добавлен!"),QMessageBox::Ok|QMessageBox::NoButton);
    loadLevel();

}
void customLineEdit::keyPressEvent(QKeyEvent *event)
{
    if(posI > this->toPlainText().size() - 1){
        emit ending();
        return;
    }
    int keyCode = event->key();
    qDebug()<<keyCode;
    emit keyPressed(event);

    if (event->nativeScanCode() == 22 || event->nativeScanCode() == 110 ||
        event->nativeScanCode() == 115 || event->nativeScanCode() == 111 ||
        event->nativeScanCode() == 113 || event->nativeScanCode() == 114 ||
        event->nativeScanCode() == 116 || event->nativeScanCode() == 119 ||
        event->nativeScanCode() == 104 || event->nativeScanCode() == 9)
    {
        return;
    }

    QString before = this->toPlainText();
    qDebug()<<event->text()<<before[posI];
    if(before[posI] == event->text()){
        strCorr[posI] = 1;
        correctS++;
    }
    else
    {
        strCorr[posI] = -1;
    }
    qDebug()<<this->toPlainText();


    QString after;
    for(int i = 0; i < strCorr.size(); i++){
        if(strCorr[i] == 1){
            QString temp = before[i];
            after += "<font color=\"green\">" + temp + "</font>"; ;
        }
        if(strCorr[i] == 0){
            QString temp = before[i];
            after += "<font color=\"grey\">" + temp + "</font>"; ;
        }
        if(strCorr[i] == -1){
            QString temp = before[i];
            after += "<font color=\"red\">" + temp + "</font>"; ;
        }
    }
    this->setHtml(after);
    posI++;
   // QLineEdit::keyPressEvent(event);
    if(posI > this->toPlainText().size() - 1){
        emit ending();
        return;
    }
}

int customLineEdit::getCorrS()
{
    return correctS;
}

int customLineEdit::getPos()
{
    return posI;
}

