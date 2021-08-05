/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 13:38:57 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/04 16:43:16 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

// constructors and destructors
span::span() : N(0){}

// changer pour un uint
span::span(unsigned int n): N(n){}
span::span(span const & src): N(src.getN()){}
span::~span(){}

// getters and setters
unsigned int span::getN() const{return N;}

// member functions
void span::addNumber(int i){
	if (this->size() == N)
	{
		throw span::SpanError();
		return ;
	}
	else
		this->push_back(i);
	return ;
}

// operator overloads
span & span::operator=(span const & rhs){
	std::list<int>::operator=(rhs);
	N = rhs.getN();
	return *this;
}

//exceptions
span::SpanError::SpanError(void){}
span::SpanError::~SpanError(void) throw(){}
const char * span::SpanError::what() const throw(){
	return "Span Error";
}

//functions
long int longestSpan(span & s){
	if (s.getN() == 0 || s.getN() == 1 || s.size() == 0 || s.size() == 1)
	{
		//throw span::SpanError();
		return 0;
	}
	s.sort();
	int max;
	int min;
	std::list<int>::const_iterator beg = s.begin();
	std::list<int>::const_iterator end = s.end();
	min = *beg;
	max = *(--end);
	long int res = static_cast<long int>(max - min);
	return res;
}

long int shortestSpan(span & s){
	if (s.getN() == 0 || s.getN() == 1 || s.size() == 0 || s.size() == 1)
	{
		//throw span::SpanError();
		return 0;
	}
	s.sort();
	int aft;
	int min;
	std::list<int>::const_iterator beg = s.begin();
	min = *beg;
	aft = *(++beg);
	long int res = static_cast<long int>(aft - min);
	return res;
}
