#include <iostream>
#include <string>
using namespace std;
class err{
private:
	int kind;
public:
	err(int i):kind(i){}
	string err_mesg() const { 
		if(kind==0)return "��J�Ʀr���ର�t��" ;
		else if(kind==1)return "�p��Ʀr�Ӥj" ;
		 
	}

};
/*==============================================================*/
int main(int argc, char const *argv[]){
	
    try {
    	//�p��s��Q�T���A�Q�T���|�W�L�̤j�Ʀr�A�ߨҥ~
    	for(unsigned i = 0; i <= 13; ++i) {
    		unsigned int x=1;
    	    for(unsigned j = 1; j <= i; ++j) {
    	    	x*=j;  		
    	    }
    	    if(i>12)throw err(1);
    	    else{
    	    	cout<<i<<"!"<<"="<<x<<endl;	
    	    }
    	}      
    }
    catch( err e ) {
    	cout << e.err_mesg() << endl ;
    }

	return 0;
}
/*==============================================================*/