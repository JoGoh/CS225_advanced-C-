/*****************************************************************************/
/*!
\file Vector2D.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class Vector2D
and declarations of its member function.
Functions included:
Vector2D() - the default synthetic constructor to initialize member variables
Vector2D(const T&, constT&) - ctor to initialize std::complex<T> based on args.
Vector2D(const std::complex<T>& copy) - copy ctor, 
which cpy based on std::complex<T> values.
x() - gettor for real part of std::complex<T>
y() - gettor for imaginary part of std::complex<T>
x(const T&) - settor for real part of std::complex<T>
y(const T&) - gettor for imaginary part of std::complex<T>
ostream& operator<<(std::ostream&,const Vector2D<T>&) - overloaded ostream.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <iostream>
#include <complex>

namespace cs225
{
  template <typename T>
  class Vector2D : private std::complex<T>
  {
  public:
    using type = T;

    type x() const;
    type y() const;

    void x(const type& value);
    void y(const type& value);

    Vector2D();
    Vector2D(const type& x, const type& y);
    
    Vector2D<T>& operator+=(const Vector2D<T>&);
    Vector2D<T>& operator-=(const Vector2D<T>&);
  };
  
  template <typename T>
  Vector2D<T> operator+(Vector2D<T> lhs, const Vector2D<T>& rhs);
  
  template <typename T>
  Vector2D<T> operator-(Vector2D<T> lhs, const Vector2D<T>& rhs);
  
  template <typename T>
  std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& rhs);
}

#include "Vector2D.hpp"

#endif