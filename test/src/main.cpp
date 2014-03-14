#include <iostream>

#include "MathMatrix.h"
#include "HashMapMatrix.h"

using namespace std;

void dispMat(MatrixEngine<int> *m)
{
	cout << m->getWidth() << "x" << m->getHeight() << endl;
	for(unsigned int i = 0; i < m->getHeight(); i++)
	{
		for(unsigned int j = 0; j < m->getWidth(); j++)
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

	m1.set(0, 0, 1);
	m1.set(1, 0, 2);
	m1.set(2, 0, 3);
	m1.set(2, 2, 5);

	m2.set(0, 0, 12);
	m2.set(1, 0, 75);
	m2.set(2, 0, 8);
	m2.set(2, 1, 5);
	m2.set(2, 2, 12);
	
	cout << "m1" << endl;
	dispMat(&m1);

	cout << "m2" << endl;
	dispMat(&m2);

	m1 += m2;
	cout << "m1" << endl;
	dispMat(&m1);
}
