/*****************************************************************************/
/*!
\file IRotatable.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #1
\date 20/06/2020
\brief
This file contains a definition of the interface class IRotatable
and declarations of its virtual member functions.
Functions included:
rotate - a pure virtual function that would be overriden 
to rotate upon a pivot
~IRotatable - a virtual default destructor
Hours spent on this assignment: 6
Specific portions that gave you the most trouble:implementing the ctor for 
RegularPolygon.
*/
/*****************************************************************************/
#ifndef IROTATABLE_H
#define IROTATABLE_H

namespace cs225
{
  class IRotatable
  {
  public:
    virtual void rotate(float angle) = 0;
    virtual ~IRotatable() = default;
  };
}

#endif