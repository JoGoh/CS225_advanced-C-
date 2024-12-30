/*****************************************************************************/
/*!
\file bitset_tep.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #4
\date 25/07/2020
\brief
This file contains the definition of the bitset_tep class 
and declaration for it's member functions.
Functions included:
bitset_tep - the ctor to perfectly forward the tpp 
create     - "creates" type erased object of templated param T
size       - a pass thru fn for Concept::size.
count      - a pass thru fn for Concept::count.
set        - a pass thru fn for Concept::set.
reset      - a pass thru fn for Concept::reset.
toggle     - a pass thru fn for Concept::flip.
test       - a pass thru fn for Concept::test.
to_string  - a pass thru fn for Concept::to_string.
operator[] - overloaded subscript operator to pass thru as Concept::[]
Hours spent on this assignment: 6 hours
Specific portions that gave you the most trouble: syntax of std::unique_ptr
*/
/*****************************************************************************/
#ifndef _BITSET_TEP_H_
#define _BITSET_TEP_H_
namespace cs225
{
  class bitset_tep
  {
    class Concept
    {
    public:
      virtual size_t size() const                                      = 0;
      virtual size_t count() const                                     = 0;
      virtual void set  (const size_t& pos, bool val)                  = 0;
      virtual void reset(const size_t& pos)                            = 0;
      virtual void flip (const size_t& pos)                            = 0;
      virtual bool test (const size_t& pos) const                      = 0;
      virtual std::string to_string(const char& O, const char& I)const = 0;
      virtual bool operator[](const size_t& pos) const                 = 0;
      virtual ~Concept() = default;
    };
    
    template <typename T> 
    class Model : public Concept
    {
      T _instance;     
    public:
      template<typename... Args> 
      Model(Args... args);
      size_t size() const  override;
      size_t count() const override;
      void set  (const size_t& pos, bool val) override; //def args in tep
      void reset(const size_t& pos) override;
      void flip (const size_t& pos) override;
      bool test (const size_t& pos) const override;
      std::string to_string(const char& O, const char& I)const override;
      bool operator[](const size_t& pos) const override;
    };
  
    std::unique_ptr<Concept> bit_storage;

  public:
    bitset_tep(std::unique_ptr<Concept> concept);
    template<typename T, typename... Args>
    static bitset_tep create(Args... args); 
    size_t size() const;
    size_t count() const;
    void set   (const size_t& pos, bool val = true); 
    void reset (const size_t& pos);
    void toggle(const size_t& pos);
    bool test  (const size_t& pos) const;
    std::string to_string(const char& O ='0',const char& I ='1') const;
    bool operator[](const size_t& pos) const;
  };
}
#include "bitset_tep.hpp"
#endif