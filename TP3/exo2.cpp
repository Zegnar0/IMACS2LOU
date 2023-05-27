#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

/**
 * @brief define indexMin and indexMax as the first and the last index of toSearch
 * @param array array of int to process
 * @param toSearch value to find
 * @param indexMin first index of the value to find
 * @param indexMax last index of the value to find
 * 
 */

int binarySearch(Array &array, int toSearch,bool cas)
{
	int min = 0;
	int max = array.size();
	int mid = (min + max) / 2;
	while (min < max)
	{
		mid = (min + max) / 2;
		if(toSearch < array[mid]){
            max = mid;
        }
		else if(toSearch > array[mid]){
            min = mid + 1;
        }
		else
		{
			int ind = mid;
            return ind;
		}
	}
	return -1;
}

void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{
	indexMin = indexMax = -1;
    int min = 0;
    int max = array.size();
    while(min <= max) {
        int mid = (min+max)/2;
        int midValue = array[mid];
        if(midValue<toSearch) {
            min = mid + 1;
        } else if (midValue>toSearch) {
            max = mid - 1;
        } else {
            indexMin = mid;
            max = mid - 1;
        }
    }

    min = 0;
    max = array.size()-1;
    while(min <= max) {
        int mid = (min+max)/2;
        int midValue = array[mid];
        if (midValue < toSearch) {
            min = mid + 1;
        } else if (midValue > toSearch) {
            max = mid - 1;
        } else {
            indexMax = mid;
            min = mid + 1;
        }
    }

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
