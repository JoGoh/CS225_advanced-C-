/*****************************************************************************/
/*!
\file Background.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class Background
and declarations of its member functions.
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
#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <vector>
#include "IShape.h"
#include "IVisitable.h"

namespace cs225
{
  template <typename T>
  class Background : public IVisitable<T>, public IShape<T>
  {
  public:   
    using pixelCount = size_t;
    Background(const pixelCount& width,
      const pixelCount& height, const Color* Cdata);
    pixelCount width() const;
    pixelCount height() const;
    const Color* colorData() const;
    void accept(IVisitor<T>& visitor) const override;

  private:       
    pixelCount _width;
    pixelCount _height;
    std::vector<Color> _Cdata;
  };
}

#include "Background.hpp"

#endif  