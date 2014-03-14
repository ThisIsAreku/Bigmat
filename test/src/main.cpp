#include <iostream>

#include "MathMatrix.h"
#include "HashMapMatrix.h"

int main()
{
	MatrixEngine<int> *m1 = new HashMapMatrix<int>;
	MatrixEngine<int> *m2 = new HashMapMatrix<int>;

	m1->set(0, 0, 1);
	m1->set(1, 0, 2);
	m1->set(2, 0, 3);

	m2->set(0, 0, 9);
	m2->set(1, 0, 8);
	m2->set(2, 0, 7);

	*m1 += *m2;
}
