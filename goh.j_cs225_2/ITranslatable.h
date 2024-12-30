/*****************************************************************************/
/*!
\file ITranslatable.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the interface class ITranslatable
and declarations of its virtual member functions.
Functions included:
translate - a pure virtual function that would be overriden for 
vector addition
~ITranslatable - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef ITRANSLATABLE_H
#define ITRANSLATABLE_H

namespace cs225
{
  template <typename T>
  class ITranslatable
  {
  public:
    virtual void translate(const T& vect) = 0;
    virtual ~ITranslatable() = default;
  };
}

#endif