#include "linked_list.h"
#include <iostream>
#include <stack>
using namespace std;

LinkedList::LinkedList(){
    head=NULL;
}
LinkedListNode* LinkedList::get_head(){
    return this->head;
}
void LinkedList::set_head(LinkedListNode* head){
    this->head=head;
}
LinkedListNode* LinkedList::get_tail(){
    if( this->head == NULL )
	return NULL;
    LinkedListNode* node=this->head;
    while( node->next != NULL ){
	node=node->next;
    }
    return node;
}
//下标从1开始
LinkedListNode* LinkedList::get_node_by_index(int index){
    if( index <= 0 || this->head==NULL)
	return NULL;
    LinkedListNode* node=this->head;
    int i=1;
    while( node != NULL && i <index){
	node=node->next;
	++i;
    }
    return node;
}

LinkedListNode* LinkedList::get_node_kth_from_tail(int k ){
    if( this->head == NULL || k <= 0 )
	return NULL;
    stack<LinkedListNode*> list;
    LinkedListNode* node=this->head;
    while( node != NULL ){
	list.push(node);
	node=node->next;
    }
    int i=1;
    LinkedListNode* kth_from_tail=NULL;
    LinkedListNode* top;
    while( ! list.empty() ){
	top=list.top();
	if( k == i ){
	    kth_from_tail=top;
	    break;
	}
	++i;
	list.pop();
    }
    return kth_from_tail;
}
//这里检查k的值很有必要
//如果代码里面存在k-1这种操作，由于k是无符号整数，这样会导致k变成一个非常大的整数，从而导致程序崩溃
//但是在这里的实现中没有这个操作
LinkedListNode* LinkedList::get_node_kth_from_tail_2(int k ){
    if( this->head == NULL || k <= 0 )
	return NULL;
    LinkedListNode* pfront=this->head;
    LinkedListNode* pback=this->head;
    int i=1;
    while( i < k && pfront != NULL ){
	pfront=pfront->next;
	++i;
    }
    if( pfront == NULL )
	return NULL;

    while( pfront->next != NULL ){
	pfront=pfront->next;
	pback=pback->next;
    }
    return pback;
}

void LinkedList::reverse_list(){
    if( this->head == NULL || this->head->next == NULL )
	return;

    LinkedListNode* back_node=this->head;
    LinkedListNode* front_node=this->head->next; 
    while( front_node != NULL ){
	LinkedListNode* tmp_node=front_node->next;
	front_node->next=back_node;
	//设置头节点的next为空，否则，链表就不会有尾节点了
	if( back_node == this->head )
	    back_node->next= NULL;
	back_node=front_node;
	front_node=tmp_node;
    }
    this->head=back_node;
}

void LinkedList::reverse_list_in_recursive(){
    this->reverse_list_in_recursive(this->head);
}

void LinkedList::reverse_list_in_recursive(LinkedListNode* node){
    if( node == NULL )
	return;
    LinkedListNode* next_node=node->next;
    if( node == this->head )
	node->next=NULL;
    reverse_list_in_recursive(next_node);
    if( next_node != NULL ){
	next_node->next=node;
    }else{
	this->head=node;
    }
}

void LinkedList::insert( int value){
    LinkedListNode* new_node=new LinkedListNode();
    new_node->data=value;
    new_node->next=NULL;
    LinkedListNode* node=this->head;
    if( node == NULL ){
	this->head=new_node;
    }else{
	while(node->next != NULL ){
	    node=node->next;
	}
	node->next=new_node;
    }
}

void LinkedList::remove_by_value(int value ){
    if( this->head== NULL )
	return;
    LinkedListNode* node_to_be_deleted;
    if( this->head->data == value ){
	node_to_be_deleted=this->head;
	this->head=this->head->next;
	delete node_to_be_deleted;
	return;
    }
    LinkedListNode* node=this->head;
    while( node->next != NULL &&  node->next->data != value ){
	node=node->next;
    }
    if( node->next == NULL )
	return;
    if( node->next->data==value){
	node_to_be_deleted=node->next;
	node->next=node->next->next;
    }
}

void LinkedList::remove(LinkedListNode* node_to_be_deleted ){
    if( node_to_be_deleted == NULL )
	return;
    //删除头结点
    if( node_to_be_deleted == this->head ){
	this->head=node_to_be_deleted->next;
	delete node_to_be_deleted;
    }else{
	LinkedListNode* node=node_to_be_deleted->next;
	if( node != NULL ){
	    node_to_be_deleted->data=node->data;
	    node_to_be_deleted->next=node->next;
	    delete node;
	    node=NULL;
	}else{ //尾节点
	    LinkedListNode* node=this->head;
	    while( node->next != node_to_be_deleted ){
		node=node->next;
	    }
	    node->next=NULL;
	    delete node_to_be_deleted;
	    node_to_be_deleted=NULL;
	}
    }

}

void LinkedList::print(){
    LinkedListNode* node=this->head;
    while( node != NULL ){
	cout << node->data << " ";
	node=node->next;
    }
    cout << endl;
}

void LinkedList::print_reverse(){
    if( this->head != NULL ){
	this->print_reverse(this->head);
	cout << endl;
    }
}

//递归打印有可能导致栈溢出，而显式用栈来打印就不会有这种风险
void LinkedList::print_reverse_no_recursive(){
    stack<LinkedListNode*> nodes;
    LinkedListNode* node=this->head;
    while( node != NULL ){
	nodes.push(node);
	node=node->next;
    }
    while( ! nodes.empty() ){
	cout << nodes.top()->data << " ";
	nodes.pop();	
    }
    cout << endl;
}
void LinkedList::print_reverse(LinkedListNode* node){
    if( node==NULL )
	return;
//    if( node->next == NULL ){
//	cout << node->data << " "; 
//    }else{
//	print_reverse(node->next);
//	cout << node->data << " ";
//    }

    if( node->next != NULL ){
	print_reverse(node->next);
    }
	cout << node->data << " ";
}

LinkedList::~LinkedList(){
    LinkedListNode* node=this->head;
    LinkedListNode* node_to_be_deleted;
    while( node != NULL ){
	node_to_be_deleted=node;
	node=node->next;
	delete node_to_be_deleted;
    }
}

int LinkedList::length(){
    LinkedListNode* node=this->head;
    int len=0;
    while( node != NULL ){
	len+=1;	
	node=node->next;
    }
    return len;
}

LinkedListNode* LinkedList::first_common_node_with_stack(LinkedList* another_list ){
    if( another_list == NULL )
	return NULL;
    stack<LinkedListNode*> list1;
    stack<LinkedListNode*> list2;
    LinkedListNode* node=this->head;
    while ( node != NULL ){
	list1.push(node);
	node=node->next;
    }
    node=another_list->get_head();
    while( node != NULL ){
	list2.push(node);
	node=node->next;
    }
    LinkedListNode* top_node1, *top_node2;
    while( ! list1.empty() && !list2.empty() ){
	top_node1 = list1.top();
	top_node2 = list2.top();
	if( top_node1 == top_node2 ){
	    list1.pop();
	    list2.pop();
	}else{
	    break;
	}
    }
    if( list1.empty() || list2.empty() ) //没有公共节点
	return NULL;
    else
	return top_node1->next;
}

LinkedListNode* LinkedList::first_common_node_no_stack(LinkedList* another_list ){
    int length1=this->length();
    int length2=another_list->length();
    int difference=length1> length2 ? length1-length2: length2-length1;
    LinkedListNode* node1=this->head;
    LinkedListNode* node2=another_list->get_head();
    //当两个链表长度相同时都取head
    if( length1 > length2 ){
	node1= this->get_node_by_index(difference ); 
    }else if( length1 < length2 ){
	node2= another_list->get_node_by_index(difference ); 
    }
    
    while( node1 != NULL && node2 != NULL ){
	if( node1 == node2 )
	    break; 
	node1=node1->next;
	node2=node2->next;
    }
    if( node1 == NULL || node2 == NULL )
	return NULL;
    else
	return node1;
}
void LinkedList::join(LinkedListNode* node){
    this->head->next=node;
}
