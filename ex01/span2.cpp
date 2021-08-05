/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 07:20:47 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/05 07:20:48 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span2.hpp"

//constructors and destructors
Span::Span(void){
	N = 0;
}

Span::Span(std::list<int>::iterator it1, std::list<int>::iterator it2){
	int i = 0;
	N = static_cast<unsigned int>(*it2 - *it1);// + 1);
	std::cout << "N: " << N << std::endl;
	while (it1 != it2)
	{
		_l.push_back(i);
		i++;
		it1++;
	}
	//_l.push_back(i);
	//for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++)
	//	std::cout << *it << std::endl;
}

Span::Span(Span const & src){
	*this = src;
}

Span::Span(unsigned int n): N(n){
	// protect against stack explosion.
	// or change _l on *_l
}

Span::~Span(){}
		
//operators overload
Span & Span::operator=(Span const & rhs){
	if (this == &rhs)
		return *this;
	else
	{
		this->N = rhs.getN();
		this->_l = rhs.getList();
		return *this;	
	}
}
		
//getters & setters
unsigned int Span::getN(void) const{return N;}
std::list<int> Span::getList(void) const{return _l;}

//exceptions
Span::SpanError::SpanError(void){}
Span::SpanError::~SpanError(void) throw(){}
const char * Span::SpanError::what() const throw(){
	return "Span Error";
}

//member functions
void Span::addNumber(int nbr)
{
	if (_l.size() == N)
		throw Span::SpanError();
	else
		_l.push_back(nbr);
}

long int Span::longestSpan(void){
	std::list<int>cpy = _l;

	cpy.sort();
	if (N == 0 || N == 1 || _l.size() == 0 || _l.size() == 1)
	{
		throw Span::SpanError();
		std::cout << "throw exc here." << std::endl;
	}
	int max;
	int min;
	std::list<int>::const_iterator beg = cpy.begin();
	std::list<int>::const_iterator end = cpy.end();
	min = *beg;
	max = *(--end);
	long int res = static_cast<long int>(max - min);
	return res;
}
long int Span::shortestSpan(void){
		std::list<int>cpy = _l;

	cpy.sort();
	if (N == 0 || N == 1 || _l.size() == 0 || _l.size() == 1)
	{
		throw Span::SpanError();
		std::cout << "throw exc here." << std::endl;
	}
	int max;
	int min;
	std::list<int>::const_iterator beg = cpy.begin();
	min = *beg;
	max = *(++beg);
	long int res = static_cast<long int>(max - min);
	return res;
}

std::ostream & operator<<(std::ostream & o, Span const & rhs){
	o << "N: " << rhs.getN() << std::endl;
	o << "elements: " << std::endl << "[";
	for (std::list<int>::iterator it1 = rhs.getList().begin(); it1 != (rhs.getList().end()); it1++)
		o << *it1 << ",";
	o << "]" << std::endl;
	return o;
}

