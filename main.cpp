#include "Qcalculate.h"
#include <QtWidgets/QApplication>

#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qcalculate w;
    w.show();

    test t;
    t.show();



    return a.exec();
}
