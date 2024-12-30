/*****************************************************************************/
/*!
\file IColoredShape.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted interface class IColoredShape
and declarations of its virtual member functions.
Functions included:
color - a pure virtual function that would be overriden as a getter
~IColoredShape - a virtual default destructor
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
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