/*****************************************************************************/
/*!
\file Vector2D.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class Vector2D's
member function.
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
#include "Vector2D.h"

namespace cs225
{
  template <typename T>
  Vector2D<T>::Vector2D() :
    std::complex<T>{}
  {
  }
  
  template <typename T>
  Vector2D<T>::Vector2D(const type& x, const type& y) :
    std::complex<T>{x, y}
  {
  }

  template <typename T>
  typename Vector2D<T>::type Vector2D<T>::x() const
  {
    return std::complex<T>::real();
  }

  template <typename T>
  typename Vector2D<T>::type Vector2D<T>::y() const
  {
    return std::complex<T>::imag();
  }

  template <typename T>
  void Vector2D<T>::x(const type& value)
  {
    std::complex<T>::real(value);
  }

  template <typename T>
  void Vector2D<T>::y(const type& value)
  {
    std::complex<T>::imag(value);
  }
  
  template <typename T>
  Vector2D<T>& Vector2D<T>::operator+=(const Vector2D<T>& rhs)
  {
    std::complex<T>::real(std::complex<T>::real()+rhs.x());
    std::complex<T>::imag(std::complex<T>::imag()+rhs.y());
    return *this;
  }

  template <typename T>
  Vector2D<T>& Vector2D<T>::operator-=(const Vector2D<T>& rhs)
  {
    std::complex<T>::real(std::complex<T>::real()-rhs.x());
    std::complex<T>::imag(std::complex<T>::imag()-rhs.y());
    return *this;
  }

  template <typename T>
  Vector2D<T> operator+(Vector2D<T> lhs, const Vector2D<T>& rhs)
  {
    return (lhs += rhs);
  }

  template <typename T>
  Vector2D<T> operator-(Vector2D<T> lhs, const Vector2D<T>& rhs)
  {
    return (lhs -= rhs);
  }
  
  template <typename T>
  std::ostream& operator<<(std::ostream& stream, const Vector2D<T>& rhs)
  {
    return (stream << rhs.x() << "," << rhs.y());
  }
}
