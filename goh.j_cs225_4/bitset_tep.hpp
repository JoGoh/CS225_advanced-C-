/*****************************************************************************/
/*!
\file bitset_tep.hpp
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #4
\date 25/07/2020
\brief
This file contains implementation of tep for bitset to encapsulate interface.
Hours spent on this assignment: 6 hours
Specific portions that gave you the most trouble: syntax of std::unique_ptr
*/
/*****************************************************************************/
#include "bitset_tep.h"
namespace cs225
{
  bitset_tep::bitset_tep(std::unique_ptr<Concept> concept):
    bit_storage{std::move(concept)}
  {
  }   
  
  template<typename T, typename... Args>
  bitset_tep bitset_tep::create(Args... args)
  {
    return {
      std::make_unique<Model<T>>(std::forward<Args&&>(args)...)};
  }
  
  size_t bitset_tep::size() const
  {
    return bit_storage->size();
  } 
  
  size_t bitset_tep::count() const
  {
    return bit_storage->count();
  }
  
  void bitset_tep::set(const size_t& pos, bool val)
  {
    bit_storage->set(pos,val);
  }
  
  void bitset_tep::reset(const size_t& pos)
  {
    bit_storage->reset(pos);
  } 

  void bitset_tep::toggle(const size_t& pos)
  {
    bit_storage->flip(pos);
  }   
  
  bool bitset_tep::test(const size_t& pos) const
  {
    return bit_storage->test(pos);
  }
  
  std::string bitset_tep::to_string(const char& O,const char& I)const
  {
    return bit_storage->to_string(O,I);
  }
  
  bool bitset_tep::operator[](const size_t& pos)const
  {
    return bit_storage->operator[](pos); //cant use deref
  } 
  
  template<typename T>
  template<typename... Args> //no assumptions, for hidden test
  bitset_tep::Model<T>::Model(Args... args) :
    _instance(std::forward<Args&&>(args)...) 
  {
  }
  
  template<typename T>
  size_t bitset_tep::Model<T>::size() const
  {
    return _instance.size();
  }
  
  template<typename T>
  size_t bitset_tep::Model<T>::count() const
  {
    return _instance.count();
  }
  
  template<typename T>  
  void bitset_tep::Model<T>::set(const size_t& pos, bool val)
  {
    _instance.set(pos,val);
  }
  
  template<typename T>  
  void bitset_tep::Model<T>::reset(const size_t& pos)
  {
    _instance.reset(pos);
  } 
  
  template<typename T>
  void bitset_tep::Model<T>::flip(const size_t& pos)
  {
    _instance.flip(pos);
  }   
  
  template<typename T>  
  bool bitset_tep::Model<T>::test(const size_t& pos) const
  {
    return _instance.test(pos);
  } 
  
  template<typename T>  
  std::string bitset_tep::Model<T>::to_string(const char& O,const char& I)const
  {
    return _instance.to_string(O,I);
  }
  
  template<typename T>  
  bool bitset_tep::Model<T>::operator[](const size_t& pos)const
  {
    return _instance[pos];
  } 
}