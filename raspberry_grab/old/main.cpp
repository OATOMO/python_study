#include "grab_gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    grab_gui w;
    w.show();

return a.exec();
}
