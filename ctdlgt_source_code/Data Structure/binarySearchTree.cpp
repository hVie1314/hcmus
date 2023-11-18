#include <iostream>
#include <queue>

using namespace std;

struct TNode
{
	int key;
	TNode* pLeft;
	TNode* pRight;
};

struct BSTree
{
	TNode* root;
};

void initialize(BSTree*& tree)
{
	tree = new BSTree;
	tree->root = nullptr;
}

void deleteTree(TNode*& node)
{
	if (node == nullptr)
	{
		return;
	}
	deleteTree(node->pLeft);
	deleteTree(node->pRight);
	delete node;
	node = nullptr;
}

void deinitialize(BSTree*& tree)
{
	if (tree == nullptr)
	{
		return;
	}
	deleteTree(tree->root);
	delete tree;
	tree = nullptr;
}

void insertNode(TNode*& root, int val)
{
	if (root == nullptr)
	{
		TNode* node = new TNode;
		if (!node)
		{
			cout << "fail to insert node" << endl;
			return;
		}
		node->key = val;
		node->pLeft = nullptr;
		node->pRight = nullptr;
		root = node;
		return;
	}
	if (root->key == val)
	{
		return;
	}
	if (root->key > val)
	{
		insertNode(root->pLeft, val);
	}
	else
	{
		insertNode(root->pRight, val);
	}
}

void insert(BSTree* tree, int val)
{
	insertNode(tree->root, val);
}

void findNodeTemp(TNode*& A, TNode*& B)
{
	//left most right
	if (B->pLeft != nullptr)
	{
		findNodeTemp(A, B->pLeft);
	}
	else
	{
		A->key = B->key;
		A = B;
		B = B->pRight;
	}
}

void deleteNodeByValue(TNode*& root, int val)
{
	if (root == nullptr)
	{
		return;
	}
	if (val < root->key)
	{
		deleteNodeByValue(root->pLeft, val);
	}
	else if (val > root->key)
	{
		deleteNodeByValue(root->pRight, val);
	}
	else // val == root->key
	{
		TNode* temp = root;
		if (root->pLeft == nullptr)
		{
			root = root->pRight;
		}
		else if (root->pRight == nullptr)
		{
			root = root->pLeft;
		}
		else // node has 2 leaf
		{
			findNodeTemp(temp, root->pRight);
		}
		delete temp;
	}
}

void deleteNodeByNode(BSTree* tree, TNode* node)
{
	deleteNodeByValue(tree->root, node->key);
}

void NLRTravel(const TNode* root)
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		NLRTravel(root->pLeft);
		NLRTravel(root->pRight);
	}

}

void LNRTravel(const TNode* root)
{
	if (root != nullptr)
	{
		LNRTravel(root->pLeft);
		cout << root->key << " ";
		LNRTravel(root->pRight);
	}

}

void RNLTravel(const TNode* root)
{
	if (root != nullptr)
	{
		RNLTravel(root->pRight);
		cout << root->key << " ";
		RNLTravel(root->pLeft);
	}

}

void LRNTravel(const TNode* root)
{
	if (root != nullptr)
	{
		LRNTravel(root->pLeft);
		LRNTravel(root->pRight);
		cout << root->key << " ";
	}
}

void levelOrderTraversal(const TNode* root)
{
	if (root == nullptr)
	{
		return;
	}
	queue<const TNode*> q;
	q.push(root);
	while (!q.empty())
	{
		const TNode* node = q.front();
		q.pop();
		cout << node->key << " ";
		if (node->pLeft != nullptr)
		{
			q.push(node->pLeft);
		}
		if (node->pRight != nullptr)
		{
			q.push(node->pRight);
		}
	}
}

//tìm kiếm không dùng đệ quy
TNode* Find(BSTree* tree, int val)
{
	if (!tree) return nullptr;
	TNode* curr = tree->root;
	// không được đổi thứ tự của 2 điều kiện
	while (curr && curr->key != val)
	{
		if (curr->key > val)
		{
			curr = curr->pLeft;
		}
		else
		{
			curr = curr->pRight;
		}
	}
	return curr;
}

TNode* depthFirstSearch(const TNode* node, int val)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	if (node->key == val)
	{
		return const_cast<TNode*>(node);
	}
	if (node->key > val)
	{
		depthFirstSearch(node->pLeft, val);
	}
	else
	{
		depthFirstSearch(node->pRight, val);
	}
}

TNode* DFSearch(const BSTree* tree, int val)
{
	return depthFirstSearch(tree->root, val);
}
// còn sai 
TNode* breadthFirstSearch(const TNode* root, int val)
{
	if (root != nullptr)
	{
		queue<const TNode*> q;
		q.push(root);
		while (!q.empty())
		{
			const TNode* curr = q.front();
			q.pop();
			if (curr->key == val)
			{
				return const_cast<TNode*>(curr);
			}
			if (curr->pLeft != nullptr)
			{
				q.push(curr->pLeft);
			}
			if (curr->pRight != nullptr)
			{
				q.push(curr->pRight);
			}
		}
	}
}

TNode* BFSearch(const BSTree* tree, int val)
{
	return breadthFirstSearch(tree->root, val);
}

void nodeHas2Leaf(const TNode* root)
{
	if (root != nullptr)
	{
		if (root->pLeft != nullptr && root->pRight != nullptr)
		{
			cout << root->key << " ";
		}
		nodeHas2Leaf(root->pLeft);
		nodeHas2Leaf(root->pRight);
	}
}

void nodeHas1Leaf(const TNode* root)
{
	if (root != nullptr)
	{
		if ((root->pLeft != nullptr && root->pRight == nullptr) || (root->pRight != nullptr && root->pLeft == nullptr))
		{
			cout << root->key << " ";
		}
		nodeHas1Leaf(root->pLeft);
		nodeHas1Leaf(root->pRight);
	}
}

void nodeLeaf(const TNode* root)
{
	if (root != nullptr)
	{
		if (root->pLeft == nullptr && root->pRight == nullptr)
		{
			cout << root->key << " ";
		}
		nodeLeaf(root->pLeft);
		nodeLeaf(root->pRight);
	}
}

TNode* findMax(const TNode* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->pRight == nullptr)
	{
		return const_cast<TNode*>(root);
	}
	return findMax(root->pRight);
}

TNode* findMin(const TNode* root)
{
	if (root == nullptr)
	{
		return nullptr;
	}
	if (root->pLeft == nullptr)
	{
		return const_cast<TNode*>(root);
	}
	return findMin(root->pLeft);
}

void menu(BSTree* tree)
{
	while (true)
	{
		system("cls");
		cout << "\n\n __________________________ MENU __________________" << endl << endl;
		cout << "\t\t 1. Insert value to tree." << endl;
		cout << "\t\t 2. Travel tree by NLR." << endl;
		cout << "\t\t 3. Travel tree by LNR." << endl;
		cout << "\t\t 4. Travel tree by RNL." << endl;
		cout << "\t\t 5. Travel tree by LRN." << endl;
		cout << "\t\t 6. Travel tree by level." << endl;
		cout << "\t\t 7. Delete node." << endl;
		cout << "\t\t 8. Search by DFS." << endl;
		cout << "\t\t 9. Search by BFS." << endl;
		cout << "\t\t 10. Node leaf." << endl;
		cout << "\t\t 11. Node has 1 leaf." << endl;
		cout << "\t\t 12. Node has 2 leaf." << endl;
		cout << "\t\t 13. Find max value in tree." << endl;
		cout << "\t\t 14. Find min value in tree." << endl;
		cout << "\t\t 0. Quit." << endl;
		cout << "___________________________________________________" << endl;

		int choice = 0;
		int val = 0;
		TNode* res = nullptr;

		cout << "Enter your require: ";
		cin >> choice;
		if (choice < 0 || choice > 14)
		{
			cout << "Invalid require, please type again." << endl;
			cout << endl;
			system("pause");
		}

		switch (choice)
		{
		case 1:
			cout << "Enter value you want to insert: ";
			cin >> val;
			insert(tree, val);
			cout << "Value " << val << " is inserted to tree." << endl;
			break;
		case 2:
			cout << "Tree travle by NLR: " << endl;
			NLRTravel(tree->root);
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "Tree travle by LNR: " << endl;
			LNRTravel(tree->root);
			cout << endl;
			system("pause");
			break;
		case 4:
			cout << "Tree travle by RNL: " << endl;
			RNLTravel(tree->root);
			cout << endl;
			system("pause");
			break;
		case 5:
			cout << "Tree travle by LRN: " << endl;
			LRNTravel(tree->root);
			cout << endl;
			system("pause");
			break;
		case 6:
			cout << "Tree travle by level: " << endl;
			levelOrderTraversal(tree->root);
			cout << endl;
			system("pause");
			break;
		case 7:
			cout << "Enter value you want to delete: ";
			cin >> val;
			res = DFSearch(tree, val);
			if (!res)
			{
				cout << "Error! Value " << val << " does not exists in tree.";
				cout << endl;
				system("pause");
				break;
			}
			deleteNodeByValue(tree->root, val);
			cout << "Deleted.";
			cout << endl;
			system("pause");
			break;
		case 8:
			cout << "Enter value you want to search: ";
			cin >> val;
			res = DFSearch(tree, val);
			if (res)
			{
				cout << val << " exists in tree." << endl;
			}
			else
			{
				cout << val << " does not exist in tree." << endl;
			}
			cout << endl;
			system("pause");
			break;
		case 9:
			cout << "Enter value you want to search: ";
			cin >> val;
			res = BFSearch(tree, val);
			if (res)
			{
				cout << val << " exists in tree." << endl;
			}
			else
			{
				cout << val << " does not exist in tree." << endl;
			}
			cout << endl;
			system("pause");
			break;
		case 10:
			cout << "Node leaf: " << endl;
			nodeLeaf(tree->root);
			cout << endl;
			system("pause");
			break;
		case 11:
			cout << "Node has 1 leaf: " << endl;
			nodeHas1Leaf(tree->root);
			cout << endl;
			system("pause");
			break;
		case 12:
			cout << "Node has 2 leaf: " << endl;
			nodeHas2Leaf(tree->root);
			cout << endl;
			system("pause");
			break;
		case 13:
			cout << "Max value in tree is: " << endl;
			cout << findMax(tree->root);
			cout << endl;
			system("pause");
			break;
		case 14:
			cout << "Min value in tree is: " << endl;
			cout << findMin(tree->root);
			cout << endl;
			system("pause");
			break;
		case 0:
			return;
		}
	}
}

int main()
{
	BSTree* tree = nullptr;
	initialize(tree);

	menu(tree);

	deinitialize(tree);
	return 0;
}


//test case: 5 7 -2 0 -5 1 6 -3