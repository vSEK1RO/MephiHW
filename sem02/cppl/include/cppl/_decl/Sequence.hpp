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

        virtual T &getFirst() const = 0;
        virtual T &getLast() const = 0;
        virtual T &operator[](uint64_t) const = 0;
        virtual Sequence<T> &getSubseq(uint64_t, uint64_t) const = 0;
        virtual uint64_t getLenght() const = 0;

        virtual void append(const T &) = 0;
        virtual void prepend(const T &) = 0;
        virtual void insertAt(const T &, uint64_t) = 0;
        virtual Sequence<T> &operator+(const Sequence<T> &) const = 0;

        // Methods
        virtual bool isEqual(T *, uint64_t) const = 0;

        // Operators
        virtual bool operator==(const Sequence<T> &) const = 0;

        // have pure virtual destructor with body
        virtual ~Sequence() = default;

    private:
    };
}

#endif