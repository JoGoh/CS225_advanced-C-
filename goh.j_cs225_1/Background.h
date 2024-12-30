/*****************************************************************************/
/*!
\file Background.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the templeted class Background
and declarations of its member functions.
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
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "IShape.h"

namespace cs225
{
  template <typename T>
  class Background : public IShape<T>
  {
  public:   
    using pixelCount = int;
    Background(const pixelCount& width, const pixelCount& height, const Color* Cdata);
    pixelCount width() const;
    pixelCount height() const;
    const Color* colorData() const;
  
  private:       
    pixelCount _width;
    pixelCount _height;
    const Color* _Cdata;
  };
}

#include "Background.hpp"

#endif  