#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _keyboard(new VirtualKeyboard(this))
    , _analizer(new StringsAnalizer("", _keyboard, Bel, this))
{
    ui->setupUi(this);
    ui->editorsLayout->addWidget(_keyboard);
    ui->checkTextEdit->installEventFilter(_analizer);

    ui->checkTextEdit->setReadOnly(true);
    ui->accuracyBox->setReadOnly(true);
    ui->wordsBox->setReadOnly(true);
    ui->timerBox->setReadOnly(true);

    connect(ui->presetbutton, SIGNAL(clicked(bool)), SLOT(slotInsertPreset()));
    connect(ui->openbutton, SIGNAL(clicked(bool)), SLOT(slotOpenFile()));
    connect(ui->langBox, SIGNAL(currentIndexChanged(int)), SLOT(slotChangeLang(int)));
    connect(ui->startbutton, SIGNAL(clicked(bool)), SLOT(slotStartCheck()));
    connect(_analizer, SIGNAL(endCheck()), SLOT(slotFinishCheck()));
    connect(_analizer, SIGNAL(updateStat()), SLOT(slotUpdateInfo()));
    connect(_analizer, SIGNAL(textChanged(QChar)), SLOT(slotColorText(QChar)));

    _redF.setForeground(Qt::red);
    _greenF.setForeground(Qt::darkGreen);
    _blackF.setForeground(Qt::black);

    presets();
    ui->aimTextEdit->setText(_presets.at(_language));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::presets()
{
    _presets.at(0) = "Das Brötchen lag da und rollte dann plötzlich vom Fenster zur Bank, von der Bank zum Boden, am Boden entlang und zu den Türen, sprang über die Schwelle in den Eingang, vom Eingang zur Veranda, von der Veranda zur der Hof, vom Hof ​​durch das Tor, immer weiter.";
    _presets.at(1) = "Le chignon est resté là, puis a soudainement roulé de la fenêtre au banc, du banc au sol, le long du sol et jusqu'aux portes, a sauté par-dessus le seuil de l'entrée, de l'entrée au porche, du porche à la cour, de la cour à la porte, encore et encore.";
    _presets.at(2) = "كانت الكعكة مستلقية هناك، ثم تدحرجت فجأة من النافذة إلى المقعد، من المقعد إلى الأرض، على طول الأرض وإلى الأبواب، قفزت فوق العتبة إلى المدخل، من المدخل إلى الشرفة، من الشرفة إلى الفناء، من الفناء عبر البوابة، مرارًا وتكرارًا.";
    _presets.at(3) = "Mianbaoren tangle yihuir, ranhou turan cong chuanghu gun dao changdeng shang, cong changdeng gun dao diban shang, yanzhe diban gun dao menkou, tiaoguo menkan dao qianting, cong qianting gun dao menlang, cong menlang gun dao yuanzi, cong yuanzi gun dao damen wai, yue gun yue yuan.";
    _presets.at(4) = "Калабок паляжаў, ды раптам і пакаціўся з акна на лаўку, з лаўкі на падлогу, па падлозе ды да дзвярэй, пераскочыў цераз парог у сенцы, з сенцаў на ганак, з ганка на двор, з двара за вароты, далей і далей.";
    _presets.at(5) = "הלחמנייה שכבה שם, ואז פתאום התגלגלה מהחלון לספסל, מהספסל לרצפה, לאורך הרצפה ואל הדלתות, קפצה מעל הסף לתוך הכניסה, מהכניסה למרפסת, מהמרפסת למרפסת. החצר, מהחצר דרך השער, הלאה והלאה.";
}

bool MainWindow::isReadOnly() const
{
    return _isReadOnly;
}

void MainWindow::setReadOnly(bool newStatus)
{
    _isReadOnly = newStatus;

    ui->presetbutton->setEnabled(!newStatus);
    ui->openbutton->setDisabled(newStatus);
    ui->checkTextEdit->setReadOnly(!newStatus);
    ui->aimTextEdit->setReadOnly(newStatus);
}

void MainWindow::slotChangeLang(int newLangIndex)
{
    _language = static_cast<Language>(newLangIndex);
    _keyboard->setLanguage(_language);
    _analizer->setLanguage(_language);
    ui->aimTextEdit->setText(_presets.at(_language));
}

void MainWindow::slotStartCheck()
{
    if (_analizer->isRunning()) {
        _analizer->finishCheck();
        return;
    }

    setReadOnly(true);
    ui->checkTextEdit->clear();
    ui->checkTextEdit->setFocus();

    _text = ui->aimTextEdit->toPlainText();
    _charCntr = 0;

    QTextCursor cursor = ui->aimTextEdit->textCursor();
    cursor.select(QTextCursor::Document);
    cursor.mergeCharFormat(_blackF);

    _analizer->setText(ui->aimTextEdit->toPlainText());
    _analizer->slotStartCheck();
    slotUpdateInfo();
}

void MainWindow::slotFinishCheck()
{
    setReadOnly(false);
    ui->langBox->setFocus();
    slotUpdateInfo();
}

void MainWindow::slotColorText(QChar newChar)
{
    QTextCursor cursor(ui->aimTextEdit->document());
    cursor.setPosition(_charCntr, QTextCursor::MoveAnchor);

    cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    if (ui->aimTextEdit->toPlainText().at(_charCntr) == newChar){
        cursor.mergeCharFormat(_greenF);
    } else {
        cursor.mergeCharFormat(_redF);
    }

    ++_charCntr;
}

void MainWindow::slotInsertPreset()
{
    ui->aimTextEdit->setText(_presets.at(static_cast<int>(_language)));
}

void MainWindow::slotUpdateInfo()
{
    ui->wordsBox->setValue(_analizer->words());
    ui->accuracyBox->setValue(_analizer->accuracy());
    ui->timerBox->setValue(_analizer->seconds());
}

void MainWindow::slotOpenFile()
{
    QString fileName = QFileDialog::getOpenFileName(nullptr, "Open Text File", "", "");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&file);
    _text = in.readAll();
    file.close();

    ui->aimTextEdit->setText(_text);
}

