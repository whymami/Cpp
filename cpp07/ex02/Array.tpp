/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:03:21 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/17 13:58:25 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
Array<T>::Array() : _arr(nullptr), _n(0) {}

template <class T>
Array<T>::Array(unsigned int n) : _n(n)
{
    this->_arr = new T[n];
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != other)
    {
        this->_n = other._n;
        this->_arr = new T[this->_n];
        for (size_t i = 0; i < this->_n; ++i) 
            _arr[i] = other._arr[i];
    }
    return (this);
}

template <class T>
Array<T>::Array(Array &other) : _n(other._n)
{
    this->_arr = new T[this->_n];
    for (size_t i = 0; i < this->_n; ++i) 
        _arr[i] = other._arr[i];
}

template <class T>
Array<T>::~Array()
{
    delete[] _arr;
}
template <class T>
T &Array<T>::operator[](const unsigned int inx)
{
    if ((inx > this->_n - 1))
        throw OutOfRangeException();
    return _arr[inx];
}

template <class T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
    return ("Out Of Range");
}