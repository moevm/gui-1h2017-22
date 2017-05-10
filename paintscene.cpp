#include "paintscene.h"

PaintScene::PaintScene(const QRectF & sceneRect, QObject *parent) : QGraphicsScene(sceneRect, parent)
{
    myBrush = new toolsbar();

}

PaintScene::~PaintScene()
{

}
void PaintScene::setBrush(toolsbar *brush)
{
    myBrush = brush;
}
void PaintScene:: setBrushType(bool status)
{
    if( !status )
        brushType = new QBrush(myBrush->getColor());
    else
        brushType = new QBrush( QColor(255, 255, 255));
}

void PaintScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    setBrushType(myBrush->getToolStatus());
    // При нажатии кнопки мыши отрисовываем эллипс
    addEllipse(event->scenePos().x() - 5,
               event->scenePos().y() - 5,
               5*myBrush->getWidth(),
               5*myBrush->getWidth(),
               QPen(Qt::NoPen),
               brushType->color());
    // Сохраняем координаты точки нажатия
    previousPoint = event->scenePos();
}

void PaintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    // Отрисовываем линии с использованием предыдущей координаты
    addLine(previousPoint.x(),
            previousPoint.y(),
            event->scenePos().x(),
            event->scenePos().y(),
            QPen(brushType->color(),
                 5*myBrush->getWidth(),
                 Qt::SolidLine,
                 Qt::RoundCap));
    // Обновляем данные о предыдущей координате
    previousPoint = event->scenePos();
}
