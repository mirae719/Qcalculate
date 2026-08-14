#include "Qcalculate.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Qcalculate w;
    w.show();

    return a.exec();
}
