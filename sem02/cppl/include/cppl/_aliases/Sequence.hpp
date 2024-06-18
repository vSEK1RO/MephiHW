#pragma once
#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class Sequence
    {
    public:
        // doesn't have default constructor, because abstract

        virtual T &getFirst() = 0;
        virtual T &getLast() = 0;
        virtual T &get(uint64_t) = 0;
        virtual Sequence<T> &getSubsequence(uint64_t, uint64_t) = 0;
        virtual uint64_t getLenght() = 0;

        virtual void append(const T &) = 0;
        virtual void prepend(const T &) = 0;
        virtual void insertAt(const T &, uint64_t) = 0;
        virtual Sequence<T> &concat(const Sequence<T> &) = 0;

        // have pure virtual destructor with body
        virtual ~Sequence() = default;

    private:
        uint64_t lenght;
    };
}

#endif