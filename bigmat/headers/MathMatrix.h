#ifndef _MATH_MATRIX_H_
#define _MATH_MATRIX_H_

#include "MatrixEngine.h"

class MathMatrix
{

	MatrixEngine *_matrix;
public:
	MathMatrix(MatrixEngine*);

	MathMatrix* add(MatrixEngine<int>*);
	MathMatrix* add(MatrixEngine<float>*);

};

#endif
