/*****************************************************************************/
/*!
\file IScalable.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the interface class IScalable
and declarations of its virtual member functions.
Functions included:
scale - a pure virtual function that would be overriden to scale with respect
to a pivot by a factor given. 
~IScalable - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef ISCALABLE_H
#define ISCALABLE_H

namespace cs225
{
  class IScalable
  {
  public:
    virtual void scale(float factor) = 0;
    virtual ~IScalable() = default;
  };
}

#endif