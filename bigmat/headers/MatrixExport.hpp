#ifndef _MATRIX_EXPORT_
#define _MATRIX_EXPORT_

#include <string>
#include <functional>

#include "matrix/MatrixEngine.hpp"

/**
   * \file MatrixExport.h
   * \author ABNP
   * \date 13 Mai 2014
*/

/**
    * \class     MatrixExport
    * \brief     Exportation de matrice
 */
class MatrixExport{
	static bool exportFile(std::string, unsigned int, unsigned int, std::function<bool (unsigned int, unsigned int)>, std::function<void (std::ofstream&)>);
public:
	static bool exportBoolMatrix(std::string, MatrixEngine<bool>*);
	static bool exportShortMatrix(std::string, MatrixEngine<short>*);
	static bool exportIntMatrix(std::string, MatrixEngine<int>*);
	static bool exportLongMatrix(std::string, MatrixEngine<long>*);
	static bool exportFloatMatrix(std::string, MatrixEngine<float>*);
	static bool exportDoubleMatrix(std::string, MatrixEngine<double>*);
};


#endif