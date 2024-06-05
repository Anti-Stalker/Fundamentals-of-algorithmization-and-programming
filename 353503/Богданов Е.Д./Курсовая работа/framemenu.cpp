#include "framemenu.h"

FrameMenu::FrameMenu(QWidget *parent) : QFrame(parent) {}

void FrameMenu::paintEvent(QPaintEvent *event) {
  const int sizeName = 50, point_for_name_x = 80, point_for_name_y = 270;

  Q_UNUSED(event);

  QPainter painter(this);

  painter.setPen("color: lightgrey");

  painter.setRenderHint(QPainter::Antialiasing);

  QFont font("Arial", sizeName, QFont::Bold);
  painter.setFont(font);

  painter.drawText(point_for_name_x, point_for_name_y, "Ark Nova");
}
