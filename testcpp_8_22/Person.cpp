#include "Person.h"


int age = 0; // 定义


//这里需要指定PrintPersonInfo是属于Person这个类域。
void Person::PrintPersonInfo()  //定义
{
	cout << "static size_1:" << &size_1 << endl;
	cout << "age:" << &age << endl;


	cout << _name << " " << _gender << " " << _age << endl;
}
