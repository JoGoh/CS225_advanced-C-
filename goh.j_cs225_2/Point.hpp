/*****************************************************************************/
/*!
\file Point.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class Point's
member functions.
Functions included:
Point - the constructor to initialize its member variables
pivot - the getter function for the member variable _pivot
color - the getter function for the member variable _color
x - pass through function for _pivot's getter for _x
y - pass through function for _pivot's getter for _y
translate - an overriden function for vector additon
accept - overriden member fn that accepts a visitor to visit based on it.
clone - memebr fn to facilitate prototype design pattern.
~Point - virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
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
  typename T::type Point<T>::x() const
  {
    return _pivot.x();
  }
  
  template <typename T>
  typename T::type Point<T>::y() const
  {
    return _pivot.y();
  }
  
  template <typename T> 
  void Point<T>::translate(const T& vect) 
  {
    _pivot = T{(vect.x()+_pivot.x()),(vect.y()+_pivot.y())};
  }
  
  template <typename T>
  void Point<T>::accept(IVisitor<T>& visitor) const 
  {
    visitor.visit(*this);
  }
  
  template <typename T>
  Point<T>* Point<T>::clone () const
  {
    return new Point<T>(*this);
  }
}