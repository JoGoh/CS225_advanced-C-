/*****************************************************************************/
/*!
\file bitset.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #3
\date 19/07/2020
\brief
This file contains the implementation of container bitset's member functions.
Hours spent on this assignment: 6 hours
Specific portions that gave you the most trouble:The size declared for array.
*/
/*****************************************************************************/
#include "bitset.h"
namespace cs225
{
  template<size_t N>
  bitset<N>::bitset() : 
    Bits{} //cl requires this
  {
  }
  
  template<size_t N>
  size_t bitset<N>::size() const
  {
    return N;
  }
  
  template<size_t N>
  size_t bitset<N>::count() const
  {
    size_t Count{};
    for(size_t i{}; i<N; i++)
    {
      Count+=static_cast<size_t>(test(i));
    }
    return Count;
  }
  
  template<size_t N>
  void bitset<N>::set(const size_t& pos, bool val)
  {
    if(pos>=N)
      throw std::out_of_range("out of range (pos>=N)");
    
    if(!val)
    {
      reset(pos);
    }
    else
    {
      //shift to that pos in that "packet"
      unsigned char ctrl = static_cast<unsigned char>(val<<(pos%CHAR_BIT));
      //get that "packet" and set it
      Bits[pos/CHAR_BIT] |= ctrl;   
    }   
  }
  
  template<size_t N>
  void bitset<N>::reset(const size_t& pos)
  {
    if(pos>=N)
      throw std::out_of_range("out of range (pos>=N)");

    unsigned char ctrl = static_cast<unsigned char>(1<<(pos%CHAR_BIT)); 
    Bits[pos/CHAR_BIT] &= static_cast<unsigned char>(~ctrl);
  }
  
  template<size_t N>
  void bitset<N>::flip(const size_t& pos)
  {
    if(pos>=N)
      throw std::out_of_range("out of range (pos>=N)");

    unsigned char ctrl = static_cast<unsigned char>(1<<(pos%CHAR_BIT));  
    Bits[pos/CHAR_BIT] ^= ctrl;
  } 

  template<size_t N>
  bool bitset<N>::test(const size_t& pos) const
  {
    if(pos>=N)
      throw std::out_of_range("out of range (pos>=N)");
    
    return static_cast<bool>(Bits[pos/CHAR_BIT]>>(pos%CHAR_BIT) & 1U);
  }   
  
  template<size_t N>
  std::string bitset<N>::to_string(const char& O,const char& I) const
  {
    std::string result;
    for(size_t i{}; i<N;i++)
    {
      if(test(N-1-i))
      {
        result.push_back(I);
      }
      else
        result.push_back(O);
    }
    return result;
  } 
  
  template<size_t N>
  bool bitset<N>::operator[](const size_t& pos) const
  {
    return test(pos); //since test alr has oob detection
  }
}