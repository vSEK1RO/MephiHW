#pragma once
#ifndef ARRAY_SEQUENCE_HPP
#define ARRAY_SEQUENCE_HPP

#include <cstdint>

#include <cppl/seq>
#include <cppl/_decl/DynamicArray.hpp>

namespace cppl
{
    template <typename T>
    class ArraySequence : public Sequence<T>
    {
    public:
        ArraySequence(T *items, uint64_t count);
        ArraySequence();
        ArraySequence(uint64_t lenght);
        ArraySequence(uint64_t length, const T &nullValue);
        ArraySequence(const ArraySequence<T> &arr);

        T &getFirst() const override;
        T &getLast() const override;
        T &operator[](uint64_t index) const override;
        ArraySequence<T> &getSubsequence(uint64_t startIndex, uint64_t endIndex) const override;
        uint64_t getLenght() const override;

        void append(const T &item) override;
        void prepend(const T &item) override;
        void insertAt(const T &item, uint64_t index) override;
        ArraySequence<T> &operator+(const ArraySequence<T> &seq) const override;

        // Methods
        bool isEqual(T *items, uint64_t count) const override;

        // Operators
        bool operator==(const ArraySequence<T> &arr) const override;

        ~ArraySequence();

    private:
        DynamicArray<T> *items;
    };
}

#endif