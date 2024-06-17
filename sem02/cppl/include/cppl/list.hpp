#pragma once
#ifndef LIST_HPP
#define LIST_HPP

#include <cstdint>

#include <cppl/seq>

namespace cppl
{
    template <typename T>
    class list : public seq<T>
    {
    public:
        // Constructors
        list(uint64_t);

        // Getters
        virtual uint64_t size() override;

        // Operators
        list<T> &operator=(const list<T> &) override;
        cppl::iter<T> &get(uint64_t) override;
        bool &operator==(const list<T> &) override;
        T &operator[](uint64_t) override;

        // Destructor
        ~list();

    private:
        
    };

}

#endif