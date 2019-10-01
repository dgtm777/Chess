#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figurewidget.h"
#include <QtSvg/QSvgRenderer>
#include <QPainter>
#include <QTextStream>
#include <QMouseEvent>

QRect MainWindow::calc_position(const QPoint &crd) const
{
    return calc_position(crd.y(), crd.x());
}

QRect MainWindow::calc_position(int h_crd, int w_crd) const
{
    return QRect(int(offset_w + grid_w * w_crd),
                 int(offset_h + grid_h * h_crd),
                 int(grid_w), int(grid_h));
}

QPoint MainWindow::position_to_crd(const QPoint &pos) const
{
    int h_crd = (pos.y() - offset_h) / grid_h;
    int w_crd = (pos.x() - offset_w) / grid_w;
    return QPoint(w_crd, h_crd);
}


void MainWindow::moveFigure(const QPoint &pos)
{
    QPoint crd = position_to_crd(pos);
    moveFigure(crd.y(), crd.x());
}

bool MainWindow::moveFigure(int h_crd, int w_crd)
{
    if (prev_selected == nullptr) {
        return false;
    }
    // check turn
    prev_selected->setGeometry(calc_position(h_crd, w_crd));
    prev_selected->h_crd = h_crd;
    prev_selected->w_crd = w_crd;
    prev_selected->setStyleSheet("border: 0px solid red;");
    prev_selected = nullptr;
    cur_turn = cur_turn == 'w' ? 'b' : 'w';
    return true;
}

void MainWindow::selectFigure(FigureWidget *cur_fig)
{
    if (cur_turn != cur_fig->color) {
        if (prev_selected) {
            moveFigure(cur_fig->h_crd, cur_fig->w_crd);
            delete cur_fig;
        }
        return;
    }
    if (prev_selected) {
        prev_selected->setStyleSheet("border: 0px solid red;");
    }
    if (prev_selected != cur_fig) {
        prev_selected = cur_fig;
        cur_fig->setStyleSheet("border: 3px solid red;");
    } else {
        prev_selected = nullptr;
    }
}


FigureWidget* MainWindow::draw_figure(int h_crd, int w_crd, const QString &id)
{
    QString img_file;
    QTextStream sstr(&img_file);
    sstr << ":/static/images/" << id << ".svg";
    FigureWidget* lbl = new FigureWidget(id[id.size() - 5].toLatin1(), h_crd, w_crd, this);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setFixedSize(100, 100);
    lbl->setGeometry(calc_position(h_crd, w_crd));

    QSvgRenderer renderer(img_file);
    QImage image(100, 100, QImage::Format_ARGB32);
    image.fill(0x00000000);
    QPainter painter(&image);
    renderer.render(&painter);
    QPixmap pxm;
    pxm.convertFromImage(image);
    lbl->setPixmap(pxm);
    return lbl;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->centralWidget()->setStyleSheet(
        "background-image: url(\":/static/images/board.svg\"); "
        "background-position: center; background-repeat: no-repeat;"
    );

    // TODO: enable rescaling and recalculate position by catching events

    prev_selected = nullptr;
    cur_turn = 'w';

    FigureWidget *field[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            field[i][j] = nullptr;
        }
    }

    field[0][0] = draw_figure(0, 0, "rook-black");
    field[0][1] = draw_figure(0, 1, "knight-black");
    field[0][2] = draw_figure(0, 2, "bishop-black");
    field[0][3] = draw_figure(0, 3, "queen-black");
    field[0][4] = draw_figure(0, 4, "king-black");
    field[0][5] = draw_figure(0, 5, "bishop-black");
    field[0][6] = draw_figure(0, 6, "knight-black");
    field[0][7] = draw_figure(0, 7, "rook-black");
    field[7][0] = draw_figure(7, 0, "rook-white");
    field[7][1] = draw_figure(7, 1, "knight-white");
    field[7][2] = draw_figure(7, 2, "bishop-white");
    field[7][3] = draw_figure(7, 3, "queen-white");
    field[7][4] = draw_figure(7, 4, "king-white");
    field[7][5] = draw_figure(7, 5, "bishop-white");
    field[7][6] = draw_figure(7, 6, "knight-white");
    field[7][7] = draw_figure(7, 7, "rook-white");
    for (int i = 0; i < 8; i++) {
        field[1][i] = draw_figure(1, i, "pawn-black");
        field[6][i] = draw_figure(6, i, "pawn-white");
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (field[i][j] != nullptr) {
                connect(field[i][j], SIGNAL(clicked(FigureWidget *)),
                        this, SLOT(selectFigure(FigureWidget *)));
            }
        }
    }

    connect(this, SIGNAL(clicked(const QPoint &)),
            this, SLOT(moveFigure(const QPoint &)));
}

void MainWindow::mousePressEvent(QMouseEvent* event) {
    const QPoint p = event->pos();
    emit clicked(p);
}

MainWindow::~MainWindow()
{
    delete ui;
}
