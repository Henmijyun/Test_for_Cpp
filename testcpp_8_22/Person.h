#pragma once

#include <iostream>
using namespace std;


// ȫ�ֱ����������Ͷ������
extern int age;    // .h�� ���У�ȫ�ֱ���ǰ + extern��������

// �������Բ�һ��
//int size;  // �������������ļ��ɼ�
static int size_1;  // �������Ե�ǰ�ļ��ɼ�


class Person
{
public:
	void PrintPersonInfo(); //����
private:
	char _name[20];      //����
	char _gender[3];
	int _age;
};



