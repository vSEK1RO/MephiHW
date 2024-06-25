#include <cppl/field>

namespace cppl
{
    template <>
    Field<double>::Field()
    {
        data = 0;
    }
    Field<double>::Field(const &double data)
    {
        this->data = data;
    }
    template <>
    Field<double> *Field<double>::operator+(const Field<double> &item) const
    {
        return new Field<double>(data + item.data);
    }
    template <>
    Field<double> *Field<double>::operator-() const
    {
        return new Field<double>(-data);
    }
    template <>
    Field<double> *Field<double>::operator-(const Field<double> &item) const
    {
        return new Field<double>(data - item.data);
    }
    template <>
    Field<double> *Field<double>::operator*(const Field<double> &item) const
    {
        return new Field<double>(data * item.data);
    }
    template <>
    Field<double> *Field<double>::operator/(const Field<double> &item) const
    {
        return new Field<double>(data / item.data);
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
    Field<double> *Field<double>::null() const
    {
        return new Field<double>();
    }
    template <>
    Field<double> *Field<double>::neutral() const
    {
        
    }
}