#include "widget.h"
#include "dialog.h"
#include <QApplication>


extern int start;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("E:\\temp.txt");

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        if(in.read(1) == "1")
        {
            start = 1;
        }
        else
        {
            Dialog d;
            d.show();
            a.exec();
        }
    }
    else
    {
        Dialog d;
        d.show();
        a.exec();
    }
    if(start)
    {
        Widget w;
        w.show();
        a.exec();
    }

    return 0;
}
