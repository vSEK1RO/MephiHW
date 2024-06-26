#ifndef SEQUENCE_HPP
#define SEQUENCE_HPP

#include <cstdint>

namespace cppl
{
    template <typename T>
    class Sequence
    {
    public:
        // doesn't have default constructor, because abstract

        // Const methods
        virtual T &getFirst() const = 0;
        virtual T &getLast() const = 0;
        virtual Sequence<T> *getSubseq(uint64_t, uint64_t) const = 0;
        virtual uint64_t getLenght() const = 0;
        virtual Sequence<T> *map(T (*func)(const T &, uint64_t)) const = 0;
        virtual Sequence<T> *where(bool (*func)(const T &, uint64_t)) const = 0;
        virtual T reduce(T (*func)(const T &, const T &), const T &c) const = 0;
        virtual bool isEqual(T *, uint64_t) const = 0;
        virtual Sequence<T> *copy() const = 0;

        // Non const methods
        virtual void append(const T &) = 0;
        virtual void prepend(const T &) = 0;
        virtual void insertAt(const T &, uint64_t) = 0;
        virtual void resize(uint64_t) = 0;
        virtual void erase(uint64_t, uint64_t) = 0;
        
        // Operators
        virtual Sequence<T> *operator=(const Sequence<T> &) = 0;
        virtual bool operator==(const Sequence<T> &) const = 0;
        virtual Sequence<T> *operator+(const Sequence<T> &) const = 0;
        virtual T &operator[](uint64_t) const = 0;

        // have pure virtual destructor with body
        virtual ~Sequence() = 0;

    private:
    };
    template <typename T>
    Sequence<T>::~Sequence(){};
}

#endif