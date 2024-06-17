#pragma once
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class iter;

    template <typename T>
    class seq
    {
    public:
        // Getters
        virtual uint64_t size() = 0;

        // Operators
        virtual seq<T> &operator=(const seq<T> &) = 0;
        virtual cppl::iter<T> &get(uint64_t) = 0;
        virtual bool &operator==(const seq<T> &) = 0;
        virtual T &operator[](uint64_t) = 0;

        // Destructor
        ~seq() = default;
    private:
        uint64_t _size;
        uint64_t _mSize;
    };
}

#endif