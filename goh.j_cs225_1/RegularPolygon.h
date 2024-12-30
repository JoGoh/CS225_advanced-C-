/*****************************************************************************/
/*!
\file RegularPolygon.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted class RegularPolygon
and declarations of its member function.
Functions included:
RegularPolygon - the constructor to initialize its member variables
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "Polygon.h"

namespace cs225
{
  template <typename T>
  class RegularPolygon : public Polygon<T>
  {
  public:
    RegularPolygon(const Color& color, const T& pivot, const T& start, 
			const size_t& sides);
  };
}

#include "RegularPolygon.hpp"

#endif