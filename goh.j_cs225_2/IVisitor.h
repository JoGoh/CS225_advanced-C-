/*****************************************************************************/
/*!
\file IVisitor.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted interface class IVisitor
and declarations of its virtual member functions.
Functions included:
visit - pure virtual fn to facilitate dynamic dispatch based on params.
~IVisitor - a virtual default destructor
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _IVISITOR_H_
#define _IVISITOR_H_

namespace cs225
{
   template<typename T>
   class Background;
   template<typename T>
   class Circle;
   template<typename T>
   class Point;
   template<typename T>
   class RegularPolygon;
   template<typename T>
   class Triangle; 
   template<typename T>
   class Polygon;
   
  template <typename T>
  class IVisitor
  {
  public:
    virtual void visit (const Background<T>& bg)     = 0;
    virtual void visit (const Circle<T>& circle)     = 0;
    virtual void visit (const Point<T>& pixel)       = 0;
    virtual void visit (const RegularPolygon<T>& rp) = 0;
    virtual void visit (const Triangle<T>& tri)      = 0;
    virtual void visit (const Polygon<T>& poly)      = 0;
    virtual ~IVisitor() = default;
  };
}

#endif