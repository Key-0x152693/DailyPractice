#include<iostream>
//���嵥����ڵ�ṹ
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};

//����һ��������
ListNode* CreateList(int value) {
	return new ListNode(value);
}

//ͷ������
ListNode* InsertHead(ListNode* head, int value) {
	ListNode* newhead = CreateList(value);
	newhead->next = head;
	return newhead;
}

//β������
ListNode* InsertTail(ListNode* head, int value) {
	ListNode* new_node = CreateList(value);
	if (head == nullptr) {
		return new_node;
	}
	ListNode* curr = head;
	while (curr->next != nullptr) {
		curr = curr->next;
	}
	curr->next = new_node;
	return head;
}

//ɾ��ֵΪval�Ľڵ�
ListNode* DeleteNode(ListNode* head,int value) {
	if (head == nullptr)return nullptr;
	if (head->val == value) {
		ListNode* curr = head;
		head = head->next;
		delete curr;
	}
	ListNode* ln = head;
	ListNode* nln = head->next;
	while (nln != nullptr) {
		if (nln->val == value) {
			ln->next = nln->next;
			delete nln;
			return head;
		}
		ln = nln;
		nln = nln->next;
	}
	return head;
}

//��ѯֵΪvalue�Ľڵ�
ListNode* FindNode(ListNode* head, int value) {
	if (head == nullptr)return nullptr;
	ListNode* curr = head;
	while (curr != nullptr) {
		if (curr->val == value) {
			return curr;
		}
		curr = curr->next;
	}
	return nullptr;
}

//����ֵΪvalue�Ľڵ��ֵ
ListNode* ModifyNode(ListNode* head, int oldvalue, int newvalue) {
	if (head == nullptr)return nullptr;
	ListNode* curr = head;
	while (curr != nullptr) {
		if (curr->val == oldvalue) {
			curr->val = newvalue;
			return head;
		}
		curr = curr->next;
	}
	return head;
}


//�������
void PrintList(ListNode* head) {
	ListNode* curr = head;
	while (curr!= nullptr) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

//�ͷ�����
void FreeList(ListNode* head) {
	while (head != nullptr) {
		ListNode* curr = head;
		head = head->next;
		delete curr;
	}
}

int main() {
	int i = 0;
	ListNode* head = nullptr;

	//���
	for (int j = 0; j < 10; j++) {
		head=InsertTail(head, ++i);
	}

	//ǰ��
	for (int j = 0; j < 10; j++) {
		head = InsertHead(head, ++i);
	}

	//ɾ��valueֵ�Ľڵ�
	head = DeleteNode(head, 10);

	//��ѯ����ȡvalueֵ�Ľڵ�
	ListNode* list = nullptr;
	list = FindNode(head, 15);
	std::cout << list->val << std::endl;

	//����ֵΪvalue�Ľڵ��ֵ
	head = ModifyNode(head, 20, 99);

	//��ӡ����
	PrintList(head);

	//�ͷ�����
	FreeList(head);

	return 0;
}