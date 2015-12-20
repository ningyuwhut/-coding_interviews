#include <iostream>
using namespace std;

void reverse_the_order_of_keywords(char* sentence);
int main(int argc, char** argv){
    char sentence[]="I am a student.";
    reverse_the_order_of_keywords(sentence);
    cout << sentence << endl;
    return 0;
}
void reverse_the_order_of_keywords(char* sentence){
    if(sentence == NULL )
	return;
    char* pbegin=sentence;
    char* pend=sentence;
    while( *pend != '\0'){
	++pend;
    }
    --pend;
    //翻转句子
    while( pbegin < pend ){
	char tmp= *pbegin;
	*pbegin=*pend;
	*pend=tmp;
	++pbegin;
	--pend;
    }

    pbegin=sentence;
    pend=sentence;
    
    while( *pbegin != '\0' ){
	while( *pend != ' ' && *pend != '\0' ){
	    ++pend;
	}
	--pend;

	char* tmp_pbegin=pbegin;
	char* tmp_pend=pend;
	while( tmp_pbegin < tmp_pend ){
	    char tmp= *tmp_pbegin;
	    *tmp_pbegin=*tmp_pend;
	    *tmp_pend=tmp;
	    ++tmp_pbegin;
	    --tmp_pend;
	}
	do{
	    ++pend;
	}while( *pend == ' ' && *pend != '\0' );
	pbegin=pend;
    }
    return;
}
