#include "PFA.h"

using namespace std;
int main(int argc , char*argv[])
{
	if(argc != 8){
		cerr<<"Error parameter setting !"<<endl;
	}
	
	
	PFA a(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atof(argv[4]),atof(argv[5]),atoi(argv[6]),atoi(argv[7]));
	a.initialization();
	a.add_to_box();





	
	return 0;
}