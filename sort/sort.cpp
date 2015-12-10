#include <iostream>
#include <limits.h>

using namespace std;

void insertion_sort(int* array, size_t length);
void selection_sort(int* array, size_t length);

//void insertion_sort(int array[], size_t length); //两种声明方式是相同的

int main(int argc, char ** argv){
	int a[]={3,2,1};
	cout << a << endl;
//	insertion_sort(a, 3);
	selection_sort(a, 3);
	for( int i =0; i<3; ++i )
		cout << a[i] << endl;
	return 0;
}

//插入排序
//升序排列
void insertion_sort(int* array, size_t length){
	if( array == NULL || length == 0 )
		return;
	int i,j,k;
	for( i = 1; i < length; ++i ){
		int cur_ele=array[i];
		for( j = i-1; j >= 0 && array[j] > cur_ele ; --j ){
			array[j+1]=array[j];
		}
		array[j+1]=cur_ele;
	}
}
void selection_sort(int* array, size_t length){
	if( array == NULL || length == 0 )
		return;
	int i,j;
	for(i=0; i< length-1; ++i ){
		int index=i;
		for( j=i+1; j<length; ++j ){
			if( array[j] < array[index] ){
				index=j;	
			}
		}
		if( index != i ){
			int tmp=array[index];
			array[index]=array[i];
			array[i]=tmp;
		}
	}
}

