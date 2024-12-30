/*****************************************************************************/
/*!
\file IVisitable.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted interface class IVisitable
and declarations of its virtual member functions.
Functions included:
accept - pure virtual fn to facilitate dynamic dispatch.
~IVisitable - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _IVISITABLE_H_
#define _IVISITABLE_H_

#include "IVisitor.h"

namespace cs225
{
  template <typename T>
  class IVisitable 
  {
  public:
    virtual void accept(IVisitor<T>& visitor) const = 0;
    virtual ~IVisitable() = default;
  };
}

#endif