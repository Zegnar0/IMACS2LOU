#include "mainwindow.h"
#include "tp3.h"
#include <QApplication>
#include <time.h>
#include <stack>
#include <queue>

MainWindow* w = nullptr;
using std::size_t;

struct SearchTreeNode : public Node
{    
    SearchTreeNode* left;
    SearchTreeNode* right;
    int value;

    void initNode(int value)
    {
        this->value = value;
        this->right = NULL;
        this->left = NULL;

    }

	void insertNumber(int value) {
        SearchTreeNode* newNode = new SearchTreeNode(value);

        if (value < this->value) {
            if (this->left) {
                this->left->insertNumber(value);
            } else {
    
                this->left = newNode;
            }
        } else {
            if (this->right) {
                this->right->insertNumber(value);
            } else {
                this->right = newNode;
            }
        }

    }

	uint height() const	{
        int leftHeight = 1, rightHeight = 1, height = 1;

        if (this->left) {
            leftHeight += this->left->height();
        }

        if (this->right) {
            rightHeight += this->right->height();
        }

        height = (rightHeight > leftHeight) ? rightHeight : leftHeight;

        return height;

    }

	uint nodesCount() const {
        int Count= 1;

        if (this->right) {
           Count += this->right->nodesCount();
        }

        if (this->left) {
            Count += this->left->nodesCount();
        }

        return Count;

	}

	bool isLeaf() const {
        // return True if the node is a leaf (it has no children)
        if(this->left==nullptr && this->right==nullptr)
            return true;
        return false;
	}
	

	void allLeaves(Node* leaves[], uint& leavesCount) {
        if (this->isLeaf()) {
            leaves[leavesCount] = this;
            leavesCount++;
        } else {
            if (this->right) {
                this->right->allLeaves(leaves, leavesCount);
            }

            if (this->left) {
                this->left->allLeaves(leaves, leavesCount);
            }
        }

	}

	void inorderTravel(Node* nodes[], uint& nodesCount) {
        if (this->left) {
            this->left->inorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount++;

        if (this->right) {
            this->right->inorderTravel(nodes, nodesCount);
        }

	}

	void preorderTravel(Node* nodes[], uint& nodesCount) {
       nodes[nodesCount] = this;
        nodesCount++;

        if (this->left) {
            this->left->preorderTravel(nodes, nodesCount);
        }

        if (this->right) {
            this->right->preorderTravel(nodes, nodesCount);
        }

	}

	void postorderTravel(Node* nodes[], uint& nodesCount) {
        if (this->left) {
            this->left->postorderTravel(nodes, nodesCount);
        }

        if (this->right) {
            this->right->postorderTravel(nodes, nodesCount);
        }

        nodes[nodesCount] = this;
        nodesCount++;

	}

	Node* find(int value) {
         Node *res = nullptr;

        if (value == this->value) {
            res = this;
        } else if (value < this->value) {
           res = this->left->find(value);
        } else if (value > this->value) {
            res = this->right->find(value);
        }

        return res;

	}

    void reset()
    {
        if (left != NULL)
            delete left;
        if (right != NULL)
            delete right;
        left = right = NULL;
    }

    SearchTreeNode(int value) : Node(value) {initNode(value);}
    ~SearchTreeNode() {}
    int get_value() const {return value;}
    Node* get_left_child() const {return left;}
    Node* get_right_child() const {return right;}
};

Node* createNode(int value) {
    return new SearchTreeNode(value);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 200;
    w = new BinarySearchTreeWindow<SearchTreeNode>();
	w->show();

	return a.exec();
}
