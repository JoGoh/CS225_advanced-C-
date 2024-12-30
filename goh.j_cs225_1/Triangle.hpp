/*****************************************************************************/
/*!
\file Triangle.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a implementation of the templeted class Triangle's
member function.
Functions included:
Triangle - the constructor to initialize its member variables
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#include "Triangle.h"

namespace cs225
{
  template <typename T>
  Triangle<T>::Triangle(const Color& color, const std::array<T, 3> pts) :
    Polygon<T>{color, 3, pts.data()}
  {
  }
}