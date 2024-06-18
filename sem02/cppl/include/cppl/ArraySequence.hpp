#pragma once
#ifndef ARRAY_SEQUENCE_HPP
#define ARRAY_SEQUENCE_HPP

#include <cstdint>

#include <cppl/seq>
#include <cppl/DynamicArray.hpp>

namespace cppl
{
    template <typename T>
    class ArraySequence : public Sequence<T>
    {
    public:
        ArraySequence(T *items, uint64_t count);
        ArraySequence();
        ArraySequence(uint64_t length, T &nullValue);
        ArraySequence(const DynamicArray<T> &arr);

        T &getFirst() override;
        T &getLast() override;
        T &get(uint64_t index) override;
        ArraySequence<T> &getSubsequence(uint64_t startIndex, uint64_t endIndex) override;
        uint64_t getLenght() override;

        void append(const T &item) override;
        void prepend(const T &item) override;
        void insertAt(const T &item, uint64_t index) override;
        ArraySequence<T> &concat(const ArraySequence<T> &seq) override;

        ~ArraySequence();

    private:
        DynamicArray<T> &items;
    };
}

#endif