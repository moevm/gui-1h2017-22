#ifndef PAINTSCENE_H
#define PAINTSCENE_H


#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>
#include "toolsbar.h"

class PaintScene : public QGraphicsScene
{

    Q_OBJECT

public:
    explicit PaintScene(const QRectF & sceneRect, QObject *parent = 0);
    void setBrush(toolsbar *brush);
    void setBrushType(bool status);
    ~PaintScene();

private:
    QPointF     previousPoint;      // Координаты предыдущей точки
    toolsbar    *myBrush;
    QBrush      *brushType;

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

};

#endif // PAINTSCENE_H
