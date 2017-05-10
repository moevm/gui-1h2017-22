#ifndef TOOLSBAR_H
#define TOOLSBAR_H

#include <QWidget>

class toolsbar : public QWidget
{
    Q_OBJECT
private:

    QColor  currentColor;
    int     currentWidth;
    bool    isRuber;

public:
    explicit toolsbar(QWidget *parent = 0);
    void changeColor(QColor selectedColor);
    QColor getColor();
    int getWidth();
    bool getToolStatus();

signals:

public slots:

    void changeWidth(int index);
    void setBrush();
    void setRuber();
};

#endif // TOOLSBAR_H
