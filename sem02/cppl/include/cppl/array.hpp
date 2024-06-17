#pragma once
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdint>

#include <cppl/seq>

namespace cppl
{
    template <typename T>
    class arr : public seq<T>
    {
    public:
        // Constructors
        arr(uint64_t);

        // Getters
        virtual uint64_t size() override;

        // Operators
        arr<T> &operator=(const arr<T> &) override;
        cppl::iter<T> &get(uint64_t) override;
        bool &operator==(const arr<T> &) override;
        T &operator[](uint64_t) override;

        // Destructor
        ~arr();

    private:
        T *data;
    };
}

#endif