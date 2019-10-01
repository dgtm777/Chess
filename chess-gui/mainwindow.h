#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "figurewidget.h"

class GameEngine {
public:
    bool check_turn() const;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    FigureWidget *prev_selected;
    char cur_turn;
    const int offset_h = 42, offset_w = 46;
    const float grid_h = 101.5, grid_w = 101.5;

    Ui::MainWindow *ui;
    FigureWidget* draw_figure(int h_crd, int w_crd, const QString &id);
    void mousePressEvent(QMouseEvent* event);
    QRect calc_position(int h_crd, int w_crd) const;
    QRect calc_position(const QPoint &crd) const;
    QPoint position_to_crd(const QPoint &pos) const;
    bool moveFigure(int h_crd, int w_crd);

private slots:
   void moveFigure(const QPoint &);
   void selectFigure(FigureWidget *cur_fig);

signals:
    void clicked(const QPoint &);
};

#endif // MAINWINDOW_H
