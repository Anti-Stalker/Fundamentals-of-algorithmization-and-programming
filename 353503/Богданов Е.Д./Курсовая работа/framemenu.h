#ifndef FRAMEMENU_H
#define FRAMEMENU_H

#include <QFrame>
#include <QPainter>

class FrameMenu : public QFrame {
 public:
  explicit FrameMenu(QWidget* parent = nullptr);
  void paintEvent(QPaintEvent* event) override;
};

#endif  // FRAMEMENU_H
