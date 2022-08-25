#pragma once

#include <iostream>
using namespace std;


// 全局变量的声明和定义分离
extern int age;    // .h文 件中，全局变量前 + extern，变声明

// 链接属性不一样
//int size;  // 链接属性所有文件可见
static int size_1;  // 链接属性当前文件可见


class Person
{
public:
	void PrintPersonInfo(); //声明
private:
	char _name[20];      //声明
	char _gender[3];
	int _age;
};



