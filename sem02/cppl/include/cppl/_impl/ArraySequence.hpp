#pragma once
#ifndef _IMPL_ARRAY_SEQUENCE_HPP
#define _IMPL_ARRAY_SEQUENCE_HPP

#include <cstdint>

#include <cppl/_decl/ArraySequence.hpp>

namespace cppl
{
    template <typename T>
    ArraySequence<T>::ArraySequence(T *items, uint64_t count)
    {
        this->items = new DynamicArray<T>(items, count);
    }
    template <typename T>
    ArraySequence<T>::ArraySequence()
    {
        this->items = new DynamicArray<T>();
    }
    template <typename T>
    ArraySequence<T>::ArraySequence(uint64_t lenght)
    {
        this->items = new DynamicArray<T>(lenght);
    }
    template <typename T>
    ArraySequence<T>::ArraySequence(uint64_t length, const T &nullValue)
    {
        this->items = new DynamicArray<T>(length, nullValue);
    }
    template <typename T>
    ArraySequence<T>::ArraySequence(const ArraySequence<T> &arr)
    {
        this->items = new DynamicArray<T>(*arr.items);
    }
    template <typename T>
    T &ArraySequence<T>::getFirst() const
    {
        if ((*this->items).getSize() == 0)
            throw std::out_of_range("ArraySequence<T>::getFirst");
        return (*this->items)[0];
    }
    template <typename T>
    T &ArraySequence<T>::getLast() const
    {
        if ((*this->items).getSize() == 0)
            throw std::out_of_range("ArraySequence<T>::getLast");
        return (*this->items)[(*this->items).getSize() - 1];
    }
    template <typename T>
    T &ArraySequence<T>::operator[](uint64_t index) const
    {
        return (*this->items)[index];
    }
    template <typename T>
    ArraySequence<T> &ArraySequence<T>::getSubseq(uint64_t startIndex, uint64_t endIndex) const
    {
        if ((*this->items).getSize() < endIndex || startIndex > endIndex)
            throw std::out_of_range("ArraySequence<T>::getSubseq");
        ArraySequence<T> *arr = new ArraySequence<T>(endIndex - startIndex);
        for (uint64_t i = 0; i < arr->getLenght(); i++)
        {
            (*arr)[i] = (*this->items)[i + startIndex];
        }
        return *arr;
    }
    template <typename T>
    uint64_t ArraySequence<T>::getLenght() const
    {
        return (*this->items).getSize();
    }
    template <typename T>
    void ArraySequence<T>::append(const T &item)
    {
        (*this->items).resize((*this->items).getSize() + 1);
        this->getLast() = item;
    }
    template <typename T>
    void ArraySequence<T>::prepend(const T &item)
    {
        (*this->items).resize((*this->items).getSize() + 1);
        for (uint64_t i = (*this->items).getSize() - 1; i > 0; i--)
        {
            (*this->items)[i] = (*this->items)[i - 1];
        }
        this->getFirst() = item;
    }
    template <typename T>
    void ArraySequence<T>::insertAt(const T &item, uint64_t index)
    {
        if ((*this->items).getSize() < index)
            throw std::out_of_range("ArraySequence<T>::insertAt");
        (*this->items).resize((*this->items).getSize() + 1);
        for (uint64_t i = index; i < (*this->items).getSize() - 1; i++)
        {
            (*this->items)[i + 1] = (*this->items)[i];
        }
        (*this->items)[index] = item;
    }
    template <typename T>
    ArraySequence<T> &ArraySequence<T>::operator+(const Sequence<T> &seq) const
    {
        ArraySequence<T> *arr = new ArraySequence<T>((*this->items).getSize() + seq.getLenght());
        for (uint64_t i = 0; i < (*this->items).getSize(); i++)
        {
            (*arr)[i] = (*this->items)[i];
        }
        for (uint64_t i = (*this->items).getSize(); i < arr->getLenght(); i++)
        {
            (*arr)[i] = seq[i - (*this->items).getSize()];
        }
        return *arr;
    }
    template <typename T>
    bool ArraySequence<T>::isEqual(T *items, uint64_t count) const
    {
        if ((*this->items).getSize() < count)
            return false;
        for (uint64_t i = 0; i < count; i++)
            if ((*this->items)[i] != items[i])
                return false;
        return true;
    }
    template <typename T>
    bool ArraySequence<T>::operator==(const Sequence<T> &arr) const
    {
        if ((*this->items).getSize() != arr.getLenght())
            return false;
        for (uint64_t i = 0; i < arr.getLenght(); i++)
            if ((*this->items)[i] != arr[i])
                return false;
        return true;
    }
    template <typename T>
    ArraySequence<T>::~ArraySequence()
    {
        delete this->items;
    }
}

#endif