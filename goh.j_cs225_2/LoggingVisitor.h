/*****************************************************************************/
/*!
\file LoggingVisitor.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains a definition of the templeted class LoggingVisitor
and declarations of its member functions.
Functions included:
LoggingVisitor - the constructor to initialize its member variables
visit - overriden member fn to facilitate dynamic dispatch based on param.
~LoggingVisitor - the destructor.
Hours spent on this assignment: 16
Specific portions that gave you the most trouble: understandint BitMap &
implementing RenderingVisitor while also overloading Polygon<T>::translate,
to prevent "output2.bmp" to have "shifting pivots".
*/
/*****************************************************************************/
#ifndef _LOGGINGVISITOR_H_
#define _LOGGINGVISITOR_H_

#include <fstream>
#include <iostream> //std::cerr
#include "IVisitor.h"
#include "Background.h"
#include "Circle.h"
#include "RegularPolygon.h"
#include "Triangle.h"

namespace cs225
{
  template <typename T>
  class LoggingVisitor : public IVisitor<T>
  { 
    std::ofstream outfile;
    
  public:
    LoggingVisitor (const std::string& output);
    void visit (const Background<T>& bg)     override;
    void visit (const Circle<T>& circle)     override;
    void visit (const Point<T>& pixel)       override;
    void visit (const RegularPolygon<T>& rp) override;
    void visit (const Triangle<T>& tri)      override;
    void visit (const Polygon<T>& poly)      override;
    ~LoggingVisitor();
  };
}

#include "LoggingVisitor.hpp"

#endif

    

