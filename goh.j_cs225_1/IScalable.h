/*****************************************************************************/
/*!
\file IScalable.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the interface class IScalable
and declarations of its virtual member functions.
Functions included:
scale - a pure virtual function that would be overriden to scale with respect
to a pivot by a factor given. 
~IScalable - a virtual default destructor
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
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