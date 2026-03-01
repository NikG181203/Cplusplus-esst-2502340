#include <iostream>

void squareMeUpNoSense(int x)
{
    x = x*x;
}

void squareMeUpPtr(int *px)
{
    *px = (*px)*(*px);
}

void squareMeUp(int &x)
{
    x = x*x;
}

int main()
{
    int val = 20;

    // Does not work because x in this function is never passed
    squareMeUpNoSense(val);
    std::cout << val << std::endl;

    // With pointers (like you know it from C)
    /*
    //pointer in C
    int *ptrVal = &val;
    squareMeUpPtr(ptrVal)
    */
    squareMeUpPtr(&val);
    std::cout << val << std::endl;

    // C++ Reference variant
    /*
    int &refVal = val
    squareMeUp(val)
    */
    squareMeUp(val); //C++ reicht auch Inhalt der Übergabe. Funktion weiß selber durch anwendung
    std::cout << val << std::endl;

    return 0;
}
