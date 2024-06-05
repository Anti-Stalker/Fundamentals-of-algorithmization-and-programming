#ifndef RATING_H
#define RATING_H

#include <QWidget>

namespace Ui {
class Rating;
}

class Rating : public QWidget {
  Q_OBJECT

 public:
  explicit Rating(QWidget *parent = nullptr);
  ~Rating() override;

 private:
  Ui::Rating *ui;
};

#endif  // RATING_H
