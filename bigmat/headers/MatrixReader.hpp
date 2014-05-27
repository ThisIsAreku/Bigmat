#ifndef _MATRIX_READER_
#define _MATRIX_READER_

#include <string>
#include <sstream>
#include <functional>

#include "matrix/HashMapMatrix.hpp"

/**
   * \file MatrixReader.h
   * \author ABNP
   * \date 13 Mai 2014
*/

/**
    * \class     MatrixExport
    * \brief     Importation de matrice
 */
class MatrixReader{
	static void readFile(std::string, std::function<void (unsigned int, unsigned int, std::stringstream&)>);
public:
	static void readBoolMatrix(std::string, HashMapMatrix<bool>*);
	static void readShortMatrix(std::string, HashMapMatrix<short>*);
	static void readIntMatrix(std::string, HashMapMatrix<int>*);
	static void readLongMatrix(std::string, HashMapMatrix<long>*);
	static void readFloatMatrix(std::string, HashMapMatrix<float>*);
	static void readDoubleMatrix(std::string, HashMapMatrix<double>*);
};

#endif
