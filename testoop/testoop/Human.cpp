#include "Human.h"

int main()
{
	Human h1;
	h1.inputInfo();
	h1.showInfo();
	Human h2(20, "Nguyen Van A");
	h2.showInfo();
	system("pause");
	return 0;
}