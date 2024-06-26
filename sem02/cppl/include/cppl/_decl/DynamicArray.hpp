#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class DynamicArray
    {
    public:
        DynamicArray(const T *items, uint64_t count);
        DynamicArray();
        DynamicArray(uint64_t size);
        DynamicArray(uint64_t size, const T &nullValue);
        DynamicArray(const DynamicArray<T> &arr);

        // Const methods
        uint64_t getSize() const;
        bool isEqual(const T *items, uint64_t count) const;

        // Non const methods
        void resize(uint64_t newSize);
        
        // Operators
        T &operator[](uint64_t index) const;
        bool operator==(const DynamicArray<T> &arr) const;
        void operator=(const DynamicArray<T> &arr);
        
        // Deprecated
        void set(uint64_t index, const T &value);

        ~DynamicArray();

    private:
        uint64_t size;
        uint64_t msize;
        T *items;
    };
}

#endif