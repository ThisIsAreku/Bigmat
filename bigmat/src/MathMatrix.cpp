#include "MathMatrix.h"

MathMatrix::MathMatrix(MatrixEngine* matrix)
{
	this->_matrix = matrix;
}

MathMatrix* MathMatrix::add(MatrixEngine<int>* m2)
{
	if(this->_matrix->getWidth() != m2->getWidth()||this->_matrix->getHeight() != m2->getHeight())
		return this;
}
MathMatrix* MathMatrix::add(MatrixEngine<float>* m2)
{
	if(this->_matrix->getWidth() != m2->getWidth()||this->_matrix->getHeight() != m2->getHeight())
		return this;
}