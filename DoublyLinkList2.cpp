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

	//��ͷ�ڵ�ǰ���ӽڵ�
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
	//��β�ڵ�����ӽڵ�
	void InsertTail(int value) {
		Node* curr = new Node(value);
		if (!head) {
			head = tail = curr;
		}
		//����ԭ��:��Ȼ�Ѿ���β�ڵ�ָ���ˣ�Ϊ�λ����ٻ���ʱ��ȥѰ��β�ڵ����ģ�����������
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

	//ɾ��һ��ָ��ֵ�ڵ�
	void DeleteOneNode(int value) {
		if (!head)return;
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				if (curr->prev) {
					curr->prev->next = curr->next;
				}
				else {//ǰ���޽ڵ㣬˵���˽ڵ���ͷ�ڵ�
					head = curr->next;
				}
				if (curr->next) {
					curr->next->prev = curr->prev;
				}
				else {//�����޽ڵ㣬˵���˽ڵ���β�ڵ�
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
				else {//ǰ���޽ڵ㣬˵���˽ڵ���ͷ�ڵ�
					head = curr->next;
				}
				if (curr->next) {
					curr->next->prev = curr->prev;
				}
				else {//�����޽ڵ㣬˵���˽ڵ���β�ڵ�
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
		Node* curr = head;
		while (curr) {
			if (curr->val == value) {
				return curr;
			}
			curr = curr->next;
		}
		return nullptr;
	}
	//�޸�ָ��ֵ�ڵ��ֵ
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


	//�˴�����δ��node���п�ָ���ж�
	/*Node* node = list->FindNode(4);
	std::cout << node->val << std::endl;*/

	// ����ָ��ֵ�Ľڵ�
	Node* node = list->FindNode(4);
	if (node) {
		std::cout << node->val << std::endl;
	}
	else {
		std::cout << "Node not found." << std::endl;
	}

	list->ChangeNodeVal(4, 99);

	list->PrintList();


	//֮ǰ����δʹ��delete���ͷ�list
	//free����������������������delete��������е���������
	delete list;

	return 0;
}