/*****************************************************************************/
/*!
\file Triangle.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class Triangle
and declarations of its member function.
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
    Triangle<T>* clone() const override;
    void accept(IVisitor<T>& visitor) const override;   
  };
}

#include "Triangle.hpp"

#endif