#include<iostream>
#include<string>
#include<cmath>
#include<stdlib.h>
using namespace std;
struct NODE {
	string data;
	struct NODE* next;
};
struct node {
	float data;
	struct node* next;
};
NODE* createnode(string x) {
	NODE* p = new NODE;
	if (!p) return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}
node* cre(float x) {
	node* p = new node;
	if (!p) return NULL;
	p->data = x;
	p->next = NULL;
	return p;
}
void addfirst(NODE*& phead, NODE* p) {
	if (!phead) {
		phead = p;
	}
	else {
		p->next = phead;
		phead = p;
	}
}
void addfirst1(node*& phead, node* p) {
	if (!phead) {
		phead = p;
	}
	else {
		p->next = phead;
		phead = p;
	}
}
void addlast(NODE*& phead, NODE* p) {
	if (!phead) {
		phead = p;
	}
	else {
		NODE* tmp = phead;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
void deletefirst(NODE*& phead) {
	if (!phead) return;
	NODE* tmp = phead;
	phead = phead->next;
	delete tmp;
}
void deletefirst1(node*& phead) {
	if (!phead) return;
	node* tmp = phead;
	phead = phead->next;
	delete tmp;
}
int preorder(string x) {
	if (x == "+") return 0;
	if (x == "-") return 1;
	if (x == "*") return 2;
	if (x == "/") return 3;
	if (x == "^") return 4;
}
//kiểm tra toán hạng
bool check(string x) {
	if (x == "+" || x == "-" || x == "*" || x == "/" || x == "^") return 1;
	return 0;
}
NODE* infixtopostfix(string s) {
	string s1 = '(' + s +')';
	NODE* a=NULL;
	NODE* b=NULL;
	string tmp = "";
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == ' ') continue;
		if (s1[i] == '(') {
			string x = "";
			x += s1[i];
			NODE* p = createnode(x);
			addfirst(a, p);
		}
		else if (isdigit(s1[i])!=0 ) {
			tmp += s1[i];
			if (i == s1.size() - 1 || isdigit(s1[i + 1])==0) {
				NODE* p = createnode(tmp);
				addlast(b, p);
				tmp = "";
			}
		}
		else if (s1[i] == ')') {
	
			while (a->data!="(") {
				NODE* p = createnode(a->data);
				addlast(b, p);
				deletefirst(a);
			}
			deletefirst(a);
		}
		else {
			if (check(a->data)) {
				string cur = "";
				cur += s1[i];
				if (preorder(cur) > preorder(a->data)) {
					NODE* p = createnode(cur);
					addfirst(a, p);
				}
				else {
					string cur = "";
					cur += s1[i];
					NODE* k = createnode(a->data);
					addlast(b, k);
					deletefirst(a);
					NODE* p = createnode(cur);
					addfirst(a, p);
				}
			}
			else {
				string cur = "";
				cur += s1[i];
				NODE* p = createnode(cur);
				addfirst(a, p);
			}
		}
	}
	return b;
}
float caculate(string s) {
	NODE*b = infixtopostfix(s);
	node* a = NULL;
	while (b) {
		if (atof(b->data.c_str())) {
			node* p = cre(atof(b->data.c_str()));
			addfirst1(a, p);
		}
		else if (b->data == "+") {
			a->next->data += a->data;
			deletefirst1(a);
		}
		else if (b->data == "-") {
			a->next->data -= a->data;
			deletefirst1(a);
		}
		else if (b->data == "*") {
			a->next->data *= a->data;
			deletefirst1(a);
		}
		else if (b->data == "/") {
			a->next->data /= a->data;
			deletefirst1(a);
		}
		else if (b->data == "^") {
			a->next->data = pow(a->next->data, a->data);
			deletefirst1(a);
		}
		b = b->next;
	}
	return a->data;
	
}
int main() {
	string s;
	getline(cin, s);
	cout<<caculate(s);

}


//------------------------------------------------------------------------------

#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
struct NODE {
	float data;
	struct NODE* next;
};
NODE* createnode(float x) {
	NODE* p = new NODE;
	p->data = x;
	p->next = NULL;
	return p;
}
void addfirst(NODE* &phead, NODE* p) {
	if (!phead) {
		phead = p;
	}
	else {
		p->next = phead;
		phead = p;
	}
}
void deletefirst(NODE*& phead) {
	if (!phead) return;
	NODE* tmp = phead;
	phead = phead->next;
	delete tmp;
}
int caculate(string s) {
	NODE* p = NULL;
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if(isdigit(s[i])) tmp += s[i];
		if (s[i] == '-' && isdigit(s[i + 1])) tmp += s[i];
		if (s[i] == ' ' && isdigit(s[i - 1])) {
			NODE* k = createnode(atof(tmp.c_str()));
			addfirst(p, k);
			tmp = "";
		}
		if (s[i] == '+') {
			p->next->data += p->data;
			deletefirst(p);
		}
		if (s[i] == '-'&&s[i+1]==' ') {
			p->next->data -= p->data;
			deletefirst(p);

		}
		if (s[i] == '*') {
			p->next->data *= p->data;
			deletefirst(p);
		}
		if (s[i] == '/') {
			p->next->data /= p->data;
			deletefirst(p);
		}
	}
	return p->data;
}
int main() {
	string s;
	getline(cin, s);
	cout<<caculate(s);
}
