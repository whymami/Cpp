/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:47:59 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/19 12:42:30 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "vector"

class Span
{
    private:
        size_t _n;
        std::vector<int> _vector;
    public:
        Span();
        Span(unsigned int n);
        Span &operator=(const Span &other);
        Span(const Span &other);
        void addNumber(int number);
        void addNumber(size_t size, size_t seed);
        int shortestSpan();
        int longestSpan();
        ~Span();
        class VectorIsFull : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};