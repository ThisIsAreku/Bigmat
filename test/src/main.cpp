#include <iostream>
#include <cstdlib>
#include <ctime>

#include "MathMatrix.hpp"
#include "MatrixReader.hpp"
#include "MatrixExport.hpp"
#include "matrix/HashMapMatrix.hpp"
#include "matrix/ArrayMatrix.hpp"
#include "matrix/FileMatrix.hpp"

using namespace std;

template <typename T>
void dispMat(MatrixEngine<T> *m)
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

    cout << "Tests..." << endl;

    cout << "[HashMapMatrix] ";
    HashMapMatrix<int> hmm;
    cout << "OK" << endl;

    cout << "[ArrayMatrix] ";
    ArrayMatrix<int> am(5, 5);
    cout << "OK" << endl;

    cout << "[FileMatrix] ";
    FileMatrix<int> fm(5, 5);
    cout << "OK" << endl;

    cout << "[HashMapMatrix] Set";
    hmm.set(1, 1, 200);
    hmm.set(0, 0, 200);
    hmm.set(2, 0, 3);
    hmm.set(2, 1, 200);
    hmm.set(2, 0, 2);
    hmm.set(1, 0, 2);
    hmm.set(4, 4, 5);
    cout << "OK" << endl;

    cout << "[ArrayMatrix] Set ";
    am.set(1, 1, 200);
    am.set(0, 0, 200);
    am.set(2, 0, 3);
    am.set(2, 1, 200);
    am.set(2, 0, 2);
    am.set(1, 0, 2);
    am.set(4, 4, 5);
    cout << "OK" << endl;

    cout << "[FileMatrix] Set";
    fm.set(1, 1, 200);
    fm.set(0, 0, 200);
    fm.set(2, 0, 3);
    fm.set(2, 1, 200);
    fm.set(2, 0, 2);
    fm.set(1, 0, 2);
    fm.set(4, 4, 5);
    cout << "OK" << endl;

    cout << "[ArrayMatrix] randomset";
    ArrayMatrix<int> amr(5, 5);
    int n = 0;
    srand(time(NULL));
    while(n < 100)
    {
        amr.set(rand() % 5, rand() % 5, rand() % 128);
        n++;
    }
    cout << "OK" << endl;

    cout << "[HashMapMatrix] Result" << endl;
    dispMat(&hmm);
    cout << "OK" << endl;

    cout << "[ArrayMatrix] Result" << endl;
    dispMat(&am);
    cout << "OK" << endl;

    cout << "[ArrayMatrix] random Result" << endl;
    dispMat(&amr);
    cout << "OK" << endl;


    cout << "[FileMatrix] Result" << endl;
    dispMat(&fm);
    cout << "OK" << endl;


    cout << "[HashMapMatrix] += [ArrayMatrix]" << endl;
    hmm += am;
    dispMat(&hmm);
    cout << "OK" << endl;

    cout << "[HashMapMatrix] -= [ArrayMatrix]" << endl;
    hmm -= am;
    dispMat(&hmm);
    cout << "OK" << endl;

    cout << "[FileMatrix] *= 2" << endl;
    fm *= 2;
    dispMat(&fm);
    cout << "OK" << endl;

    cout << "[HashMapMatrix] += [ArrayMatrix]-random" << endl;
    hmm += amr;
    dispMat(&hmm);
    cout << "OK" << endl;


    cout << "[FileMatrix] = [HashMapMatrix]" << endl;
    FileMatrix<int> fm2(hmm);
    dispMat(&fm2);
    cout << "OK" << endl;

    cout << "[ArrayMatrix] = [FileMatrix]" << endl;
    ArrayMatrix<int> a2(fm2);
    dispMat(&a2);
    cout << "OK" << endl;
}
