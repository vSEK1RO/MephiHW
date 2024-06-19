#pragma once
#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class DynamicArray
    {
    public:
        DynamicArray(T *items, uint64_t count);
        DynamicArray();
        DynamicArray(uint64_t size);
        DynamicArray(uint64_t size, const T &nullValue);
        DynamicArray(const DynamicArray<T> &arr);

        T &operator[](uint64_t index) const;
        uint64_t getSize();

        void set(uint64_t index, const T &value);
        void resize(uint64_t newSize);

        // Methods
        bool isEqual(T *items, uint64_t count) const;

        // Operators
        bool operator==(const DynamicArray<T> &arr) const;

        ~DynamicArray();

    private:
        uint64_t size;
        uint64_t msize;
        T *items;
    };
}

#endif