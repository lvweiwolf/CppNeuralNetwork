#ifndef _MEMORY_H
#define _MEMORY_H

#include <limits>
#include <iostream>
#include <stdlib.h>

namespace lvweiML
{
    class Memory
    {
    public:
        // 申请内存
        template <typename T>
        static T *acquire(const size_t n_elem);

        template <typename T>
        static void release(T *mem);
    };
    
    template<typename T>
    T* Memory::acquire(const size_t n_elem)
    {
        if (n_elem > (std::numeric_limits<size_t>::max() / sizeof(T)))
            std::cerr << "memory::acquire(): requested size is too large" << std::endl;

        T* out_memptr = (T*)malloc(sizeof(T)*n_elem);
        return out_memptr;        
    }

    template<typename T>
    void Memory::release(T* mem)
    {
        if (mem == nullptr)
            return;
            
        free((void *)(mem));
    }

} // namespace lvweiML

#endif // _MEMORY_H