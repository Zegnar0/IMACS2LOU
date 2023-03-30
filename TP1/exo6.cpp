#include <iostream>


using namespace std;

struct Noeud{
    int donnee;
    Noeud* Next;
};

struct Liste{
    Noeud* first;
 
};

struct DynaTableau{
    int* donnees;
    int cap;
    int size =0;
  
};


void initialise(Liste* liste)
{
 liste->first = nullptr;
}

bool est_vide(const Liste* liste)
{
        if (liste->first == nullptr) {
            return true;
        }

        return false;
}

void ajoute(Liste* liste, int valeur)
{
    Noeud* New = new Noeud;
    New->donnee = valeur;
    New->Next = nullptr;
    Noeud* last = liste->first;

    if(last != nullptr){
        while (last->Next != nullptr)
        {   last = last->Next; }
        last->Next = New;
    }else{
        liste->first = New;
    }

}

void affiche(const Liste* liste)
{
    Noeud* affichage = liste->first;
    while (affichage != nullptr)
    {
        cout << affichage->donnee << ", ";
        affichage = affichage->Next;
    }
    cout << endl;
}

int recupere(const Liste* liste, int n)
{
    Noeud* Get = liste->first;
    for(int i = 0; i < n; i++){
        Get = Get->Next;
    }
    return Get->donnee;
    return 0;
}

int cherche(const Liste* liste, int valeur)
{
    Noeud* Search = liste->first;
    int count = 1;
    while(Search->donnee != valeur && Search != nullptr){
        Search = Search->Next;
        count++;
    }
    if(Search == nullptr){
        return -1;
    }else{
        return count;
    }
}

void stocke(Liste* liste, int n, int valeur)
{
    Noeud* Put = liste->first;
    int i = 1;

    while(i!=n && Put != nullptr){
        Put = Put->Next;
        i++;
    }
    if(Put != nullptr){
        Put->donnee = valeur;
    }
}

void ajoute(DynaTableau* tableau, int valeur)
{
    if(tableau->size >= tableau->cap){

        tableau->cap = tableau->cap*2;

        int* Dyn = new int[tableau->cap];
        for(int i = 0; i < tableau->size; i++) {
            Dyn[i] = tableau->donnees[i];
        }
        delete[] tableau->donnees;
        tableau->donnees = Dyn;
    }

    tableau->donnees[tableau->size] = valeur;
    tableau->size = tableau->size + 1;
}


void initialise(DynaTableau* tableau, int capacite)
{
    tableau->donnees = new int[capacite];

    tableau->cap = capacite;
    tableau->size=0;

}

bool est_vide(const DynaTableau* tableau)
{
    if(tableau->donnees != nullptr){
        return false;
    }
    return true;
}

void affiche(const DynaTableau* tableau)
{
    cout << endl << "Le Tab  " << endl;
    for(int i=0; i<tableau->size; i++){
        cout << tableau->donnees[i] << endl;
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    int value = 0;
    for(int i=0; i<tableau->size; i++){
        if(value == n){
            return tableau->donnees[i];
        }
        value++;
    }
}

int cherche(const DynaTableau* tableau, int valeur)
{
    for(int i=0; i<tableau->size; i++){
        if(tableau->donnees[i] == valeur){
            return i;
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    int i;
    for(i=0; i<n; i++){
    }
    tableau->donnees[i] = valeur;
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
{
    if(liste->first == nullptr) {
        liste->first = new Noeud {valeur, nullptr};
        return;
    }

    Noeud* mdf = liste->first;
    while(mdf->Next != nullptr){
        mdf = mdf->Next;
    }
    mdf->Next = new Noeud {valeur, nullptr};

}

//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    int Dele = 0;
    if (liste != nullptr)
    {
        Noeud* mdf = liste->first->Next;
        Dele = liste->first->donnee;
        free(liste), liste->first = nullptr;
        liste->first = mdf;
    }
    return Dele;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{
    ajoute(liste, valeur);

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
   Noeud *Out = liste->first;
    int valeur;
    if(Out != nullptr && Out->Next == nullptr){
        valeur = Out->donnee;
        delete Out;
        liste->first = nullptr;
        return valeur;
    }
    if(Out != nullptr && Out->Next != nullptr){
        while (Out->Next->Next != nullptr)
        {
            Out = Out->Next;
        }
        valeur = Out->Next->donnee;

        delete Out->Next;
        Out->Next = nullptr;
        return valeur;
    }else{
        return -1;
    }
}


int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
