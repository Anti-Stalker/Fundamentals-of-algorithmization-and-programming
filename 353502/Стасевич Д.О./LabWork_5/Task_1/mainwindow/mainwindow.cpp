#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

mainwindow::mainwindow(): ui(new Ui::mainwindow) {

    ui->setupUi(this);

    // preparing
    // add setLayout
    /*
     * set layout
     * set text
     * set label at corner
     * stop timer
     * reset accuracy
     * reset symbols at minute
     */

    buttons = {ui->pushButton,
               ui->pushButton_2,
               ui->pushButton_3,
               ui->pushButton_4,
               ui->pushButton_5,
               ui->pushButton_6,
               ui->pushButton_7,
               ui->pushButton_8,
               ui->pushButton_9,
               ui->pushButton_10,
               ui->pushButton_11,
               ui->pushButton_12,
               ui->pushButton_13,
               ui->pushButton_14,
               ui->pushButton_15,
               ui->pushButton_16,
               ui->pushButton_17,
               ui->pushButton_18,
               ui->pushButton_19,
               ui->pushButton_20,
               ui->pushButton_21,
               ui->pushButton_22,
               ui->pushButton_23,
               ui->pushButton_24,
               ui->pushButton_25,
               ui->pushButton_26,
               ui->pushButton_27,
               ui->pushButton_28,
               ui->pushButton_29,
               ui->pushButton_30,
               ui->pushButton_31,
               ui->pushButton_32,
               ui->pushButton_33,
               ui->pushButton_34,
               ui->pushButton_35,
               ui->pushButton_36,
               ui->pushButton_37,
               ui->pushButton_38,
               ui->pushButton_39,
               ui->pushButton_40,
               ui->pushButton_41,
               ui->pushButton_42,
               ui->pushButton_43,
               ui->pushButton_44,
               ui->pushButton_45,
               ui->pushButton_46,
               ui->pushButton_47,
               ui->pushButton_48,
               ui->pushButton_49,
               ui->pushButton_50,
               ui->pushButton_51,
               ui->pushButton_52,
               ui->pushButton_53,
               ui->pushButton_54,
               ui->pushButton_55,
               ui->pushButton_56,
               ui->pushButton_57,
               ui->pushButton_58};

    connect_keyboard_buttons.resize(150);
    for(int i = 0; i < 150; i ++)
    {
        connect_keyboard_buttons[i] = -1;
    }
    connect_keyboard_buttons[49] = 0;
    for(int i = 10; i <= 35; i ++)
    {
        connect_keyboard_buttons[i] = i - 9;
    }
    connect_keyboard_buttons[51] = 27;
    connect_keyboard_buttons[66] = 28;
    for(int i = 38; i <= 48; i ++)
        connect_keyboard_buttons[i] = i - 9;
    connect_keyboard_buttons[36] = 40;
    connect_keyboard_buttons[50] = 41;
    for(int i = 52; i <= 62; i ++)
        connect_keyboard_buttons[i] = i - 10;
    connect_keyboard_buttons[37] = 53;
    connect_keyboard_buttons[64] = 54;
    connect_keyboard_buttons[65] = 55;
    connect_keyboard_buttons[108] = 56;
    connect_keyboard_buttons[105] = 57;

    connect_keyboard_buttons[87] = 1;
    connect_keyboard_buttons[88] = 2;
    connect_keyboard_buttons[89] = 3;
    connect_keyboard_buttons[83] = 4;
    connect_keyboard_buttons[84] = 5;
    connect_keyboard_buttons[85] = 6;
    connect_keyboard_buttons[79] = 7;
    connect_keyboard_buttons[80] = 8;
    connect_keyboard_buttons[81] = 9;
    connect_keyboard_buttons[82] = 11;
    connect_keyboard_buttons[90] = 10;
    connect_keyboard_buttons[104] = 40;

    for(int i = 0; i < buttons.size(); i ++)
    {
        buttons[i]->setStyleSheet("background-color:rgba(255, 255, 255, 100);");
    }
    timer = new QTimer(this);
    timer->setInterval(100);

    ui->widget_6->hide();


    current_language = 0;
    setLayout();
    setText();

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(change_language_clicked(int)));
    connect(timer, SIGNAL(timeout()), this, SLOT(increase_timer()));
    connect(ui->pushButton_59, SIGNAL(clicked()), this, SLOT(start_game_clicked()));
    connect(ui->pushButton_60, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->openpushButton, SIGNAL(clicked()), this, SLOT(open_file_clicked()));
}

void mainwindow::start_game_clicked() {
    ui->comboBox->setEnabled(1);
    ui->widget_6->hide();
    is_training = false;
    resetWidgets();
    setLayout();
    setText();
}

void mainwindow::keyPressEvent(QKeyEvent *e) {
    if(!is_training)
    {
        is_training = true;
        timer->start();
        resetWidgets();
    }
    int code = e->nativeScanCode();
    if(code > connect_keyboard_buttons.size()-10)
        return;
    auto k = e->text();
    qDebug() << "code " << code << " " << k;
    if(code == 50 || code == 62 || code == 66)
    {
        if(code == 66)
            caps ^= 1;
        else
            shift ^= 1;
        setLayout();
        buttons[connect_keyboard_buttons[code]]->setStyleSheet("background-color:rgba(255, 255, 0, 100);");
        return;
    }
    if(connect_keyboard_buttons[code] != -1)
    {
        if(k == training_text[cur_pos] || (k == '\r' && training_text[cur_pos] == '\n'))
        {
            buttons[connect_keyboard_buttons[code]]->setStyleSheet("background-color:rgba(0, 255, 0, 100);");
            green += training_text[cur_pos];
            black.remove(0, 1);
            cur_pos ++;
            if(k == ' ' || (k == '.' && training_text[cur_pos - 1] != '.' && training_text[cur_pos - 1] != '\"') || k == '\r')
            {
                increase_words();
            }
            QString combinedText = "<font color='green'>" + green + "</font>" +
                                   "<font color='black'>" + black + "</font> ";

            information.all_symbols++;
            ui->label->setTextFormat(Qt::RichText);
            ui->label->setText(combinedText);

            if(cur_pos == training_text.size())
            {
                // show_end_game()
                show_end_game();
                qDebug() << "all " << information.words << " " << information.mistakes << " " << information.time;

            }
        }
        else
        {
            qDebug() << "wrong " << k << " " << training_text[cur_pos];
            buttons[connect_keyboard_buttons[code]]->setStyleSheet("background-color:rgba(255, 0, 0, 100);");
            QString red;
            red += training_text[cur_pos];
            QString display_black = black;
            display_black.remove(0, 1);
            QString combinedText = "<font color='green'>" + green + "</font>" +
                                   "<font color='red'>" + red + "</font>" +
                                   "<font color='black'>" + display_black + "</font> ";

            ui->label->setTextFormat(Qt::RichText);
            ui->label->setText(combinedText);
            increase_mistake();
        }
    }


}

void mainwindow::keyReleaseEvent(QKeyEvent *e) {
    int code = e->nativeScanCode();
    auto k = e->text();
    if(code == 50 || code == 62)
    {
        shift ^= 1;
        setLayout();
        // chan
        //ge keyboard
    }
//    std::cout << connect_keyboard_buttons.size() << '\n';
    if(code > connect_keyboard_buttons.size() - 1 || connect_keyboard_buttons[code] != -1) {
        //std::cout << connect_keyboard_buttons[code] << '\n';

        if(code >  170 && code < 174)
        {

        }
        else {

            if ((code > 148 || connect_keyboard_buttons[code] == -1))
            {

            }
            else
                buttons[connect_keyboard_buttons[code]]->setStyleSheet("background-color:rgba(255, 255, 255, 100);");
        }
    }
}

void mainwindow::setLayout() {
    QString layout;
    switch (current_language) {
        case 0:
        {
            // английский
            connect_keyboard_buttons[91] = 50;
            if(caps)
            {
                if(shift)
                {
                    layout = "~!@#$%^&*()_+++qwertyuiop{}||asdfghjkl:QQQzxcvbnm<>???????";
                }
                else
                {
                    layout = "`1234567890-=btQWERTYUIOP[]-cASDFGHJKL;'esZXCVBNM,./scasac";
                }
            }
            else
            {
                if(shift)
                {
                    layout = "~!@#$%^&*()_+++QWERTYUIOP{}}}ASDFGHJKL:QQQZXCVBNM<>???????";
                }
                else
                {
                    layout = "`1234567890-=btqwertyuiop[]-casdfghjkl;'eszxcvbnm,./scasac";
                }
            }
            break;
        }
        case 1:
        {
            // русский
            connect_keyboard_buttons[91] = 51;
            if(caps)
            {
                if(shift)
                {
                    layout = "ё!@№;%:?*()_+++йцукенгшщзхъ/ффывапролджэээячсмитьбю,,,,,,,";
                }
                else
                {
                    layout = "Ё1234567890-=ИТЙЦУКЕНГШЩЗХЪЖБФЫВАПРОЛДЖЭББЯЧСМИТЬБЮ.......";
                }
            }
            else
            {
                if(shift)
                {
                    layout = "Ё!@№;%:?*()_+++ЙЦУКЕНГШЩЗХЪЪФФЫВАПРОЛДЖЭЭЭЯЧСМИТЬБЮ,,,,,,,";
                }
                else
                {
                    layout = "ё1234567890-=ббйцукенгшщзхътчфывапролджэяяячсмитьбю.......";
                }
            }
            break;
        }
        case 2:
        {
            // белорусский
            connect_keyboard_buttons[91] = 51;
            if(caps)
            {
                if(shift)
                {
                    layout = "ё!@№;%:?*()_++ййцукенгшўзх'''фывапролджэээячсмітьбю,,,,,,,";
                }
                else
                {
                    layout = "Ё1234567890-=ййЙЦУКЕНГШЎЗХ'--ФЫВАПРОЛДЖЭ--ЯЧСМІТЬБЮ.......";
                }
            }
            else
            {
                if(shift)
                {
                    layout = "Ё!@№;%:?*()_+++ЙЦУКЕНГШЎЗХ'''ФЫВАПРОЛДЖЭЭЭЯЧСМІТЬБЮ,,,,,,,";
                }
                else
                {
                    layout = "ё1234567890-=--йцукенгшўзх'--фывапролджэ--ячсмітьбю.------";
                }
            }
            break;
        }
        case 3:
        {
            // немецкий
            connect_keyboard_buttons[91] = 50;
            if(caps)
            {
                if(shift)
                {
                    layout = "°!@§$%&/()=?`QQqwertzuiopü*'aasdfghjklöäääyxcvbnm;:_______";
                }
                else
                {
                    layout = "^1234567890ẞ´++QWERTZUIOPÜ+##ASDFGHJKLÖÄÄÄYXCVBNM,.-------";
                }
            }
            else
            {
                if(shift)
                {
                    layout = "°!@§$%&/()=?`qqQWERTZUIOPÜ*'AASDFGHJKLÖÄÄÄYXCVBNM;:_______";
                }
                else
                {
                    layout = "^1234567890ß´qqqwertzuiopü+#aasdfghjklöäääyxcvbnm,.-------";
                }
            }
            break;

        }
        case 4:
        {
            // французский
            if(caps)
            {
                if(shift)
                {
                    layout = "~1234567890°+++azertyuiop¨£µµqsdfghjklm%%%wxcvbn?./§§§§§§§";
                }
                else
                {
                    layout = "²&É34(-È_ÇÀ)===AZERTYUIOP^$**QSDFGHJKLMÙÙÙWXCVBN,;:!!!!!!!";
                }
            }
            else
            {
                if(shift)
                {
                    layout = "~1234567890°+++AZERTYUIOP¨£µµQSDFGHJKLM%%%WXCVBN?./§§§§§§§";
                }
                else
                {
                    layout = "²&é34(-è_çà)===azertyuiop^$*qqsdfghjklmùùùwxcvbn,;:!!!!!!!";
                }
            }
            break;
        }
        case 5:
        {
            if(caps)
            {
                if(shift)
                {
                    layout = "~!@#$%^&*)(_+++ק'קראטוןםפ}{||שדגכעיחלךףףףףזסבהנמצתץ???????";

                }
                else
                {
                    layout = ";1234567890-===QWERTYUIOP][[[AASDFGHJKL:,,,ZXCVBNM><.......";
    //                layout = "???????ץתצמנהבסזזזףףךלחיעכגדשש|{}פםןוטארק'קקק+_()*&^%$#@!~";
                }
            }
            else
            {
                if(shift)
                {
                    layout = "~!@#$%^&*)(_+++QWERTYUIOP}{||ASDFGHJKL::::ZXCVBNM><???????";
  //                  layout = "???????ץתצמנהבסזזזףףךלחיעכגדשש|{}פםןוטארק'קקק+_()*&^%$#@!~";
                }
                else
                {
                    layout = ";1234567890-===ג'קראטוןםפ][[[שדגכעיחלךף,,,זסבהנמצתץ.......";
//                    layout = "???????ץתצמנהבסזזזףףךלחיעכגדשש|{}פםןוטארק'קקק+_()*&^%$#@!~";
                }
            }
            break;
        }
        case 6:
        {
            layout = "ذ1234567890-===ضصثقفغعهخحجدشششسيبلاتنمكطططئءؤرلللللاىةوزظظظظظظظ";
            if(shift)
            {
                layout = "ّ!@#$%^!*)(_+++ًٌَُلإإ÷×؛<>>>ٍِ][ل،/ــ::::~ْ}{قآ',.؟؟؟؟؟؟؟ظ";
                buttons[7]->setText("&&");
            }
            break;
        }
        case 7: {
            layout = "`1234567890-===qwertyuiop[]]]asdfghjkl;'qqzxcvbnm,..0....";
        }
        // other languages
    }
    for(int i = 0; i < buttons.size(); i ++)
    {
        QString add = "";
        add += layout[i];
        buttons[i]->setText(add);
    }
    buttons[13]->setText("Backspace");
    buttons[14]->setText("Tab");
    buttons[27]->setText("\\");
    if((current_language == 0 || current_language == 6) && shift)
    {
        buttons[7]->setText("&&");
    }
    if(current_language == 3) {
        buttons[27]->setText("#");
        if(shift)
        {
            buttons[6]->setText("&&");
        }
    }
    if(current_language == 4) {
        if(!shift) {
            buttons[1]->setText("&&");
            buttons[3]->setText("\"");
            buttons[4]->setText("\'");
        }
        buttons[27]->setText("*");

    }
    if(current_language == 5)
        buttons[15]->setText("\"");
    if(current_language == 6 && !shift){
        buttons[46]->setText("لا");
        buttons[47]->setText("ى");
        buttons[48]->setText("ة");
        buttons[49]->setText("و");
        buttons[50]->setText("ز");
        buttons[51]->setText("ظ");
    }
    if(current_language == 6 && shift)
    {
        buttons[19]->setText("لإ");
        buttons[21]->setText("`");
        buttons[33]->setText("لإ");
        buttons[34]->setText("أ");
        buttons[35]->setText("ـ");
        buttons[36]->setText("،");
        buttons[37]->setText("/");
        buttons[38]->setText(":");
        buttons[39]->setText("\"");
        buttons[46]->setText("لآ");
    }
    buttons[28]->setText("CapsLk");
    buttons[40]->setText("Enter");
    buttons[41]->setText("Shift");
    buttons[52]->setText("Shift");
    buttons[53]->setText("Ctrl");
    buttons[54]->setText("Alt");
    buttons[55]->setText("");
    buttons[56]->setText("Alt");
    buttons[57]->setText("Ctrl");

}

void mainwindow::change_language_clicked(int type) {
    current_language = type;
    is_training = false;
    timer->stop();
    resetWidgets();
    setLayout();
    setText();
}

void mainwindow::resetWidgets() {
    information.time = 0;
    information.mistakes = 0;
    information.words = 0;
    ui->label_9->setText(Convert());
    ui->label_10->setText("-");
    ui->label_11->setText("-");
}

void mainwindow::update_data() {
    ui->label_9->setText(Convert());
    double a = information.all_symbols;
    double b = (double)information.time / 10 / 60;
    double c = a / b;
    ui->label_10->setText(QString::number(c));
    ui->label_11->setText(QString::number((double)(100*information.all_symbols)/(information.all_symbols+information.mistakes)));
    // // qDebug() << information.time << " " << information.mistakes << " " << information.words;
}

void mainwindow::setText() {
    training_text = "";
    srand(time(0));
    QString path = "../Texts/";
    switch (current_language) {
        case 0:
        {
            path += "eng.txt";
            break;
        }
        case 1:
        {
            path += "rus.txt";
            break;
        }
        case 2:
        {
            path += "blr.txt";
            break;
        }
        case 3:
        {
            path += "de.txt";
            break;
        }
        case 4:
        {
            path += "fr.txt";
            break;
        }
        case 5:
        {
            path += "he.txt";
            break;
        }
        case 6:
        {
            path += "ar.txt";
            break;
        }
        case 7:
        {
            path += "ch.txt";
        }
    }
    QFile file(path);
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&file);
        QString text = in.readAll();
        // qDebug() << "text " << text;
        // qDebug() << text.size();
        int pos = rand() % (text.size() - 100);
        while(text[pos] != '.')
            pos --;
        pos ++;
        while(text[pos] == ' ' || text[pos] == '\n')
            pos ++;
        int all = 0;
        while(text[pos] != '.' || all < 100)
        {
            training_text += text[pos];
            pos ++;
            all ++;
        }
        training_text += ".";
        // qDebug() << training_text;
        file.close();
    }
    ui->label->setText(training_text);
    ui->label->setWordWrap(true);
    green = "";
    black = training_text;
    cur_pos = 0;
}

void mainwindow::increase_timer() {
    information.time += 1;
    QString convert_time = Convert();
    update_data();
}

void mainwindow::increase_mistake() {
    information.mistakes ++;
    update_data();
}

void mainwindow::increase_words() {
    information.words ++;
    update_data();
}

void mainwindow::show_end_game() {
    timer->stop();
    ui->widget_6->show();

    ui->comboBox->setEnabled(false);

    ui->timelabel->setText(Convert());
    ui->mistakeslabel->setText(QString::number(information.mistakes));
    double a = information.words;
    double b = (double)information.time / 10 / 60;
    double c = a / b;
    ui->speedlabel->setText(QString::number(c));
    ui->accuracylabel->setText(QString::number((double)(100*information.all_symbols)/(information.all_symbols+information.mistakes)));
    is_training = false;
}

QString mainwindow::Convert() {
    int min = information.time / 10 / 60;
    int sec = (information.time - min * 60 * 10) / 10;
    int msec = (information.time - min * 60 * 10 - sec * 10);
    return (min > 9?"":"0") + QString::number(min) + ":" + (sec > 9?"":"0") + QString::number(sec) + "." + QString::number(msec);
}

void mainwindow::open_file_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "/home", tr("Text files (*.txt)"));
    QString fileRem = fileName;
    if(fileName.size() == 0)
    {
        QMessageBox message;
        message.setText("Can't open file");
        message.exec();
        return;
    }
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadWrite);
    QTextStream fileLine(&file);
    QString text;
    while(!fileLine.atEnd()) {
        text = fileLine.readLine();
    }
    training_text = text;
    file.close();
    ui->label->setText(training_text);
    ui->label->setWordWrap(true);
    green = "";
    black = training_text;
    cur_pos = 0;
    is_training = false;
    timer->stop();
    resetWidgets();
}


