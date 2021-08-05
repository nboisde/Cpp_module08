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
	lst.push_back(12);
	std::cout << lst.size() << std::endl;
	MutantStack<int>::iterator it = lst.begin();
	MutantStack<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(lst);
}
