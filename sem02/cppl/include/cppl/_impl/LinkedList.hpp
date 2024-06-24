#pragma once
#ifndef _IMPL_LINKED_LIST_HPP
#define _IMPL_LINKED_LIST_HPP

#include <cstdint>

#include <cppl/_decl/LinkedList.hpp>

namespace cppl
{
    template <typename T>
    LinkedList<T>::LinkedList(const T *items, uint64_t count) : LinkedList(count)
    {
        LinkedListItem *curr = this->begin;
        uint64_t i = 0;
        while (curr != nullptr)
        {
            curr->item = items[i];
            i++;
            curr = curr->next;
        }
    }
    template <typename T>
    LinkedList<T>::LinkedList()
    {
        this->size = 0;
        this->begin = nullptr;
        this->end = nullptr;
    }
    template <typename T>
    LinkedList<T>::LinkedList(uint64_t size)
    {
        this->begin = nullptr;
        this->end = nullptr;
        LinkedListItem *curr;
        for (uint64_t i = 0; i < size; i++)
        {
            try
            {
                curr = new LinkedListItem;
            }
            catch (const std::exception &e)
            {
                throw e;
                return;
            }
            if (this->begin == nullptr)
            {
                curr->prev = nullptr;
                curr->next = nullptr;
                this->begin = curr;
                this->end = curr;
            }
            else
            {
                curr->prev = end;
                curr->next = nullptr;
                this->end->next = curr;
                this->end = curr;
            }
        }
        this->size = size;
    }
    template <typename T>
    LinkedList<T>::LinkedList(uint64_t size, const T &nullValue) : LinkedList(size)
    {
        LinkedListItem *curr = this->begin;
        while (curr != nullptr)
        {
            curr->item = nullValue;
            curr = curr->next;
        }
    }
    template <typename T>
    LinkedList<T>::LinkedList(const LinkedList<T> &list) : LinkedList(list.getSize())
    {
        LinkedListItem *curr = this->begin;
        uint64_t i = 0;
        while (curr != nullptr)
        {
            curr->item = list[i];
            i++;
            curr = curr->next;
        }
    }
    template <typename T>
    T &LinkedList<T>::operator[](uint64_t index) const
    {
        if (index >= this->size)
            throw std::out_of_range("LinkedList<T>::operator[]");
        LinkedListItem *curr = this->begin;
        uint64_t i = 0;
        while (i != index)
        {
            curr = curr->next;
            i++;
        }
        return curr->item;
    }
    template <typename T>
    uint64_t LinkedList<T>::getSize() const
    {
        return this->size;
    }
    template <typename T>
    void LinkedList<T>::set(uint64_t index, const T &value)
    {
        if (this->size < index)
            throw std::out_of_range("LinkedList<T>::set");
        (*this)[index] = value;
    }
    template <typename T>
    void LinkedList<T>::resize(uint64_t newSize)
    {
        LinkedListItem *curr;
        if (newSize > this->size)
        {
            while (this->size < newSize)
            {
                try
                {
                    curr = new LinkedListItem;
                }
                catch (const std::exception &e)
                {
                    throw e;
                    return;
                }
                if (this->begin == nullptr)
                {
                    curr->prev = nullptr;
                    curr->next = nullptr;
                    this->begin = curr;
                    this->end = curr;
                }
                else
                {
                    curr->next = nullptr;
                    curr->prev = this->end;
                    this->end->next = curr;
                    this->end = curr;
                }
                this->size += 1;
            }
        }
        else
        {
            curr = this->end;
            while (this->size > newSize)
            {
                if (this->size == 1)
                {
                    delete curr;
                    this->begin = nullptr;
                    this->end = nullptr;
                }
                else
                {
                    this->end = curr->prev;
                    delete curr;
                    curr = this->end;
                }
                this->size -= 1;
            }
            if (this->end != nullptr)
                this->end->next = nullptr;
        }
    }
    template <typename T>
    void LinkedList<T>::resizeRevert(uint64_t newSize)
    {
        LinkedListItem *curr;
        if (newSize > this->size)
        {
            while (this->size < newSize)
            {
                try
                {
                    curr = new LinkedListItem;
                }
                catch (const std::exception &e)
                {
                    throw e;
                    return;
                }
                if (this->begin == nullptr)
                {
                    curr->prev = nullptr;
                    curr->next = nullptr;
                    this->begin = curr;
                    this->end = curr;
                }
                else
                {
                    curr->next = this->begin;
                    curr->prev = nullptr;
                    this->begin->prev = curr;
                    this->begin = curr;
                }
                this->size += 1;
            }
        }
        else
        {
            curr = this->begin;
            while (this->size > newSize)
            {
                if (this->size == 1)
                {
                    delete curr;
                    this->begin = nullptr;
                    this->end = nullptr;
                }
                else
                {
                    this->begin = curr->next;
                    delete curr;
                    curr = this->begin;
                }
                this->size -= 1;
            }
            if (this->begin != nullptr)
                this->begin->prev = nullptr;
        }
    }
    template <typename T>
    bool LinkedList<T>::isEqual(T *items, uint64_t count) const
    {
        LinkedListItem *curr = this->begin;
        uint64_t i = 0;
        if (this->size != count)
            return false;
        while (curr != nullptr)
        {
            if (curr->item != items[i])
                return false;
            i++;
            curr = curr->next;
        }
        return true;
    }
    template <typename T>
    bool LinkedList<T>::operator==(const LinkedList<T> &list) const
    {
        if (this->size != list.size)
            return false;
        LinkedListItem *curr = this->begin;
        LinkedListItem *curr2 = list.begin;
        while (curr != nullptr)
        {
            if (curr->item != curr2->item)
                return false;
            curr = curr->next;
            curr2 = curr2->next;
        }
        return true;
    }
    template <typename T>
    void LinkedList<T>::operator=(const LinkedList<T> &list)
    {
        this->resize(list.getSize());
        LinkedListItem *curr = this->begin;
        uint64_t i = 0;
        while (curr != nullptr)
        {
            curr->item = list[i];
            curr = curr->next;
            i++;
        }
    }
    template <typename T>
    LinkedList<T>::~LinkedList()
    {
        LinkedListItem *curr = this->begin, *next;
        while (curr != nullptr)
        {
            next = curr->next;
            delete curr;
            curr = next;
        }
    }
}

#endif