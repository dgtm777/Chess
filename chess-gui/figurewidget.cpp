#include "figurewidget.h"

FigureWidget::FigureWidget(char col, int h_crd_, int w_crd_, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    h_crd = h_crd_;
    w_crd = w_crd_;
    color = col;
}

FigureWidget::~FigureWidget() {}

void FigureWidget::mousePressEvent(QMouseEvent* event)
{
    emit clicked(this);
}
