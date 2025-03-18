#include<iostream>
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node(int value) :val(value), prev(nullptr), next(nullptr){}
};

//此为普通双链表，不是循环双链表
class DoublyLinkList {
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkList():head(nullptr),tail(nullptr){}

	//返回头节点的值
	int Front() {
		return head->val;
	}

	//返回尾节点的值
	int Back() {
		return tail->val;
	}

	//在头部插入节点
	void InsertHead(int value) {
		Node* newnode = new Node(value);
		if (!head) {
			head = tail = newnode;
		}
		else {
			head->prev = newnode;
			newnode->next = head;
			head = newnode;
		}
	}
	//在尾部插入节点
	void InsertTail(int value) {
		Node* newnode = new Node(value);
		if (!head) {
			head = tail = newnode;
		}
		else {
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
	}


	//删除一个指定值节点
	void DeleteOneNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {//如果前面有节点
					curr->prev->next = curr->next;
				}
				else {//前面没有节点，所以这是头节点的处理
					head = curr->next;
				}
				if (curr->next) {//如果后面有节点
					curr->next->prev = curr->prev;
				}
				else {//后面没有节点，所以这是尾节点的处理
					tail = curr->prev;
				}
				delete curr;
				return;
			}
			curr = curr->next;
		}
	}
	//删除所以指定值节点
	void DeleteAllNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {
					curr->prev->next = curr->next;
				}
				else {//即这是头节点的处理情况
					head = curr->next;
				}
				if (curr->next) {
					curr->next->prev = curr->prev;
				}
				else {//即这是尾节点的处理情况
					tail = curr->prev;
				}
				Node* tmp = curr;
				curr = curr->next;
				delete tmp;
			}
			else {
				curr = curr->next;
			}
		}
	}
	//查找指定值节点
	Node* FindNode(int value) {
		if (!head)return nullptr;
		Node* curr = head;
		while (curr) {
			if (curr->val == value)
			{
				return curr;
			}
			curr = curr->next;
		}
		return nullptr;
	}
	//更改一个指定值节点的值
	void ChangeOneNodeVal(int oldval, int newval) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == oldval) {
				curr->val = newval;
				return;
			}
			curr = curr->next;
		}
	}
	//更改所有指定值节点的值
	void ChangeAllNodeVal(int oldval, int newval) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == oldval) {
				curr->val = newval;
			}
			curr = curr->next;
		}
	}
	//打印链表
	void PrintList() {
		if (head == nullptr)return;
		Node* curr = head;
		while (curr != nullptr) {
			std::cout << curr->val << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}
	
	~DoublyLinkList() {
		//释放链表所有节点
		while (head != nullptr) {
			Node* curr = head;
			head = head->next;
			delete curr;
		}
	}
};

int main() {
	DoublyLinkList* list = new DoublyLinkList();
	for (int i = 0; i < 3; i++) {
		list->InsertHead(i);
	}
	for (int i = 0; i < 3; i++) {
		list->InsertTail(i);
	}
	
	//std::cout << list->Back() <<" " << list->Front() << std::endl;

	//Node* node = list->FindNode(1);
	//std::cout << node->val << std::endl;

	//list->ChangeOneNodeVal(1, 99);

	//list->ChangeAllNodeVal(2, 999);

	//list->DeleteOneNode(2);
	//list->DeleteOneNode(1);
	//list->DeleteAllNode(2);
	//list->DeleteAllNode(0);
	list->PrintList();


	return 0;
}