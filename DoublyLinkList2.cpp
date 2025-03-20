#include<iostream>

class Node {
public:
	int val;
	Node* prev;
	Node* next;
public:
	Node(int value):val(value),prev(nullptr),next(nullptr){}
};

class DoublyLinkList {
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkList() :head(nullptr), tail(nullptr) {}

	//在头节点前增加节点
	void InsertHead(int value) {
		Node* curr = new Node(value);
		if (!head) {
			head = tail = curr;
			return;
		}
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	//在尾节点后增加节点
	void InsertTail(int value) {
		Node* curr = new Node(value);
		if (!head) {
			head = tail = curr;
		}
		//错误原因:既然已经有尾节点指针了，为何还有再花费时间去寻找尾节点在哪？？？！！！
		/*Node* tmp = head;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = curr;
		curr->prev = tmp;
		tail = curr;*/
		else {
			tail->next = curr;
			curr->prev = tail;
			tail = curr;
		}
	}

	//删除一个指定值节点
	void DeleteOneNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {
					curr->prev->next = curr->next;
				}
				else {//前面无节点，说明此节点是头节点
					head = curr->next;
				}
				if (curr->next) {
					curr->next->prev = curr->prev;
				}
				else {//后面无节点，说明此节点是尾节点
					tail = curr->prev;
				}
				delete curr;
				return;
			}
			curr = curr->next;
		}
	}
	//删除所有指定值节点
	void DeleteAllNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {
					curr->prev->next = curr->next;
				}
				else {//前面无节点，说明此节点是头节点
					head = curr->next;
				}
				if (curr->next) {
					curr->next->prev = curr->prev;
				}
				else {//后面无节点，说明此节点是尾节点
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
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				return curr;
			}
			curr = curr->next;
		}
		return nullptr;
	}
	//修改指定值节点的值
	void ChangeNodeVal(int oldval, int newval) {
		Node* curr = head;
		while (curr) {
			if (curr->val == oldval) {
				curr->val = newval;
				return;
			}
			curr = curr->next;
		}
	}

	void PrintList() {
		Node* curr = head;
		while (curr) {
			std::cout << curr->val << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}

	~DoublyLinkList() {
		while (head) {
			Node* curr = head;
			head = head->next;
			delete curr;
		}
	}
};


int main()
{
	DoublyLinkList* list = new DoublyLinkList();
	for (int i = 1; i < 5; ++i) {
		list->InsertHead(i);
	}
	for (int i = 1; i < 5; ++i) {
		list->InsertHead(i);
	}
	for (int i = 1; i < 5; ++i) {
		list->InsertHead(i);
	}
	for (int i = 10; i < 15; ++i) {
		list->InsertTail(i);
	}
	for (int i = 10; i < 15; ++i) {
		list->InsertTail(i);
	}
	
	//list->DeleteOneNode(4);
	//list->DeleteOneNode(1);

	//list->DeleteAllNode(4);
	//list->DeleteAllNode(1);


	//此处犯错，未对node进行空指针判断
	/*Node* node = list->FindNode(4);
	std::cout << node->val << std::endl;*/

	// 查找指定值的节点
	Node* node = list->FindNode(4);
	if (node) {
		std::cout << node->val << std::endl;
	}
	else {
		std::cout << "Node not found." << std::endl;
	}

	list->ChangeNodeVal(4, 99);

	list->PrintList();


	//之前错误，未使用delete来释放list
	//free不会调用类的析构函数，而delete会调用类中的析构函数
	delete list;

	return 0;
}