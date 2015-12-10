#ifndef LINKED_LIST
#define LINKED_LIST
typedef struct LinkedListNode{
    int data;
    struct LinkedListNode* next;
}LinkedListNode;

class LinkedList{
    public:
	LinkedList();
	LinkedListNode* get_head();
	void set_head(LinkedListNode* head);
	LinkedListNode* get_tail();
	LinkedListNode* get_node_by_index(int index);
	LinkedListNode* get_node_kth_from_tail(int k);
	LinkedListNode* get_node_kth_from_tail_2(int k);
	void reverse_list();
	void reverse_list_in_recursive();
	void reverse_list_in_recursive(LinkedListNode* node);
	void insert(int value);
	void remove_by_value(int value);
	void print();
	void print_reverse();
	void print_reverse(LinkedListNode* node);
	void print_reverse_no_recursive();
	//O(1)时间内删除指针指向的节点
	void remove(LinkedListNode* node_to_be_deleted);
	LinkedListNode* first_common_node_with_stack(LinkedList* another_list );
	LinkedListNode* first_common_node_no_stack(LinkedList* another_list );
	int length();
	void join(LinkedListNode* node );//和另外一个链表对接
	~LinkedList();
    private:
    LinkedListNode* head;	
};

#endif
