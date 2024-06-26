#ifndef _IMPL_LIST_SEQUENCE
#define _IMPL_LIST_SEQUENCE

#include <cstdint>

#include <cppl/_decl/LinkedList.hpp>

namespace cppl
{
    template <typename T>
    ListSequence<T>::ListSequence(const T *items, uint64_t count)
    {
        this->items = new LinkedList<T>(items, count);
    }
    template <typename T>
    ListSequence<T>::ListSequence()
    {
        items = new LinkedList<T>();
    }
    template <typename T>
    ListSequence<T>::ListSequence(uint64_t lenght)
    {
        items = new LinkedList<T>(lenght);
    }
    template <typename T>
    ListSequence<T>::ListSequence(uint64_t length, const T &nullValue)
    {
        items = new LinkedList<T>(length, nullValue);
    }
    template <typename T>
    ListSequence<T>::ListSequence(const ListSequence<T> &list)
    {
        items = new LinkedList<T>(*list.items);
    }
    template <typename T>
    T &ListSequence<T>::getFirst() const
    {
        return (*items)[0];
    }
    template <typename T>
    T &ListSequence<T>::getLast() const
    {
        return (*items)[items->getSize() - 1];
    }
    template <typename T>
    T &ListSequence<T>::operator[](uint64_t index) const
    {
        return (*items)[index];
    }
    template <typename T>
    ListSequence<T> *ListSequence<T>::getSubseq(uint64_t beginIndex, uint64_t endIndex) const
    {
        if ((*items).getSize() < endIndex || beginIndex > endIndex)
            throw std::out_of_range("ListSequence<T>::getSubseq");
        ListSequence<T> *resSeq = new ListSequence<T>();
        for (uint64_t i = 0; i < endIndex - beginIndex; i++)
        {
            resSeq->append((*items)[i + beginIndex]);
        }
        return resSeq;
    }
    template <typename T>
    uint64_t ListSequence<T>::getLenght() const
    {
        return items->getSize();
    }
    template <typename T>
    void ListSequence<T>::append(const T &item)
    {
        items->insertAt(item, getLenght());
    }
    template <typename T>
    void ListSequence<T>::prepend(const T &item)
    {
        items->insertAt(item, 0);
    }
    template <typename T>
    void ListSequence<T>::insertAt(const T &item, uint64_t index)
    {
        items->insertAt(item, index);
    }
    template <typename T>
    ListSequence<T> *ListSequence<T>::operator+(const Sequence<T> &seq) const
    {
        ListSequence<T> *resSeq = new ListSequence<T>();
        for (uint64_t i = 0; i < items->getSize(); i++)
        {
            resSeq->append((*items)[i]);
        }
        for (uint64_t i = 0; i < seq.getLenght(); i++)
        {
            resSeq->append(seq[i]);
        }
        return resSeq;
    }
    template <typename T>
    bool ListSequence<T>::isEqual(T *items, uint64_t count) const
    {
        return this->items->isEqual(items, count);
    }
    template <typename T>
    ListSequence<T> *ListSequence<T>::copy() const
    {
        return new ListSequence<T>(*this);
    }
    template <typename T>
    void ListSequence<T>::resize(uint64_t newSize)
    {
        items->resize(newSize);
    }
    template <typename T>
    void ListSequence<T>::erase(uint64_t beginIndex, uint64_t endIndex)
    {
        this->items->erase(beginIndex, endIndex);
    }
    template <typename T>
    ListSequence<T> *ListSequence<T>::map(T (*func)(const T &, uint64_t)) const
    {
        ListSequence<T> *resSeq = new ListSequence<T>();
        for (uint64_t i = 0; i < getLenght(); i++)
        {
            resSeq->append(func((*this)[i], i));
        }
        return resSeq;
    }
    template <typename T>
    ListSequence<T> *ListSequence<T>::where(bool (*func)(const T &, uint64_t)) const
    {
        ListSequence<T> *resSeq = new ListSequence<T>();
        for (uint64_t i = 0; i < getLenght(); i++)
        {
            if (func((*this)[i], i))
            {
                resSeq->append((*this)[i]);
            }
        }
        return resSeq;
    }
    template <typename T>
    T ListSequence<T>::reduce(T (*func)(const T &, const T &), const T &c) const
    {
        T res = func((*this)[0], c);
        for (uint64_t i = 1; i < getLenght(); i++)
        {
            res = func((*this)[i], res);
        }
        return res;
    }
    template <typename T>
    ListSequence<T> *ListSequence<T>::operator=(const Sequence<T> &seq)
    {
        delete items;
        items = new LinkedList<T>(0);
        for (uint64_t i = 0; i < seq.getLenght(); i++)
        {
            items->insertAt(seq[i], items->getSize());
        }
        return this;
    }
    template <typename T>
    bool ListSequence<T>::operator==(const Sequence<T> &seq) const
    {
        if (this->items->getSize() != seq.getLenght())
            return false;
        for (uint64_t i = 0; i < seq.getLenght(); i++)
            if ((*this->items)[i] != seq[i])
                return false;
        return true;
    }
    template <typename T>
    ListSequence<T>::~ListSequence()
    {
        delete items;
    }
}

#endif