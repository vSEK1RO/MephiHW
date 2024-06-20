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
        LinkedList(uint64_t size);
        LinkedList(uint64_t size, const T &nullValue);
        LinkedList(const LinkedList<T> &list);

        T &operator[](uint64_t index) const;
        uint64_t getSize() const;

        void set(uint64_t index, const T &value);
        void resize(uint64_t newSize);
        void resizeRevert(uint64_t newSize);

        // Methods
        bool isEqual(T *items, uint64_t count) const;

        // Operators
        bool operator==(const LinkedList<T> &list) const;
        void operator=(const LinkedList<T> &list);

        ~LinkedList();

    private:
        uint64_t size;
        class LinkedListItem
        {
        public:
            T item;
            LinkedListItem *next;
            LinkedListItem *prev;
        };
        LinkedListItem *begin;
        LinkedListItem *end;
    };
}

#endif