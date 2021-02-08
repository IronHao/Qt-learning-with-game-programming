#include <QApplication>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>

QGraphicsRectItem *createComplexItem(qreal width, qreal height, qreal radius);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;

//    QGraphicsRectItem *rectItem = new  QGraphicsRectItem();
//    rectItem->setRect(0, 0, 100, 50);
//    scene.setSceneRect(0, 20, 100, 100);
//    scene.addItem(rectItem);
//    QGraphicsEllipseItem *circleItem = new QGraphicsEllipseItem(QRect(0, 50, 25, 25));
//    scene.addItem(circleItem);
//    QGraphicsSimpleTextItem *textItem = new QGraphicsSimpleTextItem(QObject::tr("Demo"));
//    scene.addItem(textItem);
//    textItem->setPos(50, 50);
//    //textItem->moveBy(10, 10);
//    textItem->setRotation(-20);   // clockwise if positive number, -20 equals 340 and 450 equals 90
//    textItem->setScale(2);
//    QGraphicsView view(&scene);
//    view.setAlignment(Qt::AlignTop | Qt::AlignLeft);
//    //view.scale(5, 5);
//    //view.rotate(20);
//    view.shear(1, 0);
//    view.show();

//    scene.addLine(-100, 0, 100, 0);
//    scene.addLine(0, -100, 0, 100);
//    QGraphicsRectItem* rectItem = scene.addRect(-25, -25, 50, 50);
//    rectItem->setPos(75, 75);
//    rectItem->setTransformOriginPoint(75, 75);
//    QTransform transform;
//    transform.rotate(45);
//    rectItem->setTransform(transform);
//    rectItem->setRotation(45);
//    QGraphicsView view(&scene);
//    view.show();
//    return a.exec();

      QGraphicsRectItem *item1 = createComplexItem(100, 60, 8);
      scene.addItem(item1);

      QGraphicsRectItem *item2 = createComplexItem(100, 60, 8);
      scene.addItem(item2);
      item2->setPos(200, 0);
      item2->setRotation(20);
      QGraphicsView view(&scene);
      view.show();
      return a.exec();


}

QGraphicsRectItem *createComplexItem(qreal width, qreal height, qreal radius){
    QRectF rect(-width/2, -height/2, width, height);
    QGraphicsRectItem *parent = new QGraphicsRectItem(rect);
    QRectF circleBoundary(-radius, -radius, 2 * radius, 2 * radius);
    for(int i = 0; i < 4; i++){
        QGraphicsEllipseItem *child = new QGraphicsEllipseItem(circleBoundary, parent);
        child->setBrush(Qt::black);
        QPointF pos;
        switch(i){
        case 0:
            pos = rect.topLeft();
            break;
        case 1:
            pos = rect.bottomLeft();
            break;
        case 2:
            pos = rect.topRight();
            break;
        case 3:
            pos = rect.bottomRight();
            break;
        }
        child->setPos(pos);
    }
    return parent;
}
