// Online C++ compiler to run C++ program online
#include <iostream>

struct Node {
    int data;
    Node* pLeft;
    Node* pRight;
};

int height(Node* root) {
    if (!root) return 0;
    return 1 + std::max(height(root->pLeft), height(root->pRight));
}

void add(Node*& tree, int data) {
    
    if (!tree){
        Node* p=new Node;
        p->data=data;
        p->pLeft=NULL;
        p->pRight=NULL;
        tree=p;
    }
    else{
        if (data == tree->data) continute;
        else if(data<tree->data) add(tree->pLeft,data);
        else if(data>tree->data) add(tree->pRight,data);
    }
}

bool isAVL(Node* tree) {
    if (!tree) return 1;
    if (abs(height(tree->pLeft) - height(tree->pRight)) >=2) {
        return 0;
    }
    isAVL(tree->pLeft);
    isAVL(tree->pRight);
}

int main() {
    Node* tree = NULL;
    add(tree, 7);
    add(tree, 5);
    add(tree, 9);
    add(tree, 6);
    add(tree, 4);
    add(tree, 3);
    add(tree, 10);
    add(tree, 11);
    //dd(tree, 12);
    add(tree, 8);
    std::cout << height(tree) << std::endl;
    std::cout << height(tree->pLeft) << " " << height(tree->pRight);
    std::cout << isAVL(tree);
    return 0;
}
