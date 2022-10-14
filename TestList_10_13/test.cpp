#define _CRT_SECURE_NO_WARNINGS 1
#include "MyList.h"


void test_list1()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    list<int>::iterator it = lt.begin();
    while (it != lt.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : lt)
    {
        e *= 2;
        cout << e << " ";
    }
    cout << endl;
}

void test_list2()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    auto pos = find(lt.begin(), lt.end(), 3);
    if (pos != lt.end())
    {
        // ����pos���������ʧЧ��posָ�򲻻�ı䣬�����ظ�������޸�
        lt.insert(pos, 30); // ��posλ��ǰ�����һ���ڵ�30
        *pos *= 100;
    }

    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;

    pos = find(lt.begin(), lt.end(), 300);
    if (pos != lt.end())
    {
        // ����pos����һ��֮�󣬵�������ʧЧ
        lt.erase(pos); // ɾ���ڵ㣬���ͷſռ�
    }

    for (auto e : lt)
    {
        cout << e << " ";
    }
    cout << endl;
}


int main()
{
    try
    {
        // test_list2();
        skk::test_list1();
    }
    catch (const exception& e) // ���쳣
    {
        cout << e.what() << endl;
    }

    return 0;
}
