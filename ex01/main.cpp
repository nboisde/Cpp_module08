/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 11:38:40 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 15:06:07 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int main(void)
{
	span s(4);
	s.addNumber(120);
	s.addNumber(10);
	s.addNumber(3);
	s.addNumber(400);
	s.addNumber(4);

	std::cout << longestSpan(s) << std::endl;
	std::cout << shortestSpan(s) << std::endl;
}
