/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:38:46 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 16:43:03 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>
#include <iostream>

class span: public std::list<int>
{
	public:
		span(unsigned int n);
		~span();

		unsigned int getN() const;
		void addNumber(int i);
		span & operator=(span const & rhs);

	class SpanError : public std::exception
	{
		public:
			SpanError(void);
			virtual ~SpanError(void) throw();
			virtual const char * what() const throw();
	};

	private:
		span();
		span(span const & src);
		unsigned int N;
};

long int longestSpan(span & s);
long int shortestSpan(span & s);

#endif
