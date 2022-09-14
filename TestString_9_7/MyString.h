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
        const_iterator bedin()const // 为区分传参对象是不是const
        {
            return _str;
        }

        iterator end()
        {
            return _str + _size; // 最后一个下标+1的位置
        }
        const_iterator end()const
        {
            return _str + _size;
        }


        /*err  不能把字符串构造置为空，应在里面保'\0'
        string(const char* str)
            :_str(nullptr),
            _size(0),
            _capacity(0);
            {}  // 不使用或半使用初始化列表，有助于工程后期修改
            // 在函数内定义，不用在意初始化顺序
           */

        string(const char* str = "") // 空字符串里面自带\0
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_capacity + 1]; // _capacity里面没有算\0

            strcpy(_str, str);
        }

        // 传统写法 
        // 深拷贝： 先开一个空间，再把数据拷贝进这个空间里面
        // s2(s1)  拷贝构造
        //string(const string& s)
        //	:_str(new char[s._capacity+1])  // 创建一样大的空间
        //	, _size(s._size)
        //	, _capacity(s._capacity)
        //{
        //	strcpy(_str, s._str);  // 拷贝过去 （这里是深拷贝）
        //}
        
        //// s1 = s3
        //// s1 = s1
        //string& operator=(const string& s)
        //{
        //	if (this != &s)
        //	{
        //		char* tmp = new char[s._capacity + 1];
        //		strcpy(tmp, s._str); // 先拷贝

        //		delete[] _str;  // 再释放

        //		_str = tmp;
        //		_size = s._size;
        //		_capacity = s._capacity;
        //	}

        // 现代写法 - 资本主义
        // s2(s1)
        void swap(string& tmp)
        {
            ::swap(_str, tmp._str);
            ::swap(_size, tmp._size);
            ::swap(_capacity, tmp._capacity);
        }

        // s2(s1)
        string(const string& s)
            :_str(nullptr)  // 初始化列表把s2初始化了，
            ,_size(0)       // s2和tmp交换后，tmp的释放s2的nullptr
            ,_capacity(0)
        {
            string tmp(s._str);  // 用构造函数，相当于string tmp("hello")
            swap(tmp); // 交换   this->swap(tmp);
        }

        // s1 = s3
        string& operator=(const string& s)
        {
            if (this != &s) // 两个地址对比
            {
                //string tmp(s._str); // 复用 构造
                string tmp(s); // 复用 拷贝构造
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
