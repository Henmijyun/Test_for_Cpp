#include "Person.h"


int age = 0; // ����


//������Ҫָ��PrintPersonInfo������Person�������
void Person::PrintPersonInfo()  //����
{
	cout << "static size_1:" << &size_1 << endl;
	cout << "age:" << &age << endl;


	cout << _name << " " << _gender << " " << _age << endl;
}
