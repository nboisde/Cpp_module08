/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 09:47:48 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/05 09:47:49 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <list>
#include <stack>
#include <iostream>

int main(void)
{
	MutantStack<int> lst;
	lst.push(10);
	lst.push(11);
	lst.push(42);

	std::cout << "size: " << lst.size() << std::endl;
	MutantStack<int>::iterator it = lst.begin();
	MutantStack<int>::iterator ite = lst.end();
	++it;
	--it;
	std::cout << "iterate through stack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Here shows the legacy of MutantStack from std::stack.
	std::stack<int> s(lst);

	std::cout << std::endl << "-------------------------------------------" << std::endl;
	MutantStack<int> lst2(lst);
	MutantStack<int>::iterator it2 = lst.begin();
	MutantStack<int>::iterator ite2 = lst.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
}
