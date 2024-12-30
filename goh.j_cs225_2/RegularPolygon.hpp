/*****************************************************************************/
/*!
\file RegularPolygon.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class RegularPolygon's
member function.
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
#include "RegularPolygon.h"

namespace cs225
{
  template <typename T>
  RegularPolygon<T>::RegularPolygon(const Color& color, const T& pivot, 
    const T& start, const size_t& sides) :
    Polygon<T>{color, 1, &start} //start with first pt
  {
    const float angle = (2.0f*std::acos(-float{1}))/
      round<float, size_t>(sides);
    Point<T>::_pivot = pivot;
    float xrot{};
    float yrot{};
    for (; Polygon<T>::_size < sides; Polygon<T>::_size++)
    { //increment _size as more "sides" added
      xrot = round<float, typename Point<T>::type>(
        Polygon<T>::_points[Polygon<T>::_size-1].x() - Point<T>::_pivot.x()
      );
      yrot = round<float, typename Point<T>::type>(
        Polygon<T>::_points[Polygon<T>::_size-1].y() - Point<T>::_pivot.y()
      );
      
      Polygon<T>::_points.push_back(T{
          round<typename Point<T>::type, float>(
            round<float, typename Point<T>::type>(Point<T>::_pivot.x()) + 
            std::cos(angle) * xrot - std::sin(angle) * yrot
          ),
          round<typename Point<T>::type, float>(
            round<float, typename Point<T>::type>(Point<T>::_pivot.y()) + 
            std::sin(angle) * xrot + std::cos(angle) * yrot
          )
        }
      );
    }
  }
  
  template <typename T>
  void RegularPolygon<T>::accept(IVisitor<T>& visitor) const
  {
    visitor.visit(*this);
  }
  
  template <typename T>
  RegularPolygon<T>* RegularPolygon<T>::clone () const
  {
    return new RegularPolygon<T>(*this);
  }   
} 