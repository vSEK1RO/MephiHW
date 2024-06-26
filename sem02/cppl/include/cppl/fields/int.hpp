#ifndef FIELDS_INT_HPP
#define FIELDS_INT_HPP

#include <cppl/field>

namespace cppl
{
    template <>
    Field<int>::Field()
    {
        data = 0;
    }
    template <>
    Field<int>::Field(const int &data)
    {
        this->data = data;
    }
    template <>
    Field<int> Field<int>::operator+(const Field<int> &item) const
    {
        return Field<int>(data + item.data);
    }
    template <>
    Field<int> Field<int>::operator-() const
    {
        return Field<int>(-data);
    }
    template <>
    Field<int> Field<int>::operator-(const Field<int> &item) const
    {
        return Field<int>(data - item.data);
    }
    template <>
    Field<int> Field<int>::operator*(const Field<int> &item) const
    {
        return Field<int>(data * item.data);
    }
    template <>
    Field<int> Field<int>::operator/(const Field<int> &item) const
    {
        return Field<int>(data / item.data);
    }
    template <>
    bool Field<int>::operator<(const Field<int> &item) const
    {
        return data < item.data;
    }
    template <>
    bool Field<int>::operator>(const Field<int> &item) const
    {
        return data > item.data;
    }
    template <>
    bool Field<int>::operator==(const Field<int> &item) const
    {
        return data == item.data;
    }
    template <>
    bool Field<int>::operator!=(const Field<int> &item) const
    {
        return data != item.data;
    }
    template <>
    Field<int> Field<int>::null() const
    {
        return Field<int>();
    }
    template <>
    Field<int> Field<int>::neutral() const
    {
        return Field<int>(1);   
    }
}

#endif