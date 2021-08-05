/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 07:20:55 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/05 07:20:56 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <list>
#include <iostream>
#include <stdexcept>

class Span{
	public:
		//constructors and destructors
		Span(unsigned int n);
		Span(std::list<int>::iterator it1, std::list<int>::iterator it2);
		~Span();
		
		//operators overload
		Span & operator=(Span const & rhs);
		
		//getters & setters
		unsigned int getN(void) const;
		std::list<int> getList(void) const;

		//member functions
		long int longestSpan(void);
		long int shortestSpan(void);
		void addNumber(int nbr);

		//exception
		class SpanError : public std::exception
		{
			public:
				SpanError(void);
				virtual ~SpanError(void) throw();
				virtual const char * what() const throw();
		};

	private:
		Span();
		Span(Span const & src);
		std::list<int> _l;
		unsigned int N;
};

std::ostream & operator<<(std::ostream & o, Span const & rhs);

#endif
