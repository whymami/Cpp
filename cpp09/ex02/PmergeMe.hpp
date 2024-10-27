/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:16:19 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:33 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
#define PMERGE_ME

#include "iostream"
#include "vector"
#include "deque"
#include <sstream>

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
        void mergeSort(T &c, T &left, T &rigt);

        void parser(char **av);
};

#endif