#include <iostream>
#include <string>
using namespace std;
class err{
private:
	int kind;
public:
	err(int i):kind(i){}
	string err_mesg() const { 
		if(kind==0)return "块计ぃ璽计" ;
		else if(kind==1)return "璸衡计び" ;
		 
	}

};
/*==============================================================*/
int main(int argc, char const *argv[]){
	
    try {
    	//璸衡箂顶顶穦禬筁程计┻ㄒ
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