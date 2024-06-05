#include "productwidget.h"
#include "ui_productwidget.h"

ProductWidget::ProductWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductWidget)
{
    ui->setupUi(this);

    arrLabelPriceShop.push_back(ui->labelPriceFirstShop);
    arrLabelPriceShop.push_back(ui->labelPriceSecondShop);
    arrLabelPriceShop.push_back(ui->labelPriceThirdShop);
    arrLabelPriceShop.push_back(ui->labelPriceFourthShop);
    arrLabelPriceShop.push_back(ui->labelPriceFifthShop);
    arrLabelPriceShop.push_back(ui->labelPriceSixthShop);
    arrLabelPriceShop.push_back(ui->labelPriceSeventhShop);

    arrLabelShop.push_back(ui->labelShop_1);
    arrLabelShop.push_back(ui->labelShop_2);
    arrLabelShop.push_back(ui->labelShop_3);
    arrLabelShop.push_back(ui->labelShop_4);
    arrLabelShop.push_back(ui->labelShop_5);
    arrLabelShop.push_back(ui->labelShop_6);
    arrLabelShop.push_back(ui->labelShop_7);

    ui->label->setAlignment(Qt::AlignCenter);



    setAppearance();

    this->setWindowFlags(Qt::WindowStaysOnTopHint |
                         Qt::WindowSystemMenuHint |
                         Qt::FramelessWindowHint|
                         Qt::Window |
                         Qt::Popup);
}

void ProductWidget::setAppearance() {
    QFont* fontPrice = new QFont();
    QFont* font = new QFont();
    font->setPointSize(10);
    font->setBold(true);
    fontPrice->setPointSize(13);
    ui->nameProduct->setFont(*font);
    ui->categoryProduct->setFont(*font);
    for(int i = 0; i < 7; i++) {
        arrLabelShop[i]->setFont(*font);
        arrLabelPriceShop[i]->setFont(*fontPrice);
    }
}
void ProductWidget::add(Product* product) {
    if(product->getName() != " " && product->getBestPrice() != 0) {
        ui->nameProduct->setText(product->getName());

        for(int i = 0; i < 7; i++) {
            if(product->getArrPrice()[i] == product->getBestPrice()) {
                setBestPrice(i, product->getArrPrice()[i]);
            }
            else {
                setPrice(i, product->getArrPrice()[i]);
            }
        }

        QPixmap picture = product->getPicture();

        picture = picture.scaled(ui->label->size(), Qt::KeepAspectRatio);

        ui->label->setPixmap(picture);

        this->move(MOVING_WIDGET_X_CENTRE,MOVING_WIDGET_Y_CENTRE);
        this->show();
    }
}


void ProductWidget::setBestPrice(int number, double price) {
    arrLabelShop[number]->setStyleSheet("QLabel { color : red; }");
    arrLabelPriceShop[number]->setStyleSheet("QLabel { color : red; }");
    arrLabelPriceShop[number]->setText((price == -1) ? "—" : StringProcessing::additionPrice(QString::number(price)));
}

ProductWidget::~ProductWidget()
{
    delete ui;
}

void ProductWidget::setPrice(int number, double price) {
    arrLabelShop[number]->setStyleSheet("QLabel { color : black; }");
    arrLabelPriceShop[number]->setStyleSheet("QLabel { color : black; }");
    arrLabelPriceShop[number]->setText((price == -1) ? "—" : StringProcessing::additionPrice(QString::number(price)));
}
