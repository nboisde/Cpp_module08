/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:38:46 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 15:04:10 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>
#include <iostream>

class span: public std::list<int>
{
	public:
		span(int n);
		~span();

		int getN() const;
		void addNumber(int i);
		span & operator=(span const & rhs);

	private:
		span();
		int N;
};

long int longestSpan(span & s);
long int shortestSpan(span & s);

#endif
