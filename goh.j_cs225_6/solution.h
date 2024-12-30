/*****************************************************************************/
/*!
\file solution.h
\author Josiah Goh
\par email: goh.j\@digipen.edu
\par DigiPen login: goh.j
\par Course: CS225
\par Assignment #6
\date 03/08/2020
\brief
This file contains the definition of a structure vector and a union vertex,
which could be used in a hypothetical 3D graphics engine.

Hours spent on this assignment: 7
Specific portions that gave you the most trouble: bitwise operations 
implementation of memory pooling, restriction on use of std::bitset.
*/
/*****************************************************************************/
#include <forward_list>

/*****************************************************************************/
/*!
  \brief
    Overload of operator new in global scope
    
  \param size
    The amount of memory to allocate
    
  \return pointer to the allocated memory
*/
/*****************************************************************************/
void* operator new(size_t size)
{
  std::cout << "  Global allocate " << size << " bytes." << std::endl;
  void* result = malloc(size);
  if (!result)
  {
    throw std::bad_alloc();
  }
  return result;
}

/*****************************************************************************/
/*!
  \brief
    Overload of operator delete in global scope
    
  \param pointer
    The pointer to be freed
*/
/*****************************************************************************/
void operator delete(void* pointer)
{
  std::cout << "  Global deallocate." << std::endl;
  if (pointer != nullptr)
  {
    free(pointer);
  }
}

/*****************************************************************************/
/*!
  \brief
    Overload of operator delete in global scope
    
  \param pointer
    The pointer to be freed
    
  \param not used
*/
/*****************************************************************************/
void operator delete(void* pointer, size_t)
{
  ::operator delete(pointer);
}

namespace my
{
  template <typename TDataType, typename TFlags>
  class allocator
  { 
    static const size_t NumBits = sizeof(TFlags) * 8;
    TFlags sizeFlag;   // bitmask for size to be allocated
    
    struct Pool
    {
      TDataType mem_block[NumBits];
      TFlags flag{};
    };
    // forward list holding the pools of memory blocks
    std::forward_list<Pool> mem_pools;
    
/*****************************************************************************/
/*!
  \brief
    Convert size needed to flag
    
  \param size
    The size to be converted to flag
*/
/*****************************************************************************/
    void SizeToFlag(size_t size)
    {
      // set the bits through assignment, so it resets the prev aswell
      sizeFlag = static_cast<TFlags>((1U<<size)-1U);
    }
    
  public:
    using pointer = TDataType*;
    
/*****************************************************************************/
/*!
  \brief
    Allocate memory with the size given
    
  \param size
    The amount of memory to be allocated
    
  \return pointer to the allocated memory
*/
/*****************************************************************************/
    pointer allocate(size_t size)
    {
      std::cout << "\n  Allocator allocate " 
                << size 
                << " elements. " << std::endl;
                
      if (size > NumBits)
        throw std::bad_alloc();
      
      // Convert the size to flag
      SizeToFlag(size);
      
      if (!mem_pools.empty())
      {
        for(Pool &p : mem_pools)
        {
          for(size_t i{}; i < (NumBits - size); ++i)
          {
            if((sizeFlag & p.flag) != 0)
              sizeFlag =  static_cast<TFlags>(sizeFlag << 1);
            else
            {
              std::cout << "  Found space in a pool for " << size 
                << " elements at index " << i << "."
                << std::endl;
              p.flag |= sizeFlag;
              return p.mem_block + i;
            }
          }
          std::cout << "  Did not find space in a pool." << std::endl;
          std::cout << "  Checking next available pool..." << std::endl;
          // Reset sizeFlag for next loop
          SizeToFlag(size);
        }
      }
      // no pools with count of continuous bits found or list is empty
      std::cout << "  Allocating a new pool." << std::endl;
      mem_pools.emplace_front();
      // Set flag of memory pool
      mem_pools.front().flag |= sizeFlag;
      std::cout << "  Found space in a pool for " << size 
                << " elements at index 0." << std::endl;
      return mem_pools.front().mem_block;
    }
    
/*****************************************************************************/
/*!
  \brief
    Deallocates the memory of the given pointer
    
  \param ptr
    The pointer to be deallocated
    
  \param size
    The amount of memory to be deallocated
*/
/*****************************************************************************/
    void deallocate(pointer ptr, size_t size)
    {
      std::cout << "  Allocator deallocate " << size << " elements. "
        << std::endl;
      
      if(!mem_pools.empty())
      {
        for(Pool& p : mem_pools)
        {
          // if pointer is within this memory block
          if(ptr >= p.mem_block && ptr <= (p.mem_block + NumBits))
          {
            std::cout << "  Found " << size << " elements in a pool."
              << std::endl;
            for(size_t i{}; i < size; ++i)
            {
              // reset bits for deallocated elements
              p.flag &= 
                static_cast<TFlags>(~(1U<< ((ptr - (p.mem_block)) + i)));
            }
            mem_pools.remove_if(
              [](Pool &p)
              {
                if (p.flag == 0)
                {
                  std::cout <<  "  Removing an empty pool." << std::endl;
                  return true;
                }
                return false;
              }
            );
            break;
          }
          std::cout << "  Checking next existing pool..." << std::endl;
        }
      }
    }
  };
  
  struct vector
  {
    float x;
    float y;
    float z;
    float w;
    
    vector() :
      x{0},
      y{0},
      z{0},
      w{0}
    {
    }
    
    vector(float ax, float ay, float az, float aw) :
      x{ax},
      y{ay},
      z{az},
      w{aw}
    {
    }

/*****************************************************************************/
/*!
  \brief
    Overloading of new operator in local scope
    
  \param size
    The amount of memory to be allocated.
    
  \return pointer to allocated memory.
*/
/*****************************************************************************/
    void* operator new(size_t size)
    {
      std::cout << "  In-class allocate " << size << " bytes." << std::endl;
      return ::operator new(size);
    }

/*****************************************************************************/
/*!
  \brief
    Overloading of delete operator in local scope
    
  \param ptr
    The pointer to be freed
*/
/*****************************************************************************/
    void operator delete(void* pointer)
    {
      std::cout << "  In-class deallocate." << std::endl;
      ::operator delete(pointer);
    }
  };

  union vertex
  {
    vector vertexCoordinates;
    float axisCoordinates[sizeof(vector) / sizeof(float)];

    vertex() :
      vertexCoordinates{}
    {
    }
    
    vertex(float ax, float ay, float az, float aw) :
      vertexCoordinates{ax, ay, az, aw}
    {
    }
  };
}