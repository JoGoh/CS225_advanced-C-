/*****************************************************************************/
/*!
\file Background.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implmentation of templeted class Background's
member functions.
Functions included:
Background - the constructor to initialize its member variables
width - the getter function for the member variable _width
height - the getter function for the member variable _height
colorData - the getter function for the member _Cdata
accept - overriden member fn that accepts a visitor to visit based on it.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#include "Background.h"

namespace cs225
{
  template <typename T>
  Background<T>::Background(const pixelCount& width,
    const pixelCount& height, const Color* Cdata) :
    _width{width},
    _height{height},
    _Cdata{Cdata, Cdata+(width*height)}
  {
  }
  
  template <typename T>
  typename Background<T>::pixelCount Background<T>::width() const
  {
    return _width;
  }
  
  template <typename T>
  typename Background<T>::pixelCount Background<T>::height() const
  {
    return _height;
  }
  
  template <typename T>
  const Color* Background<T>::colorData() const
  {
    return _Cdata.data();
  }
  
  template <typename T>
  void Background<T>::accept(IVisitor<T>& visitor) const
  {
    visitor.visit(*this);
  }   
}