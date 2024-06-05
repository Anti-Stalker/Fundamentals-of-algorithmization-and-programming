#include "drawergl.h"

DrawerGL::DrawerGL(QWidget *parent)
    : QOpenGLWidget(parent), _grid(nullptr)
{
}

void DrawerGL::SetGrid(Object ***grid)
{
    this->_grid = grid;
    update();
}

void DrawerGL::draw(Object ***grid)
{
    if (_is_active) {
        update();
    }
}

void DrawerGL::activate()
{
    _is_active = !_is_active;
    update();
}

void DrawerGL::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.6, 0.6, 0.6, 0);
}

void DrawerGL::paintGL() {
    if (!_grid || !_is_active) return;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < width() / CELL_SIZE; ++i) {
        for (int j = 0; j < height() / CELL_SIZE; ++j) {
            QColor color = _grid[i][j]->getColor();
            int x1 = i * CELL_SIZE;
            int y1 = j * CELL_SIZE;
            int x2 = i * CELL_SIZE + CELL_SIZE - IS_BORDER;
            int y2 = j * CELL_SIZE;
            int x3 = i * CELL_SIZE + CELL_SIZE - IS_BORDER;
            int y3 = j * CELL_SIZE + CELL_SIZE - IS_BORDER;
            int x4 = i * CELL_SIZE;
            int y4 = j * CELL_SIZE + CELL_SIZE - IS_BORDER;


            glColor3f(color.redF(), color.greenF(), color.blueF());
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
            glVertex2f(x3, y3);
            glVertex2f(x4, y4);
        }
    }
    glEnd();
}

void DrawerGL::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}
