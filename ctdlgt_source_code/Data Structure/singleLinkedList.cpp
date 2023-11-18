#include <iostream>

using namespace std;

//define node
struct NODE
{
	int data;
	NODE* pNext;
};

//create a node
NODE* createNode(int x)
{
	NODE* pHead = new NODE;
	//check if fail
	if (pHead == NULL)
	{
		cout << "Fail to create node" << endl;
		return NULL;
	}
	pHead->data = x;
	pHead->pNext = NULL;
	return pHead;
}

//check if node is empty
bool empty(NODE* pHead)
{
	if (pHead == NULL) return true;
	return false;
	// return pHead == NULL;
}

int Size(NODE* pHead)
{
	int  count = 0;
	while (pHead != NULL)
	{
		++count;
		pHead = pHead->pNext;
	}
	return count;
}

void insertFirst(NODE* &pHead, int x)
{
	NODE* pNode = createNode(x);
	if (pHead == NULL)
	{
		pHead = pNode;
		return;
	}
	pNode->pNext = pHead;
	pHead = pNode;
}

void insertLast(NODE* &pHead, int x)
{
	NODE* pNode = createNode(x);
	if (pNode == NULL)
	{
		pHead = pNode;
		return;
	}
	NODE* tmp = pHead;
	while (tmp->pNext != NULL)
	{
		tmp = tmp->pNext;
	}
	tmp->pNext = pNode;
}

void insertMiddle(NODE* &pHead, int x, int pos)
{
	int n = Size(pHead);
	//check if the pos is not valid
	if (pos <= 0 || pos > n + 1)
	{
		cout << "The insert position is not valid" << endl;
		return;
	}	

	//check if it insert first or last
	if (pos == 1)
	{
		insertFirst(pHead, x);
		return;
	}
	if (pos == n + 1) 
	{
		insertLast(pHead, x);
		return;
	}
	
	//for example: insert nodeX to node0-node1-(node2)-node3 to the position 2
	//step1: move the pointer to the position before pos (node1)
	//step2: assign nodeX->next = node2
	//step3: assign node1->next = nodeX
	//after insert, we have: node0-node1-nodeX-node2-node3
	
	NODE* pNode = createNode(x);
	NODE* tmp = pHead;
	for (int i = 1; i < pos - 1; i++)
	{
		tmp = tmp->pNext;
	}
	pNode->pNext = tmp->pNext;
	tmp->pNext = pNode;
}

void deleteFirst(NODE* &pHead)
{
	if (pHead == NULL) return;
	// check if node has 1 element, delete this element, then assign node = nullptr
	if (pHead->pNext == NULL)
	{
		delete pHead;
		pHead = NULL;
		return;
	}
	NODE* tmp = pHead;
	pHead = pHead->pNext;
	delete tmp;
}

void deleteLast(NODE* &pHead)
{
	if (pHead == NULL) return;
	NODE* before = NULL;
	NODE* after = pHead;

	while (after->pNext != NULL)
	{
		before = after;
		after = after->pNext;
	}

	//check if list only have 1 element, then just delete it
	if (before == NULL)
	{
		pHead = NULL;
		return;
	}
	before->pNext = NULL;
	delete after;
}

void deleteMiddle(NODE* &pHead, int pos)
{
	int n = Size(pHead);
	// check if pos is invalid
	if (pos <= 0 || pos > n)
	{
		cout << "The position you want to delete is invalid" << endl;
		return;
	}
	//check if pos is first or last
	if (pos == 1)
	{
		deleteFirst(pHead);
		return;
	}
	if (pos == n)
	{
		deleteLast(pHead);
		return;
	}

	NODE* before = NULL;
	NODE* after = pHead;
	for (int i = 1; i < pos; i++)
	{
		before = after;
		after = after->pNext;
	}
	before->pNext = after->pNext;
	delete after;
}

void deleteAll(NODE* &pHead)
{
	NODE* pNode = NULL;
	while (pHead != NULL)
	{
		pNode = pHead;
		pHead = pHead->pNext;
		delete pNode;
	}
	pHead = NULL;
}

void printNode(NODE* pHead)
{
	cout << "--------------------------------" << endl;
	while (pHead != NULL)
	{
		cout << pHead->data << " ";
		pHead = pHead->pNext;
	}
	cout << endl << "--------------------------------" << endl;
}

void getNode(NODE* pHead, int pos)
{
	if (pos <= 0 || pos > Size(pHead))
	{
		cout << "The position you want to get is invalid" << endl;
		return;
	}
	NODE* pNode = pHead;
	for (int i = 1; i < pos; i++)
	{
		pNode = pNode->pNext;
	}
	cout << "Value at node " << pos << " is: " << pNode->data << endl;
}

void findValue(NODE* pHead, int val)
{
	NODE* pNode = pHead;
	int count = 0;
	while (pNode != NULL)
	{
		++count;
		if (pNode->data == val)
		{
			cout << "Your value is at node: " << count << endl;
			return;
		}
		pNode = pNode->pNext;
	}
	cout << "The value does not exist in list" << endl;
}

//use selection sort algorithm
void sortNode(NODE* &pHead)
{
	for (NODE* a = pHead; a->pNext != NULL; a = a->pNext)
	{
		NODE* min = a;
		for (NODE* b = a; b != NULL; b = b->pNext)
		{
			if (b->data < min->data)
			{
				min = b;
			}
		}
		//swap
		int tmp = a->data;
		a->data = min->data;
		min->data = tmp;
	}
}

//this function will separate odd number to a new node, remain even number in pHead
void separateNode(NODE*& nodeA)
{
	NODE* pNode = nodeA;
	NODE* nodeB = NULL;
	NODE* prevNode = NULL;
	NODE* tmpNode = NULL;
	while (pNode != NULL)
	{
		if (pNode->data % 2 != 0)
		{
			// Remove the current node from nodeA
			if (prevNode == NULL) {
				nodeA = pNode->pNext;
			}
			else {
				prevNode->pNext = pNode->pNext;
			}
			// Insert the current node at the end of nodeB
			insertLast(nodeB, pNode->data);
			// Save the next node and delete the current node
			tmpNode = pNode;
			pNode = pNode->pNext;
			tmpNode->pNext = NULL;
		}
		else {
			prevNode = pNode;
			pNode = pNode->pNext;
		}
	}
	printNode(nodeA);
	printNode(nodeB);
}

int main()
{
	NODE* pHead = NULL;	
	int choice = 0;
	int pos = 0;
	int val = 0;
	while (1)
	{
		cout << "-----------------MENU---------------" << endl;
		cout << "1. Insert element to head of linked list" << endl;
		cout << "2. Insert element to tail of linked list" << endl;
		cout << "3. Insert element to middle of linked list" << endl;
		cout << "4. Delete element at the head of linked list" << endl;
		cout << "5. Delete element at the tail of linked list" << endl;
		cout << "6. Delete element at the middle of linked list" << endl;
		cout << "7. Get value from node" << endl;
		cout << "8. Find node" << endl;
		cout << "9. Sort" << endl;
		cout << "10. Print linked list" << endl;
		cout << "0. Exist program" << endl;

		cout << "Enter your choice: ";
		cin >> choice;
		if (choice < 0 || choice > 10 || isalpha(choice))
		{
			cout << "You have typed invalid value, please retype your choice" << endl;
		}

		switch (choice)
		{
			case 1: 
				cout << "Enter value: ";
				cin >> val;
				insertFirst(pHead, val);
				break;
			case 2:
				cout << "Enter value: ";
				cin >> val;
				insertLast(pHead, val);
				break;
			case 3:
				cout << "Enter value: ";
				cin >> val;
				cout << "Enter position you want to insert: ";
				cin >> pos;
				insertMiddle(pHead, val, pos);
				break;
			case 4:
				deleteFirst(pHead);
				break;
			case 5:
				deleteLast(pHead);
				break;
			case 6:
				cout << "Enter position you want to delete: ";
				cin >> pos;
				deleteMiddle(pHead, pos);
				break;				
			case 7: 
				cout << "Enter your node you want to get value: ";
				cin >> pos;
				getNode(pHead, pos);
				break;
			case 8: 
				cout << "Enter your value you want to find: ";
				cin >> val;
				findValue(pHead, val);
				break;
			case 9: 
				sortNode(pHead);
				break;
			case 10: 
				printNode(pHead);
				break;
			case 0:
				deleteAll(pHead);
				return 0;
		}
	}
	return 0;
}