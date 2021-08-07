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
	MutantStack<int> mstack;
	mstack.push(10);
	mstack.push(11);
	mstack.push(42);

	std::cout << "size: " << mstack.size() << std::endl;


	std::cout << mstack.top() << std::endl;

	mstack.pop();

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	mstack.push(42);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterate through stack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Here shows the legacy of MutantStack from std::stack.
	std::stack<int> s(mstack);

	std::cout << std::endl << "-------------------------------------------" << std::endl;
	MutantStack<int> mstack2(mstack);
	MutantStack<int>::iterator it2 = mstack.begin();
	MutantStack<int>::iterator ite2 = mstack.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
}
