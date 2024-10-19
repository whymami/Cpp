/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:22:44 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/19 16:15:16 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "pop: " << mstack.top() << std::endl;
    std::cout << "size: " <<mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    std::cout << "it begin: " << *it << std::endl;
    MutantStack<int>::iterator ite = mstack.end();
    std::cout << "it end: " << *ite << std::endl;
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << "index: " << *it << std::endl;
    *it = 42;
    std::cout << "index: " << *it << std::endl;
    MutantStack<int>::const_reverse_iterator crit = mstack.rbegin();
    std::cout << "rbegin: " << *crit << std::endl;
    return 0;
}