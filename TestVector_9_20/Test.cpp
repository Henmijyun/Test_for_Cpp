#include "MyVector.h"

int main()
{
    try
    {
        // skk::TestVector1();
        // skk::TestVector2();
        // skk::TestVector3();
        skk::TestVector4();
    }
    catch (const exception& e) // ���쳣����
    {
        cout << e.what() << endl;
    }

    return 0;
}