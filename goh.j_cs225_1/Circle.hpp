/*****************************************************************************/
/*!
\file Circle.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a implentation of the templeted class Circle's
member functions.
Functions included:
Circle - the constructor to initialize its member variables
radius - the getter function for the member variable _radius
scale - scales the Circle with respect to pivot by a factor provided
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#include "Circle.h"

namespace cs225
{
  template <typename T>
  Circle<T>::Circle(const Color& color, const T& vect, const int radius) : 
    Point<T>(color, vect), 
    _radius(radius) 
  {
  } 
  
  template <typename T>
  int Circle<T>::radius() const
  {
    return _radius;
  }
  
  template <typename T>
  void Circle<T>::scale(float factor)
  {
    _radius *= round<int, float>(factor);
  }
}