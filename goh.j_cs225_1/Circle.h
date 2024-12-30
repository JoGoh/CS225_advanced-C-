/*****************************************************************************/
/*!
\file Circle.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted class Circle
and declarations of its member functions.
Functions included:
Circle - the constructor to initialize its member variables
radius - the getter function for the member variable _radius
scale - scales the Circle with respect to pivot by a factor provided
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
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
    int _radius;
    
  public:
    Circle(const Color& color, const T& vect, const int radius);
    int radius ()const;
    void scale(float factor) override;
  };
}

#include "Circle.hpp"

#endif