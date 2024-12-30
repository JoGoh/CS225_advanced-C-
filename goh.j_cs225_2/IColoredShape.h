/*****************************************************************************/
/*!
\file IColoredShape.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted interface class IColoredShape
and declarations of its virtual member functions.
Functions included:
color - a pure virtual function that would be overriden as a getter
~IColoredShape - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef ICOLOREDSHAPE_H
#define ICOLOREDSHAPE_H

#include "IShape.h"

namespace cs225
{
  template <typename T>
  class IColoredShape : public IShape<T>
  {
    public:
    virtual Color color() const = 0;
    virtual ~IColoredShape() = default;
  };
}

#endif