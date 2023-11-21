#include "AVL.h"
#include "queue.h"
#include"stack.h"


/*
* @brief  1. Khởi tạo một NODE từ một giá trị cho trước :
* @param data - key của node cần tạo
* @return Node vừa được tạo, nếu lỗi trả về nullptr
*/
AVL::AVLNode* AVL::createNode( int data) {
	 
	    AVLNode* newNode = new AVLNode;
	

		newNode->key = data;

		newNode->p_left = nullptr;

		newNode->p_right = nullptr;

		newNode->height = 1;

		if(newNode)
		    return newNode;
	
	    else
			return nullptr;

}


/* 
* @brief Tìm giá trị lớn nhất giữa hai số nguyên
* @param a và b 
* @return giá trị lớn hơn giữa a và b
*/
int AVL::max(int a, int b) {

	if (a > b) return a;

	else return b;
}


/* 
*@brief Tìm chiều cao của một node 
*@param pRoot - node cần tìm chiều cao
*@return chiều cao của node
*/
int AVL::Height(AVLNode* p) {

	// Nếu cây rỗng trả về 0
	if (!p) 
		return 0;
	
	return p->height;	
}


/*
*@brief Hiệu chiều cao cây con trái và cây con phải của một node
*@param pRoot - node cần tìm  
*@return hiệu chiều cao cây con trái và phải
*/
int AVL::differentHeight(AVLNode* p){

	if (!p) return 0;
	
	return Height( p->p_left) - Height( p->p_right);

}


/*
*@brief Xoay phải một node
*@param a - node cần xoay 
*@return b - node cha mới sau khi xoay
*/
AVL::AVLNode* AVL::rightRotation(AVLNode* a) {

	AVLNode* b = a->p_left;
	AVLNode* temp = b->p_right;

	b->p_right = a;
	a->p_left = temp;
	
	a->height = max(Height(a->p_left), Height(a->p_right)) + 1;
	b->height = max(Height(b->p_left), Height(b->p_right)) + 1;

	return b;
}


/*
*@brief Xoay trái một node
*@param a - node cần xoay 
*@return b - node cha mới sau khi xoay
*/
AVL::AVLNode* AVL::leftRotation(AVLNode* a) {

	AVLNode* b = a->p_right;
	AVLNode* temp = b->p_left;

	b->p_left = a;
	a->p_right = temp;

	a->height = max(Height(a->p_left), Height(a->p_right)) + 1;
	b->height = max(Height(b->p_left), Height(b->p_right)) + 1;
	
	return b;
}


/*
* @brief Tìm vị trí làm cha của node cần thêm đồng thời thêm tất cả các node tổ tiên vào stack
* @param x - giá trị node cần thêm
* @param st - Stack chứa các node tổ tiên
* @return Trả về node tìm được
*/
AVL::AVLNode* AVL::findPosition(int x, Stack<AVLNode*> &st) {

	AVLNode* p_cur = getpRoot();

	if (!p_cur) return nullptr;


	AVLNode* parent = nullptr;

	while (p_cur) {

		if (x > p_cur->key) {

			parent = p_cur;
			st.push(parent);
			p_cur = p_cur->p_right;
		}
		else if (x < p_cur->key) {
			
			parent = p_cur;
			st.push(parent);
			p_cur = p_cur->p_left;
		}
		else return nullptr;
	}
	

	return parent;
}



/*
* @brief Thực hiện cân bằng cây tại vị trí mất cân bằng
* @param p - Node cần xoay
* @param x - giá trị node gây mất cân bằng
* @param sub - hiệu của cây con trái và phải của p
* @return Node thu được sau khi xoay
*/
AVL::AVLNode* AVL::Rotation(AVLNode* p, int x, int sub) {

	// Nếu mất cân bằng trái
	if (sub > 1) {
		// x lớn hơn giá trị key con pRoot->p_left nên cây mất cân bằng trái-phải
		if (x > p->p_left->key) {

			p->p_left = leftRotation(p->p_left);
		
				p = rightRotation(p);

				return p;
			
		}
		// x lớn hơn giá trị key con pRoot->p_left nên cây mất cân bằng trái-trái
		else if (x < p->p_left->key) {		
				p = rightRotation(p);
				return p;
		}


	}
	// Nếu mất cân bằng phải
	else if (sub < -1) {

		// x lớn hơn giá trị key con pRoot->p_left nên cây mất cân bằng trái-phải
		if (x > p->p_right->key) {
			
				p = leftRotation(p);
				return p;
			
		}
		// x lớn hơn giá trị key con pRoot->p_left nên cây mất cân bằng trái-trái
		else if (x < p->p_right->key) {

			p->p_right = rightRotation(p->p_right);

				p = leftRotation(p);
				return p;
			
		}

	}
	return p;
}




/*
* @brief Cật nhật chiều cao toàn bộ node trong cây
* @param p - Node gốc
* @return Cây sau khi cập nhật
*/
void AVL::UpdateHeight(AVLNode* p) {

	Queue<AVLNode*> q;

	Stack<AVLNode*> st;

	st.init();

	q.init();

	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		AVLNode* cur = q.getfront();

		st.push(cur);
		// In giá trị của Node ở đầu hàng đợi sau đó xóa nó khỏi hàng đợi
		//cur->height = max(Height(cur->p_left), Height(cur->p_right)) + 1;
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

	while (!st.isEmpty()) {

		AVLNode* cur = st.gettop();

		cur->height = max(Height(cur->p_left), Height(cur->p_right)) + 1;

		st.pop();
	}

}



/*
*@brief 2. Thêm một NODE có giá trị cho trước vào cây AVL cho trước(Chú ý giá trị cho trước có tồn tại hay chưa) :
*@param pRoot - node gốc, x - giá trị cần thêm
*@return cây sau khi thêm
*/
void AVL::Insert(int x) {

	if (!getpRoot()) {

		AVL::pRoot = createNode(x);

		return;
	}
	Stack<AVLNode*> st;

	st.init();

	st.push(nullptr);

	AVLNode* temp = findPosition(x,st);

	// Nếu đã tồn tại
	if (!temp) return;


	if (x > temp->key) temp->p_right = createNode(x);


	else if (x < temp->key) temp->p_left = createNode(x);

	UpdateHeight(pRoot);


	AVLNode* updatedNode = nullptr;

	while (!st.isEmpty()) {

		
		AVLNode* top = st.gettop();

		int sub = differentHeight(top);

		st.pop();

		if (sub > 1 || sub < -1) {

			 updatedNode = Rotation(top,x,sub);

			 if(st.gettop() == nullptr)

			 pRoot = updatedNode;

			 else {
				 if (top->key < st.gettop()->key) {
					 
					 st.gettop()->p_left = updatedNode;
				 }
				 else if(temp->key > st.gettop()->key){
					 
			         st.gettop()->p_right = updatedNode;
				 }

			 }

			 UpdateHeight(pRoot);
			
		 }
				
	 }
	
	return ;
}


/*
* @brief Thực hiện xóa node
* @param cur - Node con
* @param parent - Node cha của cur
*/
void AVL::deleteNode(AVLNode* cur, AVLNode* parent, AVLNode* replace) {

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

		AVL::pRoot = replace;
		return;
	}

}



/*
*@brief 3. Xóa một NODE với giá trị cho trước từ một cây AVL cho trước (Chú ý giá trị đó có tồn tại hay không):
*@param pRoot - node gốc, x - giá trị cần xóa
*@return cây sau khi xóa
*/
void AVL::Remove(int x) {


	if (!pRoot) return;


	// Biến chạy cur
	AVLNode* cur = getpRoot();

	// Cha của cur
	AVLNode* parent = nullptr;

	while (cur) {

		// Nếu x lớn hơn key của cur thì chạy sang phải
		if (x > cur->key) {

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
				deleteNode(cur, parent,nullptr);
				break;

			}

			// Node cần xóa chỉ có con phải
			if (!cur->p_left) {

				deleteNode(cur, parent,cur->p_right);
				break;

			}

			// Node cần xóa chỉ có con trái
			else if (!cur->p_right) {
				
				deleteNode(cur, parent,cur->p_left);
				break;
			}

			// Node cần xóa có 2 con
			else {


				AVLNode* min = cur->p_right;

				AVLNode* parOfmin = cur->p_right;

				while (min && min->p_left) {

					parOfmin = min;

					min = min->p_left;
				}

				cur->key = min->key;

				if (min == cur->p_right) {

					AVL::pRoot->key = min->key;

					AVL::pRoot->p_right = nullptr;

					delete  min;

					break;
				}
				if (min->p_right) {

					parOfmin->p_left = min->p_right;

					delete min;

					break;
				}
				else {

					parOfmin->p_left = nullptr;

					delete min;

					break;
				}

			}
			break;

		}
	}

	if (!pRoot) return;

	 // Cập nhật chiều cao cây sau khi xóa
	UpdateHeight(pRoot);

	Stack<AVLNode*> st;

	st.init();

	st.push(nullptr);

	AVLNode* temp = findPosition(x, st);
	
	AVLNode* updatedNode = nullptr;

	while (!st.isEmpty()) {


		AVLNode* top = st.gettop();

		int sub = differentHeight(top);

		st.pop();

		if (sub > 1 || sub < -1) {

			int k;

			if (sub > 1) {

				if (top->p_left->p_left) {

					k = top->p_left->p_left->key;

				}
				else if (!top->p_left->p_left && top->p_left->p_right) {

					k = top->p_left->p_right->key;

				}
			}
			else if (sub < -1) {

				if (top->p_right->p_right) {

					k = top->p_right->p_right->key;
				}
				else if (!top->p_right->p_right && top->p_right->p_left) {

					k = top->p_right->p_left->key;

				}
			}
			updatedNode = Rotation(top, k, sub);

			if (st.gettop() == nullptr)

				pRoot = updatedNode;

			else {
				if (top->key < st.gettop()->key) {

					st.gettop()->p_left = updatedNode;
				}
				else if (temp->key > st.gettop()->key) {

					st.gettop()->p_right = updatedNode;
				}

			}

			UpdateHeight(pRoot);
		}
	}	

	st.deleteStack();
}


/* 
*@brief 4. Duyệt tiền thứ tự(key và height của NODE được yêu cầu) :
*@param pRoot - node gốc.
*@return key và height của các node.
*/
void AVL::NLR() {
	if (!pRoot) return;


	Stack<AVLNode*> st;
	st.init();


	st.push(pRoot);
	cout << pRoot->key << " " << pRoot->height << endl;
	while (!st.isEmpty()) {

		// Lấy đỉnh stack
		AVLNode* cur = st.gettop();

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Xóa bỏ đỉnh ( lúc này là nullptr)
			st.pop();

			// In ra đỉnh stack 

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
				cout << cur->p_right->key << " " << cur->p_right->height << endl;
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

					cout << cur->key << " " << cur->height << endl;;
				}
			}

			// Nếu không có con trái 
			else {

				// Không có con phải
				if (!cur->p_right) {
			
					st.pop();
				}

				// Có con phải
				else {
					cout << cur->p_right->key << " " << cur->p_right->key << endl;
					st.pop();
					st.push(cur->p_right);

				}
			}
		}
	}
}


/*
*@brief 5. Duyệt trung thứ tự(key và height của NODE được yêu cầu) :
*@param pRoot - node gốc.
*@return key và height của các node.
*/
void AVL::LNR() {
	if (!pRoot) return;


	Stack<AVLNode*> st;
	st.init();


	st.push(pRoot);

	while (!st.isEmpty()) {

		// Lấy đỉnh stack
		AVLNode* cur = st.gettop();

		// Nếu cur là nullptr chứng tỏ bên dưới đỉnh stack là 1 node đã thăm tất cả con trái
		if (!cur) {

			// Xóa bỏ đỉnh ( lúc này là nullptr)
			st.pop();

			// In ra đỉnh stack 

			cout << st.gettop()->key << " " << st.gettop()->height<<endl;
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
					cout << cur->key << " " << cur->height << endl;
					st.pop();
				}

				// Có con phải
				else {
					cout << cur->key << " " << cur->height << endl;
					st.pop();
					st.push(cur->p_right);

				}
			}
		}
	}
}


/* 
*@brief 6. Duyệt hậu thứ tự(key và height của NODE được yêu cầu) :
*@param pRoot - node gốc.
*@return key và height của các node.
*/
void AVL::LRN(AVLNode* pRoot) {
	if (!pRoot) {
		return;
	}
	LRN(pRoot->p_left);
	LRN(pRoot->p_right);
	cout << pRoot->key << " " << pRoot->height << endl;
}
void AVL::LRN() {
	LRN(AVL::pRoot);
}


/* 
*@brief 7. Duyệt theo tầng(key và height của NODE được yêu cầu) :
*@param pRoot - node gốc.
*@return key và height của các node.
*/
void AVL::LevelOrder() {
	if (!pRoot) return;

	// Khởi tạo hàng đợi
	Queue<AVLNode*> q;

	q.init();
	// Thêm pRoot vào hàng đợi
	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		AVLNode* cur = q.getfront();

		// In giá trị và chiều cao của Node ở đầu hàng đợi sau đó xóa nó khỏi hàng đợi
		cout << cur->key << " " << cur->height << endl;

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
*@brief 8. Xác định một cây nhị phân có phải là cây AVL không :
*@param pRoot - node gốc.
*@return true nếu là cây AVL, ngược lại trả về false.
*/
bool AVL::isAVL() {

	
	if (!pRoot) return true;

	Queue<AVLNode*> q;
	q.init();

	q.enQueue(pRoot);

	while (!q.isEmpty()) {

		AVLNode* cur = q.getfront();
		 
		if (differentHeight(cur) > 1 || differentHeight(cur) < -1)
			return false;

		q.deQueue();


		if (cur->p_left)
			q.enQueue(cur->p_left);

		if (cur->p_right) {
			q.enQueue(cur->p_right);
		}

	}
	
	q.deleteQueue();

	return true;
}



/*
* @brief Copy giá trị từ một cây cho trước
* @param Cây cần copy
* @return Cây sau khi copy
*/
void AVL::copy(const AVL &tree) {

	Queue<AVLNode*> q;
	q.init();

	q.enQueue(tree.pRoot);

	while (!q.isEmpty()) {

		AVLNode* cur = q.getfront();

		Insert(cur->key);

		q.deQueue();

		if (cur->p_left)
			q.enQueue(cur->p_left);

		if (cur->p_right)
			q.enQueue(cur->p_right);

	}

	q.deleteQueue();
}