#include<iostream>
#include<vector>

class Node {
public:
	int val;
	Node* next;
	Node(int value):val(value),next(nullptr){}
};

class SingleList {
private:
	Node* head;
public:
	SingleList():head(nullptr){}

	//��ͷ�ڵ�ǰ���ӽڵ�
	void InsertHead(int value) {
		Node* newnode = new Node(value);
		newnode->next = head;
		head = newnode;
	}
	//��β�ڵ�����ӽڵ�
	void InsertTail(int value) {
		Node* newnode = new Node(value);
		if (!head) {
			head = newnode;
			//InsertHead(value);
			return;
		}
		Node* curr = head;
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newnode;
	}
	//ɾ��һ��ָ��ֵ�ڵ�
	void DeleteOneNode(int value) {
		if (!head)return;
		if (head->val == value) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
			return;
		}
		Node* curr = head;
		while (curr->next) {
			if (curr->next->val == value) {
				Node* tmp = curr->next;
				curr->next = curr->next->next;
				delete tmp;
				return;
			}
			else {
				curr = curr->next;
			}
		}
	}

	//ɾ������ָ��ֵ�ڵ�
	void DeleteAllNode(int value) {
		while (head && head->val == value ) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
		if (!head)return;
		Node* curr = head;
		while (curr->next) {
			if (curr->next->val == value) {
				Node* tmp = curr->next;
				curr->next = curr->next->next;
				delete tmp;
			}
			else {
				curr = curr->next;
			}
		}
	}

	//��ѯָ��ֵ�ڵ�
	Node* FindNode(int value) {
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				return curr;
			}
			else {
				curr = curr->next;
			}
		}
		return nullptr;
	}

	//����һ��ָ��ֵ�ڵ��ֵ
	void ChangeOneNodeVal(int oldval, int newval) {
		Node* curr = head;
		while (curr) {
			if (curr->val == oldval) {
				curr->val = newval;
				return;
			}
			else {
				curr = curr->next;
			}
		}
	}

	//��������ָ��ֵ�ڵ��ֵ
	void ChangeAllNodeVal(int oldval, int newval) {
		Node* curr = head;
		while (curr) {
			if (curr->val == oldval) {
				curr->val = newval;
				curr = curr->next;
			}
			else {
				curr = curr->next;
			}
		}
	}

	//��ӡ��������ڵ��ֵ
	void PrintList() {
		Node* curr = head;
		while (curr) {
			std::cout << curr->val << " ";
			curr = curr->next;
		}
		std::cout << std::endl;
	}

	~SingleList() {
		while (head) {
			Node* curr = head;
			head = head->next;
			delete curr;
		}
	}
};

int main() {

	SingleList* list = new SingleList();

	for (int i = 0; i < 5; ++i) {
		list->InsertHead(i);
	}

	for (int i = 0; i < 5; ++i) {
		list->InsertTail(i);
	}

	//list->DeleteOneNode(2);

	//list->DeleteAllNode(4);

	list->ChangeOneNodeVal(0, 99);

	list->ChangeAllNodeVal(4, 88);

	list->PrintList();

	return 0;
}