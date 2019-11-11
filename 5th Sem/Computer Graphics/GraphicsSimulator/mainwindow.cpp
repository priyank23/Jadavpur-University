#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QEvent>
#include<QPointF>
#include<cmath>
#include <chrono>
#include <sutherlandpolygonClipping.h>
#include<complex>
typedef complex<double>point;
#include<reflection.h>
#define PI 3.1415926535897923846
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g=new graph(ui->MyGraph,5,30);
    ui->PixSixe->setRange(5,20);
    ui->GridSize->setRange(20,100);
    ui->ed->hide();
    ui->ld->show();
    ui->cd->hide();
    connect(g,SIGNAL(sendMousePosition(pair<int,int>)),this,SLOT(showMousePosition(pair<int,int>)));
    connect(g,SIGNAL(HighlightPixel(pair<int,int>)),this,SLOT(HighlightPixel(pair<int,int>)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::setPixel(int x0,int y0)
{
    if ((-1*g->Grid <= x0) && (x0 <= g->Grid) && (-1*g->Grid <= y0) && (y0 <=g->Grid))
    {if(y0<=0 && x0>=0) g->setPixel((x0)*g->Pix,(-1*y0)*g->Pix);
    else if(y0<=0) g->setPixel((x0)*g->Pix+1,(-1*y0)*g->Pix);
    else if(x0>=0) g->setPixel(x0*g->Pix,(-1*y0)*g->Pix);
    else g->setPixel(x0*g->Pix,(-1*y0)*g->Pix);
    }
}
void MainWindow::setPixel2(int x0,int y0)
{
    if ((-1*g->Grid <= x0) && (x0 <= g->Grid) && (-1*g->Grid <= y0) && (y0 <=g->Grid))
    {if(y0<=0 && x0>=0) g->setPixel2((x0)*g->Pix,(-1*y0)*g->Pix);
    else if(y0<=0) g->setPixel2((x0)*g->Pix+1,(-1*y0)*g->Pix);
    else if(x0>=0) g->setPixel2(x0*g->Pix,(-1*y0)*g->Pix);
    else g->setPixel2(x0*g->Pix,(-1*y0)*g->Pix);
    }
}
void MainWindow::setPixel3(int x0,int y0)
{
    if ((-1*g->Grid <= x0) && (x0 <= g->Grid) && (-1*g->Grid <= y0) && (y0 <=g->Grid))
    {if(y0<=0 && x0>=0) g->setPixel3((x0)*g->Pix,(-1*y0)*g->Pix);
    else if(y0<=0) g->setPixel3((x0)*g->Pix+1,(-1*y0)*g->Pix);
    else if(x0>=0) g->setPixel3(x0*g->Pix,(-1*y0)*g->Pix);
    else g->setPixel3(x0*g->Pix,(-1*y0)*g->Pix);
    }
}
void MainWindow::on_pushButton_clicked()
{
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    poly_size=0;
}

void MainWindow::showMousePosition(pair<int,int>p)
{
    if(p.first >= -1*g->Grid && p.first <=g->Grid && p.second>= -1*g->Grid-1 && p.second <=g->Grid )
    {ui->dispX->display(p.first);
    ui->dispY->display(p.second);}
}

void MainWindow::HighlightPixel(pair<int,int>p)
{
    if(p.first >= -1*g->Grid && p.first <=g->Grid && p.second>= -1*g->Grid && p.second <=g->Grid )
    {ui->X->display(p.first);
    ui->Y->display(p.second);}
}

void MainWindow::lineBresenham(pair<int,int>init,pair<int,int>final)
{
    int x0=init.first ;
    int y0=init.second ;
    int x1=final.first;
    int y1=final.second;
    int dx, dy;
    int stepx, stepy;
    dx = x1 - x0;
    dy = y1 - y0;
    if (dy < 0)
    {
        dy = -dy;
        stepy = -1;
    }
    else
    {
        stepy = 1;
    }
    if (dx < 0)
    {
        dx = -dx;
        stepx = -1;
    }
    else
    {
        stepx = 1;
    }
    dy <<= 1;                            /* dy is now 2*dy */
    dx <<= 1;                            /* dx is now 2*dx */
    setPixel(x0,y0);

    if (dx > dy)
    {
        int fraction = dy - (dx >> 1);
        while (x0 != x1)
        {
            x0 += stepx;
            if (fraction >= 0)
            {
                y0 += stepy;
                fraction -= dx;
            }
            fraction += dy;
            setPixel(x0,y0);
        }
    }

    else
    {
        int fraction = dx - (dy >> 1);
        while (y0 != y1)
        {
            if (fraction >= 0)
            {
                x0 += stepx;
                fraction -= dy;
            }
            y0 += stepy;
            fraction += dx;
            setPixel(x0,y0);
        }
    }
}
void MainWindow::on_pushButton_4_clicked()
{
//    g->setGrid(g->Pix,g->Grid);

    const clock_t begin_time = clock();
    DDA(g->init,g->final);
    ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");

}

void MainWindow::on_pushButton_2_pressed()
{
   g->init=make_pair(ui->X->value(),ui->Y->value());
}

void MainWindow::on_pushButton_3_pressed()
{
    g->final=make_pair(ui->X->value(),ui->Y->value());
}

void MainWindow::DDA(pair<int,int>init,pair<int,int>final)
{
    int x0=init.first;
    int x1=final.first;
    int y0=init.second;
    int y1=final.second;

    int dx=x1-x0;
    int dy=y1-y0;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float) steps;
    float Yinc = dy /(float) steps;

    float x=x0,y=y0;

    for(int i=0;i<=steps;i++)
    {
       setPixel(x,y);

        x+=Xinc;
        y+=Yinc;
    }
}

void MainWindow::parameterizedLine(pair<int,int>init,pair<int,int>final)
{
    int x0=init.first;
    int x1=final.first;
    int y0=init.second;
    int y1=final.second;

    int dx=x1-x0;
    int dy=y1-y0;

    double m=double(dy)/dx;
    double b=y1-m*x1;
    if(abs(m)<=1)
    {
        if(dx>0)
        {
            while(x0!=x1)
            {
                y0=int(m*x0+b+0.5);

               setPixel(x0,y0);

                x0++;
            }
        }

        else
        {
            while(x0!=x1)
            {
                y1=int(m*x1+b+0.5);

                setPixel(x1,y1);

                x1++;
            }
        }
    }
    else
    {
        if(dy>0)
        {
            while(y0!=y1)
            {
                x0=int(((y0-b)/m)+0.5);

                setPixel(x0,y0);

                y0++;
            }
        }
        else
        {
            while(y0!=y1)
            {
                x1=int((y1-b)/m+0.5);

                setPixel(x1,y1);

                y1++;
            }
        }
    }

    setPixel(x0,y0);
    setPixel(x1,y1);
}

void MainWindow::on_BresenhamLine_clicked()
{
//    g->setGrid(g->Pix,g->Grid);

    const clock_t begin_time = clock();

    lineBresenham(g->init,g->final);

    ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");

}

void MainWindow::on_PLine_clicked()
{
//    g->setGrid(g->Pix,g->Grid);

    const clock_t begin_time = clock();
    parameterizedLine(g->init,g->final);
    ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");

}

void MainWindow::on_setCenter_pressed()
{
    g->center=make_pair(ui->X->value(),ui->Y->value());
}

void MainWindow::on_draw_circle_p_pressed()
{
//    g->setGrid(g->Pix,g->Grid);
    const clock_t begin_time = clock();
    circleParameterized(g->center,ui->radius->value());
     ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");
}
void MainWindow::drawCircle(int xc, int yc, int x, int y)
{
    setPixel(xc+x, yc+y);
    setPixel(xc-x, yc+y);
    setPixel(xc+x, yc-y);
    setPixel(xc-x, yc-y);
    setPixel(xc+y, yc+x);
    setPixel(xc-y, yc+x);
    setPixel(xc+y, yc-x);
    setPixel(xc-y, yc-x);
}

void MainWindow::circleParameterized(pair<int,int>p,int r)
{
        double x = 0;
        double y=r;

        while(x<=r/sqrt(2))
        {
            drawCircle(p.first,p.second,round(x),round(y));
            x++;
            double temp=x*x;
            temp=r*r-temp;
            temp=pow(temp,0.5);
            y=temp;
        }
}

void MainWindow::circlePolar(pair<int,int>p,int r)
{
    int x=r,y=0;
    double theta=0,dtheta=1.0/r;
    drawCircle(p.first,p.second,x,y );
    while(x>y)
    {
        theta+=dtheta;
        x=(int)(r*std::cos(theta) + 0.5);
        y=(int)(r*std::sin(theta)+0.5);
        drawCircle(p.first,p.second,x,y);
    }
}

void MainWindow::on_draw_circle_polar_pressed()
{
//    g->setGrid(g->Pix,g->Grid);

    const clock_t begin_time = clock();
    circlePolar(g->center,ui->radius->value());
     ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");
}

void MainWindow::circleBresenham(pair<int,int>p,int r)
{
    int pk = 1 - r;
        int x=0,y = r;
        drawCircle(p.first,p.second,x,y);
        while(x <= y)
        {
            drawCircle(p.first,p.second,x,y);
            x++;
            if(pk < 0)
            {
                pk = pk + (2*x) + 1;
            }
            else
            {
                pk = pk + 2*(x-y)+4;
                y--;
            }
        }
}
void MainWindow::on_draw_circle_b_pressed()
{
//    g->setGrid(g->Pix,g->Grid);
    const clock_t begin_time = clock();
    circleBresenham(g->center,ui->radius->value());
     ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");
}
void MainWindow::drawEllipse(int xc,int yc,int x,int y)
{
    setPixel(xc+x, yc+y);
    setPixel(xc-x, yc+y);
    setPixel(xc+x, yc-y);
    setPixel(xc-x, yc-y);
}
void MainWindow::bresenhamEllipse(pair<int,int>p,int rx,int ry)
{
    float dx, dy, d1, d2, x, y;
        x = 0;
        y = ry;
        // Initial decision parameter of region 1
        d1 = (ry * ry) - (rx * rx * ry) +
                         (0.25 * rx * rx);
        dx = 2 * ry * ry * x;
        dy = 2 * rx * rx * y;

        // For region 1
        while (dx < dy)
        {

            // Print points based on 4-way symmetry
            drawEllipse(p.first,p.second,x,y);

            // Checking and updating value of
            // decision parameter based on algorithm
            if (d1 < 0)
            {
                x++;
                dx = dx + (2 * ry * ry);
                d1 = d1 + dx + (ry * ry);
            }
            else
            {
                x++;
                y--;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                d1 = d1 + dx - dy + (ry * ry);
            }
        }

        // Decision parameter of region 2
        d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
             ((rx * rx) * ((y - 1) * (y - 1))) -
              (rx * rx * ry * ry);

        // Plotting points of region 2
        while (y >= 0)
        {

            // Print points based on 4-way symmetry
           drawEllipse(p.first,p.second,x,y);

            // Checking and updating parameter
            // value based on algorithm
            if (d2 > 0)
            {
                y--;
                dy = dy - (2 * rx * rx);
                d2 = d2 + (rx * rx) - dy;
            }
            else
            {
                y--;
                x++;
                dx = dx + (2 * ry * ry);
                dy = dy - (2 * rx * rx);
                d2 = d2 + dx - dy + (rx * rx);
            }
        }
}

void MainWindow::on_pushButton_5_clicked()
{
    g->center=make_pair(ui->X->value(),ui->Y->value());
}

void MainWindow::on_bEllipse_clicked()
{
    const clock_t begin_time = clock();
    bresenhamEllipse(g->center,ui->radiusx->value(),ui->radiusy->value());
     ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");
}

void MainWindow::EllipseParametric(pair<int,int>p,int a,int b)
{
    int x=a,y=0;
    double theta=0,dtheta=1.0/a;
    if(a<b) dtheta=1.0/b;
    drawEllipse(p.first,p.second,x,y );
    while(theta<PI/2)
    {
        theta+=dtheta;
        x=(int)(a*std::cos(theta) + 0.5);
        y=(int)(b*std::sin(theta)+0.5);
        drawEllipse(p.first,p.second,x,y);
    }
}

void MainWindow::on_PEllipse_clicked()
{
    const clock_t begin_time = clock();
    EllipseParametric(g->center,ui->radiusx->value(),ui->radiusy->value());
     ui->TIME->setText(QString::fromStdString(to_string(1000*float( clock () - begin_time ) /  CLOCKS_PER_SEC))+"ms");
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    if(arg1=="Line Drawing")
    {
        ui->ld->show();
        ui->cd->hide();
        ui->ed->hide();
    }
    else if(arg1=="Circle Drawing")
    {
        ui->cd->show();
        ui->ld->hide();
        ui->ed->hide();
    }
    else if(arg1=="Ellipse Drawing")
    {
        ui->ed->show();
        ui->ld->hide();
        ui->cd->hide();
    }
}

bool MainWindow::compare(pair<int,int>x,pair<int,int>y)
{
    return(x.first>y.first);
}
void MainWindow::scanlineFill()
{
    for(int i=-g->Grid;i<=g->Grid;i++)
    {
        vector<pair<int,int>>points;
        for(int j=1*g->Grid;j>=-g->Grid;j--)
        {
            QGraphicsItem *item1 = g->q->itemAt(i*g->Pix,j*g->Pix,QTransform());
            if(item1){ QGraphicsRectItem *rect1 = qgraphicsitem_cast<QGraphicsRectItem *>(item1);
                QColor colorPix=rect1->brush().color();
                if(colorPix==QColor(2,36,173,255))
                {
                    points.push_back((make_pair(i,j)));
                }}
        }
        for(int j=0;j<points.size();j++)
        {
            cout<<points[j].first<<" "<<points[j].second<<endl;
        }
        cout<<endl;
        //,compare(pair<int,int>,pair<int,int>));
        if(points.size()>1)
        {
           //sort(points.begin(),points.end());
            int flag=0;
            for(int i=0;i<points.size()-1;i++)
            {
                pair<int,int>x(points[i].first,points[i].second);
                pair<int,int>y(points[i+1].first,points[i+1].second);
//                setPixel2(x.first,-1*x.second);
//                setPixel2(y.first,-1*y.second);
                if(x.second+1!=y.second && flag==0){
                    for(int j=x.second-1;j>y.second;j--)
                    {
                        setPixel2(x.first,-1*j);
                        cout<<j<<" "<<x.second<<endl;
                    }
                    i++;
                    flag=flag^1;
                }
                else if(x.second+1!=y.second)
                {
                    flag=flag^1;
                }
            }
        }
    }
}
/*
 * void boundaryFill4(int x, int y, int fill_color,int boundary_color)
{
    if(getpixel(x, y) != boundary_color &&
       getpixel(x, y) != fill_color)
    {
        putpixel(x, y, fill_color);
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}
*/

void MainWindow::boundaryFill(int x,int y,int z)
{
//    vector<pair<int,int>>::iterator it;
    if(std::find(v.begin(),v.end(),make_pair(x,y))!=v.end()) return;
    v.push_back(make_pair(x,y));
    QColor bc(2, 36, 173,255),fc(255,255,1,255);
    QGraphicsItem *item1 = g->q->itemAt(x*g->Pix,-1*y*g->Pix,QTransform());
    QColor colorPix;
    if(item1){ QGraphicsRectItem *rect1 = qgraphicsitem_cast<QGraphicsRectItem *>(item1);
     colorPix=rect1->brush().color();

     cout<<(colorPix!=bc)<<(colorPix!=fc)<<endl;
     if( colorPix!=bc && colorPix!=fc)
     {
         z++;
 //        if(z>=10) return;
         setPixel2(x,y);
//         cout<<x<<" "<<y;
         boundaryFill(x+1,y,z);
         boundaryFill(x,y+1,z);
         boundaryFill(x-1,y,z);
         boundaryFill(x,y-1,z);
         return;
     }
    return;}
}

void MainWindow::floodFill(int x,int y)
{
    boundaryFill(x,y,0);
//    if(std::find(v.begin(),v.end(),make_pair(x,y))!=v.end()) return;
//    v.push_back(make_pair(x,y));
//    cout<<x<<" "<<y;
//    QGraphicsItem *item1 = g->q->itemAt(x*g->Pix,-1*y*g->Pix,QTransform());
//    QColor colorPix;
//    if(item1){ QGraphicsRectItem *rect1 = qgraphicsitem_cast<QGraphicsRectItem *>(item1);
//     colorPix=rect1->brush().color();

//     cout<<(colorPix!=bc)<<(colorPix!=fc)<<endl;
//     if( colorPix==QColor(112,179,129,255) || colorPix==QColor(Qt::lightGray))
//     {
// //        if(z>=10) return;
//         setPixel2(x,y);

//         floodFill(x+1,y);
//         floodFill(x,y+1);
//         floodFill(x-1,y);
//         floodFill(x,y-1);
//         return;
//     }
//    return;
//    }
}

void MainWindow::on_pushButton_6_clicked()
{
    scanlineFill();
}

void MainWindow::on_booundaryFill_clicked()
{
    v.clear();
    int x=ui->X->value(),y=ui->Y->value();
    v.push_back(make_pair(x,y));
    setPixel2(x,y);
    boundaryFill(x+1,y,0);
    boundaryFill(x,y+1,0);
    boundaryFill(x-1,y,0);
    boundaryFill(x,y-1,0);
   // boundaryFill(ui->X->value(),ui->Y->value(),1);
}


void MainWindow::on_floodFill_clicked()
{
    cout<<"1"<<endl;
    v.clear();
    int x=ui->X->value(),y=ui->Y->value();
    cout<<x<<" "<<y;
    v.push_back(make_pair(x,y));
    setPixel2(x,y);

    floodFill(x+1,y);
    floodFill(x,y+1);
    floodFill(x-1,y);
    floodFill(x,y-1);
}


// Defining x_max, y_max and x_min, y_min for
// clipping rectangle. Since diagonal points are
//enough to define a rectangle
//const int x_max = 10;
//const int y_max = 8;
//const int x_min = 4;
//const int y_min = 4;

// Function to compute region code for a point(x, y)
int MainWindow::computeCode(int x, int y)
{
    // initialized as being inside
    int code = INSIDE;

    if (x < x_min)       // to the left of rectangle
        code |= LEFT;
    else if (x > x_max)  // to the right of rectangle
        code |= RIGHT;
    if (y < y_min)       // below the rectangle
        code |= BOTTOM;
    else if (y > y_max)  // above the rectangle
        code |= TOP;

    return code;
}
  void MainWindow::drawRect()
  {
//      x_max=p1.first;
//      y_max=p1.second;
//      x_min=p2.first;
//      y_min=p2.second;
      pair<int,int>p1(make_pair(x_max,y_max));
      pair<int,int>p2(make_pair(x_min,y_min));
      DDA(p1,make_pair(p2.first,p1.second));
      DDA(p1,make_pair(p1.first,p2.second));
      DDA(p2,make_pair(p1.first,p2.second));
      DDA(p2,make_pair(p2.first,p1.second));
  }
// Implementing Cohen-Sutherland algorithm
// Clipping a line from P1 = (x2, y2) to P2 = (x2, y2)
void MainWindow::cohenSutherlandClip()
{
    int x1=g->init.first, y1=g->init.second,x2=g->final.first, y2=g->final.second;
    // Compute region codes for P1, P2
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    g->setGrid(g->Pix,g->Grid);
    drawRect();
    // Initialize line as outside the rectangular window
    bool accept = false;

    while (true)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            // If both endpoints lie within rectangle
            accept = true;
            break;
        }
        else if (code1 & code2)
        {
            // If both endpoints are outside rectangle,
            // in same region
            break;
        }
        else
        {
            // Some segment of line lies within the
            // rectangle
            int code_out;
            int x, y;

            // At least one endpoint is outside the
            // rectangle, pick it.
            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            // Find intersection point;
            // using formulas y = y1 + slope * (x - x1),
            // x = x1 + (1 / slope) * (y - y1)
            if (code_out & TOP)
            {
                // point is above the clip rectangle
                x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
                y = y_max;
            }
            else if (code_out & BOTTOM)
            {
                // point is below the rectangle
                x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
                y = y_min;
            }
            else if (code_out & RIGHT)
            {
                // point is to the right of rectangle
                y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
                x = x_max;
            }
            else if (code_out & LEFT)// Defining code_out & LEFT)
            {
                // point is to the left of rectangle
                y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
                x = x_min;
            }

            // Now intersection point x,y is found
            // We replace point outside rectangle
            // by intersection point
            if (code_out == code1)
            {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }
    if (accept)
    {
        DDA(make_pair(x1,y1),make_pair(x2,y2));
    }
    else
        cout << "Line rejected" << endl;
}

void MainWindow::on_EndPointWindow1_clicked()
{
    x_max=ui->X->value();
    y_max=ui->Y->value();
}

void MainWindow::on_EndPointWindow2_clicked()
{
    x_min=ui->X->value();
    y_min=ui->Y->value();
}

void MainWindow::on_lineClip_clicked()
{
    cohenSutherlandClip();
}

void MainWindow::on_pushButton_7_clicked()
{
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
//    drawRect();
    poly_size--;
    suthHodgClip(poly_points,poly_size,make_pair(x_max,y_max),make_pair(x_min,y_min));
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
    scanlineFill();
    poly_size=0;
}

void MainWindow::on_pushButton_8_clicked()
{
    poly_points[poly_size][0]=ui->X->value();
    poly_points[poly_size++][1]=ui->Y->value();
}

void MainWindow::on_scale_clicked()
{
    float s[2][2]={ui->XScale->text().toDouble(),0,0,ui->YScale->text().toDouble()};

    for(int x=0;x<poly_size;x++)
    {
//        poly_points[i][0]*=ui->XScale->text().toLong();
//        poly_points[i][1]*=ui->YScale->text().toLong();

        float temp[1][2] = { 0 };

            for (int i = 0; i < 1; i++)
                for (int j = 0; j < 2; j++)
                    for (int k = 0; k < 2; k++)
                        temp[i][j] += (s[k][j] * poly_points[x+i][k]);

            poly_points[x][0] = temp[0][0];
            poly_points[x][1] = temp[0][1];
    }
     g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}

void MainWindow::on_Up_clicked()
{
    for(int i=0;i<poly_size;i++)
    {
        poly_points[i][1]+=1;
    }
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}

void MainWindow::on_Bottom_clicked()
{
    for(int i=0;i<poly_size;i++)
    {
        poly_points[i][1]-=1;
    }
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}


void MainWindow::on_Left_clicked()
{
    for(int i=0;i<poly_size;i++)
    {
        poly_points[i][0]-=1;
    }
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}

void MainWindow::on_Riight_clicked()
{
    for(int i=0;i<poly_size;i++)
    {
        poly_points[i][0]+=1;
    }
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}

void MainWindow::on_pushButton_9_clicked()
{
    float x=ui->X->value(),y=ui->Y->value();
    float radian=(ui->Angle->text().toLong()*PI)/180;

    float t,v;
    for(int i=0;i<poly_size;i++)
    {
        t=poly_points[i][0]-x;
        v=poly_points[i][1]-y;
        poly_points[i][0]=x+floor(t*cos(radian)-v*sin(radian));
        poly_points[i][1]=y+floor(v*cos(radian)+t*sin(radian));
    }
    g->setGrid(ui->PixSixe->value(),ui->GridSize->value());
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}


void MainWindow::on_Reflect_clicked()
{
    for(int i=0;i<poly_size;i++)
    {
        point p(poly_points[i][0],poly_points[i][1]);
        point a(g->init.first,g->init.second);
        point b(g->final.first,g->final.second);

        point news=reflect(p,a,b);
        poly_points[i][0]=news.real();
        poly_points[i][1]=news.imag();
    }
    for (int i=0; i < poly_size; i++)
        DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}

void MainWindow::on_pushButton_10_clicked()
{
    for(int i=0;i<poly_size;i++) DDA(make_pair(poly_points[i][0],poly_points[i][1]),make_pair(poly_points[(i+1)%poly_size][0],poly_points[(i+1)%poly_size][1]));
}
int ncr(int n,int r)
{
    int num=1,den=1;
    for(int i=n-r+1;i<=n;i++)
        num*=i;
    for(int i=1;i<=r;i++)
        den*=i;
    return (int)(num/den);
}
void MainWindow::on_BezierCurve_clicked()
{
    double t=0;
    for(t=0;t<=1;t+=0.0001)
    {
        double sumx=0,sumy=0;
        for(int i=0;i<poly_size;i++)
        {
            cout<<ncr(poly_size-1,i)<<'\t'<<poly_points[i][0]<<'\t'<<poly_points[i][1];
            sumx+=ncr(poly_size-1,i)*pow(1-t,poly_size-1-i)*pow(t,i)*poly_points[i][0];
            sumy+=ncr(poly_size-1,i)*pow(1-t,poly_size-1-i)*pow(t,i)*poly_points[i][1];
        }
      setPixel((int)sumx,(int)sumy);
    }
}
