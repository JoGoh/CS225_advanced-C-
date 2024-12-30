/*****************************************************************************/
/*!
\file ShapeFactory.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class ShapeFactory
and declarations of its member functions.
Functions included:
ShapeFactory - the constructor to initialize its member variables
create - member fn to facilitate factory design pattern for shapes.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include"Background.h"
#include"Circle.h"
#include"RegularPolygon.h"
#include"Triangle.h"
#include"BitmapCanvas.h"

namespace cs225
{
  template<typename T>
  class ShapeFactory 
  {
  public:
    IShape<T>* create(size_t index);
  };
}

#include"ShapeFactory.hpp"

#endif