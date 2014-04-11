#include <iostream>

#include "MathMatrix.h"
#include "matrix/HashMapMatrix.h"
#include "matrix/ArrayMatrix.h"

using namespace std;

void dispMat(MatrixEngine<int> *m)
{
    cout << m->getWidth() << "x" << m->getHeight() << endl;
    cout << "Pointer: " << m << endl;
    for(unsigned int j = 0; j < m->getHeight(); j++)
    {
        for(unsigned int i = 0; i < m->getWidth(); i++)
        {
            cout << m->get(i, j) << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    HashMapMatrix<int> m1;
    HashMapMatrix<int> m2;

    ArrayMatrix<int> a1(3, 3);

    m1.set(0, 0, 1);
    m1.set(1, 0, 2);
    m1.set(2, 0, 3);
    m1.set(2, 2, 5);

    m2.set(0, 0, 12);
    m2.set(1, 0, 75);
    m2.set(2, 0, 8);
    m2.set(2, 1, 5);
    //m2.set(2, 2, 12);

    a1.set(1, 1, 200);
    a1.set(0, 0, 200);
    a1.set(2, 1, 200);
    //a1.set(4, 4, 5);

    cout << "a1" << endl;
    dispMat(&a1);

    cout << "m1" << endl;
    dispMat(&m1);

    cout << "m2" << endl;
    dispMat(&m2);

    m1 += m2;
    cout << "m1" << endl;
    dispMat(&m1);

    secured = false;

    m1 += m2;
    cout << "m1" << endl;
    dispMat(&m1);

    m2 += m1;
    cout << "m2" << endl;
    dispMat(&m2);

    m2 += a1;
    cout << "m2" << endl;
    dispMat(&m2);


    HashMapMatrix<int> m3(m2);
    cout << "recopie m3 = m2" << endl;
    dispMat(&m3);

    ArrayMatrix<int> a2(a1);
    cout << "recopie a2 = a1" << endl;
    dispMat(&a2);

    ArrayMatrix<int> a3(m3);
    cout << "recopie a3 = m3" << endl;
    dispMat(&a3);
}
