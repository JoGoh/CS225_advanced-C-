/*****************************************************************************/
/*!
\file Triangle.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted class Triangle
and declarations of its member function.
Functions included:
Triangle - the constructor to initialize its member variables
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Polygon.h"
#include <array>

namespace cs225
{
  template <typename T>
  class Triangle : public Polygon<T>
  {
  public:
    Triangle(const Color& color, const std::array<T, 3> pts);
  };
}

#include "Triangle.hpp"

#endif