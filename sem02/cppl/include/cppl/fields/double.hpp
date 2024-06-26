#ifndef FIELDS_DOUBLE_HPP
#define FIELDS_DOUBLE_HPP

#include <cppl/field>

namespace cppl
{
    template <>
    Field<double>::Field()
    {
        data = 0.0;
    }
    template <>
    Field<double>::Field(const double &data)
    {
        this->data = data;
    }
    template <>
    Field<double> Field<double>::operator+(const Field<double> &item) const
    {
        return Field<double>(data + item.data);
    }
    template <>
    Field<double> Field<double>::operator-() const
    {
        return Field<double>(-data);
    }
    template <>
    Field<double> Field<double>::operator-(const Field<double> &item) const
    {
        return Field<double>(data - item.data);
    }
    template <>
    Field<double> Field<double>::operator*(const Field<double> &item) const
    {
        return Field<double>(data * item.data);
    }
    template <>
    Field<double> Field<double>::operator/(const Field<double> &item) const
    {
        return Field<double>(data / item.data);
    }
    template <>
    bool Field<double>::operator<(const Field<double> &item) const
    {
        return data < item.data;
    }
    template <>
    bool Field<double>::operator>(const Field<double> &item) const
    {
        return data > item.data;
    }
    template <>
    bool Field<double>::operator==(const Field<double> &item) const
    {
        return data == item.data;
    }
    template <>
    bool Field<double>::operator!=(const Field<double> &item) const
    {
        return data != item.data;
    }
    template <>
    Field<double> Field<double>::null() const
    {
        return Field<double>();
    }
    template <>
    Field<double> Field<double>::neutral() const
    {
        return Field<double>(1.0);   
    }
}

#endif