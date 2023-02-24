#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
	Array& sorted=w->newArray(toSort.size());
	
	for(int i=0; i<toSort.size(); i++){
		int val = toSort[i];
		int j = i-1;
		while( j>=0 && sorted[j]> val){
			sorted[j+1] = sorted[j];
			j = j-1;
		}
		sorted [j+1] = val;
	}
	// insertion sort from toSort to sorted
	
	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
