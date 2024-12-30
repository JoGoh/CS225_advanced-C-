/*****************************************************************************/
/*!
\file Point.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted class Point
and declarations of its member functions.
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
#ifndef POINT_H
#define POINT_H

#include "IColoredShape.h"
#include "ITranslatable.h"
#include "Round.h"

namespace cs225
{
  template <typename T>
  class Point : public IColoredShape<T>, public ITranslatable<T>
  {
  public:
    using type = typename T::type;
    Point(const Color& color, const T& vect); 
    const T& pivot() const; 
    Color color() const override;
    int x() const;
    int y() const;  
    virtual void translate(const T& vect) override;
    virtual ~Point() = default;
    
  protected:
    Color _color;
    T _pivot; 
  };
}

#include "Point.hpp"

#endif