/*****************************************************************************/
/*!
\file Polygon.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class Polygon's
member functions.
Functions included:
Polygon - the constructor to initialize its member variables
scale - scales the Polygon with respect to pivot by a factor provided
rotate - overriden function to rotate Polygon upon a pivot
translate - an overriden function for rendering to maintain proper pivot
size - the getter function for the member variable _size
points - the getter function for the member variable _points
accept - overriden member fn that accepts a visitor to visit based on it.
clone - memebr fn to facilitate prototype design pattern.
~Polygon - virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
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
    Point<T>::_pivot= T{
      round<typename T::type, float>(
        static_cast<float>(Point<T>::_pivot.x())/
        static_cast<float>(size)),
      round<typename T::type, float>(
        static_cast<float>(Point<T>::_pivot.y())/
        static_cast<float>(size))
    };
  }
  
  template <typename T>
  void Polygon<T>::scale(float factor)
  {
    for(size_t i{}; i<_size; i++)
    {
      _points[i] = T{
        Point<T>::_pivot.x() + round<typename T::type, float>(factor) *
          (_points[i].x() - Point<T>::_pivot.x()),
        Point<T>::_pivot.y() + round<typename T::type, float>(factor) *
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
      xrot = round<float, typename Point<T>::type>(
        _points[i].x() - Point<T>::_pivot.x()
      );
      yrot = round<float, typename Point<T>::type>(
        _points[i].y() - Point<T>::_pivot.y()
      );
        
      _points[i] = T{
        round<typename Point<T>::type,float>(
          round<float,typename Point<T>::type>(Point<T>::_pivot.x()) +
          std::cos(angle) * xrot - std::sin(angle) * yrot
        ),
        round<typename Point<T>::type,float>(
          round<float,typename Point<T>::type>(Point<T>::_pivot.y()) +
          std::sin(angle) * xrot + std::cos(angle) * yrot
        )
      };
    }
  }
  
  template<typename T>
  void Polygon<T>::translate(const T& vect)
  {
    for (size_t i{}; i < _size; i++)
    {
      _points[i] += vect;
    }
    Point<T>::translate(vect);
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
  
  template <typename T>
  void Polygon<T>::accept(IVisitor<T>& visitor) const
  {
    visitor.visit(*this);
  }
  
  template <typename T>
  Polygon<T>* Polygon<T>::clone () const
  {
    return new Polygon<T>(*this);
  } 
} 