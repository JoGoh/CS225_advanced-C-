/*****************************************************************************/
/*!
\file Triangle.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class Triangle's
member function.
Functions included:
Triangle - the constructor to initialize its member variables
accept - overriden member fn that accepts a visitor to visit based on it.
clone - memebr fn to facilitate prototype design pattern.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
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
  
  template <typename T>
  void Triangle<T>::accept(IVisitor<T>& visitor) const
  {
    visitor.visit(*this);
  }
  
  template <typename T>
  Triangle<T>* Triangle<T>::clone() const
  {
    return new Triangle(*this);
  } 
}