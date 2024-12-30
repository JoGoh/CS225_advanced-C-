/*****************************************************************************/
/*!
\file VisitorFactory.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class VisitorFactory
and declarations of its member functions.
Functions included:
create - member fn to facilitate factory design pattern for visitors.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _VISITORFACTORY_H_
#define _VISITORFACTORY_H_

#include "LoggingVisitor.h"
#include "RenderingVisitor.h"

namespace cs225
{
  template <typename T>
  class VisitorFactory
  {
  public:
    using type = IVisitor<T> *;
    type create(std::size_t visitorIndex)const; 
  };
}

#include "VisitorFactory.hpp"

#endif