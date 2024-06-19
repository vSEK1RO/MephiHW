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
        ListSequence(uint64_t length, T &nullValue);
        ListSequence(const LinkedList<T> &list);

        T &getFirst() override;
        T &getLast() override;
        T &get(uint64_t index) override;
        ListSequence<T> &getSubsequence(uint64_t startIndex, uint64_t endIndex) override;
        uint64_t getLenght() override;

        void append(const T &item) override;
        void prepend(const T &item) override;
        void insertAt(const T &item, uint64_t index) override;
        ListSequence<T> &concat(const ListSequence<T> &seq) override;

        ~ListSequence();

    private:
        LinkedList<T> &items;
    };
}

#endif