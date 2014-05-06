#ifndef _MATRIX_READER_
#define _MATRIX_READER_

#include <string>

#include "matrix/HashMapMatrix.h"

class MatrixReader{
public:
	static void readBoolMatrix(std::string, HashMapMatrix<bool>*);
	static void readShortMatrix(std::string, HashMapMatrix<short>*);
	static void readIntMatrix(std::string, HashMapMatrix<int>*);
	static void readLongMatrix(std::string, HashMapMatrix<long>*);
	static void readFloatMatrix(std::string, HashMapMatrix<float>*);
	static void readDoubleMatrix(std::string, HashMapMatrix<double>*);
};

#endif