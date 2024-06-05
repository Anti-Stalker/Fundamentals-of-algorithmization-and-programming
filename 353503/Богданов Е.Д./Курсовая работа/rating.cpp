#include "rating.h"

#include "ui_rating.h"

Rating::Rating(QWidget *parent) : QWidget(parent), ui(new Ui::Rating) {
  ui->setupUi(this);

}

Rating::~Rating() { delete ui; }
/*


*/
