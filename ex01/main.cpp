/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:38:40 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 16:39:55 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	//span s(4);
	span s(4);
	s.addNumber(120);
	s.addNumber(10);
	s.addNumber(3);
	s.addNumber(400);
	//try
	//{
		s.addNumber(5);
	//}
	//catch(const std::exception& e)
	//{
	//	std::cerr << e.what() << '\n';
	//}
	std::cout << longestSpan(s) << std::endl;
	std::cout << shortestSpan(s) << std::endl;
	//s.addNumber(120);
	//s.addNumber(10);
	//s.addNumber(3);
	//s.addNumber(400);
	//std::cout << longestSpan(s) << std::endl;
	//std::cout << shortestSpan(s) << std::endl;

	/*span o(0);
	try
	{
		std::cout << longestSpan(o) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}*/
	/*span k(2);
	k.addNumber(1);
	try
	{
		std::cout << longestSpan(k) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}*/
	
}
