#include <iostream>
#include "linked_list.h"

using namespace std;

LinkedList* merge_two_sorted_linked_list(LinkedList* l_list, LinkedList* r_list);
int main(){
    LinkedList* list=new LinkedList();
    list->insert(1);
    list->insert(4);
    list->insert(6);
    list->insert(9);
    list->insert(10);

    LinkedList* list2=new LinkedList();
    list2->insert(1);
    list2->insert(3);
    list2->insert(5);
    list2->insert(7);
    list2->insert(9);
    LinkedList* merged_list=merge_two_sorted_linked_list(list, list2);

    cout << "list1" << endl;
    list->print();
    cout << "list2" << endl;
    list2->print();

    cout << "print merged list" << endl;
    merged_list->print();
    exit(0);


    cout << "print list" << endl;
    list->print();
    cout << "test get_node_kth_from_tail" << endl;
    LinkedListNode* third_node_from_tail=list->get_node_kth_from_tail(3);
    cout << "third from tail " << endl;
    cout << third_node_from_tail->data << endl;

    LinkedListNode* last_node=list->get_node_kth_from_tail(1);
    cout << "last node" << endl;
    cout << last_node->data << endl;

    LinkedListNode* fifth_node_from_tail=list->get_node_kth_from_tail(5);
    cout << "fifth_node_from_tail" << endl;
    cout << fifth_node_from_tail->data << endl;

    LinkedListNode* sixth_node_from_tail=list->get_node_kth_from_tail(6);
    cout << "sixth_node_from_tail" << " ";
    if ( sixth_node_from_tail == NULL )
	cout << "is null" << endl;

    cout << "test get_node_kth_from_tail_2" << endl;
    third_node_from_tail=list->get_node_kth_from_tail_2(3);
    cout << "third from tail " << endl;
    cout << third_node_from_tail->data << endl;

    last_node=list->get_node_kth_from_tail_2(1);
    cout << "last node" << endl;
    cout << last_node->data << endl;

    fifth_node_from_tail=list->get_node_kth_from_tail_2(5);
    cout << "fifth_node_from_tail" << endl;
    cout << fifth_node_from_tail->data << endl;

    sixth_node_from_tail=list->get_node_kth_from_tail_2(6);
    cout << "sixth_node_from_tail" << " ";
    if ( sixth_node_from_tail == NULL )
	cout << "is null" << endl;

    cout << "reverse list" << endl;
//    list->reverse_list();
    list->reverse_list_in_recursive();
    list->print();

    cout << "delete head" << endl;
    list->remove(list->get_head());
    list->print();
    cout << "delete tail" << endl;
    list->remove(list->get_tail());
    list->print();
    cout << "delete mid" << endl;
    list->remove(list->get_node_by_index(2));
    list->print();

    cout << "print list by reverse" << endl;
    list->print_reverse();
    list->print_reverse_no_recursive();

    cout << "remove head" << endl;
    list->remove_by_value(2);
    list->print();
    cout << "remove tail" << endl;
    list->remove_by_value(5);
    list->print();
    cout << "remove mid" << endl;
    list->remove_by_value(3);
    list->print();
    delete list;
};

LinkedList* merge_two_sorted_linked_list(LinkedList* l_list, LinkedList* r_list){
    if( l_list == NULL && r_list == NULL )
	return NULL;
    //应该复制
    if( l_list == NULL )
	return r_list;
    if( r_list == NULL )
	return l_list;

    LinkedList* merged_list=new LinkedList();

    LinkedListNode* l_node=l_list->get_head();
    LinkedListNode* r_node=r_list->get_head(); //head为空怎么办

    LinkedListNode* new_node=NULL;
    LinkedListNode* pre_node=NULL;
    while( l_node != NULL && r_node != NULL ){
	if( l_node->data < r_node->data ){
	    new_node=new LinkedListNode();
	    new_node->data=l_node->data;
	    l_node=l_node->next;
	}else{
	    new_node=new LinkedListNode();
	    new_node->data=r_node->data;
	    r_node=r_node->next;
	}
	if( merged_list->get_head() == NULL ){
	    merged_list->set_head(new_node);
	    pre_node=new_node;
	}else{
	    pre_node->next=new_node;
	    pre_node=new_node;
	}

    }

    while( l_node != NULL ){
	new_node=new LinkedListNode();
	new_node->data=l_node->data;
	pre_node->next=new_node;
	pre_node=new_node;
	l_node=l_node->next;
    }
    while( r_node != NULL ){
	new_node=new LinkedListNode();
	new_node->data=r_node->data;
	pre_node->next=new_node;
	pre_node=new_node;
	r_node=r_node->next;
    }
    pre_node->next=NULL;
    return merged_list;
}
