#define _CRT_SECURE_NO_WARNINGS 1

#include "myStack.h"
#include "myQueue.h"
#include "myPriorityQueue.h"

int main()
{
    try
    {
        skk::test_stack1();
        skk::test_queue1();
        skk::test_priority_queue1();

    }
    catch (const exception& e) // Å×Òì³£
    {
        cout << e.what() << endl;
    }
    return 0;
}