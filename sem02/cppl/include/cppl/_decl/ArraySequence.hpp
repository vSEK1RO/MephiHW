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
        ArraySequence(const T *items, uint64_t count);
        ArraySequence();
        ArraySequence(uint64_t lenght);
        ArraySequence(uint64_t length, const T &nullValue);
        ArraySequence(const ArraySequence<T> &arr);

        // Const methods
        T &getFirst() const override;
        T &getLast() const override;
        ArraySequence<T> *getSubseq(uint64_t startIndex, uint64_t endIndex) const override;
        uint64_t getLenght() const override;
        ArraySequence<T> *map(T (*func)(const T &, uint64_t)) const override;
        ArraySequence<T> *where(bool (*func)(const T &, uint64_t)) const override;
        T reduce(T (*func)(const T &, const T &), const T &c) const override;
        bool isEqual(T *items, uint64_t count) const override;
        ArraySequence<T> *copy() const override;

        // Non const methods
        void append(const T &item) override;
        void prepend(const T &item) override;
        void insertAt(const T &item, uint64_t index) override;
        void resize(uint64_t newSize) override;
        
        // Operators
        bool operator==(const Sequence<T> &arr) const override;
        ArraySequence<T> *operator+(const Sequence<T> &seq) const override;
        T &operator[](uint64_t index) const override;

        ~ArraySequence();

    private:
        DynamicArray<T> *items;
    };
}

#endif