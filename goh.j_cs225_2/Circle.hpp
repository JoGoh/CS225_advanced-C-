/*****************************************************************************/
/*!
\file Circle.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class Circle's
member functions.
Functions included:
Circle - the constructor to initialize its member variables
radius - the getter function for the member variable _radius
scale - scales the Circle with respect to pivot by a factor provided
accept - overriden member fn that accepts a visitor to visit based on it.
clone - memebr fn to facilitate prototype design pattern.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#include "Circle.h"

namespace cs225
{
  template <typename T>
  Circle<T>::Circle(const Color& color, const T& vect, const float& radius) : 
    Point<T>(color, vect), 
    _radius(radius) 
  {
  } 
  
  template <typename T>
  float Circle<T>::radius() const
  {
    return _radius;
  }
  
  template <typename T>
  void Circle<T>::scale(float factor)
  {
    _radius *= factor;
  }
  
  template <typename T>
  void Circle<T>::accept(IVisitor<T>& visitor) const
  {
    visitor.visit(*this);
  }
  
  template <typename T>
  Circle<T>* Circle<T>::clone () const
  {
    return new Circle<T>(*this);
  } 
}