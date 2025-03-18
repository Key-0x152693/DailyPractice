#include<iostream>
//定义单链表节点结构
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};
};

//创建一个单链表
ListNode* CreateList(int value) {
	return new ListNode(value);
}

//头部插入
ListNode* InsertHead(ListNode* head, int value) {
	ListNode* newhead = CreateList(value);
	newhead->next = head;
	return newhead;
}

//尾部插入
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

//删除值为val的节点
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

//查询值为value的节点
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

//更改值为value的节点的值
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


//输出链表
void PrintList(ListNode* head) {
	ListNode* curr = head;
	while (curr!= nullptr) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

//释放链表
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

	//后插
	for (int j = 0; j < 10; j++) {
		head=InsertTail(head, ++i);
	}

	//前插
	for (int j = 0; j < 10; j++) {
		head = InsertHead(head, ++i);
	}

	//删除value值的节点
	head = DeleteNode(head, 10);

	//查询并获取value值的节点
	ListNode* list = nullptr;
	list = FindNode(head, 15);
	std::cout << list->val << std::endl;

	//更改值为value的节点的值
	head = ModifyNode(head, 20, 99);

	//打印链表
	PrintList(head);

	//释放链表
	FreeList(head);

	return 0;
}