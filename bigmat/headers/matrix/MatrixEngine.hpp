#ifndef _MATRIX_ENGINE_
#define _MATRIX_ENGINE_

/**
   * \file MatrixEngine.h
   * \author ABNP
   * \date 13 Mai 2014
*/

/**
    * \class     MatrixEngine
    * \tparam T  Type de donnée
    * \brief     Classe abstraite de matrice
 */
template <typename T>
class MatrixEngine
{
public:
    virtual T get(unsigned int, unsigned int) = 0;
    virtual void set(unsigned int, unsigned int, T) = 0;


    /**
        * \fn getWidth()
        * \brief Retourne la largeur de la matrice
        * \return largeur de la matrice
    */
    virtual unsigned int getWidth() = 0;

    /**
        * \fn getHeight()
        * \brief Retourne la hauteur de la matrice
        * \return Hauteur de la matrice
    */
    virtual unsigned int getHeight() = 0;


    /**
        * \fn setWidth()
        * \param width Nouvelle largeur
        * \brief Défini la largeur de la matrice
    */
    virtual void setWidth(unsigned int) = 0;

    /**
        * \fn setHeight()
        * \param height Nouvelle hauteur
        * \brief Défini la hauteur de la matrice
    */
    virtual void setHeight(unsigned int) = 0;
};

#endif
