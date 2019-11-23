#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT


public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();



signals:
  void clicked_left();
  void clicked_right();

private:
    Ui::Widget *ui;


protected:
    void paintEvent(QPaintEvent *);
    virtual void mouseReleaseEvent(QMouseEvent *e);
};

#endif // WIDGET_H
