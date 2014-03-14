#ifndef __MATRIX_CALC__
#define __MATRIX_CALC__

class MatrixEngine;

class MatrixCalc 
{
	virtual void compute() = 0;
	virtual MatrixEngine getResult() = 0;
};


#endif
