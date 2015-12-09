#include <iostream>

using namespace std;

void replace_blank(char str[], int length);
void replace_blank2(char str[], int length);

//下面这种情况可能会有内存覆盖，得到的结果是错误的
int main(){
//    char str1[]="we are happy";
 //   char str2[]=" we are happy";
    //char str3[] ="we are happy ";
   // char str4[] ="we are  happy";
    char str5[] ="happy";
    
//////////////////    replace_blank(str, 13);
    //replace_blank2(str1, 13);
    //replace_blank2(str2, 14);
   // replace_blank2(str3, 14);
    //replace_blank2(str4, 14);
    replace_blank2(str5, 6);
    //cout << str1 << endl;
    //cout << str2 << endl;
    //cout << str3 << endl;
    //cout << str4 << endl;
    cout << str5 << endl;
    return 0;
}

//o(n^2)的解法
void replace_blank(char str[], int length){
    if( str == NULL || length <=0 )
	return;
    int i=0;
    int new_length=length;
    while( i < new_length ){
	if( str[i] != ' ' )
	    ++i;
	else{
	    int j=new_length-1;
	    while( j > i ){
		str[j+2]=str[j];
		--j;
	    }
	    str[j]='%';
	    str[j+1]='2';
	    str[j+2]='0';
	    new_length+=2;
	    i+=3;
	}
    }
    str[new_length]='\0';
}

void replace_blank2(char str[], int length){
    if( str == NULL || length <=0 )
	return;
    int blank_number=0;
    for( int i =0; i < length; ++i ){
	if( str[i] == ' ' )
	    blank_number+=1;
    }
    int new_length=length+2*blank_number;
    int i=length-1;
    int j=new_length-1;
    str[new_length]='\0';
    while( i >= 0 ){
	if( str[i] == ' ' ){
	    str[j--]='0';
	    str[j--]='2';
	    str[j--]='%';
	    --i;
	}else{
	    str[j--]=str[i--];
	}
    }
}
