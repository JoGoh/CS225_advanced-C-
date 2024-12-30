/*****************************************************************************/
/*!
\file LoggingVisitor.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class LoggingVisitor's
member functions.
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
#include "LoggingVisitor.h"

namespace cs225
{
  template <typename T>
  LoggingVisitor<T>::LoggingVisitor(const std::string& output) :
    outfile{output}
  {
    if (outfile.is_open())
    {
      outfile<<"### List of shapes ###"<<std::endl;
    }
    else
      std::cerr << "Unable to open file for logging.\n";
  }
  
  template <typename T>
  void LoggingVisitor<T>::visit (const Background<T>& bg) 
  {
    if (outfile.is_open())
    {
      outfile<<'\t'<<"Background"<<std::endl;
      outfile<<"\t\t"<<"Size: ("<<bg.height()<<", "<<bg.width()<<")"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n";   
  }
  
  template <typename T>
  void LoggingVisitor<T>::visit (const Circle<T>& circle) 
  {
    if (outfile.is_open())
    {
      outfile<<'\t'<<"Circle"<<std::endl;
      outfile<<"\t\t"<<"Center: ("<<circle.x()<<", "<<circle.y()<<")"
        <<std::endl;
      outfile<<"\t\t"<<"Coordinates: ("<<circle.x()<<", "
        <<circle.y()<<", "<<circle.radius()<<")"<<std::endl;
      outfile<<"\t\t"<<"Color: ("
        <<static_cast<size_t>(circle.color().red())<<", "
        <<static_cast<size_t>(circle.color().green())<<", "
        <<static_cast<size_t>(circle.color().blue())<<")"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n";       
  }
  
  template <typename T>
  void LoggingVisitor<T>::visit (const Point<T>& pixel) 
  {
    if (outfile.is_open())
    {
      outfile<<'\t'<<"Pixel"<<std::endl;
      outfile<<"\t\t"<<"Coordinates: ("
        <<pixel.x()<<", "<<pixel.y()<<")"<<std::endl;
      
      outfile<<"\t\t"<<"Color: ("
        <<static_cast<size_t>(pixel.color().red())<<", "
        <<static_cast<size_t>(pixel.color().green())<<", "
        <<static_cast<size_t>(pixel.color().blue())<<")"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n"; 
  } 
  
  template <typename T>
  void LoggingVisitor<T>::visit (const RegularPolygon<T>& rp) 
  {
    if (outfile.is_open())
    {
      outfile<<'\t'<<"Regular polygon"<<std::endl;
      outfile<<"\t\t"<<"Pivot: ("<<rp.x()<<", "<<rp.y()<<")"<<std::endl;
      for(size_t i{};i<rp.size();i++)
      {
        outfile<<"\t\t"<<"Point["<<i<<"]: ("<<(rp.points())[i].x()<<", "
          <<(rp.points())[i].y()<<")"<<std::endl;
      }
      outfile<<"\t\t"<<"Color: ("
        <<static_cast<size_t>(rp.color().red())<<", "
        <<static_cast<size_t>(rp.color().green())<<", "
        <<static_cast<size_t>(rp.color().blue())<<")"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n";     
  }
  
  template <typename T>
  void LoggingVisitor<T>::visit (const Triangle<T>& tri) 
  {
    if (outfile.is_open())
    {
      outfile<<'\t'<<"Triangle"<<std::endl;
      outfile<<"\t\t"<<"Pivot: ("<<tri.x()<<", "<<tri.y()<<")"<<std::endl;
      for(size_t i{};i<3;i++)
      {
        outfile<<"\t\t"<<"Point["<<i<<"]: ("<<(tri.points())[i].x()<<", "
          <<(tri.points())[i].y()<<")"<<std::endl;
      }
      outfile<<"\t\t"<<"Color: ("
        <<static_cast<size_t>(tri.color().red())<<", "
        <<static_cast<size_t>(tri.color().green())<<", "
        <<static_cast<size_t>(tri.color().blue())<<")"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n";       
  }
  
  template <typename T>
  void LoggingVisitor<T>::visit (const Polygon<T>& poly) 
  {
    if (outfile.is_open())
    {
      outfile<<'\t'<<"Polygon"<<std::endl;
      outfile<<"\t\t"<<"Pivot: ("<<poly.x()<<", "<<poly.y()<<")"<<std::endl;
      for(size_t i{};i<poly.size();i++)
      {
        outfile<<"\t\t"<<"Point["<<i<<"]: ("<<(poly.points())[i].x()<<", "
          <<(poly.points())[i].y()<<")"<<std::endl;
      }
      outfile<<"\t\t"<<"Color: ("
        <<static_cast<size_t>(poly.color().red())<<", "
        <<static_cast<size_t>(poly.color().green())<<", "
        <<static_cast<size_t>(poly.color().blue())<<")"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n";     
  }
  
  template <typename T>
  LoggingVisitor<T>::~LoggingVisitor()
  {
    if (outfile.is_open())
    {
      outfile<<"###"<<std::endl;
    }
    else
      std::cerr << "Failed to open file for logging.\n";
  }
}