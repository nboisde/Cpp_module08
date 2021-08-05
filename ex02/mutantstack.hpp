/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 09:48:09 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/05 09:48:10 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <list>
#include <stack>

template<typename T>
class MutantStack : public std::list<T>, public std::stack<T>
{
	public:
		MutantStack<T>(void){}
		~MutantStack<T>(void){}
		MutantStack<T>(MutantStack<T> const & src){}
	
		size_t size() const{
			return this->std::stack<T>::size();
		}
		void pop(){
			this->std::stack<T>::pop();
			this->std::list<T>::pop_front();
		}
		void push(T data){
			this->std::stack<T>::push(data);
			this->std::list<T>::push_front(data);
		}

	private:
};

#endif
