#include "toolsbar.h"
#include  <QDebug>

toolsbar::toolsbar(QWidget *parent) : QWidget(parent)
{
    currentWidth = 1;
    isRuber = false;
    currentColor.setRgb(Qt::black);

}

void toolsbar:: changeColor(QColor selectedColor)
 {
     currentColor = selectedColor;
     qDebug()<<"its work!";

 }

void toolsbar:: changeWidth(int index)
 {
     currentWidth = index+1;
     qDebug()<<"width changed to"<< currentWidth;
 }


void toolsbar:: setBrush()
{
    isRuber = false;
}

void toolsbar:: setRuber()
{
    isRuber = true;
}

QColor toolsbar:: getColor()
{
    return this->currentColor;
}

int toolsbar:: getWidth()
{
    return this->currentWidth;
}

bool toolsbar:: getToolStatus()
{
    return this->isRuber;
}
