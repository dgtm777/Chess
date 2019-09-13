#ifndef FIGUREWIDGET_H
#define FIGUREWIDGET_H

#include <QLabel>
#include <QWidget>
#include <Qt>

class FigureWidget : public QLabel { 
    Q_OBJECT 

public:
    explicit FigureWidget(char color, int h_crd, int w_crd,
                          QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~FigureWidget();
    char color;
    int h_crd, w_crd;

signals:
    void clicked(FigureWidget *);

protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // FIGUREWIDGET_H
