#pragma once
#ifndef LIST_SEQUENCE_HPP
#define LIST_SEQUENCE_HPP

#include <cstdint>

#include <cppl/seq>
#include <cppl/_decl/LinkedList.hpp>

namespace cppl
{
    template <typename T>
    class ListSequence : public Sequence<T>
    {
    public:
        ListSequence(T *items, uint64_t count);
        ListSequence();
        ListSequence(uint64_t lenght);
        ListSequence(uint64_t length, const T &nullValue);
        ListSequence(const ListSequence<T> &list);

        T &getFirst() const override;
        T &getLast() const override;
        T &operator[](uint64_t index) const override;
        ListSequence<T> &getSubseq(uint64_t startIndex, uint64_t endIndex) const override;
        uint64_t getLenght() const override;

        void append(const T &item) override;
        void prepend(const T &item) override;
        void insertAt(const T &item, uint64_t index) override;
        ListSequence<T> &operator+(const ListSequence<T> &seq) const override;

        // Methods
        bool isEqual(T *items, uint64_t count) const override;

        // Operators
        bool operator==(const ListSequence<T> &list) const override;

        ~ListSequence();

    private:
        LinkedList<T> *items;
    };
}

#endif