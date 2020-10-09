//Dorizabelle Northecide
//Software Development
//October 6, 2020

#include <iostream>
using namespace std;

// g++ main.cpp -o dori -g && valgrind --leak-check=full --show-reachable=yes ./dori;
int main()
{
    int *a;
    int b = 10;
    int *c;
    int **d;
    int **e;

    //Allocate memory and assign given values
    a = new int;
    *a = 0x8;
    cout << "Value of a: DEC " << std::dec << *a << endl;
    cout << "Value of a: HEX " << std::hex << *a << endl;

    // Request memory for the variable
    // using new operator
    // a = new(nothrow) int;
    // if (!a)
    //     cout << "allocation of memory failed\n";
    // else
    // {
    //     // Store value at allocated address
    //     *a = 0x8;
    //     cout << "Value of a: " << a << endl;
    //     cout << "Value of *a: " << *a << endl;

    // }

    // c = new(nothrow) int(0x16);
    //----------------------------------------------------------------------------------------------------------------------------
    cout << "Value of b: DEC " << std::dec << b << endl;

    //----------------------------------------------------------------------------------------------------------------------------
    c = new int[6];
    *c = 0x16;
    for (int i = 1; i < 6; i++)
    {
        *(c + i) = 16 + (i * 4);
    }
    // int c[] = {0x16, 20, 24, 28, 32, 36}; //-- did not work
    // *(c+1) = 20;
    // *(c+2) = 24;
    // *(c+3) = 28;
    // *(c+4) = 32;
    // *(c+5) = 36;
    // cout << "Value of c: DEC " << std::dec << *c << endl;
    // cout << "Value of c: HEX " << std::hex << *c << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Value of c[" + to_string(i) + "]: DEC " << std::dec << c[i] << endl;
        cout << "Value of c[" + to_string(i) + "]: HEX " << std::hex << c[i] << endl;
    }
    //a = aNumbers;
    //int aNumbers[5] = {20, 24, 28, 32, 36}
    // *c = 22;

    //----------------------------------------------------------------------------------------------------------------------------
    //assuming c is a simple 1d integer array
    //assuming d is a 2d integer array (1x4)
    //assuming e is a 2d integer array (3x1)
    //need to confirm ^ w/ dr koc

    // https://www.learncpp.com/cpp-tutorial/65-multidimensional-arrays/
    // http://www.cplusplus.com/forum/beginner/202864/
    int dNumbers[] = {0x40, 0x1, 0x6, 0x36}; // dynamic
    int dRows = 1; // dynamic
    int dCols;
    // https://stackoverflow.com/questions/20234898/correct-way-of-looping-through-c-arrays
    dCols = sizeof(dNumbers) / sizeof(dNumbers[0]);
    std::cout << "sizeOf(dNumbers[]) = " << to_string(dCols) << std::endl;

    d = new int *;
    *d = new int[dCols];
    
    // **d = 0x40;
    // **(d+1) = 0x1;
    // **(d+2) = 0x6;
    // **(d+3) = 0x36;

    // d[0][0] = 0x40;
    // d[0][1] = 0x1;
    // d[0][2] = 0x6;
    // d[0][3] = 0x36;

    for (int i = 0; i < dRows; i++)
    {
        for (int j = 0; j< dCols; j++)
        {
            d[i][j]=dNumbers[j];
            cout << "Value of d[" + to_string(i) + "][" + to_string(j) + "]: DEC " << std::dec << d[i][j] << endl;
            cout << "Value of d[" + to_string(i) + "][" + to_string(j) + "]: HEX " << std::hex << d[i][j] << endl;
        }
    }
    //----------------------------------------------------------------------------------------------------------------------------
    e = new int *;
    *e = new int[3];
    e[0][0] = 0x32;
    e[0][1] = 0x44;
    e[0][2] = 5;

    for (int i = 0; i < 3; i++)
    {
        cout << "Value of e[" + to_string(i) + "]: DEC " << std::dec << e[0][i] << endl;
        cout << "Value of e[" + to_string(i) + "]: HEX " << std::hex << e[0][i] << endl;
    }

    // **e = 50;ı

    //Deallocate dynamically allocated memory
    delete a;
    delete[] c;

    // this seemed to work, but not sure why
    // delete[] * d;
    // https://stackoverflow.com/questions/30720594/deleting-a-dynamically-allocated-2d-array/30720628
    for (int i = 0; i < dRows; i++)
    {
        delete [] d[i];
    }
    delete [] d;

    // for (int i = 0; i < 3; i++)
    // {
    //     delete[] e[i];
    // }
    // delete[] e;
    delete[] * e;
    delete[] e;
    cout << "Deallocated dynamically allocated memory for a .. e: " << endl;
    return 0;
}