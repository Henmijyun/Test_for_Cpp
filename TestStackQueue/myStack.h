#pragma once 

#include <iostream>
#include <vector>
#include <list>
#include <deque> // ����vector��list�Ľ���壬��������ƽӹ

using namespace std;

namespace skk
{

    template<class T, class Container = deque<T>> // ȱʡֵ��deque
    class stack
    {
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }

        void pop()
        {
            _con.pop_back();
        }

        T& top()
        {
            return _con.back(); // ȡβ������
        }

        const T& top() const
        {
            return _con.back();
        }

        bool empty() const // �п�
        {
            return _con.empty();
        }

        size_t size() const
        {
            return _con.size();
        }
    private:
        // vector<T> _con; 
        Container _con;
    };

    void test_stack1()
    {
        //stack<int, vector<int>> st; // ��vector
        //stack<int, list<int>> st;  // ��list
        stack<int> st;  // ��ȱʡֵ��deque
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);

        while (!st.empty())
        {
            cout << st.top() << endl;
            st.pop();
        }
        cout << endl;
    }
}