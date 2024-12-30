/*****************************************************************************/
/*!
\file RenderingVisitor.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #2
\date 03/07/2020
\brief
This file contains the implementation of templeted class RenderingVisitor's
member functions.
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
#include "RenderingVisitor.h"

namespace cs225
{
  template <typename T>
  RenderingVisitor<T>::RenderingVisitor (const int& width, const int& height,
    const float& scalew, const float& scaleh, const std::string& output) :
    _width{width},
    _height{height},
    _wfull{width*cs225::round<int,float>(scalew)},   
    _hfull{height*cs225::round<int,float>(scaleh)},
    _sw{scalew},
    _sh{scaleh},
    _out{output},
    _bitmap{
      static_cast<size_t>(_wfull),
      static_cast<size_t>(_hfull)
    } 
  {
  }
  
  template <typename T>
  void RenderingVisitor<T>::visit (const Background<T>& bg)
  {
    int _hdiv{};
    int _wdiv{};
    for (int ht{}; ht < _hfull; ht++)
    {
      for (int wd{}; wd < _wfull; wd++)
      {
        _hdiv = ht/round<int,float>(_sh);
        _wdiv = wd/round<int,float>(_sw);
        _bitmap.color(bg.colorData()[_hdiv*_width+_wdiv]);
        _bitmap.drawPixel({wd,_hfull-ht-1});
      }
    }
  }
  
  template<typename T>
  void RenderingVisitor<T>::visit(const Circle<T>& circle)
  {
    const Vector2D<float> ULeft{ 
      (static_cast<float>(circle.x()) - circle.radius())*_sw,
      (static_cast<float>(circle.y()) + circle.radius())*_sh 
    };
    const Vector2D<float> LRight{
      (static_cast<float>(circle.x()) + circle.radius())*_sw,
      (static_cast<float>(circle.y()) - circle.radius())*_sh 
    };

    const typename BitmapCanvas<T>::point2D upL{
      round<int,float>(ULeft.x()),
      round<int,float>(static_cast<float>(_hfull) - ULeft.y())
    };
    const typename BitmapCanvas<T>::point2D loR{
      round<int,float>(LRight.x()),
      round<int,float>(static_cast<float>(_hfull) - LRight.y())
    };
    
    _bitmap.color(circle.color());
    _bitmap.drawEllipse(upL, loR);
  } 

  template<typename T>
  void RenderingVisitor<T>::visit(const Point<T>& pixel)
  {
    const typename BitmapCanvas<T>::point2D loR{
      round<int,float>(static_cast<float>(pixel.x())*_sw),
      round<int,float>(
        static_cast<float>(_hfull) - (static_cast<float>(pixel.y())*_sh)
      )
    };
    _bitmap.color(pixel.color());
    _bitmap.drawPixel(loR);
  }
  
  template<typename T>
  void RenderingVisitor<T>::visit(const RegularPolygon<T>& rp)
  {
    RenderingVisitor<T>::visit(static_cast<Polygon<T>>(rp));
  }

  template<typename T>
  void RenderingVisitor<T>::visit(const Triangle<T>& tri)
  {
    RenderingVisitor<T>::visit(static_cast<Polygon<T>>(tri));
  } 

  template<typename T>
  void RenderingVisitor<T>::visit(const Polygon<T>& poly)
  {
    std::vector<typename BitmapCanvas<T>::point2D> vP;
    for (size_t i{}; i < poly.size(); i++)
    {
      const typename BitmapCanvas<T>::point2D upL{
        round<int, float>(static_cast<float>((poly.points())[i].x())*_sw),
        round<int, float>(
          static_cast<float>(_hfull)-(
          static_cast<float>((poly.points())[i].y())*_sh)
        )
      };
      vP.push_back(upL);
    } 
    _bitmap.color(poly.color());
    _bitmap.drawPolygon(vP);
  }

  template<typename T>
  RenderingVisitor<T>::~RenderingVisitor()
  {
    _bitmap.save(_out);
  } 
}