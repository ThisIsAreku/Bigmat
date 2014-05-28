#ifndef _MATH_MATRIX_H_
#define _MATH_MATRIX_H_

#include "matrix/MatrixEngine.hpp"

/**
   * \file MathMatrix.h
   * \author ABNP
   * \date 13 Mai 2014
 */


/**
    * \class     MathMatrix
    * \brief     Calcul matriciels
 */
class MathMatrix{
public:
   
    template <typename K>
    static MatrixEngine<K> inversion(MatrixEngine<K> &a);
    
    template <typename K>
    static MatrixEngine<K> complementAlgebrique(MatrixEngine<K> &a);
    
    template <typename K>
    static MatrixEngine<K> transpose(MatrixEngine<K> &a);
    
    template <typename K>
    static int det(MatrixEngine<K> &a);

};

/**
    * \fn +=
    * \param a Matrice a
    * \param b Matrice b
    * \brief Spécification du template pour les matrices booléenes
    * \return Matrice a modifiée
*/
MatrixEngine<bool> &operator +=(MatrixEngine<bool> &a, MatrixEngine<bool> &b)
{
    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) || b.get(i, j));
        }
    }
    return a;
}

/**
    * \fn +=
    * \tparam Type de matrice
    * \param a Matrice a
    * \param b Matrice b
    * \return Matrice a modifiée
*/
template <typename K>
MatrixEngine<K> &operator +=(MatrixEngine<K> &a, MatrixEngine<K> &b)
{

    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();

    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) + b.get(i, j));
        }
    }
    return a;
}

/**
    * \fn -=
    * \param a Matrice a
    * \param b Matrice b
    * \brief Spécification du template pour les matrices booléenes
    * \return Matrice a modifiée
*/
MatrixEngine<bool> &operator -=(MatrixEngine<bool> &a, MatrixEngine<bool> &b)
{
    return a;
}


/**
    * \fn -=
    * \tparam Type de matrice
    * \param a Matrice a
    * \param b Matrice b
    * \return Matrice a modifiée
*/
template <typename K>
MatrixEngine<K> &operator -=(MatrixEngine<K> &a, MatrixEngine<K> &b)
{
    
    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) - b.get(i, j));
        }
    }
    return a;
}

/**
    * \fn *=
    * \tparam Type de matrice
    * \param a Matrice a
    * \param number Nombre multiplicateur
    * \brief Multiplie une matrice par un nombre
    * \return Matrice a modifiée
*/
template <typename K>
MatrixEngine<K> &operator *=(MatrixEngine<K> &a, int number)
{
    unsigned int maxWidth = a.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    for(unsigned int i = 0; i < maxWidth; i++){
        for(unsigned int j = 0; j < maxHeight; j++){
            a.set(i, j, a.get(i, j) * number);
        }
    }
    return a;
}

/**
    * \fn *=
    * \param a Matrice a
    * \param b Matrice b
    * \brief Spécification du template pour les matrices booléenes
    * \return Matrice a modifiée
*/
MatrixEngine<bool> &operator *=(MatrixEngine<bool> &a, MatrixEngine<bool> &b){
    unsigned int maxWidth = b.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    a.setHeight(maxHeight);
    a.setWidth(maxWidth);
    
    bool tmp = false;
    bool value = false;
    
    for(unsigned int i = 0; i < maxHeight; i++){
        for(unsigned int j = 0; j < maxWidth; j++){
            for(unsigned int k = 0; k < maxHeight; k++){
                tmp = a.get(k,i) || b.get(j,k);
                value = value || tmp;
            }
            a.set(i,j,value);
            value = 0;
        }
    }
    return a;
}

/**
    * \fn *=
    * \tparam Type de matrice
    * \param a Matrice a
    * \param b Matrice b
    * \brief Multiplie deux matrices
    * \return Matrice a modifiée
*/
template <typename K>
MatrixEngine<K> &operator *=(MatrixEngine<K> &a, MatrixEngine<K> &b){
    unsigned int maxWidth = b.getWidth();
    unsigned int maxHeight = a.getHeight();
    
    a.setHeight(maxHeight);
    a.setWidth(maxWidth);
    
    K tmp =0;
    K value = 0;
    
    for(unsigned int i = 0; i < maxHeight; i++){
        for(unsigned int j = 0; j < maxWidth; j++){
            for(unsigned int k = 0; k < maxHeight; k++){
                tmp = a.get(k,i) + b.get(j,k);
                value += tmp;
            }
            a.set(i,j,value);
            value = 0;
        }
    }
    return a;
}


/**
    * \fn /=
    * \param a Matrice a
    * \param b Matrice b
    * \brief Spécification du template pour les matrices booléenes
    * \return Matrice a modifiée
*/
MatrixEngine<bool> &operator /=(MatrixEngine<bool> &a, MatrixEngine<bool> &b){    
    return a;
}

/**
    * \fn /=
    * \tparam Type de matrice
    * \param a Matrice a
    * \param b Matrice b
    * \brief Divise deux matrices
    * \return Matrice a modifiée
*/
template <typename K>
MatrixEngine<K> &operator /=(MatrixEngine<K> &a, MatrixEngine<K> &b){ 
    a *= MathMatrix::inversion(b);    
    return a;
}

/**
    * \fn inversion
    * \tparam Type de matrice
    * \param a Matrice a
    * \brief Inverse une matrice
    * \return Matrice a modifiée
*/  
template <typename K>
MatrixEngine<K> MathMatrix::inversion(MatrixEngine<K> &a){
    
    int det = det(a);
    
    MatrixEngine<K> aPrime = complementAlgebrique(a);
    MatrixEngine<K> aPrimeTrans = transpose(aPrime);
    a = (aPrimeTrans *= (1/det));
    
    return a;
}

/**
    * \fn complementAlgebrique
    * \tparam Type de matrice
    * \param a Matrice a
    * \brief Complement algebrique d'une matrice
    * \return Matrice a modifiée
*/ 
template <typename K>
MatrixEngine<K> MathMatrix::complementAlgebrique(MatrixEngine<K> &a){
    
    
    return a;
}

/**
    * \fn transpose
    * \tparam Type de matrice
    * \param a Matrice a
    * \brief Inverse une matrice
    * \return Matrice a modifié
*/ 
template <typename K>
MatrixEngine<K> MathMatrix::transpose(MatrixEngine<K> &a){
    
    
    
    return a;
}

/**
    * \fn det
    * \tparam Type de matrice
    * \param a Matrice a
    * \brief Calcul de déterminant de la matrice
    * \return déterminant
*/ 
template <typename K>
int MathMatrix::det(MatrixEngine<K> &a){
    int det = a.get(0, 0);
    
    if(a.getHeight() ==  a.getWidth()){
        for(int i =1; i < a.getWidth(); i++){
            det *= a.get(i, i);
        }
    }
    
    return det;
}

#endif
