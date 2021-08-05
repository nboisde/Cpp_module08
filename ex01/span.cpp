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

#include "span.hpp"

//constructors and destructors
Span::Span(void){
	N = 0;
	_full = false;
}

Span::Span(std::list<int>::iterator it1, std::list<int>::iterator it2){
	int i = 0;
	//N = static_cast<unsigned int>(*it2 - *it1);// + 1);

	while (it1 != it2)
	{
		_l.push_back(*it1);
		i++;
		it1++;
	}
	std::cout << "i: " << i << std::endl;
	N = static_cast<unsigned int>(i);
	_full = false;
	std::cout << "N: " << N << std::endl;
	//_l.push_back(i);
	//for (std::list<int>::iterator it = _l.begin(); it != _l.end(); it++)
	//	std::cout << *it << std::endl;
}

Span::Span(Span const & src){
	*this = src;
}

Span::Span(unsigned int n): N(n), _full(false){}

Span::~Span(){}
		
//operators overload
Span & Span::operator=(Span const & rhs){
	if (this == &rhs)
		return *this;
	else
	{
		this->N = rhs.getN();
		this->_l = rhs.getList();
		this->_full = rhs.getFull();
		return *this;	
	}
}
		
//getters & setters
unsigned int Span::getN(void) const{return N;}
std::list<int> Span::getList(void) const{return _l;}
bool Span::getFull(void) const{return _full;}

//exceptions
Span::SpanError::SpanError(void){}
Span::SpanError::~SpanError(void) throw(){}
const char * Span::SpanError::what() const throw(){
	return "Span Error";
}

//member functions
void Span::addNumber(int nbr)
{
	try
	{
		if (_l.size() == N)
		{
			_full = true;
			throw Span::SpanError();
		}
		else
			_l.push_back(nbr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Span::addRange(std::list<int>::iterator it1, std::list<int>::iterator it2){
	while (it1 != it2)
	{
		if (_full == true)
			break ;
		this->addNumber(*it1);
		it1++;
	}
}


long int Span::longestSpan(void){
	if (N == 0 || N == 1 || _l.size() == 0 || _l.size() == 1)
		throw Span::SpanError();

	std::list<int>cpy = _l;
	cpy.sort();
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
	if (N == 0 || N == 1 || _l.size() == 0 || _l.size() == 1)
		throw Span::SpanError();

	std::list<int>cpy = _l;
	cpy.sort();
	int max;
	int min;
		std::list<int>::const_iterator beg = cpy.begin();
	min = *beg;
	max = *(++beg);
	long int span = static_cast<long int>(max - min);
	//std::cout << span << std::endl;
	std::list<int>::const_iterator end = (--(cpy.end()));
	std::list<int>::iterator it = cpy.begin();
	while (it != end)
	{
		int i = *it;
		long int tmp = static_cast<long int>(*(++it) - i);
		if (tmp < span)
			span = tmp;
	}
	return span;
}

std::ostream & operator<<(std::ostream & o, Span const & rhs){
	o << "N: " << rhs.getN() << std::endl;
	o << "elements: " << std::endl << "[";
	// fix error here.
	std::list<int> cpy = rhs.getList();
	for (std::list<int>::iterator it1 = cpy.begin(); it1 != cpy.end(); ++it1)
		o << *it1 << ",";
	o << "]" << std::endl;
	return o;
}
