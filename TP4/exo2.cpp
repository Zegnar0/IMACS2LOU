#include <time.h>
#include <stdio.h>
#include <QApplication>
#include <QDebug>

#include "tp3.h"
#include "tp4.h"
#include "tp4_exo2.h"
#include "HuffmanNode.h"

_TestMainWindow* w1 = nullptr;
using std::size_t;
using std::string;

void processCharFrequences(string data, Array& frequences);
void buildHuffmanHeap(const Array& frequences, HuffmanHeap& priorityMinHeap, int& heapSize);
HuffmanNode* makeHuffmanSubTree(HuffmanNode* rightNode, HuffmanNode* leftNode);
HuffmanNode* buildHuffmanTree(HuffmanHeap& priorityMinHeap, int heapSize);

string huffmanEncode(const string& toEncode, HuffmanNode* huffmanTree);
string huffmanDecode(const string& toDecode, const HuffmanNode& huffmanTreeRoot);


void main_function(HuffmanNode*& huffmanTree)
{
    string data = "Ouesh, bien ou bien ? Ceci est une chaine de caracteres sans grand interet";

    // this array store each caracter frequences indexed by their ascii code
    Array characterFrequences(256);
    characterFrequences.fill(0);
    // this array store each caracter code indexed by their ascii code
    string characterCodes[256];
    HuffmanHeap priorityMinHeap;
    int heapSize = 0;

    processCharFrequences(data, characterFrequences);
    displayCharacterFrequences(characterFrequences);
    buildHuffmanHeap(characterFrequences, priorityMinHeap, heapSize);
    qDebug() << priorityMinHeap.toString().toStdString().c_str();

    huffmanTree = buildHuffmanTree(priorityMinHeap, heapSize);
    huffmanTree->processCodes("");
    string encoded = huffmanEncode(data, huffmanTree);
    string decoded = huffmanDecode(encoded, *huffmanTree);

    qDebug("Encoded: %s\n", encoded.c_str());
    qDebug("Decoded: %s\n", decoded.c_str());
}


void processCharFrequences(string data, Array& frequences)
{
    
    frequences.fill(0);
    for (size_t i = 0; i < data.size(); i++) {
        int Lettre = (int) data[i];
        frequences[Lettre] += 1;
    }



}

void HuffmanHeap::insertHeapNode(int heapSize, HuffmanNode* newNode)
{

     int j = heapSize;
    this->set(j, newNode);
    while((j > 0) && (this->get(j)->frequences < this->get((j-1)/2)->frequences)) {
        this->swap(j, (j-1)/2);
        j = (j-1)/2;
    }

}

void buildHuffmanHeap(const Array& frequences, HuffmanHeap& priorityMinHeap, int& heapSize)
{
   
    heapSize = 0;
    uint i = heapSize;
    for(i; i<frequences.size(); i++) {
        if(frequences[i] > 0) {

            HuffmanNode* tempNode = new HuffmanNode(i, frequences[i]);
            priorityMinHeap.insertHeapNode(heapSize, tempNode);
            heapSize++;

        }
    }

}

void HuffmanHeap::heapify(int heapSize, int nodeIndex)
{
    
    int min = nodeIndex;
    for(int i=nodeIndex; i<heapSize; i++) {
        if(this->get(i)->frequences < this->get(min)->frequences) {
            min = i;
        }
    }

    if(min != nodeIndex){
        swap(nodeIndex, min);   
        heapify(heapSize, min);
    }

}


HuffmanNode* HuffmanHeap::extractMinNode(int heapSize)
{
    
    HuffmanNode* firstNode = this->get(0);
    this->swap(0, heapSize - 1);
    heapify(heapSize - 1, 0);
    return firstNode;
}

HuffmanNode* makeHuffmanSubTree(HuffmanNode* rightNode, HuffmanNode* leftNode)
{
    
   HuffmanNode* subTree = new HuffmanNode('\0');
        subTree->right = rightNode;
        subTree->left = leftNode;
        subTree->frequences = rightNode->frequences + leftNode->frequences;
    return subTree;
}

HuffmanNode* buildHuffmanTree(HuffmanHeap& priorityMinHeap, int heapSize)
{
    
    HuffmanNode* huffmanTree = nullptr;
    HuffmanNode* leftChild;
    HuffmanNode* rightChild;

    while (heapSize > 1) {
        leftChild = priorityMinHeap.extractMinNode(heapSize--);
        rightChild = priorityMinHeap.extractMinNode(heapSize--);
        huffmanTree = makeHuffmanSubTree(leftChild, rightChild);
        priorityMinHeap.insertHeapNode(heapSize++, huffmanTree);
    }

    return huffmanTree;
}

void HuffmanNode::processCodes(const std::string& baseCode)
{
    
    if (this->left == nullptr && this->right == nullptr) {
    this->code = baseCode;
    return;
    }

    if (this->left != nullptr) {
        this->left->processCodes(baseCode + "0");
    }

    if (this->right != nullptr) {
        this->right->processCodes(baseCode + "1");
    }

}

void HuffmanNode::fillCharactersArray(std::string charactersCodes[])
{
    
    if (!this->left && !this->right)
        charactersCodes[this->character] = this->code;
    else {

        if (this->left)
            this->left->fillCharactersArray(charactersCodes);
        if (this->right)
            this->right->fillCharactersArray(charactersCodes);
    }
}

string huffmanEncode(const string& toEncode, HuffmanNode* huffmanTree)
{
    
    std::string charactersCodes[256];
    huffmanTree->fillCharactersArray(charactersCodes);
    std::string encoded;

    for (char c : toEncode) {
        encoded.append(charactersCodes[(c)]);
    }

    return encoded;
}


string huffmanDecode(const string& toDecode, const HuffmanNode& huffmanTreeRoot)
{
   
    string decoded = "";
    const HuffmanNode* currentNode = &huffmanTreeRoot;

    for (char c : toDecode) {
        currentNode = (c == '0') ? currentNode->left : currentNode->right;

        if (currentNode->isLeaf()) {
            decoded += currentNode->character;
            currentNode = &huffmanTreeRoot;
        }
    }

    return decoded;
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Array::wait_for_operations = false;
    w1 = new HuffmanMainWindow(main_function);
    w1->show();
    return a.exec();
}
