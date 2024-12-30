/*****************************************************************************/
/*!
\file ShapeFactory.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class ShapeFactory's
member functions.
Functions included:
ShapeFactory - the constructor to initialize its member variables
create - member fn to facilitate factory design pattern for shapes.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#include "ShapeFactory.h"

namespace cs225
{
  template<typename T>
  IShape<T>* ShapeFactory<T>::create(size_t index)
  {
    std::array<T, 3> aT3;
    std::array<T, 5> aT5;
    std::vector<Color> vC;
    
    switch (index)
    {
    case 0:
    {
      size_t width{};
      size_t height{};
      BitmapCanvas<T>::load(
        "Logo.bmp",
        width,
        height,
        vC
      );

      return new Background<T>{
        static_cast<typename Background<T>::pixelCount>(height), 
        static_cast<typename Background<T>::pixelCount>(width), 
        vC.data()
      };
    }
    case 1:
    {   
      return new Circle<T>{
        { 0, 200, 0 }, 
        { 100, 150 }, 
        15
      };
    }
    case 2:
    {
      return new Point<T>{
        { 100, 0, 0 }, 
        { 95, 150 } 
      };
    }
    case 3:
    {   
      return new Point<T>{
        { 100, 0, 0 }, 
        { 105, 150 } 
      };
    }
    case 4: 
    {
      return new RegularPolygon<T>{
        { 200, 0, 200 }, 
        { 100, 50 }, 
        { 110, 50 }, 
        6
      };
    }
    case 5:
    {
      aT3 = { T{100,135}, T{70,115},T{130,115} };
      return new Triangle<T>{
        { 200,200, 0 }, 
        aT3
      };
    }
    case 6:
    {
      aT5 = { T{85, 115}, T{90, 60},T{100, 50},T{110, 60}, T{115, 115} };
      return new Polygon<T>{
        { 0, 200, 200 }, 
        aT5.size(), 
        aT5.data()
      };
    }
    default: throw std::string{ "Not supported!" };
    }
  }
}