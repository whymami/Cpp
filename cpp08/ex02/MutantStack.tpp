/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:07:03 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/19 16:01:35 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() { return this->c.end(); }

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const { return this->c.end(); }

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() { return this->c.rbegin(); }

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() { return this->c.rend(); }

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const { return this->c.rbegin(); }

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const { return this->c.rend(); }

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    if (this != &src)
        this->c = src.c;
    return *this;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &other) { *this = other; }

template <typename T>
MutantStack<T>::MutantStack() {}

template <typename T>
MutantStack<T>::~MutantStack() {}