#include <iostream>
using namespace std;

int get_index_of_first_k(int* array, int length, int k );
int get_index_of_last_k(int* array, int length, int k );
int occurrance_of_k(int* array, int length, int k);
int main(int argc, char** argv){
    int array[]={1,2,3,3,3,3,3,4,4,4,4,5,6,7};
    int length=sizeof(array)/sizeof(array[0]);
    int k;
    cout << " input target number: " << endl;
    cin >> k;
    cout << "occurrance of " << k << " in array :" <<endl;

    cout << occurrance_of_k( array, length, k) << endl;
    return 0;
}

int get_index_of_first_k(int* array, int length, int k ){
    if( array == NULL || length <=0 )
	return -1;

    int i=0;
    int j=length-1;
    int mid;

    //退出条件是i>j
    //如果i==j的时候退出，那么如果这个数字的位置等于k，那么有可能漏掉这个数字
    //解释的不太清楚
    //可以以i==j位置处元素为K这种情况来考虑
    while( i <= j ){
	mid=(i+j)>>1;
	cout << "mid" << mid << array[mid] << endl;
	cout << "i" << i << " " << j << endl;
	if( array[mid] > k ){
	    j=mid-1;
	}else if( array[mid] < k ){
	    i=mid+1;
	}else{ //相等
	    if( (mid -1) >= 0){
		if( array[mid-1] != k )
		    return mid;
		else{
		    j=mid-1;
		}
	    }
	}
    }
    return -1;
}
int get_index_of_last_k(int* array, int length, int k ){
    if( array == NULL || length <=0 )
	return -1;
    int i=0;
    int j=length-1;
    int mid;
    while( i <= j ){
	mid=(i+j)>>1;
	if( array[mid] > k ){
	    j=mid-1;
	}else if( array[mid] < k ){
	    i=mid+1;
	}else{ //相等
	    if( (mid +1) < length ){
		if( array[mid+1] != k )
		    return mid;
		else{
		    i=mid+1;
		}
	    }
	}
    }
    return -1;
}
int occurrance_of_k(int* array, int length, int k){
    if( array == NULL || length <= 0 )
	return -1;
    int index_of_first_k=get_index_of_first_k(array, length, k);
    int index_of_last_k=get_index_of_last_k(array, length,k );
    cout << index_of_first_k << endl;
    cout << index_of_last_k << endl;
    if( index_of_first_k != -1 && index_of_last_k != -1 )
	return index_of_last_k-index_of_first_k+1;
    return -1;
}
