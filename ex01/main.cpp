/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 07:20:40 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/05 07:20:42 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	Span sp(5);

	std::cout << sp << std::endl;
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp << std::endl;
	//sp.addNumber(23);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span sp2(2);
	sp2.addNumber(2);
	try
	{
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// Here limits TESTS with a lot of numbers.
	// change comparaison of for loop, for 10000000, mesure with time on clusters (15.17s user 0.33s system 99% cpu 15.499 total)
	// tested until 100000000, dosn't explode stack, too long to render result.
	std::list<int>lst;
	for (int i = 0; i < 100000; i++)
	{
		lst.push_back(i);
	}
	std::list<int>::iterator beg = lst.begin();
	std::list<int>::iterator end = lst.end();
	Span l(beg, end);
	std::cout << l.longestSpan() << std::endl;
	/* WAYYYY TOOOOO LOOOOOONG
	std::list<int>lst2;
	for (unsigned int i = 0; i < 4294967295; i++)
	{
		lst2.push_back(i);
	}
	std::list<int>::iterator beg2 = lst2.begin();
	std::list<int>::iterator end2 = lst2.end();
	Span l2(beg2, end2);
	std::cout << l2.longestSpan() << std::endl;*/
//	std::cout << l << std::endl;
	try
	{
		l.addNumber(1000);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	Span stack(-1);
	std::cout << stack.getN() << std::endl;

	return 0;
}
