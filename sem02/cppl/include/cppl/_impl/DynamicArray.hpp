#pragma once
#ifndef _IMPL_DYNAMIC_ARRAY_HPP
#define _IMPL_DYNAMIC_ARRAY_HPP

#include <cstdint>

#include <cppl/_decl/DynamicArray.hpp>

namespace cppl
{
    template <typename T>
    DynamicArray<T>::DynamicArray(T *items, uint64_t count) : DynamicArray(count)
    {
        for (uint64_t i = 0; i < count; i++)
        {
            this->items[i] = items[i];
        }
    }
    template <typename T>
    DynamicArray<T>::DynamicArray()
    {
        this->items = nullptr;
        this->size = 0;
        this->msize = 0;
    }
    template <typename T>
    DynamicArray<T>::DynamicArray(uint64_t size)
    {
        try
        {
            this->items = new T[size];
        }
        catch (const std::exception &e)
        {
            throw e;
            return;
        }
        this->size = size;
        this->msize = size;
    }
    template <typename T>
    DynamicArray<T>::DynamicArray(uint64_t size, const T &nullValue) : DynamicArray(size)
    {
        for (uint64_t i = 0; i < size; i++)
        {
            this->items[i] = nullValue;
        }
    }
    template <typename T>
    DynamicArray<T>::DynamicArray(const DynamicArray<T> &arr) : DynamicArray(arr.size)
    {
        for (uint64_t i = 0; i < arr.size; i++)
        {
            this->items[i] = arr[i];
        }
        this->msize = arr.msize;
    }
    template <typename T>
    T &DynamicArray<T>::operator[](uint64_t index) const
    {
        if (this->size <= index)
            throw std::out_of_range("DynamicArray<T>::operator[]");
        return this->items[index];
    }
    template <typename T>
    uint64_t DynamicArray<T>::getSize() const
    {
        return this->size;
    }
    template <typename T>
    void DynamicArray<T>::set(uint64_t index, const T &value)
    {
        if (this->size < index)
            throw std::out_of_range("DynamicArray<T>::set");
        this->items[index] = value;
    }
    template <typename T>
    void DynamicArray<T>::resize(uint64_t newSize)
    {
        if (newSize <= this->msize / 2 || newSize > this->msize)
        {
            T *buff = this->items;
            uint64_t i;
            if (newSize > this->msize / 4 && newSize <= this->msize / 2)
            {
                try
                {
                    buff = new T[msize / 2];
                }
                catch (const std::exception &e)
                {
                    throw e;
                    return;
                }
                this->msize /= 2;
            }
            else if (newSize > this->msize && newSize <= this->msize * 2)
            {
                try
                {
                    buff = new T[msize * 2];
                }
                catch (const std::exception &e)
                {
                    throw e;
                    return;
                }
                this->msize *= 2;
            }
            else if (newSize <= this->msize / 4 || newSize > this->msize * 2)
            {
                try
                {
                    buff = new T[newSize];
                }
                catch (const std::exception &e)
                {
                    throw e;
                    return;
                }
                this->msize = newSize;
            }
            for (i = 0; i < newSize; i++)
            {
                buff[i] = this->items[i];
            }
            delete[] this->items;
            this->items = buff;
        }
        this->size = newSize;
    }
    template <typename T>
    bool DynamicArray<T>::isEqual(T *items, uint64_t count) const
    {
        if (this->size < count)
            return false;
        for (uint64_t i = 0; i < count; i++)
            if (this->items[i] != items[i])
                return false;
        return true;
    }
    template <typename T>
    bool DynamicArray<T>::operator==(const DynamicArray<T> &arr) const
    {
        if (this->size != arr.size)
            return false;
        for (uint64_t i = 0; i < arr.size; i++)
            if (this->items[i] != arr[i])
                return false;
        return true;
    }
    template <typename T>
    DynamicArray<T>::~DynamicArray()
    {
        delete[] this->items;
    }
}

#endif