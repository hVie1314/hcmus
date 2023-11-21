#include <iostream>

struct AVLTree
{
    int data;
    AVLTree* pLeft;
    AVLTree* pRight;
    int height;
};

struct Stack
{
    AVLTree* tree;
    Stack* pNext;
};

Stack* createStack(AVLTree* tree) {
    Stack* stack = new Stack;
    if (!stack) return NULL;
    stack->tree = tree;
    stack->pNext = NULL;
    return stack;
}

bool empty(Stack* stack) {
    return stack == NULL;
}

Stack* push(Stack*& stack, AVLTree* tree)
{
    Stack* st = createStack(tree);
    if (!stack) {
        stack = st;
         return stack;
    }
    st->pNext = stack;
    stack = st;
    return stack;
}

AVLTree* top(Stack* stack) 
{
    if (!stack) return NULL;
    return stack->tree;
}

AVLTree* pop(Stack*& stack) {
    if (!stack) return NULL;
    AVLTree* tree = stack->tree;
    Stack* temp = stack;
    stack = stack->pNext;
    delete temp;
    return tree;
}

void delStack(Stack*& stack) {
    if (!stack) return;
    Stack* temp = NULL;
    while (stack) {
        temp = stack;
        stack = stack->pNext;
        delete temp;
    } 
}

AVLTree* createNode(int data) {
    AVLTree* tree = new AVLTree;
    if (!tree) return NULL;
    tree->data = data;
    tree->pLeft = NULL;
    tree->pRight = NULL;
    tree->height = 1;
    return tree;
}

int height(AVLTree* tree) {
    if (!tree) return 0;
    return tree->height;
}

// int height(AVLTree* tree) {
//     if (!tree) return 0;
//     return 1 + std::max(height(tree->pLeft), height(tree->pRight));
// }

// bool isAVL(AVLTree* tree) {
//     if (!tree) return 1;
//     if (abs(height(tree->pLeft) - height(tree->pRight)) >=2) {
//         return 0;
//     }
//     isAVL(tree->pLeft);
//     isAVL(tree->pRight);
// }

int updateHeight(AVLTree* tree) {
    return 1 + std::max(height(tree->pLeft), height(tree->pRight));
}

int getBalance(AVLTree* tree) {
    if (!tree) return 0;
    return height(tree->pLeft) - height(tree->pRight);
}

AVLTree* singleRightRotate(AVLTree*& tree) {
    if (!tree) return NULL;
    AVLTree* temp = tree->pLeft;
    tree->pLeft = temp->pRight;
    temp->pRight = tree;
    tree->height = height(tree);
    temp->height = height(temp);
    return temp;
}

AVLTree* singleLeftRotate(AVLTree*& tree) {
    if (!tree) return NULL;
    AVLTree* temp = tree->pRight;
    tree->pRight = temp->pLeft;
    temp->pLeft = tree;
    tree->height = updateHeight(tree);
    temp->height = updateHeight(temp);
    return temp;
}

AVLTree* doubleRightRotate(AVLTree*& tree) {
    if (!tree) return NULL;
    tree->pLeft = singleLeftRotate(tree->pLeft);
    return singleRightRotate(tree);
}

AVLTree* doubleLeftRotate(AVLTree*& tree) {
    if (!tree) return NULL;
    tree->pRight = singleRightRotate(tree->pRight);
    return singleLeftRotate(tree);
}

AVLTree* insert(AVLTree*& tree, int data) {
    if (!tree) {
        tree = createNode(data);
        return tree;
    }
    if (tree->data == data) return tree;
    else if (data < tree->data) {
        tree->pLeft = insert(tree->pLeft, data);
        if (getBalance(tree) == 2) {
            if (data < tree->pLeft->data)
            {
                return singleRightRotate(tree);
            }
            else {
                return doubleRightRotate(tree);
            }
        }
    }
    else {
        tree->pRight = insert(tree->pRight, data);
        if (getBalance(tree) == -2) {
            if (data > tree->pRight->data) {
                return singleLeftRotate(tree);
            }
            else {
                return doubleLeftRotate(tree);
            }
        }
    }
    tree->height = updateHeight(tree);
    return tree;
}

AVLTree* findMinNode(AVLTree* tree) {
    if (!tree) return NULL;
    if (!tree->pLeft) return tree;
    return findMinNode(tree->pLeft);
}

AVLTree* findMaxNode(AVLTree* tree) {
    if (!tree) return NULL;
    if (!tree->pRight) return tree;
    return findMaxNode(tree->pRight);
}

AVLTree* remove(AVLTree*& tree, int data) {
    if (!tree) return NULL;
    if (data < tree->data) {
        tree->pLeft = remove(tree->pLeft, data);
    }
    else if (data > tree->data) {
        tree->pRight = remove(tree->pRight, data);
    }
    else { // found 
        if (!tree->pLeft || !tree->pRight) {
            AVLTree* temp = tree;
            if (!tree->pLeft) {
                tree = tree->pRight;
            }
            else {
                tree = tree->pLeft;
            }
            delete temp;
            return tree;
        }
        else {
            AVLTree* temp = findMinNode(tree->pRight);
            tree->data = temp->data;
            tree->pRight = remove(tree->pRight, temp->data);
        }
    }
    if (!tree) return NULL;
    tree->height = updateHeight(tree);
    if (getBalance(tree) == 2) {
        if (getBalance(tree->pLeft) >= 0) {
            return singleRightRotate(tree);
        }
        else {
            return doubleRightRotate(tree);
        }
    }
    else if (getBalance(tree) == -2) {
        if (getBalance(tree->pRight) <= 0) {
            return singleLeftRotate(tree);
        }
        else {
            return doubleLeftRotate(tree);
        }
    }
    return tree;
}

void NLRTravel(AVLTree* tree)
{
	if (!tree) return;
    std::cout << tree->data << " ";
    NLRTravel(tree->pLeft);
    NLRTravel(tree->pRight);
}

void LNRTravel(AVLTree* tree) {
    if (!tree) return;
    LNRTravel(tree->pLeft);
    std::cout << tree->data << " ";
    LNRTravel(tree->pRight);
}

void LRNTravel(AVLTree* tree)
{
	if (!tree) return;
    LRNTravel(tree->pLeft);
    LRNTravel(tree->pRight);
    std::cout << tree->data << " ";
}

// void NLRTravelIterative(AVLTree* tree) {
//     if (!tree) return;
//     Stack* stack = NULL;
//     push(stack, tree);

//     while (!empty(stack)) {
//         AVLTree* topData = top(stack);
//         pop(stack);
//         std::cout << topData->data << " ";
//         if (tree->pRight) {
//             push(stack, tree->pRight);
//         }
//         if (tree->pLeft) {
//             push(stack, tree->pLeft);
//         }
//     }
// }

void NLRTravelIterative(AVLTree* tree) {
    if (!tree) return;
    Stack* stack = NULL;
    AVLTree* pCurr = tree;
    while (!empty(stack) || pCurr) {
        if (pCurr) {
            std::cout << pCurr->data << " ";
            push(stack, pCurr);
            pCurr = pCurr->pLeft;
        }
        else {
            pCurr = top(stack);
            pop(stack);
            pCurr = pCurr->pRight;
        }
    }
}

// void LNRTravelIterative(AVLTree* tree) {
//     if (!tree) return;
//     Stack* stack = NULL;
//     AVLTree* pCurr = tree;
//     while (!empty(stack) || pCurr) {
//         if (pCurr) {
//             push(stack, pCurr);
//             pCurr = pCurr->pLeft;   
//         }
//         else {
//             AVLTree* topData = top(stack);
//             pop(stack);
//             std::cout << topData->data << " ";
//             pCurr = pCurr->pRight;
//         }
//     }
// }

void LNRTravelIterative(AVLTree* tree) {
    if (!tree) return;
    Stack* stack = NULL;
    AVLTree* pCurr = tree;

    while (pCurr || !empty(stack)) {
        if (pCurr) {
            push(stack, pCurr);
            pCurr = pCurr->pLeft; // Visit the left subtree first
        }
        else {
            pCurr = top(stack);
            pop(stack); // Visit the root node
            std::cout << pCurr->data << " "; // Print the node's data
            pCurr = pCurr->pRight; // Visit the right subtree next
        }
    }
}


void LRNTravelIterativeUseTwoStack(AVLTree* tree) {
    if (!tree) return;
    Stack* stack1 = NULL;
    Stack* stack2 = NULL;
    push(stack1, tree);
    while (!empty(stack1)) {
        tree = top(stack1);
        pop(stack1);
        push(stack2, tree);
        if (tree->pLeft) {
            push(stack1, tree->pLeft);
        }
        if (tree->pRight) {
            push(stack1, tree->pRight);
        }
    }
    while (!empty(stack2)) {
        AVLTree* topData = top(stack2);
        pop(stack2);
        std::cout<< topData->data << " ";
    }
}

// void LRNTravelIterativeUseOneStack(AVLTree* tree) {
//     if (!tree) return;
//     Stack* stack = NULL;
//     AVLTree* pCurr = tree;
//     AVLTree* pPrev = NULL;

//     while (!pCurr || !empty(stack)) {
//         if (pCurr) {
//             push(stack, pCurr);
//             pCurr = pCurr->pLeft;
//         }
//         else {
//             pCurr = top(stack);
//             if (!pCurr->pRight || (pCurr->pRight = pPrev)) {
//                 pop(stack);
//                 std::cout << pCurr->data << " ";
//                 pPrev = pCurr;
//                 pCurr = NULL;
//             }
//             else {
//                 pCurr = pCurr->pRight;
//             }
//         }
//     }
// }

// void LRNTravelIterativeUseOneStack(AVLTree* tree) {
//     if (!tree) return;
//     Stack* stack = NULL;
//     AVLTree* pCurr = tree, *pPrev = NULL;

//     while (!pCurr || !empty(stack)) {
//         if (pCurr) {
//             push(stack, pCurr);
//             pCurr = pCurr->pLeft;
//         } else {
//             pCurr = top(stack);
//             if (!pCurr->pRight || (pCurr->pRight == pPrev)) {
//                 pop(stack);
//                 std::cout << pCurr->data << " ";
//                 pPrev = pCurr;
//                 pCurr = NULL;
//             } else {
//                 pCurr = pCurr->pRight;
//             }
//         }
//     }
// }


void delAVLTree(AVLTree*& tree) {
    if (!tree) return;
    delAVLTree(tree->pLeft);
    delAVLTree(tree->pRight);
    delete tree;
    tree = NULL;
}

int main() {
    AVLTree* tree = NULL;

    insert(tree, 5);
    insert(tree, 9);
    insert(tree, 0);
    insert(tree, 7);
    insert(tree, 3);
    insert(tree, 4);
    insert(tree, 6);
    insert(tree, 2);
    insert(tree, 1);
    insert(tree, 6);
    insert(tree, 8);

    std::cout << "In-order traversal after inserting: ";
    LNRTravel(tree);
    std::cout << std::endl;
    //memory leak
    std::cout << "In-order traversal iterative: ";
    LNRTravelIterative(tree);
    std::cout << std::endl;

    std::cout << "Pre-order traversal after inserting: ";
    NLRTravel(tree);
    std::cout << std::endl;
    //infinite loop
    std::cout << "Pre-order traversal iterative: ";
    NLRTravelIterative(tree);
    std::cout << std::endl;

    std::cout << "Post-order traversal after inserting: ";
    LRNTravel(tree);
    std::cout << std::endl;
    // dont print 
    // std::cout << "Post-order traversal iterative use 1 stack: ";
    // LRNTravelIterativeUseOneStack(tree);
    // std::cout << std::endl;
    std::cout << "Pre-order traversal iterative use 2 stack: ";
    LRNTravelIterativeUseTwoStack(tree);
    std::cout << std::endl;

    remove(tree, 1);
    remove(tree, 5);
    remove(tree, 9);
    remove(tree, 3);
    remove(tree, 7);

    std::cout << "In-order traversal after removing: ";
    LNRTravel(tree);
    std::cout << std::endl;

    delAVLTree(tree);
    return 0;
}


