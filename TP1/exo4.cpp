/*#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

void allEvens(Array& evens, Array& array, int evenSize, int arraySize)
{
    Context _("allEvens", evenSize, arraySize); // do not care about this, it allow the display of call stack

    // your code

    return;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new AllEvensWindow(allEvens); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}*/
#include <iostream>
using namespace std;

int allEvens(int evens[], int array[], int evenSize, int arraySize)
{
    if (arraySize == 0)
    {
        return evenSize;
    }
    else if (array[arraySize - 1] % 2 == 0)
    {
        evens[evenSize] = array[arraySize - 1];
        return allEvens(evens, array, evenSize + 1, arraySize - 1);
    }
    else
    {
        return allEvens(evens, array, evenSize, arraySize - 1);
    }


}


int main()
{
    int evens[150];
    int array[14] = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
    cout << "Result: " << allEvens(evens, array, 0, 14) << endl;
    
    
    
    
    
    return 0;
}





