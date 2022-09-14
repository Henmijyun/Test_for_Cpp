#pragma once 

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
        const_iterator bedin()const // Ϊ���ִ��ζ����ǲ���const
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size; // ���һ���±�+1��λ��
        }
        const_iterator end()const
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
            _str = new char[_capacity + 1]; // _capacity����û����\0

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

        // s1 = s3
        string& operator=(const string& s)
        {
            if (this != &s) // ������ַ�Ա�
            {
                //string tmp(s._str); // ���� ����
                string tmp(s); // ���� ��������
                swap(tmp);  // this->swap(tmp);
            }
            return *this;
        }


    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };


}
