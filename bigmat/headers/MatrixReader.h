#ifndef _MATRIX_READER_
#define _MATRIX_READER_

#include <string>

#include "matrix/HashMapMatrix.h"

class MatrixReader{
public:
	static void exportBoolMatrix(std::string, HashMapMatrix<bool>*);
	static void exportShortMatrix(std::string, HashMapMatrix<short>*);
	static void exportIntMatrix(std::string, HashMapMatrix<int>*);
	static void exportLongMatrix(std::string, HashMapMatrix<long>*);
	static void exportFloatMatrix(std::string, HashMapMatrix<float>*);
	static void exportDoubleMatrix(std::string, HashMapMatrix<double>*);
};

#endif
