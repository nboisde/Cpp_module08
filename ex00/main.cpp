/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:36:30 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/03 23:36:32 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>

//#define T std::list
#define T std::deque
//#define T std::vector


int main(void)
{
	T<int> lst;

	lst.push_back(42);
	lst.push_back(10);
	lst.push_back(12);
	lst.push_back(84);
	lst.push_back(32);

	try
	{
		easyfind< T<int> >(lst, 10);
		std::cout << "elem found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "elem not found" << std::endl;
	}
	try
	{
		easyfind< T<int> >(lst, 28);
		std::cout << "elem found" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << "elem not found" << std::endl;
	}
	return 0;
}
