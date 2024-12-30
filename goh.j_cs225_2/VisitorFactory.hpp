/*****************************************************************************/
/*!
\file VisitorFactory.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class VisitorFactory's
member functions.
Functions included:
create - member fn to facilitate factory design pattern for visitors.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#include "VisitorFactory.h"

namespace cs225
{
  template<typename T>
  typename VisitorFactory<T>::type 
    VisitorFactory<T>::create(size_t visitorIndex) const
  {
    switch (visitorIndex)
    {
      case 0: return new LoggingVisitor<T>{"output0.txt"}; 
      case 1: return new RenderingVisitor<T>{640,240,2.0f,2.0f,"output1.bmp"};
      case 2: return new RenderingVisitor<T>{640,480,1.0f,1.0f,"output2.bmp"};
      default: throw std::string{"Not supported!"};
    }
  }
}