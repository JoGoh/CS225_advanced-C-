/*****************************************************************************/
/*!
\file Point.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a implementation of the templeted class Point's
member functions.
Functions included:
Point - the constructor to initialize its member variables
pivot - the getter function for the member variable _pivot
color - the getter function for the member variable _color
x - pass through function for _pivot's getter for _x
y - pass through function for _pivot's getter for _y
translate - an overriden function for vector additon
~Point - virtual default destructor
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#include "Point.h"

namespace cs225
{
  template <typename T>
  Point<T>::Point(const Color& color, const T& vect) :
    _color(color), 
    _pivot(vect)
  {
  }
    
  template <typename T> 
  const T& Point<T>::pivot() const
  {
    return _pivot;
  }
  
  template <typename T> 
  Color Point<T>::color() const
  {
    return _color;
  }
  
  template <typename T>
  int Point<T>::x() const
  {
    return _pivot.x();
  }
  
  template <typename T>
  int Point<T>::y() const
  {
    return _pivot.y();
  }
  
  template <typename T> 
  void Point<T>::translate(const T& vect) 
  {
    _pivot = T{(vect.x()+_pivot.x()),(vect.y()+_pivot.y())};
  }
}