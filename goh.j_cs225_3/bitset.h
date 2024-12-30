/*****************************************************************************/
/*!
\file bitset.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #3
\date 19/07/2020
\brief
This file contains the definition of container bitset and declaration for 
it's member functions.
Functions included:
bitset - the ctor to initialize the container with 0's.
size - a "gettor-like" fn that returns the number of bits.
count - returns the number of 1's in the bitset.
set - sets or clears a bit depending on the second arg at first arg's location
reset - clears a bit at the arg's location.
flip - toggles a bit at the arg's location
test - checks if the bit at arg's location is 1 or 0, returns result.
to_string - returns the string of the bitset, replaces 0 
with 1st arg and 1 with 2nd
operator[] - overloaded subscript operator that returns bit at arg's location.
Hours spent on this assignment: 6 hours
Specific portions that gave you the most trouble:The size declared for array.
*/
/*****************************************************************************/
#ifndef _BITSET_H_
#define _BITSET_H_
namespace cs225
{
  template <size_t N> 
  class bitset
  {
    unsigned char Bits[(N+(CHAR_BIT-1))/CHAR_BIT];      
  public:
    bitset();
    size_t size() const;
    size_t count() const;
    void set  (const size_t& pos, bool val = true);
    void reset(const size_t& pos);
    void flip (const size_t& pos);
    bool test (const size_t& pos) const;
    std::string to_string(const char& O ='0',const char& I ='1') const;
    bool operator[](const size_t& pos) const;
  };
}
#include "bitset.hpp"
#endif