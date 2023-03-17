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
	int minus = 0;
	int maxus = 0;
	int min = 0;
	int max = array.size() - 1;
	int mid = (min + max) / 2;
	while (min <= max)
	{
		if (array[mid] < toSearch)
		{
			min = mid + 1;
		}
		else if (array[mid] == toSearch)
		{
			if (cas == 0){
				minus=mid;
				if (array[mid]-1 == array[mid])
				{
					while (array[mid] >= toSearch)
					{
						mid--;
						minus = mid;
					}
				}
				return minus;
			}

			if (cas == 1)
			{
				maxus = mid;
				if (array[mid]+1 == array[mid])
				{
				while (array[mid] <= toSearch)
				{
					mid++;
					maxus = mid;
				}
				}
				return maxus;
			}
			
		}
		else
		{
			max = mid - 1;
		}
		mid = (min + max) / 2;
	}
	return -1;
}

void binarySearchAll(Array& array, int toSearch, int& indexMin, int& indexMax)
{

	indexMin = binarySearch(array, toSearch,0);
	//indexMax = binarySearch(array, toSearch,1);
	// do not use increments, use two different binary search loop
    //indexMin = indexMax = -1;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchAllWindow(binarySearchAll);
	w->show();

	return a.exec();
}
