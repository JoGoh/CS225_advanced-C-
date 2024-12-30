/*****************************************************************************/
/*!
\file Background.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a implementation of the templeted class Background's
member functions.
Functions included:
Background - the constructor to initialize its member variables
width - the getter function for the member variable _width
height - the getter function for the member variable _height
colorData - the getter function for the member _Cdata
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#include "Background.h"

namespace cs225
{
  template <typename T>
  Background<T>::Background(const pixelCount& width, const pixelCount& height, const Color* Cdata) :
    _width(width),
    _height(height), 
    _Cdata(Cdata) 
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
    return _Cdata;
  }
}