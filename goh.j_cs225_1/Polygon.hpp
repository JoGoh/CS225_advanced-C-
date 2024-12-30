/*****************************************************************************/
/*!
\file Polygon.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a implementation of the templeted class Polygon's
member functions.
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
#include "Polygon.h"

namespace cs225
{
  template <typename T>
  Polygon<T>::Polygon(const Color& color, const size_t& size, const T* pts) :
    Point<T>{color, T{}},
    _size(size)
  {
    for(size_t i{}; i<_size ; i++)
    {
      _points.push_back(pts[i]);
      Point<T>::translate(pts[i]);
    }
    Point<T>::_pivot= T{Point<T>::_pivot.x()/round<int, size_t>(size),
      Point<T>::_pivot.y()/round<int, size_t>(size)};
  }
  
  template <typename T>
  void Polygon<T>::scale(float factor)
  {
    for(size_t i{}; i<_size; i++)
    {
      _points[i] = T{
        Point<T>::_pivot.x() + round<int, float>(factor) *
          (_points[i].x() - Point<T>::_pivot.x()),
        Point<T>::_pivot.y() + round<int, float>(factor) *
          (_points[i].y() - Point<T>::_pivot.y())
      };
    }
  }
  
  template <typename T>
  void Polygon<T>::rotate(float angle)
  {
    float xrot{};
    float yrot{};
    for (size_t i{}; i < _size; ++i)
    {
      xrot = round<float, typename Point<T>::type>(_points[i].x() - Point<T>::_pivot.x());
      yrot = round<float, typename Point<T>::type>(_points[i].y() - Point<T>::_pivot.y());
      _points[i] = T{
        round<typename Point<T>::type,float>(round<float,typename Point<T>::type>(Point<T>::_pivot.x()) + 
          std::cos(angle) * xrot - std::sin(angle) * yrot),
        round<typename Point<T>::type,float>(round<float,typename Point<T>::type>(Point<T>::_pivot.y()) + 
          std::sin(angle) * xrot + std::cos(angle) * yrot)
      };
    }
  }
  
  template <typename T>
  size_t Polygon<T>::size() const
  {
    return _size;
  }
  
  template <typename T>
  const T* Polygon<T>::points() const 
  {
    return _points.data();
  }
} 