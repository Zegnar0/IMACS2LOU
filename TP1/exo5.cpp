#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point)
{
    if (n > 0){
        int mod = sqrt(z.x * z.x + z.y * z.y);
        if (mod > 2){
            return n;
        }
        else{
            Point z_more;
            z_more.x = (z.x * z.x - z.y * z.y) + point.x;
            z_more.y = (2 * z.x * z.y) + point.y;
            return isMandelbrot(z_more, n - 1, point);
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}