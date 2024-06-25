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
            curr = new LinkedListItem;
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
    void LinkedList<T>::erase(uint64_t beginIndex, uint64_t endIndex)
    {
        if (beginIndex > endIndex || beginIndex > size || endIndex > size)
            throw std::out_of_range("LinkedList<T>::erase");
        LinkedListItem *startPtr, *endPtr;
        bool mvbegin, mvend;
        mvbegin = beginIndex == 0;
        mvend = endIndex == size;
        if (beginIndex < size - endIndex)
        {
            endPtr = begin;
            shiftPtr(endPtr, beginIndex);
            startPtr = endPtr->prev;
            shiftPtrErase(endPtr, endIndex - beginIndex);
            if (startPtr != nullptr)
                startPtr->next = endPtr;
            if (endPtr != nullptr)
                endPtr->prev = startPtr;
        }
        else
        {
            startPtr = end;
            shiftPtrRevert(startPtr, size - endIndex);
            endPtr = startPtr->next;
            shiftPtrRevertErase(startPtr, endIndex - beginIndex);
            if (endPtr != nullptr)
                endPtr->prev = startPtr;
            if (startPtr != nullptr)
                startPtr->next = endPtr;
        }
        if (mvbegin)
            begin = endPtr;
        if (mvend)
            end = startPtr;
    }
    template <typename T>
    void LinkedList<T>::insertAt(const T &item, uint64_t index)
    {
        if (index > size)
            throw std::out_of_range("LinkedList<T>::insertAt");
        LinkedListItem *curr, *buff;
        if(index!=0 && index!=size){
            if(index < size/2){
                curr = begin;
                shiftPtr(curr, index);
                buff = curr->prev;
                curr->prev = new LinkedListItem();
                curr->prev->item = item;
                curr->prev->next = curr;
                curr->prev->prev = buff;
                buff->next = curr->prev;
            }else{
                curr = end;
                shiftPtrRevert(curr,size-index);
                buff = curr->next;
                curr->next = new LinkedListItem();
                curr->next->item = item;
                curr->next->prev = curr;
                curr->next->next = buff;
                buff->prev = curr->next;
            }
        }else if(index == 0 && index != size){
            begin->prev = new LinkedListItem();
            begin->prev->next = begin;
            begin = begin->prev;
            begin->prev = nullptr;
            begin->item = item;
        }else if(index == size && index != 0){
            end->next = new LinkedListItem();
            end->next->prev = end;
            end = end->next;
            end->next = nullptr;
            end->item = item;
        }else{
            begin = new LinkedListItem();
            end = begin;
            begin->next = begin->prev = nullptr;
            begin->item = item;
        }
        size+=1;
    }
    // template <typename T>
    // void LinkedList<T>::rearr(uint64_t begin, uint64_t end)
    // {

    // }
    // template <typename T>
    // uint64_t LinkedList<T>::find(const T& item, uint64_t ent)
    // {

    // }
    // template <typename T>
    // uint64_t LinkedList<T>::count(const T& item, uint64_t ent)
    // {

    // }
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
                curr = new LinkedListItem;
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
                curr = new LinkedListItem;
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
    bool LinkedList<T>::isEqual(const T *items, uint64_t count) const
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
    template <typename T>
    void LinkedList<T>::shiftPtr(LinkedListItem *&ptr, uint64_t count) const
    {
        for (uint64_t i = 0; i < count && ptr != nullptr; i++)
        {
            ptr = ptr->next;
        }
        if (ptr == nullptr)
            throw std::out_of_range("LinkedList<T>::shiftPtr");
    }
    template <typename T>
    void LinkedList<T>::shiftPtrRevert(LinkedListItem *&ptr, uint64_t count) const
    {
        for (uint64_t i = 0; i < count && ptr != nullptr; i++)
        {
            ptr = ptr->prev;
        }
        if (ptr == nullptr)
            throw std::out_of_range("LinkedList<T>::shiftPtrRevert");
    }
    template <typename T>
    void LinkedList<T>::shiftPtrErase(LinkedListItem *&ptr, uint64_t count)
    {
        LinkedListItem *buff;
        for (uint64_t i = 0; i < count && ptr != nullptr; i++)
        {
            buff = ptr;
            ptr = ptr->next;
            delete buff;
            size -= 1;
        }
    }
    template <typename T>
    void LinkedList<T>::shiftPtrRevertErase(LinkedListItem *&ptr, uint64_t count)
    {
        LinkedListItem *buff;
        for (uint64_t i = 0; i < count && ptr != nullptr; i++)
        {
            buff = ptr;
            ptr = ptr->prev;
            delete buff;
            size -= 1;
        }
    }
}

#endif