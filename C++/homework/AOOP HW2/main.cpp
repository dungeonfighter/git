#include "Mytar.h"

int main(int argc, char *argv[])
{
	cerr<<"testing..."<<endl<<endl;

	Mytar E(argv[1]);
	E.read();
	E.showContent();
	return 0;
}