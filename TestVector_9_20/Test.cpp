#define _CRT_SECURE_NO_WARNINGS 1


#include "MyVector.h"

int mian()
{
	try
	{
		skk::TestVector1();
	}
	catch (const exception& e) // Å×Òì³£´¦Àí
	{
		cout << e.what() << endl;
	}

	return 0;
}