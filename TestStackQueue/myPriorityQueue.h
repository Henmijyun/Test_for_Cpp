#pragma once 

#include <iostream>
#include <vector>
#include <functional> // less ��� / greater С��

using namespace std;

namespace skk
{
    // Ĭ�� ���
    // Compare�ǽ��бȽϵķº����� less->��� / greater->С��   
    template<class T, class Container = vector<T>, class Compare = std::less<T>>
    class priority_queue
    {
    public:
        priority_queue()
        {} // ��ʼ���׶Σ��Զ�����Container��ȱʡ�򴫲Σ����й���

        template<class InputIterator>
        priority_queue(InputIterator first, InputIterator last) // �õ������ڼ�������
        {
            while (first != last) // �Ȱ����ݷŽ�ȥ
            {
                _con.push_back(*first);
                ++first;
            }

            // �ٽ���
            for (int i = (_con.size() - 1 - 1) / 2; i >= 0; --i)
            {
                adjust_down(i); // ���µ������� ��Ч�ʸ��ߣ�
            }
        }

        // O(logN)
        void adjust_up(size_t child) // ���ϵ�����
        {
            Compare com; // ����һ���º�������
            size_t parent = (child - 1) / 2; // ���ڵ�
            while (child > 0) // �����±� > ���ڵ�
            {
                // if (_con[child] > _con[parent]) // ����>����
                // if (_con[parent] < _con[child]) // ����>����
                if (com(_con[parent], _con[child])) // ����>���� �º���
                {
                    std::swap(_con[child], _con[parent]);
                    child = parent;
                    parent = (child - 1) / 2;  // �����󣬸��¸��ӽڵ�
                }
                else
                {
                    break;
                }
            }
        }

        void push(const T& x)
        {
            // �����ݲ����β�У������ϵ���
            _con.push_back(x);
            adjust_up(_con.size() - 1); // �ѵ����ϵ���  size-1���²������ݵ��±�
        }

        // O(logN)
        void adjust_down(size_t parent) // ���µ�����
        {
            Compare com; // ����һ���º�������
            size_t child = parent * 2 + 1;  // ���ӽڵ�
            while (child < _con.size()) // �����±� < �������һ���±� 
            {
                // ѡ�����Һ����У������һ��
                // �Һ��Ӵ��ڣ�����������
               // if (child + 1 < _con.size() && _con[child + 1] > _con[child])
               // if (child + 1 < _con.size() && _con[child] < _con[child + 1])
                if (child + 1 < _con.size() && com(_con[child], _con[child + 1])) // �º���
                {
                    ++child; // �±�ָ���Һ���
                }

                // if (_con[child] > _con[parent]) // ���� > ���ڵ�
                // if (_con[parent] < _con[child]) // ���� > ���ڵ�
                if (com(_con[parent], _con[child])) // �º���
                {
                    std::swap(_con[child], _con[parent]);
                    parent = child;
                    child = parent * 2 + 1;
                }
                else
                {
                    break;
                }
            }
        }

        void pop()
        {
            // �ȰѸ��ڵ�Ͷ�β���ݽ�������ɾ����������µ���
            std::swap(_con[0], _con[_con.size() - 1]);
            _con.pop_back();

            adjust_down(0); // �Ӹ��ڵ㣬���µ�����
        }

        const T& top()
        {
            return _con[0];
        }

        bool empty() const
        {
            return _con.empty();
        }

        size_t size() const
        {
            return _con.size();
        }


    private:
        Container _con;
    };

    void test_priority_queue1()
    {
        priority_queue<int> pq; // Container��ȱʡֵΪ vector<int>

        pq.push(3);
        pq.push(5);
        pq.push(2);
        pq.push(4);
        pq.push(1);

        while (!pq.empty())
        {
            cout << pq.top() << " ";
            pq.pop();
        }
        cout << endl;

        int a[] = { 3, 2, 7, 6, 0, 4, 1, 9, 8, 5 };
        //prociority_queue<int> heap(a, a + sizeof(a) / sizeof(int)); // �õ��������乹��
        priority_queue<int, vector<int>, greater<int>> heap(a, a + sizeof(a) / sizeof(int));
        while (!heap.empty())
        {
            cout << heap.top() << " ";
            heap.pop();
        }
        cout << endl;
    }
}
