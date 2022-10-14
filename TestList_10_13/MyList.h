#pragma once 

#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <assert.h>

using namespace std;

namespace skk
{
    template<class T>
    struct list_node  // �����ڵ�
    {
        T _data;
        list_node<T>* _next;
        list_node<T>* _prev;

        list_node(const T& x = T())
            : _data(x)
            , _next(nullptr)
            , _prev(nullptr)
        {}
    };

    // typedef __list_iterator<T, T&, T*>             iterator;
    // typedef __list_iterator<T, const T&, const T*> const_iterator;

    // ��ָ��һ���Ķ���
    template<class T, class Ref, class Ptr>  // Ϊ�˿���const T& ��const T*
    struct __list_iterator  // ������(����)
    {

        typedef list_node<T> Node;
        typedef __list_iterator<T, Ref, Ptr> iterator;


        //////////////////////////////
        //������Ϊ��ʹ��std::find()�����ӵ�Դ��typedef,��list�޹أ����ù�
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef Ptr pointer;
        typedef Ref reference;
        typedef ptrdiff_t difference_type;
        ////////////////////////////// 


        Node* _node;

        __list_iterator(Node* node)
            :_node(node)
        {}

        bool operator!=(const iterator& it) const // ����!=
        {
            return _node != it._node;
        }

        // *it  it.operator*() 
        // T& operator*()
        Ref operator*()
        {
            return _node->_data;
        }

        // T* operator->()
        Ptr operator->()
        {
            return &(operator*()); // �൱�� &(_node->_data)
        }

        // ++it 
        iterator& operator++()
        {
            _node = _node->_next;
            return *this;
        }

        // it++
        iterator operator++(int)
        {
            iterator tmp(*this);
            _node = _node->_next;
            return tmp;
        }

        // --it 
        iterator& operator--()
        {
            _node = _node->_prev;
            return *this;
        }

        // it--
        iterator operator--(int)
        {
            iterator tmp(*this);
            _node = _node->_prev;
            return tmp;
        }
    };

    template<class T>
    class list
    {
        typedef list_node<T> Node;
    public:
        typedef __list_iterator<T, T&, T*> iterator;
        typedef __list_iterator<T, const T&, const T*> const_iterator;
        // ����ģ��ʵ����ȥ����const T& �� const T*

        iterator begin()
        {
            return iterator(_head->_next);
        }

        iterator end()
        {
            return iterator(_head);
        }

        const_iterator begin() const
        {
            return const_iterator(_head->_next);
        }

        const_iterator end() const
        {
            return const_iterator(_head);
        }

        void empty_init() // ���� �� ��ʼ�� �ڱ�λ��ͷ
        {
            _head = new Node;
            _head->_next = _head;
            _head->_prev = _head;
        }

        template <class InputIterator>
        list(InputIterator first, InputIterator last) // ���� ���������� ���й���
        {
            empty_init(); // �ڱ�λ��ͷ

            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        list()
        {
            empty_init(); // �ڱ�λ��ͷ
        }

        void swap(list<T>& x) // ����
        {
            std::swap(_head, x._head);
        }

        // lt2(lt1) �ִ�д��
        list(const list<T>& lt) // ��������
        {
            empty_init();
            list<T> tmp(lt.begin(), lt.end()); // �����������Զ�����
            swap(tmp);

        }

        // lt1 = lt3 
        list<T>& operator=(list<T> lt)
        {
            swap(lt);  // lt�൱��lt3��������Դ�ֵ���λ´�����죬�ٽ��н���
            return *this;  // ��������������lt�Զ����� ����ȫ������
        }

        ~list()
        {
            clear();
            delete _head;
            _head = nullptr;
        }

        void clear() // ���������������
        {
            iterator it = begin();
            while (it != end())
            {
                it = erase(it);
            }
        }

        void push_back(const T& x) // β��
        {
            //  Node* tail = _head->_prev;
            //  Node* newnode = new Node(x);

            //  // _head       tail  newnode
            //  tail->_next = newnode;
            //  newnode->_prev = tail;
            //  newnode->_next = _head;
            //  _head->_prev = newnode;

            insert(end(), x);
        }

        void push_front(const T& x) // ͷ��
        {
            insert(begin(), x);
        }

        iterator insert(iterator pos, const T& x) // ָ��λ�ò���
        {
            Node* cur = pos._node;    // ȡ������pos����Ľڵ�λ��
            Node* prev = cur->_prev;

            Node* newnode = new Node(x);
            // prev  newnode  cur 
            prev->_next = newnode;
            newnode->_prev = prev;
            newnode->_next = cur;
            cur->_prev = newnode;

            return iterator(newnode); // �����²�������λ�õĵ����� 
            // ����iterator�࣬ȥ����һ�����������ٷ���

        }

        void pop_back() // βɾ
        {
            erase(--end()); // ͷ�ڵ��prev
        }

        void pop_front() // ͷɾ
        {
            erase(begin());
        }

        iterator erase(iterator pos) // ָ��λ��ɾ��
        {
            assert(pos != end());

            Node* cur = pos._node;
            Node* prev = cur->_prev;
            Node* next = cur->_next;

            prev->_next = next;
            next->_prev = prev;
            delete cur;

            return iterator(next); // ����ɾ����pos�����λ��next�ĵ�����
        }



    private:
        Node* _head;  // �ڱ�λ��ͷ
    };

    void test_list1()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        list<int>::iterator it = lt.begin(); // ������
        while (it != lt.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

    }

    void Func(const list<int>& l)
    {
        list<int>::const_iterator it = l.begin();
        while (it != l.end())
        {
            cout << *it << " ";
            ++it;
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

        Func(lt);

        for (auto& e : lt)
        {
            e *= 2;
            cout << e << " ";
        }
        cout << endl;

        lt.pop_back();
        lt.pop_front();

        for (auto& e : lt)
        {
            cout << e << " ";
        }
        cout << endl;

        list<int>::iterator pos = find(lt.begin(), lt.end(), 6);
        if (pos != lt.end())
        {
            pos = lt.erase(pos); //ָ��λ��ɾ��
            pos = lt.insert(pos, 50); //ָ������
            *pos *= 100;
        }
        for (auto& e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void test_list3()
    {
        list<int> lt;
        lt.push_back(1);
        lt.push_back(2);
        lt.push_back(3);
        lt.push_back(4);
        lt.push_back(5);

        list<int> copy = lt;
        for (auto& e : copy)
        {
            e *= 2;
            cout << e << " ";
        }
        cout << endl;

        lt = copy;
        for (auto& e : lt)
        {
            cout << e << " ";
        }
        cout << endl;
    }

}













