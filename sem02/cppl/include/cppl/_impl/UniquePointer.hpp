#pragma once
#ifndef _IMPL_UNIQUE_POINTER_HPP
#define _IMPL_UNIQUE_POINTER_HPP

#include <cppl/_decl/UniquePointer.hpp>

namespace cppl
{
    template <typename T>
    UniquePointer<T>::UniquePointer(T *data)
    {
        this->data = data;
    }
    template <typename T>
    T &UniquePointer<T>::getData() const
    {
        if (this->data == nullptr)
            throw std::out_of_range("UniquePointer<T>::getData");
        return *this->data;
    }
    template <typename T>
    UniquePointer<T>::~UniquePointer()
    {
        delete this->data;
    }
}

#endif