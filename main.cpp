#include <QTextStream>

#include "widget.h"
#include <QApplication>
#include <field.h>
#include <QPaintDevice>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();



    Field f(7,7);
    f.Field_generation(10);
    f.Print_field();

   // system("pause>>NULL");
    return a.exec();
}
