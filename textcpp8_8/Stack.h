#pragma once

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>
using namespace std;


struct Stack
{
	int* _a;  //��ǰ��ʼ��ΪNULL�����ǲ��á�
	int _top;
	int _capacity;
	//�����֪Ҫ����������������ǻ�����Ҫ�������ݡ����ݻ���ڴ������Ƭ�����������д��ۣ�
	//ÿ�γ˶�Ҳ������
};

void StackInit(struct Stack* ps, int capacity = 4);


typedef struct SeqList
{
	int* _a;
	int _size;
	int _capacity;
}SL;

void SLInit(SL& s, int capacity = 4);

void SLPushBack(SL& s, int x);

//�޸�˳������ݵĺ���
//void SLModity(SL& s, int pos, int x); //��ǰ�޸����ݣ���Ҫ�Ȳ��ң����޸�
int& SLAt(SL& s, int pos);  //�������÷���ֵ
