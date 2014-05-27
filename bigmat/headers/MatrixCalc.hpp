#ifndef __MATRIX_CALC__
#define __MATRIX_CALC__

/**
   * \file MatrixCalc.h
   * \author ABNP
   * \date 13 Mai 2014
*/

class MatrixEngine;

class MatrixCalc
{
    virtual void compute() = 0;
    virtual MatrixEngine getResult() = 0;
};


#endif
