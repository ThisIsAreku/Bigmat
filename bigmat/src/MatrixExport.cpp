#include "MatrixExport.h"

void  MatrixExport::export(std::string path, HashMapMatrix<T> *matrix)
{
  for (unsigned int i = 0; i < matrix->getWidth(); i++)
  {
    for(unsigned int j = 0; j < matrix->getHeight(); j++)
    {
      T = matrix->get(i, j);

      std::ofstream file;
      file.open(path, std::fstream::out | std::ios::out | std::ios::app);
      if(file)
      {
        file << x;
        file << " ";
        file << y;
        file << " ";
        file << T;
        file << " ";
        file << '\n';
      }
      else 
        std::cout << "Could not opened file "<< path << std::endl;

    }

  }

}