#pragma once
#ifndef ITER_HPP
#define ITER_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class seq;

    template <typename T>
    class iter
    {
        friend class seq<T>;

    public:
        // Constructors
        iter(const  cppl::seq<T> &, uint64_t);
        iter(const iter<T> &);
        iter<T> &operator=(const iter<T> &);

        // Getters
        uint64_t index();
        cppl::seq<T> &seq();

        // Operators
        bool operator==(const iter<T> &);
        iter<T> &operator++();
        iter<T> &operator--();
        iter<T> &operator++(int);
        iter<T> &operator--(int);
        iter<T> &operator+=(uint64_t);
        iter<T> &operator-=(uint64_t);
        T &operator*();
        T &operator[](uint64_t);

        // Destructor
        ~iter();

    private:
        cppl::seq<T> _seq;
        uint64_t _index;
    };
}

#endif