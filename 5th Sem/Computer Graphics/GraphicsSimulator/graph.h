#ifndef GRAPH_H
#define GRAPH_H
#include <QGraphicsView>
#include <QBrush>
#include <QGraphicsItem>
#include <QMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <iostream>
#include <QWidget>
#include <utility>
#include<vector>
using namespace std;
class graph : public QGraphicsView{
    Q_OBJECT
    QGraphicsView *gv;

public:
    QPointF Buf;
    int Pix;
    int Grid;
    //int no_of_pixels;
    pair<int,int>init,final,center;
    graph(QGraphicsView *temp,int n,int m)
    {
        gv=temp;
        Pix=n;
        Grid=m;
        setGrid(n,m);

    }
//    QGraphicsScene *q;
    //QMouseEvent curPos=new QMouseEvent(QEvent::MouseButtonPress,,Qt::NoButton)
   // QGraphicsSceneHoverEvent *event=new QGraphicsSceneHoverEvent

    class MyScene: public QGraphicsScene
    {
        //Q_OBJECT
           // QGraphicsScene *child;
        graph *parent;
        public:
            MyScene(graph *p)
            {
//                QGraphicsScene::QGraphicsScene(parent);
                parent=p;
                //this->setMouseTracking(true);

            }
            void mousePressEvent(QGraphicsSceneMouseEvent *event)
            {
                if(event->scenePos().x()>=0 && event->scenePos().y()<=0)
                emit parent->HighlightPixel(pair<int,int>(event->scenePos().x()/(parent->Pix),-1*event->scenePos().y()/(parent->Pix)));
                else if(event->scenePos().y()<=0)
                emit parent->HighlightPixel(pair<int,int>((event->scenePos().x()/(parent->Pix))-1,-1*event->scenePos().y()/(parent->Pix)));
                else if(event->scenePos().x()>=0)
                emit parent->HighlightPixel(pair<int,int>((event->scenePos().x()/(parent->Pix)),(-1*event->scenePos().y()/(parent->Pix))-1));
                else
                 emit parent->HighlightPixel(pair<int,int>((event->scenePos().x()/(parent->Pix))-1,(-1*event->scenePos().y()/(parent->Pix))-1));
               //parent->setGrid(parent->Pix,parent->Grid);
               parent->setPixel3(event->scenePos().x(),event->scenePos().y());
               parent->Buf=event->scenePos();
            }
            void mouseMoveEvent(QGraphicsSceneMouseEvent *event)
            {
                if(event->scenePos().x()>=0 && event->scenePos().y()<=0)
                emit parent->sendMousePosition(pair<int,int>(event->scenePos().x()/(parent->Pix),-1*event->scenePos().y()/(parent->Pix)));
                else if(event->scenePos().y()<=0)
                emit parent->sendMousePosition(pair<int,int>((event->scenePos().x()/(parent->Pix))-1,-1*event->scenePos().y()/(parent->Pix)));
                else if(event->scenePos().x()>=0)
                emit parent->sendMousePosition(pair<int,int>((event->scenePos().x()/(parent->Pix)),(-1*event->scenePos().y()/(parent->Pix))-1));
                else
                 emit parent->sendMousePosition(pair<int,int>((event->scenePos().x()/(parent->Pix))-1,(-1*event->scenePos().y()/(parent->Pix))-1));
                //parent->point= event->scenePos();
                //std::cout<<"1\n";
            }
    };

    MyScene *q;
    void setGrid(int pix,int num)
        {
            Pix=pix;
            Grid=num;
            q=new MyScene(this);
            for(int i=-num;i<=num;i++)
            {
                for(int j=num;j>=-num;j--)
                 q->addRect(i*pix,j*pix,pix,pix,QPen(QBrush(QColor(150,150,150,255)),1));
            }
            for(int i=-num;i<=num;i++)
            {
                QGraphicsItem *item1 = q->itemAt(0, i * pix, QTransform());
                QGraphicsItem *item2 = q->itemAt(i*pix,0,QTransform());
                   QGraphicsRectItem *rect1 = qgraphicsitem_cast<QGraphicsRectItem *>(item1);
                   QGraphicsRectItem *rect2 = qgraphicsitem_cast<QGraphicsRectItem *>(item2);
                   QBrush br(Qt::SolidPattern);
                   br.setColor(Qt::lightGray);
                   rect1->setBrush(br);
                   rect2->setBrush(br);
                   rect1->update();
                   rect2->update();
            }
            gv->setScene(q);
            gv->setBackgroundBrush(QBrush(QColor(255,255,255,255), Qt::SolidPattern));
        }
    void setPixel(int x,int y)
    {
        QGraphicsItem *item = q->itemAt(x,y,QTransform());
        if(item){
        QGraphicsRectItem *rect= qgraphicsitem_cast<QGraphicsRectItem *>(item);
        rect->setBrush(QBrush(QColor(2, 36, 173,255)));
        rect->update();}
    }
    void setPixel2(int x,int y)
    {
        QGraphicsItem *item = q->itemAt(x,y,QTransform());
        if(item){
        QGraphicsRectItem *rect= qgraphicsitem_cast<QGraphicsRectItem *>(item);
        rect->setBrush(QBrush(QColor(255,255,51,255)));
        rect->update();}
    }

    void setPixel3(int x,int y)
    {
        QGraphicsItem *item = q->itemAt(x,y,QTransform());
        if(item){
        QGraphicsRectItem *rect= qgraphicsitem_cast<QGraphicsRectItem *>(item);
        rect->setBrush(QBrush(QColor(51,255,255,255)));
        rect->update();}
    }
public:
signals:
    void HighlightPixel(pair<int,int>);
    void sendMousePosition(pair<int,int>);
      //void Mouse_Pos();
public slots:
};



#endif // GRAPH_H
