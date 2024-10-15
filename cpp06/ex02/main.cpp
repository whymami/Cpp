/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muguveli <muguveli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 18:00:01 by muguveli          #+#    #+#             */
/*   Updated: 2024/10/15 18:34:58 by muguveli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void) 
{
    int random = rand() % 3;
    switch (random)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        default:
            return new C();
    }
}

void identify(Base* p) 
{
    if (!p) 
    {
        std::cout << "Null pointer provided." << std::endl;
        return;
    }
    if (A* a = dynamic_cast<A*>(p)) 
        a->info();
    else if (B* b = dynamic_cast<B*>(p)) 
        b->info();
    else if (C* c = dynamic_cast<C*>(p)) 
        c->info();
    else 
        std::cout << "Unknown type." << std::endl;
}


void identify(Base& p) 
{
    try 
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        p.info();
    } 
    catch (std::exception &e)
    {
        try 
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            p.info();
        } 
        catch (std::exception &e) 
        {
            try 
            {
                C &c = dynamic_cast<C&>(p);
                p.info();
                (void)c;
            }
            catch (std::exception &e) 
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}

int main() 
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
