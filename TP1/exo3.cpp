/*#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);


int search(int value, Array& toSort, int size)
{
    Context _("search", value, size); // do not care about this, it allow the display of call stack

    // your code
    // check the last cell and if it does not correspond
    // then consider a smaller array when recalling search
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new SearchWindow(search); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}
*/
#include <iostream>
using namespace std;

int search(int value, int Array[], int size)
{
    if (size == 0)
    {
        return -1;
    }
    else if (Array[size - 1] == value)
    {
        return size - 1;
    }
    else
    {
        return search(value, Array, size - 1);
    }
}

int main()
{

    int Array[150] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
    int value;
    cout << "Enter value: ";
    cin >> value;
    cout << "Result: " << search(value, Array, 5) << endl;
    
    
    return 0;
}





