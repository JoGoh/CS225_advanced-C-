/*****************************************************************************/
/*!
\file Circle.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class Circle
and declarations of its member functions.
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
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "IScalable.h"

namespace cs225
{
  template <typename T>
  class Circle : public Point<T>, public IScalable
  {
    float _radius;
    
  public:
    Circle(const Color& color, const T& vect, const float& radius);
    float radius ()const;
    void scale(float factor) override;
    void accept(IVisitor<T>& visitor) const override;
    Circle<T>* clone () const override;
  };
}

#include "Circle.hpp"

#endif