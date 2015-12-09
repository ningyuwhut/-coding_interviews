#include <iostream>

using namespace std;

bool find_number_in_partially_sorted_matrix(int matrix[][4],int rows, int columns, int target);
int main(){
    int matrix[4][4]={ {1,2,8,9},
	{2,4,9,12},
	{4,7,10,13},
	{6,8,11,15} };

    if( find_number_in_partially_sorted_matrix( matrix, 4,4, 10 ) == true ){
	cout << "Found 10" << endl;
    }else{
	cout << "not Found 10" << endl;
    }
    if( find_number_in_partially_sorted_matrix( matrix, 4,4, 1 ) == true ){
	cout << "Found 1" << endl;
    }else{
	cout << "not Found 1" << endl;
    }

    if( find_number_in_partially_sorted_matrix( matrix, 4,4, 15 ) == true ){
	cout << "Found 15" << endl;
    }else{
	cout << "not Found 15" << endl;
    }

    if( find_number_in_partially_sorted_matrix( matrix, 4,4, 3 ) == true ){
	cout << "Found 3" << endl;
    }else{
	cout << "not Found 3" << endl;
    }
    if( find_number_in_partially_sorted_matrix( matrix, 4,4, 0 ) == true ){
	cout << "Found 0" << endl;
    }else{
	cout << "not Found 0" << endl;
    }
    if( find_number_in_partially_sorted_matrix( matrix, 4,4, 16 ) == true ){
	cout << "Found 16" << endl;
    }else{
	cout << "not Found 16" << endl;
    }
    return 0;
};

//bool find_number_in_partially_sorted_matrix(int* matrix, int rows, int columns, int target){
//编译器寻址
//注意二维数组参数的传参方法
bool find_number_in_partially_sorted_matrix(int matrix[][4], int rows, int columns, int target){
//没有做参数检查
    int row_index=0;
    int col_index=columns-1;
    bool found=false;
    while( row_index >=0 && row_index < rows && col_index >=0 && col_index < columns ){
	int ele=matrix[row_index][col_index];
	if( ele == target ){
	    found=true;
	    break;
	}else if ( ele < target ){
	    row_index +=1;
	}else if( ele > target ){
	    col_index -=1;
	}
    }
    return found;
}
