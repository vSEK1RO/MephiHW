#pragma once
#ifndef _IMPL_LIST_SEQUENCE
#define _IMPL_LIST_SEQUENCE

#include <cstdint>

#include <cppl/_decl/LinkedList.hpp>

namespace cppl
{
    template <typename T>
    ListSequence<T>::ListSequence(T *items, uint64_t count)
    {
        this->items = new LinkedList<T>(items, count);
    }
    template <typename T>
    ListSequence<T>::ListSequence()
    {
        this->items = new LinkedList<T>();
    }
    template <typename T>
    ListSequence<T>::ListSequence(uint64_t lenght)
    {
        this->items = new LinkedList<T>(lenght);
    }
    template <typename T>
    ListSequence<T>::ListSequence(uint64_t length, const T &nullValue)
    {
        this->items = new LinkedList<T>(length, nullValue);
    }
    template <typename T>
    ListSequence<T>::ListSequence(const ListSequence<T> &list)
    {
        this->items = new LinkedList<T>(*list.items);
    }
    template <typename T>
    T &ListSequence<T>::getFirst() const
    {
        return (*this->items)[0];
    }
    template <typename T>
    T &ListSequence<T>::getLast() const
    {
        return (*this->items)[this->items->getSize() - 1];
    }
    template <typename T>
    T &ListSequence<T>::operator[](uint64_t index) const
    {
        return (*this->items)[index];
    }
    template <typename T>
    ListSequence<T> &ListSequence<T>::getSubseq(uint64_t startIndex, uint64_t endIndex) const
    {
        if ((*this->items).getSize() < endIndex || startIndex > endIndex)
            throw std::out_of_range("ArraySequence<T>::getSubseq");
        ListSequence<T> *list = new ListSequence<T>(endIndex - startIndex);
        for (uint64_t i = 0; i < list->getLenght(); i++)
        {
            (*list)[i] = (*this->items)[i + startIndex];
        }
        return *list;
    }
    template <typename T>
    uint64_t ListSequence<T>::getLenght() const
    {
        return this->items->getSize();
    }
    template <typename T>
    void ListSequence<T>::append(const T &item)
    {
        this->items->resize(this->items->getSize() + 1);
        this->getLast() = item;
    }
    template <typename T>
    void ListSequence<T>::prepend(const T &item)
    {
        this->items->resizeRevert(this->items->getSize() + 1);
        this->getFirst() = item;
    }
    template <typename T>
    void ListSequence<T>::insertAt(const T &item, uint64_t index)
    {
        if (this->items->getSize() < index)
            throw std::out_of_range("ArraySequence<T>::insertAt");
        this->items->resize(this->items->getSize() + 1);
        for (uint64_t i = index; i < this->items->getSize() - 1; i++)
        {
            (*this->items)[i + 1] = (*this->items)[i];
        }
        (*this->items)[index] = item;
    }
    template <typename T>
    ListSequence<T> &ListSequence<T>::operator+(const Sequence<T> &seq) const
    {
        ListSequence<T> *list = new ListSequence<T>(this->items->getSize() + seq.getLenght());
        for (uint64_t i = 0; i < this->items->getSize(); i++)
        {
            (*list)[i] = (*this->items)[i];
        }
        for (uint64_t i = this->items->getSize(); i < list->getLenght(); i++)
        {
            (*list)[i] = seq[i - this->items->getSize()];
        }
        return *list;
    }
    template <typename T>
    bool ListSequence<T>::isEqual(T *items, uint64_t count) const
    {
        if (this->items->getSize() < count)
            return false;
        for (uint64_t i = 0; i < count; i++)
            if ((*this->items)[i] != items[i])
                return false;
        return true;
    }
    template <typename T>
    bool ListSequence<T>::operator==(const Sequence<T> &list) const
    {
        if (this->items->getSize() != list.getLenght())
            return false;
        for (uint64_t i = 0; i < list.getLenght(); i++)
            if ((*this->items)[i] != list[i])
                return false;
        return true;
    }
    template <typename T>
    ListSequence<T>::~ListSequence()
    {
        delete this->items;
    }
}

#endif