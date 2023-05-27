#include <tp5.h>
#include <QApplication>
#include <time.h>
#include <map>
#include <string>


MainWindow* w = nullptr;


std::vector<string> TP5::names(
{
    "Yolo", "Anastasiya", "Clement", "Sirine", "Julien", "Sacha", "Leo", "Margot",
    "JoLeClodo", "Anais", "Jolan", "Marie", "Cindy", "Flavien", "Tanguy", "Audrey",
    "Mr.PeanutButter", "Bojack", "Mugiwara", "Sully", "Solem",
    "Leo", "Nils", "Vincent", "Paul", "Zoe", "Julien", "Matteo",
    "Fanny", "Jeanne", "Elo"
});


int HashTable::hash(std::string element)
{
    // use this->size() to get HashTable size
    return (int)element[0] % this->size();
}

void HashTable::insert(std::string element)
{
    int index = this->hash(element);
    this->get(index) = element;
    // use (*this)[i] or this->get(i) to get a value at index i
}

/**
 * @brief buildHashTable: fill the HashTable with given names
 * @param table table to fill
 * @param names array of names to insert
 * @param namesCount size of names array
 */
void buildHashTable(HashTable& table, std::string* names, int namesCount)
{
  for(int i=0 ; i< namesCount ; i++){
    table.insert(names[i]);
  }
}

bool HashTable::contains(std::string element)
{
    string i = element;
    return (this->get(hash(i)) == element);

}
//Je ne sais pas comment je passe autant de temps sur aussi peu de ligne ALED

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 10;
	w = new HashWindow();
	w->show();

	return a.exec();
}
