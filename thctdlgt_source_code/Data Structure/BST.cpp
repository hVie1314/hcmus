#include"BST.h"
#include "queue.h"
#include "stack.h"

/*
* @brief  1. Khởi tạo một NODE từ một giá trị cho trước :
* @param data - key của node cần tạo
* @return Node vừa được tạo, nếu lỗi trả về nullptr
*/
BST::BSTNode* BST::createNode(int data) {
	BSTNode* newNode = new BSTNode;                       // Cấp phát động một Node
	newNode->key = data;                           
	newNode->p_left = nullptr;
	newNode->p_right = nullptr;
	if (newNode)                                 // Nếu tạo Node thành công, trả về Node đó
		return newNode;
	else {
		cout << "Creating Node Error!";        // Ngược lại, in ra màn hình "Creating Node Error!" và trả về nullptr
		//return nullptr;
	}
} 


/*
*@brief 2. Duyệt tiền thứ tự
*@param pRoot - node gốc.
*@return key của các node.
*/
void BST::NLR() {
	if (!pRoot) return;


	Stack<BSTNode*> st;
	st.init();


	st.push(pRoot);
	cout << pRoot->key << " ";
	while (!st.isEmpty()) {

		// Lấy đỉnh stack
		BSTNode* cur = st.gettop();

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Xóa bỏ đỉnh ( lúc này là nullptr)
			st.pop();

			// In ra đỉnh stack 

			//cout << st.gettop()->key << " ";
		}

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Lấy đỉnh stack 
			cur = st.gettop();

			// Nếu không có con phải thì xóa khỏi stack
			if (!cur->p_right) {
				st.pop();
			}

			// Ngược lại thì xóa khỏi stack và thêm con phải vào stack
			else {
				st.pop();
				cout << cur->p_right->key << " ";
				st.push(cur->p_right);

			}

		}

		// Nếu cur khác nullptr ( chưa thăm hết con trái )

		else {

			if (cur->p_left) {

				// Đẩy vào stack nullptr và con trái xen kẽ nhau để đánh dấu các node đã thăm con trái
				while (cur && cur->p_left) {

					st.push(nullptr);

					

					st.push(cur->p_left);

					cur = cur->p_left;

					cout << cur->key << " ";
				}
			}

			// Nếu không có con trái 
			else {

				// Không có con phải
				if (!cur->p_right) {
					//cout << cur->key << " ";
					st.pop();
				}

				// Có con phải
				else {
					cout << cur->p_right->key << " ";
					st.pop();
					st.push(cur->p_right);

				}
			}
		}
	}
}


/*
*@brief 3. Duyệt trung thứ tự
*@param pRoot - node gốc.
*@return key của các node.
*/
void BST::LNR() {
	if (!pRoot) return;


	Stack<BSTNode*> st;
	st.init();


	st.push(pRoot);

	while (!st.isEmpty()) {

		// Lấy đỉnh stack
		BSTNode* cur = st.gettop();

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Xóa bỏ đỉnh ( lúc này là nullptr)
			st.pop();

			// In ra đỉnh stack 
			
			cout << st.gettop()->key << " ";
		}

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Lấy đỉnh stack 
			cur = st.gettop();

			// Nếu không có con phải thì xóa khỏi stack
			if (!cur->p_right) {
				st.pop();
			}

			// Ngược lại thì xóa khỏi stack và thêm con phải vào stack
			else {
				st.pop();
				st.push(cur->p_right);

			}

		}

		// Nếu cur khác nullptr ( chưa thăm hết con trái )

		else {

			if (cur->p_left) {

				// Đẩy vào stack nullptr và con trái xen kẽ nhau để đánh dấu các node đã thăm con trái
				while (cur && cur->p_left) {

					st.push(nullptr);

					st.push(cur->p_left);

					cur = cur->p_left;
				}
			}

			// Nếu không có con trái 
			else {

				// Không có con phải
				if (!cur->p_right) {
					cout << cur->key << " ";
					st.pop();
				}

				// Có con phải
				else {
					cout << cur->key << " ";
					st.pop();
					st.push(cur->p_right);

				}
			}
		}
	}
}


/*
*@brief 4. Duyệt hậu thứ tự
*@param pRoot - node gốc.
*@return key của các node.
*/
void BST::LRN(BST::BSTNode* pRoot) {
	if (!pRoot) {
		return;
	}
	LRN(pRoot->p_left);
	LRN(pRoot->p_right);
	cout << pRoot->key << " ";
}
void BST::LRN() {
	LRN(BST::pRoot);
}


/*
*@brief 5. Duyệt theo mức
*@param pRoot - node gốc.
*@return key và height của các node.
*/
void BST::LevelOrder() {

	

	if (!pRoot) return;

	// Khởi tạo hàng đợi
	Queue<BSTNode*> q;

	q.init();
	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		// In giá trị của Node ở đầu hàng đợi sau đó xóa nó khỏi hàng đợi
		cout << cur->key << " ";

		q.deQueue();

		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
			q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}
		
	}
}


/*
*@brief 6. Tìm và trả về một NODE với giá trị cho trước từ một cây nhị phân tìm kiếm :
*@param pRoot - node gốc, x - key của node cần tìm
*@return Node cần tìm
*/
BST::BSTNode* BST::Search(int x) {

	 BSTNode* p_cur = getpRoot();

	// Nếu cây rỗng, trả về nullptr
	if (!p_cur) return nullptr;

	while (p_cur) {

		if (p_cur->key > x) {
			p_cur = p_cur->p_left;
		}
		else if (p_cur->key < x) {
			p_cur = p_cur->p_right;
		}
		else {
			return p_cur;
		}
	}
	return nullptr;
}


/*
* @brief Tìm vị trí làm cha của node cần thêm đồng thời thêm tất cả các node tổ tiên vào stack
* @param x - giá trị node cần thêm
* @param st - Stack chứa các node tổ tiên
* @return Trả về node tìm được
*/
BST::BSTNode* BST::findPosition(int x) {

	 BSTNode* p_cur = getpRoot();

	if (!p_cur) return nullptr;
	
	BSTNode* parent = nullptr;

	while (p_cur) {

		if (x > p_cur->key) {
			parent = p_cur;
			p_cur = p_cur->p_right;
		}
		else if (x < p_cur->key) {
			parent = p_cur;
			p_cur = p_cur->p_left;
		}
		else {

			return nullptr;
		}
	}

	return parent;
}


/*
*@brief 7. Thêm một NODE với giá trị cho trước vào cây nhị phân tìm kiếm :
*@param pRoot - node gốc, x - giá trị cần thêm
*@return Cây sau khi thêm
*/
void BST::Insert(int x) {

	if (!getpRoot()) {

		BST::pRoot = createNode(x);

		return;
	}

	BSTNode* temp = findPosition(x);

	if (!temp) return;

	if (x > temp->key) temp->p_right = createNode(x);

	else if (x < temp->key) temp->p_left = createNode(x);

}


void BST::deleteNode(BSTNode* cur, BSTNode* parent, BSTNode* replace) {

	if (parent && parent->key > cur->key) {

		parent->p_left = replace;
		delete cur;
		return;
	}

	else if (parent && parent->key < cur->key) {

		parent->p_right = replace;
		delete cur;
		return;
	}
	if (!parent) {

		BST::pRoot = replace;
		return;
	}

}


/*
*@brief 8. Xóa một NODE với giá trị cho trước từ một cây AVL cho trước (Chú ý giá trị đó có tồn tại hay không):
*@param pRoot - node gốc, x - giá trị cần xóa
*@return cây sau khi xóa
*/
void BST::Remove(int x) {
	
	// Biến chạy cur
	BSTNode* cur = getpRoot();

	// Cha của cur
	BSTNode* parent = nullptr;

	while (cur) {

		// Nếu x lớn hơn key của cur thì chạy sang phải
		if (x > cur -> key) {

			parent = cur;

			cur = cur->p_right;
		}

		// Nếu x nhỏ hơn key của cur thì chạy sang trái
		else if (x < cur->key) {

			parent = cur;

			cur = cur->p_left;
		}

		// Nếu tìm được vị trí cần xóa
		else {

			 // Node cần xóa là node lá
			if (!cur->p_left && !cur->p_right)
			{
				
				deleteNode(cur, parent, nullptr);
				return;				
			}

			// Node cần xóa chỉ có con phải
			if (!cur->p_left) {
		
				deleteNode(cur, parent, cur->p_right);
				return;
			}

			// Node cần xóa chỉ có con trái
			else if (!cur->p_right) {

				deleteNode(cur, parent, cur->p_left);
				return;				
			}

			// Node cần xóa có 2 con
			else {
               
				BSTNode* min = cur->p_right;

				BSTNode* parOfmin = cur->p_right;

				while (min && min->p_left) {

					parOfmin = min;

					min = min->p_left;
				}

				cur->key = min->key;

				if (min == cur->p_right) {

					BST::pRoot->key = min->key;
					
					BST::pRoot->p_right = nullptr;

					delete  min;
					return;
				}
				if (min->p_right) {

					parOfmin->p_left = min->p_right;

					delete min;

					return;
				}
				else {

					parOfmin->p_left = nullptr;

					delete min;

					return;
				}

			}
			break;

		}
	}

	
		
}


/* 
*@brief 9. Khởi tạo một cây nhị phân tìm kiếm từ một mảng cho trước :
*@param a[] - mảng, n - số phần tử của mảng
*@return Cây sau khi tạo
*/
void BST::createTree(int a[], int n) {

	// Khởi tạo cây
	BST::pRoot = nullptr;
	// Lần lượt duyệt và thêm cái phần tử của mảng vào cây
	for (int i = 0; i < n; i++) {
		Insert(a[i]);
	}
}

/*

*brief 10. Xóa hoàn toàn một cây nhị phân tìm kiếm :
*@param pRoot - node gốc
*@return Cây sau khi xóa

*/
void BST::removeTree() {

	// Nếu cây rỗng, trả về
	if (!pRoot) return;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		// In giá trị của Node ở đầu hàng đợi sau đó xóa nó khỏi hàng đợi

		q.deQueue();

		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
			q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}

		delete cur;

		cur = nullptr;
	}
	pRoot = nullptr;
}


/*
*@brief 11. Tính chiều cao của một cây nhị phân tìm kiếm :
*@param pRoot - node gốc
*@return Chiều cao của cây
*/
int BST::Height() {
	// Nếu cây rỗng trả về 0
	if (!pRoot) return 0;

	// Chiều cao của cây sẽ bằng chiều cao lớn hơn giữa cây con trái và cây con phải của node gốc + 1
	int count = 0;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	q.enQueue(nullptr);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		q.deQueue();

		// Gặp nullptr - tức là đã duyệt xong 1 tầng
		if (cur == nullptr) {
			count++;
		}

		if (cur) {
			// Thêm node con trái vào hàng đợi
			if (cur->p_left) {
				q.enQueue(cur->p_left);
			}
			// Thêm node con phải vào hàng đợi
			if (cur->p_right) {
				q.enQueue(cur->p_right);
			}
		}

		// Thêm nullptr lại vào queue
		else if (!q.isEmpty()) q.enQueue(nullptr);
	}
	return count;
}



/*
*@brief 12. Đếm số lượng NODE của một cây nhị phân :
*@param pRoot - node gốc
*@return Số lượng Node của cây
*/
int BST::countNode() {

	// Nếu cây rỗng trả về 0
	if (!pRoot) return 0;
	
	Queue<BSTNode*> q;

	q.init();

	int count = 0;
	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		
		count++;

		q.deQueue();

			// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
				q.enQueue(cur->p_left);
		}
			// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
				q.enQueue(cur->p_right);
		}
	}
		
	
	return count;
}


/*
*@brief 13. Tính tổng giá trị của toàn bộ NODEs trong một cây nhị phân :
*@param pRoot - node gốc
*@return Tổng giá trị các Node trong cây
*/
int BST::sumNode() {

	// Nếu cây rỗng trả về 0
	if (!pRoot) return 0;

	Queue<BSTNode*> q;

	q.init();

	int sum = 0;

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		
		sum+= cur->key;

		q.deQueue();

		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
			q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}
	}
	return sum;
}

/*
*@brief 14. Tính toán chiều cao của một NODE với giá trị cho trước : (trả về - 1 nếu không tồn tại)
*@param pRoot - node gốc, value - giá trị của node cần tính chiều cao.
*@return Chiều cao của node đó.
*/
int BST::heightNode(int value) {

	// Nếu cây rỗng trả về -1
	if (!pRoot) return -1;


	// Nếu giá trị key của pRoot bằng value, trả về chiều cao pRoot
	if (pRoot->key == value) return Height();

	BSTNode* temp = Search(value);

	int count = 0;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(temp);

	q.enQueue(nullptr);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		

		q.deQueue();

		// Gặp nullptr - tức là đã duyệt xong 1 tầng
		if (cur == nullptr) {
			count++;
		}


		if (cur) {
			// Thêm node con trái vào hàng đợi
			if (cur->p_left) {
				q.enQueue(cur->p_left);
			}
			// Thêm node con phải vào hàng đợi
			if (cur->p_right) {
				q.enQueue(cur->p_right);
			}
		}

		// Thêm nullptr lại vào queue
		else if (!q.isEmpty()) q.enQueue(nullptr);
	}

	return count;
	
}


/*
*@brief 15. * Tính toán tầng của một NODE cho trước :
*@param pRoot - node gốc, p - node cần tìm tầng
*@return Tầng của Node cần tìm
*/
int BST::Level(BSTNode* p) {


	return Height() - heightNode(p->key);
}


/*
*@brief: 16. * Đếm số lá của một cây nhị phân :
*@param pRoot - node gốc
*@return Số node lá của cây
*/
int BST::countLeaf() {

	// Nếu cây rỗng trả về 0
	if (!pRoot) return 0;

	int count = 0;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		// Nếu không có con thì node đó là node lá
		if (!cur->p_left && !cur->p_right) count++;

		q.deQueue();

		
		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
				q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
				q.enQueue(cur->p_right);
		}
	}
		
	return count;	
}


/*17. * Đếm số NODE của một cây nhị phân tìm kiếm mà giá trị key nhỏ hơn giá trị cho trước :
*@param pRoot - node gốc, x - giá trị so sánh
*@return Số node nhỏ hơn x
*/
int BST::countLess(int x) {

	// Nếu cây rỗng trả về 0
	if (!pRoot) return 0;

	int count = 0;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		
		if (cur->key < x) count++;

		q.deQueue();


		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
			q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}
	}

	return count;
}


/*
*@brief 18. * Đếm số lượng NODE của một cây nhị phân tìm kiếm cho trước mà giá trị key lớn hơn giá trị cho trước :
*@param pRoot - node gốc, x - giá trị so sánh
*@return Số node lớn hơn x
*/
int BST::countGreater( int x) {

	// Nếu cây rỗng trả về 0
	if (!pRoot) return 0;

	int count = 0;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		
		if (cur->key > x) count++;

		q.deQueue();


		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
			q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}
	}

	return count;
}



// Đưa các giá trị trong cây vào Queue bằng trung thứ tự
Queue<int> BST::inOrder() {

	Queue<int> q;
	q.init();
	if (!pRoot) return q;


	Stack<BSTNode*> st;
	st.init();

	st.push(pRoot);
	
	while (!st.isEmpty()) {

		// Lấy đỉnh stack
		BSTNode* cur = st.gettop();

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Xóa bỏ đỉnh ( lúc này là nullptr)
			st.pop();

			// In ra đỉnh stack 
			q.enQueue(st.gettop()->key);
			
		}

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Lấy đỉnh stack 
			cur = st.gettop();

			// Nếu không có con phải thì xóa khỏi stack
			if (!cur->p_right) {
				st.pop();
			}

			// Ngược lại thì xóa khỏi stack và thêm con phải vào stack
			else {
				st.pop();
				st.push(cur->p_right);

			}

		}

		// Nếu cur khác nullptr ( chưa thăm hết con trái )

		else {

			if (cur->p_left) {

			    // Đẩy vào stack nullptr và con trái xen kẽ nhau để đánh dấu các node đã thăm con trái
				while (cur && cur->p_left) {

					st.push(nullptr);

					st.push(cur->p_left);

					cur = cur->p_left;
				}
			}

			// Nếu không có con trái 
			else {

				// Không có con phải
				if (!cur->p_right) {
					q.enQueue(cur->key);
					st.pop();
				}

				// Có con phải
				else {
					q.enQueue(cur->key);
					st.pop();
					st.push(cur->p_right);

				}
			}
		}
	}

}


/* 
*brief 19. Xác định cây nhị phân có phải là cây nhị phân tìm kiếm hay không :
*@param pRoot - node gốc
*@return Nếu là cây nhị phân tìm kiếm trả về true, ngược lại trả về false
*/
bool BST::isBST() {

	// Khởi tạo hàng đợi
	Queue<int> q;
	q.init();

    // Đưa giá trị các node của cây vào hàng đợi theo trung thứ tự
	//q = inOrder();

	// Nếu dãy giá trị lưu trong queue không phải dãy tăng ngặt thì cây đó công phải cây nhị phân tìm kiếm
	while (!q.isEmpty()) {

		int temp = q.getfront();

		q.deQueue();

		if (temp >= q.getfront()) {
			return false;
		}

	}
	return true;
}


/* 
*@brief 20. * Xác định cây nhị phân có phải là cây nhị phân tìm kiếm đầy đủ hay không :
*@param pRoot - node gốc
*@return Nếu là cây nhị phân tìm kiếm đầy đủ thì trả về true, ngược lại trả về false
*/
bool BST::isFullBST() {

	// Nếu cây rỗng trả về true
	if (!pRoot) return true;

	Queue<BSTNode*> q;

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (q.size != 1) {

		BSTNode* cur = q.getfront();

		// In giá trị của Node ở đầu hàng đợi sau đó xóa nó khỏi hàng đợi
		
		if ((!cur->p_left && cur->p_right) || (!cur->p_right && cur->p_left))  return false;

		q.deQueue();


		// Thêm node con trái vào hàng đợi
		if (cur->p_left) {
			q.enQueue(cur->p_left);
		}
		// Thêm node con phải vào hàng đợi
		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}
	}

	return true;
}


/*
* @brief Copy giá trị từ một cây cho trước
* @param Cây cần copy
* @return Cây sau khi copy
*/
void BST::copy(const BST &tree) {

	Queue<BSTNode*> q;

	q.init();

	q.enQueue(tree.pRoot);

	while (!q.isEmpty()) {

		BSTNode* cur = q.getfront();

		Insert(cur->key);

		q.deQueue();

		if (cur->p_left)
			q.enQueue(cur->p_left);

		if (cur->p_right)
			q.enQueue(cur->p_right);

	}

	q.deleteQueue();

}