/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:16:19 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/31 17:26:40 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
#define PMERGE_ME

#include "iostream"
#include "vector"
#include "deque"
#include <sstream>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;
        std::string _input;
    public:
        PmergeMe();
        PmergeMe(char **av);
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();

        template <typename T>
        void FordJohnson(T &c);

        template <typename T>
        void mergeSort(T &c, const T &left, const T &right);

        template <typename T, typename J>
        void display(const T &c, const J &c1, std::clock_t start, std::clock_t end, std::clock_t start1, std::clock_t end1);

        void parser(char **av);
};

#endif