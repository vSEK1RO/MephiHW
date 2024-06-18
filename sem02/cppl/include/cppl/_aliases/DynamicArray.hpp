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
        DynamicArray(T *items, uint64_t count)
        DynamicArray();
        DynamicArray(uint64_t size, T &nullValue);
        DynamicArray(const DynamicArray<T> &arr);

        T &get(uint64_t index);
        uint64_t getSize();

        void set(uint64_t index, T &value);
        void resize(uint64_t newSize);

        ~DynamicArray();

    private:
        uint64_t size;
    };
}

#include <cppl/_impl/DynamicArray.hpp>

#endif