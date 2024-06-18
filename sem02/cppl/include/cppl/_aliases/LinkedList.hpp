#pragma once
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class LinkedList
    {
    public:
        LinkedList(T *items, uint64_t count);
        LinkedList();
        LinkedList(uint64_t size, T &nullValue);
        LinkedList(const DynamicArray<T> &arr);

        T &get(uint64_t index);
        uint64_t getSize();

        void set(uint64_t index, T &value);
        void resize(uint64_t newSize);

        ~LinkedList();

    private:
        uint64_t size;
    };
}

#include <cppl/_impl/LinkedList.hpp>

#endif