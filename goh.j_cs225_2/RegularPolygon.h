/*****************************************************************************/
/*!
\file RegularPolygon.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class RegularPolygon
and declarations of its member function.
Functions included:
RegularPolygon - the constructor to initialize its member variables
accept - overriden member fn that accepts a visitor to visit based on it.
clone - memebr fn to facilitate prototype design pattern.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef REGULARPOLYGON_H
#define REGULARPOLYGON_H

#include "Polygon.h"

namespace cs225
{
  template <typename T>
  class RegularPolygon : public Polygon<T>
  {
  public:
    RegularPolygon(const Color& color, const T& pivot, const T& start, 
      const size_t& sides);
    void accept(IVisitor<T>& visitor) const override;
    RegularPolygon<T>* clone () const override;  
  };
}

#include "RegularPolygon.hpp"

#endif