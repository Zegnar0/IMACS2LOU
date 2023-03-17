#include "tp3.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;
using std::size_t;

int binarySearch(Array& array, int toSearch)
{
	
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
			return mid;
		}
		else
		{
			max = mid - 1;
		}
		mid = (min + max) / 2;
	}
	return -1;


}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 500;
	w = new BinarySearchWindow(binarySearch);
	w->show();

	return a.exec();
}
