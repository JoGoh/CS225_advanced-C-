/*****************************************************************************/
/*!
\file RenderingVisitor.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class RenderingVisitor
and declarations of its member functions.
Functions included:
RenderingVisitor - the constructor to initialize its member variables
visit - overriden member fn to facilitate dynamic dispatch based on param.
~RenderingVisitor - the destructor to delete buffer after "save".
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _RENDERINGVISITOR_H_
#define _RENDERINGVISITOR_H_

#include <fstream>
#include "Round.h"
#include "Vector2D.h"
#include "IVisitor.h"
#include "BitmapCanvas.h"

namespace cs225
{
  template <typename T>
  class RenderingVisitor : public IVisitor<T>
  {
    int _width;
    int _height;
    int _wfull;
    int _hfull;
    float _sw;
    float _sh;
    std::string _out;
    BitmapCanvas<T> _bitmap;

  public:
    RenderingVisitor (const int& width, const int& height, 
      const float& scalew, const float& scaleh, const std::string& output);
    void visit (const Background<T>& bg)     override;
    void visit (const Circle<T>& circle)     override;
    void visit (const Point<T>& pixel)       override;
    void visit (const RegularPolygon<T>& rp) override;
    void visit (const Triangle<T>& tri)      override;
    void visit (const Polygon<T>& poly)      override;
    ~RenderingVisitor();
  };
}

#include "RenderingVisitor.hpp"

#endif