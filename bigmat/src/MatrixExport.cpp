#include <fstream>
#include "MatrixExport.hpp"

/**
   * \file MatrixExport.cpp
   * \author ABNP
   * \date 13 Mai 2014
*/

bool MatrixExport::exportFile(std::string path, unsigned int w, unsigned int h, std::function<bool (unsigned int, unsigned int)> doCallback, std::function<void (std::ofstream&)> writeCallback)
{
	std::ofstream file(path);

	if(!file)
		return false;
	for (unsigned int i = 0; i < w; i++)
	{
		for(unsigned int j = 0; j < h; j++)
		{
			if(!doCallback(i, j))
				continue;

			file << i;
			file << " ";
			file << j;
			file << " ";
			writeCallback(file);
			file << " ";
			file << '\n';

		}
	}
	return true;
}
bool MatrixExport::exportBoolMatrix(std::string path, MatrixEngine<bool>* matrix)
{
	bool data;
	return exportFile(path, matrix->getWidth(), matrix->getHeight(),
		[&] (unsigned int x, unsigned int y) {
			data = matrix->get(x, y);
			return (data != false);
		},
		[&] (std::ofstream& out) {
			out << data;
		});
}
bool MatrixExport::exportShortMatrix(std::string path, MatrixEngine<short>* matrix)
{
	short data;
	return exportFile(path, matrix->getWidth(), matrix->getHeight(),
		[&] (unsigned int x, unsigned int y) {
			data = matrix->get(x, y);
			return (data != 0);
		},
		[&] (std::ofstream& out) {
			out << data;
		});
}
bool MatrixExport::exportIntMatrix(std::string path, MatrixEngine<int>* matrix)
{
	int data;
	return exportFile(path, matrix->getWidth(), matrix->getHeight(),
		[&] (unsigned int x, unsigned int y) {
			data = matrix->get(x, y);
			return (data != 0);
		},
		[&] (std::ofstream& out) {
			out << data;
		});
}
bool MatrixExport::exportLongMatrix(std::string path, MatrixEngine<long>* matrix)
{
	long data;
	return exportFile(path, matrix->getWidth(), matrix->getHeight(),
		[&] (unsigned int x, unsigned int y) {
			data = matrix->get(x, y);
			return (data != 0);
		},
		[&] (std::ofstream& out) {
			out << data;
		});
}
bool MatrixExport::exportFloatMatrix(std::string path, MatrixEngine<float>* matrix)
{
	float data;
	return exportFile(path, matrix->getWidth(), matrix->getHeight(),
		[&] (unsigned int x, unsigned int y) {
			data = matrix->get(x, y);
			return (data != .0);
		},
		[&] (std::ofstream& out) {
			out << data;
		});
}
bool MatrixExport::exportDoubleMatrix(std::string path, MatrixEngine<double>* matrix)
{
	double data;
	return exportFile(path, matrix->getWidth(), matrix->getHeight(),
		[&] (unsigned int x, unsigned int y) {
			data = matrix->get(x, y);
			return (data != .0);
		},
		[&] (std::ofstream& out) {
			out << data;
		});
}