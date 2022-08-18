#pragma once

#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include <iostream>
using namespace std;


struct Stack
{
	int* _a;  //以前初始化为NULL，但是不好。
	int _top;
	int _capacity;
	//如果已知要插入的数据量，但是还是需要不断扩容。扩容会对内存造成碎片化。（扩容有代价）
	//每次乘二也不方便
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

//修改顺序表数据的函数
//void SLModity(SL& s, int pos, int x); //以前修改数据，需要先查找，再修改
int& SLAt(SL& s, int pos);  //利用引用返回值
