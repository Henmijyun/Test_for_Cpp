#define _CRT_SECURE_NO_WARNINGS 1



#include "Stack.h"

void StackInit(struct Stack* ps, int capacity)//°ëÈ±Ê¡
{
	ps->_a = (int*)malloc(sizeof(int) * capacity);
	//
	ps->_top = 0;
	ps->_capacity = capacity;
}


void SLInit(SL& s, int capacity)
{
	s._a = (int*)malloc(sizeof(int) * capacity);
	assert(s._a);
	//...
	s._size = 0;
	s._capacity = capacity;
}

void SLPushBack(SL& s, int x)
{
	if (s._size == s._capacity)
	{
		//...
	}

	s._a[s._size++] = x;

}


int& SLAt(SL& s, int pos)
{
	assert(pos >= 0 && pos <= s._size);

	return s._a[pos];
}