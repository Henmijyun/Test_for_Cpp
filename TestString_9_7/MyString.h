#pragma once 

#include <iostream>
#include <string>
#include <list>
#include <assert.h>

using namespace std;

namespace bit
{
    class string
    {
    public:
        typedef char* iterator;
        typedef const char* const_iterator;

        iterator bedin()
        {
            return _str;
        }
        const_iterator bedin() const // Ϊ���ִ��ζ����ǲ���const
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size; // ���һ���±�+1��λ��
        }
        const_iterator end() const
        {
            return _str + _size;
        }


        /*err  ���ܰ��ַ���������Ϊ�գ�Ӧ�����汣'\0'
        string(const char* str)
            :_str(nullptr),
            _size(0),
            _capacity(0);
            {}  // ��ʹ�û��ʹ�ó�ʼ���б������ڹ��̺����޸�
            // �ں����ڶ��壬���������ʼ��˳��
           */

        string(const char* str = "") // ���ַ��������Դ�\0
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1]; // _capacity����û����\0 ������+1

            strcpy(_str, str);
        }

        // ��ͳд�� 
        // ����� �ȿ�һ���ռ䣬�ٰ����ݿ���������ռ�����
        // s2(s1)  ��������
        //string(const string& s)
        //	:_str(new char[s._capacity+1])  // ����һ����Ŀռ�
        //	, _size(s._size)
        //	, _capacity(s._capacity)
        //{
        //	strcpy(_str, s._str);  // ������ȥ �������������
        //}
        
        //// s1 = s3
        //// s1 = s1
        //string& operator=(const string& s)
        //{
        //	if (this != &s)
        //	{
        //		char* tmp = new char[s._capacity + 1];
        //		strcpy(tmp, s._str); // �ȿ���

        //		delete[] _str;  // ���ͷ�

        //		_str = tmp;
        //		_size = s._size;
        //		_capacity = s._capacity;
        //	}

        // �ִ�д�� - �ʱ�����
        // s2(s1)
        void swap(string& tmp)
        {
            ::swap(_str, tmp._str);
            ::swap(_size, tmp._size);
            ::swap(_capacity, tmp._capacity);
        }

        // s2(s1)
        string(const string& s)
            :_str(nullptr)  // ��ʼ���б��s2��ʼ���ˣ�
            ,_size(0)       // s2��tmp������tmp���ͷ�s2��nullptr
            ,_capacity(0)
        {
            string tmp(s._str);  // �ù��캯�����൱��string tmp("hello")
            swap(tmp); // ����   this->swap(tmp);
        }

        // s1 = s3  ��ͳд��
        //string& operator=(const string& s)
        //{
        //    if (this != &s) // ������ַ�Ա�
        //    {
        //        //string tmp(s._str); // ���� ����
        //        string tmp(s); // ���� ��������
        //        swap(tmp);  // this->swap(tmp);
        //    }
        //    return *this;
        //}

        // s1 = s3  �ִ�д��
        // s����tmp������
        string& operator=(string s) // ֱ���ô�ֵ���εĿ�������������
        {
            swap(s);  
            // �������Լ�ʵ�ֵ�swap����Ϊȫ�ֵ�swap�ײ�Ҳ�Ǹ�����������ص�=
            // �ᵼ����ѭ�����޷�ִ��
            return *this;
        }

        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        const char* c_str() const
        {
            return _str; // ����ֵ�Զ�ǿתΪconst char*
        }

        size_t size() const
        {
            return _size;
        }

        size_t capacity() const
        {
            return _capacity;
        }

        const char& operator[](size_t pos) const
        {
            assert(pos < _size);

            return  _str[pos];
        }

        char& operator[](size_t pos)
        {
            assert(pos < _size);

            return _str[pos];
        }

        void reserve(size_t n) // ����
        {
            if (n > _capacity) // �ж��Ƿ�����
            {
                char* tmp = new char[n + 1];
                strcpy(tmp, _str);
                delete[] _str;

                _str = tmp;
                _capacity = n;
            }
        }

        void push_back(char ch) // β���ַ�
        {
            // ���˾�����
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }

            _str[_size] = ch;
            ++_size;
            _str[_size] = '\0';  // �ǵý�β��\0
        }

        void append(const char* str) //β���ַ���
        {
            size_t len = strlen(str);
            
            // β��֮��װ���µĻ���������
            if (_size + len > _capacity)
            {
                reserve(_size + len);
            }

            strcpy(_str + _size, str);
            //strcat(_str, str); ��Ҫ������\0��Ч�ʵ�
            _size += len;

        }

        /* // ����ֻ����ԭ�к����Ļ����ϣ��������ʵ��
        void append(const string& s)
        {
            append(s._str);
        }

        void append(size_t n, char ch)
        {
            reserve(_size + n);
            for (size_t i = 0; i < n; ++i)
            {
                push_back(ch); // β��n��ch
            }
        }
        */
        
        string& operator+=(char ch)
        {
            push_back(ch);
            return *this;
        }

        string& operator+=(const char* str)
        {
            append(str);
            return *this;
        }

        string& insert(size_t pos, char ch)
        {
            assert(pos <= _size);
            
            if (_size == _capacity) // ���˾�����
            {
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }

            //// Ų������
            //int end = _size;
            //while (end >= (int)pos) // ��Ҫǿת��ʵ��
            //{
            //	_str[end + 1] = _str[end];
            //	--end;
            //}

            size_t end = _size + 1;
            while (end > pos)  // ��ĩβ���������pos�±�Ų��
            {
                _str[end] = _str[end - 1];
                --end;
            }

            _str[pos] = ch;
            ++_size;

            return *this;
        }

        string& insert(size_t pos, const char* str)
        {
            assert(pos <= _size);
            size_t len = strlen(str);
            if (_size == _capacity)
            {
                reserve(_capacity == 0 ? 4 : _capacity * 2);
            }

            // Ų������
            size_t end = _size + len; // ������ĩβ�±�
            while (end > pos)
            {
                // ��ԭ�ַ��� ���м�λ�� �ճ� Ҫ������ַ����ռ�
                _str[end] = _str[end - len]; 
                --end;
            }

            strncpy(_str + pos, str, len); // ��������
            _size += len;

            return *this;
        }

        void erase(size_t pos, size_t len = npos) // ɾ��
        {
            assert(pos < _size);

            if (len == npos || (pos + len) >= _size)
            {
                _str[pos] = '\0';
                _size = pos;
            }
            else
            {
                strcpy(_str + pos, _str + pos + len); // �Ѻ���ʣ�µ��ַ���ǰ�渲��
                _size -= len;
            }

        }

        size_t find(char ch, size_t pos = 0) const;
        size_t find(const char* sub, size_t pos = 0) const;
        bool operator>(const string& s) const;
        bool operator==(const string& s) const;
        bool operator>=(const string& s) const;
        bool operator<=(const string& s) const;
        bool operator<(const string& s) const;
        bool operator!=(const string& s) const;
    private:
        char* _str;
        size_t _size;
        size_t _capacity;

        // const static �﷨���⴦��
        // ֱ�ӿ��Ե��ɶ����ʼ��
        const static size_t npos = -1;
    };
    //size_t string::npos = -1; // ������Ҫ�������涨��ģ������������const���Ͳ�����

    ostream& operator<<(ostream& out, const string& s)
    {
        for (size_t i = 0; i < s.size(); ++i)
        {
            out << s[i];
        }
        return out;
    }

    istream& operator>>(istream& in, string& s)
    {
        //  �����ַ����ܳ�������+=��Ƶ�����ݣ�Ч�ʺܵͣ���ҿ����뷨�Ż�һ�� 
        char ch;
        //in >> ch; // �޷�ʶ��ո�ͻس�
        ch = in.get();

        while (ch != ' ' && ch != '\n')
        {
            s += ch;
            ch = in.get();
        }

        return in;
    }



    void TestString1()
    {
        string s1("hello");
        string s2(s1);
        string s3 = s1; // ��� = �� ��������

        cout << s2.c_str() << " " << s3.c_str() << endl << endl;

        s2 = "xxxxxxx";
        s1.swap(s2);  // ����
        cout << s1.c_str() << " " << s2.c_str() << endl;
        swap(s1, s2);
        cout << s1.c_str() << " " << s2.c_str() << endl << endl;

        s1.push_back('Q'); // ����
        s2.append("QQQ");
        cout << s1.c_str() << " " << s2.c_str() << endl << endl;

        s1.insert(2, "XXX"); // ָ������
        s2.insert(2, 'X');
        cout << s1.c_str() << " " << s2.c_str() << endl << endl;

        s1.erase(5, 2);  // ɾ��
        s2.erase(5);
        cout << s1.c_str() << " " << s2.c_str() << endl << endl;

        cin >> s1 >> s2;
        cout << s1 << "---" << s2 << endl;

    }

    void TestString2()
    {
        /*	string s1;
            cin >> s1;
            cout << s1 << endl;*/

        string s1("hello");
        cout << s1 << endl;
        cout << s1.c_str() << endl;
        s1 += '\0';
        s1 += "world";
        cout << s1 << endl;
        cout << s1.c_str() << endl;

        string s3, s4;
        cin >> s3 >> s4;
        cout << s3 << " -- " << s4 << endl;
    }

}
