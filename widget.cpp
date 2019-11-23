#include "widget.h"
#include "ui_widget.h"
#include <QMouseEvent>
#include <field.h>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    int n =7, m = 7;
    Field m_field(n,m);

    m_field.Field_generation(10);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
//            connect(m_field.field.at(i).at(j), SIGNAL(clicked_left()), this, SLOT(on_DotClickedLeft()));
//            connect(m_field[i][j], SIGNAL(clicked_right()), this, SLOT(on_DotClickedRight()));
        }
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::mouseReleaseEvent(QMouseEvent *e)
{

  if (e->button() == Qt::LeftButton) emit clicked_left();
  if (e->button() == Qt::LeftButton) qDebug() << "нажата левая кнопка мыши" << endl;
  if (e->button() == Qt::RightButton) emit clicked_right();
}

void Widget::paintEvent(QPaintEvent *event)
{

 QPainter painter(this); //новый объект "рисовальщика"
 painter.setPen (QPen(Qt::red,Qt::SolidLine));
  //создать и установить перо - красная сплошная линия
 painter.drawLine(0,0,width(),height());
  //нарисовать линию через рабочую область формы
 painter.setBrush(QBrush(Qt::green,Qt::SolidPattern));
  //создать и установить кисть - зелёная слошная заливка
 QPoint center(width()/2,height()/2);
 int rad = qMin(width()/4,height()/4);
 painter.drawEllipse(center,rad,rad);
  //нарисовать окружность по центру
 painter.setFont(QFont("sans-serif",-1,10));
  //установить шрифт заданного начертания и размера 10 пт
 QRect rect(center.x()-rad,center.y()-rad,rad*2,rad*2);
 painter.drawText(rect, Qt::AlignCenter, tr("Hello,\nworld!"));
  //вывели строку текста, выравненную по центру
}
