#include <fstream>
#include "MatrixReader.h"

/**
   * \file MatrixReader.cpp
   * \author ABNP
   * \date 13 Mai 2014
*/

void MatrixReader::readFile(std::string filename, std::function<void (unsigned int, unsigned int, std::stringstream&)> callback)
{
	std::ifstream file(filename.c_str(), std::ios::in);
	std::stringstream sstream;
	unsigned int x, y;
	std::string s;
	while(!file.eof())
	{
		// empreinte mémoire reduite: charge "x y d", remplis la map, décharge le sstream
		file >> s;
		sstream << s << " ";
		file >> s;
		sstream << s << " ";
		file >> s;
		sstream << s << " ";

		sstream >> x >> y;
		callback(x, y, sstream);
		sstream.str(std::string());
		sstream.clear();
	}
	file.close();
}

void MatrixReader::readBoolMatrix(std::string filename, HashMapMatrix<bool>* matrix)
{
	bool data;
	readFile(filename, [&] (unsigned int x, unsigned int y, std::stringstream& ss) {
		ss >> data;
		matrix->set(x, y, data);
	});
}

void MatrixReader::readShortMatrix(std::string filename, HashMapMatrix<short>* matrix)
{
	short data;
	readFile(filename, [&] (unsigned int x, unsigned int y, std::stringstream& ss) {
		ss >> data;
		matrix->set(x, y, data);
	});
}

void MatrixReader::readIntMatrix(std::string filename, HashMapMatrix<int>* matrix)
{
	int data;
	readFile(filename, [&] (unsigned int x, unsigned int y, std::stringstream& ss) {
		ss >> data;
		matrix->set(x, y, data);
	});
}

void MatrixReader::readLongMatrix(std::string filename, HashMapMatrix<long>* matrix)
{
	long data;
	readFile(filename, [&] (unsigned int x, unsigned int y, std::stringstream& ss) {
		ss >> data;
		matrix->set(x, y, data);
	});
}

void MatrixReader::readFloatMatrix(std::string filename, HashMapMatrix<float>* matrix)
{
	float data;
	readFile(filename, [&] (unsigned int x, unsigned int y, std::stringstream& ss) {
		ss >> data;
		matrix->set(x, y, data);
	});
}

void MatrixReader::readDoubleMatrix(std::string filename, HashMapMatrix<double>* matrix)
{
	double data;
	readFile(filename, [&] (unsigned int x, unsigned int y, std::stringstream& ss) {
		ss >> data;
		matrix->set(x, y, data);
	});
}