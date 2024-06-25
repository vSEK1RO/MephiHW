#pragma once
#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class LinkedListItem
    {
    public:
        T item;
        LinkedListItem *next;
        LinkedListItem *prev;
    };

    template <typename T>
    class LinkedList
    {
    public:
        LinkedList(const T *items, uint64_t count);
        LinkedList();
        LinkedList(const LinkedList<T> &list);

        // Const methods
        uint64_t getSize() const;
        bool isEqual(const T *items, uint64_t count) const;
        uint64_t find(const T &item, uint64_t entry) const;
        uint64_t count(const T &item) const;

        // Non const methods
        void erase(uint64_t beginIndex, uint64_t endIndex);
        void insertAt(const T &item, uint64_t index);
        void rearr(uint64_t i1, uint64_t i2);

        // Operators
        T &operator[](uint64_t index) const;
        bool operator==(const LinkedList<T> &list) const;
        void operator=(const LinkedList<T> &list);

        // Deprecated
        LinkedList(uint64_t size);
        LinkedList(uint64_t size, const T &nullValue);
        void resize(uint64_t newSize);
        void resizeRevert(uint64_t newSize);
        void set(uint64_t index, const T &value);

        ~LinkedList();

    private:
        uint64_t size;
        
        LinkedListItem<T> *begin;
        LinkedListItem<T> *end;

        LinkedListItem<T> &getItem(uint64_t index) const;
        void shiftPtr(LinkedListItem<T> *&ptr, uint64_t count) const;
        void shiftPtrRevert(LinkedListItem<T> *&ptr, uint64_t count) const;
        void shiftPtrErase(LinkedListItem<T> *&ptr, uint64_t count);
        void shiftPtrRevertErase(LinkedListItem<T> *&ptr, uint64_t count);
    };
}

#endif