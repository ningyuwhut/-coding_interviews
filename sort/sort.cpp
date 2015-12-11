#include <iostream>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


template< typename T> void bubble_sort(T* array, size_t length);
template< typename T> void insertion_sort(T* array, size_t length);
template< typename T> void selection_sort(T* array, size_t length);
template< typename T> void merge_sort_no_recursive(T* array, size_t length);
template< typename T> void merge_sort(T* array, size_t length);
template< typename T> void merge_sort_recursive(T* array, T* rep, size_t begin, size_t end);
template< typename T> void local_swap(T& a, T& b); //swap是c++的内置函数，所以要另起一个名字

template< typename T> bool check( T* array, size_t length );
//void insertion_sort(int array[], size_t length); //两种声明方式是相同的

int main(int argc, char ** argv){
	srand((unsigned)time(NULL));  

	int length= rand()%100+1;
	cout << "length"<< length<<endl;
	int *array = new int[length];
	//int length=sizeof(a)/sizeof(*a);
	for( int i =0 ; i < length; ++i )
	    array[i] = rand();
	cout << array << endl;
	bubble_sort(array, length);
//	insertion_sort(array, length);
//	selection_sort(array, length);
//	merge_sort(array, length);
	merge_sort_no_recursive(array, length);
	for( int i =0; i<length; ++i )
		cout << array[i] << endl;
	if( check( array, length ) == false ) 
	    cout << "the array is out of order" << endl;
	else
	    cout << "the array is in order" << endl;
	delete [] array;
	return 0;
}

template< typename T> void bubble_sort(T* array, size_t length){
    int i,j;
    for( i=0; i < length-1; ++i){
	bool swapped=false;
	for( j = 0; j < length-1-i; ++j ){
	    if( array[j] > array[j+1] ){
		local_swap(array[j], array[j+1]);
		swapped=true;
	    }
	}
	if(swapped == false)
	    break;
    }
}
//插入排序
//升序排列
template< typename T> void insertion_sort(T* array, size_t length){
	if( array == NULL || length == 0 )
		return;
	int i,j,k;
	for( i = 1; i < length; ++i ){
		T cur_ele=array[i];
		for( j = i-1; j >= 0 && array[j] > cur_ele ; --j ){
			array[j+1]=array[j];
		}
		array[j+1]=cur_ele;
	}
}
template< typename T> void selection_sort(T* array, size_t length){
	if( array == NULL || length == 0 )
		return;
	int i,j;
	for(i=0; i< length-1; ++i ){
		int index=i; //记录最小的元素的下标
		for( j=i+1; j<length; ++j ){
			if( array[j] < array[index] ){
				index=j; 
			}
		}
		if( index != i ){
		    local_swap(array[i], array[index]);
		}
	}
}

template< typename T> void merge_sort_no_recursive(T* array, size_t length){
    T rep[length];
    int span,i;
    for(span=1;span<length; span+=span){ //间隔
	for( i=0; i< length; i+=(span*2)){
	    int end=i+span*2;
	    if( end >= length )
		end = length; //end有可能大于length

	    int mid=i+((end-i)>>1);
	    if( mid >= length )
		mid=length;
	    int m=i;
	    int n=mid;
	    int k=i;
	    cout << "here" << m << " " << n << " " <<  end << endl;
	    if( n > length ) 
		cout << "error" << endl;
	    while( m < mid && n< end ){
		rep[k++]=array[m] < array[n] ? array[m++] : array[n++];
	    }
	    if( m < mid ){
		while( m< mid ){
		    rep[k++]=array[m++];
		}
	    }
	    if( n < end ){
		while( n < end ){
		    rep[k++]=array[n++];
		}
	    }
	    for( k=i;k<end; ++k )
		array[k]=rep[k];
	}
    }
}

template< typename T> void merge_sort(T* array, size_t length){
    T rep[length];
    merge_sort_recursive( array, rep, 0, length-1);
}

template< typename T> void merge_sort_recursive(T* array, T* rep, size_t begin, size_t end){
    if( begin >= end )
	return;
    size_t mid = begin + ((end-begin)>>1);
    merge_sort_recursive( array, rep, begin, mid );
    merge_sort_recursive( array, rep, mid+1, end);
    int i=begin, j=mid+1, k=begin;
    while( i <=mid && j <= end ){
	rep[k++]=array[i] < array[j] ? array[i++] : array[j++]; 
    }
    if( i <= mid ){
	while( i <= mid ){
	    rep[k++]=array[i++];
	}
    }
    if( j <= end ){
	while( j <= end ){
	    rep[k++]=array[j++];
	}
    }
    for( k=begin; k<=end; ++k ){
	array[k]=rep[k];
    }
}

template< typename T> void local_swap(T& a, T& b){
    T tmp=a;
    a=b;
    b=tmp;
}
template< typename T> bool check( T* array, size_t length ){
    bool sorted=true;
    for( int i =0; i < length-1; ++i ){
	if( array[i] > array[i+1]){
	    sorted=false;
	    break;
	}
    }
    return sorted;
}
