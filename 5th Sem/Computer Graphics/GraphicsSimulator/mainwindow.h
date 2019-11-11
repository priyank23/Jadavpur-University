#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include "graph.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT


public:
        vector<pair<int,int>>v;
   graph *g;
    int poly_points[10][2];
    int poly_size=0;
   int x_max;
   int y_max;
   int x_min;
   int y_min;
   const int INSIDE = 0; // 0000
   const int LEFT = 1;   // 0001
   const int RIGHT = 2;  // 0010
   const int BOTTOM = 4; // 0100
   const int TOP = 8;    // 1000

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void lineBresenham(pair<int,int>,pair<int,int>);
    void DDA(pair<int,int>,pair<int,int>);
    void parameterizedLine(pair<int,int>,pair<int,int>);
    void setPixel(int x,int y);
    void setPixel2(int x,int y);
    void setPixel3(int x,int y);
    void circleParameterized(pair<int,int>,int);
    void drawCircle(int xc, int yc, int x, int y);
    void circlePolar(pair<int,int>p,int r);
    void circleBresenham(pair<int,int>,int);
    void bresenhamEllipse(pair<int,int>p,int a,int b);
    void drawEllipse(int xc,int yc,int x,int y);
    void EllipseParametric(pair<int,int>p,int a,int b);
    bool compare(pair<int,int>,pair<int,int>);
    void scanlineFill();
    void boundaryFill(int x,int y,int z);
    void floodFill(int x,int y);
    void drawRect();
    void cohenSutherlandClip();
    int computeCode(int x, int y) ;
//    connect(graph,SIGNAL(showMousePosition(QPointF&)),this,SLOT(showMousePosition(QPointF&)));
private slots:

    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_2_pressed();

    void on_pushButton_3_pressed();

    void on_BresenhamLine_clicked();

    void on_PLine_clicked();

    void on_setCenter_pressed();

    void on_draw_circle_p_pressed();

    void on_draw_circle_polar_pressed();

    void on_draw_circle_b_pressed();

    void on_pushButton_5_clicked();

    void on_bEllipse_clicked();

    void on_PEllipse_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_booundaryFill_clicked();

    void on_floodFill_clicked();

    void on_EndPointWindow1_clicked();

    void on_EndPointWindow2_clicked();


    void on_lineClip_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_scale_clicked();

    void on_Up_clicked();

    void on_Bottom_clicked();

    void on_Left_clicked();

    void on_Riight_clicked();

    void on_pushButton_9_clicked();


    void on_Reflect_clicked();

    void on_pushButton_10_clicked();

    void on_BezierCurve_clicked();

private:
    Ui::MainWindow *ui;

public slots:
    void showMousePosition(pair<int,int>);
    void HighlightPixel(pair<int,int>);

};

#endif // MAINWINDOW_H
