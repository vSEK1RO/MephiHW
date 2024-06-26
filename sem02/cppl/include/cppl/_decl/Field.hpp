#ifndef FIELD_HPP
#define FIELD_HPP

namespace cppl
{
    template <typename T>
    class Field
    {
    public:
        T data;

        Field();
        Field(const T &data);

        // default operator=
        Field<T> operator+(const Field<T> &item) const;
        Field<T> operator-() const;
        Field<T> operator-(const Field<T> &item) const;
        Field<T> operator*(const Field<T> &item) const;
        Field<T> operator/(const Field<T> &item) const;
        bool operator<(const Field<T> &item) const;
        bool operator>(const Field<T> &item) const;
        bool operator==(const Field<T> &item) const;
        bool operator!=(const Field<T> &item) const;
        Field<T> null() const;
        Field<T> neutral() const;

        ~Field() = default;
    };
}

#endif