/*****************************************************************************/
/*!
\file Polygon.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted class Polygon
and declarations of its member functions.
Functions included:
Polygon - the constructor to initialize its member variables
scale - scales the Polygon with respect to pivot by a factor provided
rotate - overriden function to rotate Polygon upon a pivot
size - the getter function for the member variable _size
points - the getter function for the member variable _points
~Polygon - virtual default destructor
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#ifndef POLYGON_H
#define POLYGON_H

#include "Point.h"
#include "IScalable.h"
#include "IRotatable.h"
#include <cmath>
#include <vector>

namespace cs225
{
  template <typename T>
  class Polygon : public Point<T>, public IScalable, public IRotatable
  {
  public: 
    Polygon(const Color& color, const size_t& size, const T* pts);  
    void scale(float factor) override;  
    void rotate(float angle) override;  
    size_t size() const; 
    const T* points ()const;    
    virtual ~Polygon() = default;
    
  protected:
    size_t _size;
    std::vector<T> _points;
  };
}

#include "Polygon.hpp"

#endif