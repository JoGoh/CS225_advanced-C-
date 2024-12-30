/*****************************************************************************/
/*!
\file IShape.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted interface class IShape
and declarations of its virtual member functions.
Functions included:
~IShape - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef ISHAPE_H
#define ISHAPE_H

#include "Color.h"

namespace cs225
{
  template <typename T>
  class IShape 
  {
  public:
    virtual ~IShape() = default;
  };
}

#endif  