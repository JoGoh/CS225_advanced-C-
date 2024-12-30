/*****************************************************************************/
/*!
\file Point.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
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
accept - overriden member fn that accepts a visitor to visit based on it.
clone - memebr fn to facilitate prototype design pattern.
~Point - virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef POINT_H
#define POINT_H

#include "IColoredShape.h"
#include "ITranslatable.h"
#include "Round.h"
#include "ICloneable.h"
#include "IVisitable.h"

namespace cs225
{
  template <typename T>
  class Point : public IColoredShape<T>, public ITranslatable<T>, 
    public ICloneable, public IVisitable<T>
  {
  public:
    using type = typename T::type;
    Point(const Color& color, const T& vect); 
    const T& pivot() const; 
    Color color() const override;
    typename T::type x() const;
    typename T::type y() const;  
    virtual void translate(const T& vect) override;
    void accept(IVisitor<T>& visitor) const override;
    Point<T>* clone () const override;
    virtual ~Point() = default;
    
  protected:
    Color _color;
    T _pivot; 
  };
}

#include "Point.hpp"

#endif