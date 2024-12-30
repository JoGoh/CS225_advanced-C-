/*****************************************************************************/
/*!
\file IShape.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted interface class IShape
and declarations of its virtual member functions.
Functions included:
~IShape - a virtual default destructor
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
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