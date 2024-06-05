#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QPalette>
#include <QPainter>
#include <QRandomGenerator>
#include <QTextEdit>

#include "dialog.h"
#include "initializer.h"
#include "poolgame.h"

class RulesScreen : public QWidget {
public:
    RulesScreen(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout;
        QLabel *label = new QLabel("Правила игры", this);
        label->setAlignment(Qt::AlignCenter);
        QFont font = label->font();
        font.setPointSize(30); // Устанавливаем размер шрифта
        label->setFont(font); // Применяем шрифт к надписи

        // Создаем текстовое поле для отображения правил
        QTextEdit *rulesText = new QTextEdit(this);
        rulesText->setReadOnly(true);
        QFont fontRulesText = rulesText->font();
        font.setPointSize(30); // Устанавливаем размер шрифта
        rulesText->setFont(font);
        rulesText->setPlainText("Для игры одному:\nОсновной целью является загнать все шарики в кармашки.Бить можно только белым шариком.Цвета шариков обозначают их стоимость.\nКрасный - 1 очко\nЖёлтый - 2 очка\nСиний - 3 очка\nФиолетовый - 4 очка\nОранжевый - 5 очков\nРозовый - 6 очков\nБелый - штраф 3 очка\nДля игры компанией требуется поочерёдно передавать управление, стоимость шариков остаётся прежней,однако существует два варианта выбора победителя.\nПервый вариант: победил тот,кто набрал больше всего очков после того, как на столе закончились шары.\nВторой вариант: победителем становится игрок, забивший последний шар на столе.");

        // Создаем кнопку "Назад"
        QPushButton *backButton = new QPushButton("Назад", this);
        backButton->setMinimumSize(200, 100); // Устанавливаем минимальный размер кнопки
        QFont buttonFont = backButton->font();
        buttonFont.setPointSize(30); // Устанавливаем размер шрифта
        buttonFont.setItalic(true);
        backButton->setFont(buttonFont); // Применяем шрифт к кнопке
        connect(backButton, &QPushButton::clicked, this, &QWidget::close); // Закрываем текущий экран при нажатии на кнопку "Назад"
        QPalette palette = this->palette();
        palette.setColor(QPalette::Window, QColor(255,182,193)); // RGB для нежно-розового цвета
        this->setPalette(palette);
        this->setAutoFillBackground(true);
        layout->addWidget(label);
        layout->addWidget(rulesText);
        layout->addWidget(backButton); // Добавляем кнопку в layout
        setLayout(layout);
    }
};

class StartScreen : public QWidget {
public:
    StartScreen(std::unique_ptr<PoolGame> game, QWidget *parent = nullptr)
        : QWidget(parent), m_game(std::move(game)) {
        QVBoxLayout *layout = new QVBoxLayout;
        QLabel *label = new QLabel("Бильярд", this);
        label->setAlignment(Qt::AlignCenter);
        QFont font = label->font();
        font.setPointSize(200); // Устанавливаем размер шрифта
        font.setItalic(true); // Устанавливаем шрифт курсивным
        label->setFont(font); // Применяем шрифт к надписи
        QPushButton *startButton = new QPushButton("Начать игру", this);
        startButton->setMinimumSize(200, 100); // Устанавливаем минимальный размер кнопки
        QFont buttonFont = startButton->font();
        buttonFont.setPointSize(30); // Устанавливаем размер шрифта
        buttonFont.setItalic(true);
        startButton->setFont(buttonFont); // Применяем шрифт к кнопке

        QPushButton *rulesButton = new QPushButton("Правила игры", this);
        rulesButton->setMinimumSize(200, 100); // Устанавливаем минимальный размер кнопк
        rulesButton->setFont(buttonFont); // Применяем шрифт к кнопке
        QPushButton *quitButton = new QPushButton("Выйти", this); // Добавляем кнопку "Выйти"
        quitButton->setMinimumSize(200, 100); // Устанавливаем минимальный размер кнопк
        quitButton->setFont(buttonFont); // Применяем шрифт к кнопке
        layout->addWidget(label);
        layout->addWidget(startButton);
        layout->addWidget(rulesButton);
        layout->addWidget(quitButton);
        setLayout(layout);

        // Устанавливаем фон фиолетового цвета
        QPalette Pal(palette());
        Pal.setColor(QPalette::Window, Qt::darkMagenta);
        this->setAutoFillBackground(true);
        this->setPalette(Pal);

        connect(startButton, &QPushButton::clicked, this, &StartScreen::startGame);
        connect(rulesButton, &QPushButton::clicked, this, &StartScreen::showRules);
        connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    }

    void paintEvent(QPaintEvent *) override {
        QPainter painter(this);
        for (int i = 0; i < 200; ++i) {
            int x = QRandomGenerator::global()->bounded(width());
            int y = QRandomGenerator::global()->bounded(height());
            QColor color = QColor::fromHsv(QRandomGenerator::global()->bounded(360), 255, 255);
            painter.setBrush(color);
            painter.drawEllipse(x, y, 30, 30); // Увеличиваем диаметр шариков до 30
        }
    }

private slots:
    void startGame() {
        Dialog *dialog = new Dialog(std::move(m_game));
        dialog->showMaximized();
        dialog->start();
        close();
    }
    void showRules() {
        RulesScreen *rulesScreen = new RulesScreen;
        rulesScreen->showMaximized();
    }

private:
    std::unique_ptr<PoolGame> m_game;
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    std::unique_ptr<PoolGame> game = Initializer().createPoolgame("../PoolTable/config.json");
    //if the returned game is a nullptr the json file couldn't be found or was invalid
    if (game.get() == nullptr) return a.exec();

    StartScreen w(std::move(game));
    w.showMaximized();

    return a.exec();
}
