#define _CRT_SECURE_NO_WARNINGS 1


#include "MyVector.h"

int main()
{
	try
	{
		//skk::TestVector1();
		//skk::TestVector2();
		skk::TestVector3();

	}
	catch (const exception& e) // Å×Òì³£´¦Àí
	{
		cout << e.what() << endl;
	}

	return 0;
}