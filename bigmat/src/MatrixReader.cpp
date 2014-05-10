#include "MatrixReader.h"

void MatrixReader::readBoolMatrix(std::string filename, HashMapMatrix<bool>* matrix)
{
      std::ifstream file(path, std::ios::in);


      while(!file.eof())
      {
        std::string x, y, value;
  		  file >> x;
        file >> y;
        file >> value; 
		  
  		  std::stringstream ssx, ssy, ssvalue;
  		  int x, y;
  		  bool value;
  		  x << ssx;          
  		  y << ssy;          
  		  value << ssvalue;
		  
          matrix->set(x, y, value);
      }	
      
      file.close();
}

void MatrixReader::readShortMatrix(std::string filename, HashMapMatrix<short>* matrix)
{
      std::ifstream file(path, std::ios::in);


      while(!file.eof())
      {
        std::string x, y, value;
        file >> x;
        file >> y;
        file >> value; 
      
        std::stringstream ssx, ssy, ssvalue;
        int x, y;
        short value;
        x << ssx;          
        y << ssy;          
        value << ssvalue;
      
          matrix->set(x, y, value);
      } 
      
      file.close();
}

void MatrixReader::readIntMatrix(std::string filename, HashMapMatrix<int>* matrix)
{
      std::ifstream file(path, std::ios::in);


      while(!file.eof())
      {
        std::string x, y, value;
        file >> x;
        file >> y;
        file >> value; 
      
        std::stringstream ssx, ssy, ssvalue;
        int x, y;
        int value;
        x << ssx;          
        y << ssy;          
        value << ssvalue;
      
          matrix->set(x, y, value);
      } 
      
      file.close();
}

void MatrixReader::readLongMatrix(std::string filename, HashMapMatrix<long>* matrix)
{
      std::ifstream file(path, std::ios::in);


      while(!file.eof())
      {
        std::string x, y, value;
        file >> x;
        file >> y;
        file >> value; 
      
        std::stringstream ssx, ssy, ssvalue;
        int x, y;
        long value;
        x << ssx;          
        y << ssy;          
        value << ssvalue;
      
          matrix->set(x, y, value);
      } 
      
      file.close();
}

void MatrixReader::readFloatMatrix(std::string filename, HashMapMatrix<float>* matrix)
{
      std::ifstream file(path, std::ios::in);


      while(!file.eof())
      {
        std::string x, y, value;
        file >> x;
        file >> y;
        file >> value; 
      
        std::stringstream ssx, ssy, ssvalue;
        int x, y;
        float value;
        x << ssx;          
        y << ssy;          
        value << ssvalue;
      
          matrix->set(x, y, value);
      } 
      
      file.close();
}

void MatrixReader::readDoubleMatrix(std::string filename, HashMapMatrix<double>* matrix)
{
      std::ifstream file(path, std::ios::in);


      while(!file.eof())
      {
        std::string x, y, value;
        file >> x;
        file >> y;
        file >> value; 
      
        std::stringstream ssx, ssy, ssvalue;
        int x, y;
        double value;
        x << ssx;          
        y << ssy;          
        value << ssvalue;
      
          matrix->set(x, y, value);
      } 
      
      file.close();
}