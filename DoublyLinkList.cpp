#include<iostream>
class Node {
public:
	int val;
	Node* prev;
	Node* next;
	Node(int value) :val(value), prev(nullptr), next(nullptr){}
};

//��Ϊ��ͨ˫��������ѭ��˫����
class DoublyLinkList {
private:
	Node* head;
	Node* tail;
public:
	DoublyLinkList():head(nullptr),tail(nullptr){}

	//����ͷ�ڵ��ֵ
	int Front() {
		return head->val;
	}

	//����β�ڵ��ֵ
	int Back() {
		return tail->val;
	}

	//��ͷ������ڵ�
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
	//��β������ڵ�
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


	//ɾ��һ��ָ��ֵ�ڵ�
	void DeleteOneNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {//���ǰ���нڵ�
					curr->prev->next = curr->next;
				}
				else {//ǰ��û�нڵ㣬��������ͷ�ڵ�Ĵ���
					head = curr->next;
				}
				if (curr->next) {//��������нڵ�
					curr->next->prev = curr->prev;
				}
				else {//����û�нڵ㣬��������β�ڵ�Ĵ���
					tail = curr->prev;
				}
				delete curr;
				return;
			}
			curr = curr->next;
		}
	}
	//ɾ������ָ��ֵ�ڵ�
	void DeleteAllNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {
					curr->prev->next = curr->next;
				}
				else {//������ͷ�ڵ�Ĵ������
					head = curr->next;
				}
				if (curr->next) {
					curr->next->prev = curr->prev;
				}
				else {//������β�ڵ�Ĵ������
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
	//����ָ��ֵ�ڵ�
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
	//����һ��ָ��ֵ�ڵ��ֵ
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
	//��������ָ��ֵ�ڵ��ֵ
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
	//��ӡ����
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
		//�ͷ��������нڵ�
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