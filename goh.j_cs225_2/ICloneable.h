/*****************************************************************************/
/*!
\file ICloneable.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted interface class ICloneable
and declarations of its virtual member functions.
Functions included:
clone - pure virtual fn to facilitate prototype design pattern.
~ICloneable - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _ICLONEABLE_H_
#define _ICLONEABLE_H_

namespace cs225
{
  class ICloneable
  {
  public:
    virtual ICloneable* clone() const = 0;
    virtual ~ICloneable() = default;
  };
}

#endif