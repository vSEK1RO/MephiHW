#pragma once
#ifndef UNIQUE_POINTER_HPP
#define UNIQUE_POINTER_HPP

namespace cppl
{
    template <typename T>
    class UniquePointer
    {
        public:
            UniquePointer(T *data);
            
            T &getData() const;

            ~UniquePointer();
        private:
        T *data;
    };
}

#endif