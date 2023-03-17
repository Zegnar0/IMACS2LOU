#include "tp4.h"
#include "mainwindow.h"

#include <QApplication>
#include <time.h>
#include <stdio.h>

MainWindow* w = nullptr;
using std::size_t;
using std::string;

int Heap::leftChildIndex(int nodeIndex)
{

	return nodeIndex * 2 + 1;
}

int Heap::rightChildIndex(int nodeIndex)
{
	return 	nodeIndex * 2 + 2;
}

void Heap::insertHeapNode(int heapSize, int value)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i = heapSize;
	(*this)[i] = value;
	while (i > 0 && (*this)[i] > (*this)[(i - 1) / 2]) {
		int temp = (*this)[i];
		(*this)[i] = (*this)[(i - 1) / 2];
		(*this)[(i - 1) / 2] = temp;
		i = (i - 1) / 2;

}
}

void Heap::heapify(int heapSize, int nodeIndex)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int i_max = nodeIndex;
	int i_left = leftChildIndex(nodeIndex);
	int i_right = rightChildIndex(nodeIndex);
	if (i_left < heapSize && (*this)[i_left] > (*this)[i_max]) {
		i_max = i_left;
	}
	if (i_right < heapSize && (*this)[i_right] > (*this)[i_max]) {
		i_max = i_right;
	}
	if (i_max != nodeIndex) {
		int temp = (*this)[i_max];
		(*this)[i_max] = (*this)[nodeIndex];
		(*this)[nodeIndex] = temp;
		heapify(heapSize, i_max);
	}
	
}

void Heap::buildHeap(Array& numbers)
{
	// use (*this)[i] or this->get(i) to get a value at index i
	for (int i = 0; i < numbers.size(); i++) {
		insertHeapNode(i, numbers[i]);
	}
}

void Heap::heapSort()
{
	// use (*this)[i] or this->get(i) to get a value at index i
	int heapSize = this->size();
	for (int i = heapSize - 1; i > 0; i--) {
		int temp = (*this)[0];
		(*this)[0] = (*this)[i];
		(*this)[i] = temp;
		heapSize--;
		heapify(heapSize, 0);
	}

}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    MainWindow::instruction_duration = 50;
    w = new HeapWindow();
	w->show();

	return a.exec();
}
