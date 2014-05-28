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

void fillMat(MatrixEngine<int> *m, int iter)
{
    int n = 0;
    while(n < iter)
    {
        m->set(rand() % m->getWidth(), rand() % m->getHeight(), rand() % 128);
        n++;
    }
}

int main()
{

    srand(time(NULL));
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
    fillMat(&amr, 100);
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


    cout << "ArrayMatrix huge test" << endl;
    cout << "100x100 ";
    ArrayMatrix<int> lam1(100, 100);
    fillMat(&lam1, 10000);
    cout << "OK" << endl;
    cout << "1000x1000 ";
    ArrayMatrix<int> lam2(1000, 1000);
    fillMat(&lam2, 1000000);
    cout << "OK" << endl;
    cout << "10000x10000 ";
    ArrayMatrix<int> lam3(10000, 10000);
    fillMat(&lam3, 100000000);
    cout << "OK" << endl;


    cout << "FileMatrix huge test" << endl;
    cout << "100x100 ";
    FileMatrix<int> lfm1(100, 100);
    fillMat(&lfm1, 10000);
    cout << "OK" << endl;
    cout << "1000x1000 ";
    FileMatrix<int> lfm2(1000, 1000);
    fillMat(&lfm2, 1000000);
    cout << "OK" << endl;
    cout << "10000x10000 ";
    FileMatrix<int> lfm3(10000, 10000);
    fillMat(&lfm3, 100000000);
    cout << "OK" << endl;
    cout << "100000x100000 ";
    FileMatrix<int> lfm4(100000, 100000);
    fillMat(&lfm4, 100000000);
    cout << "OK" << endl;
}
