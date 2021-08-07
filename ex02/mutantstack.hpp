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
#include <vector>


template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack<T>(void){}
		~MutantStack<T>(void){}
		MutantStack<T>(MutantStack<T> const & src){
			static_cast<void>(src);
		}

		class iterator{
			public:
				iterator(T* ptr) : m_ptr(ptr){}

				iterator& operator++(){
					m_ptr--;
					return *this;
				}

				iterator operator++(int){
					iterator it = *this;
					--(*this);
					return it;
				}

				iterator& operator--(){
					m_ptr++;
					return *this;
				}

				iterator operator--(int){
					iterator it = *this;
					++(*this);
					return it;
				}

				T& operator[](int idx){
					return *(m_ptr + idx);
				}

				T* operator->(){
					return m_ptr;
				}

				T& operator*(){
					return *m_ptr;
				}

				bool operator==(const iterator& other) const{
					return (m_ptr == other.m_ptr);
				}

				bool operator!=(const iterator& other) const{
					return !(*this == other);
				}
			private:
				T* m_ptr;
		};

		MutantStack<T> const & operator=(MutantStack<T> const & rhs)
		{
			std::stack<T>::operator=(rhs);
			return *this;
		}

		iterator begin() {return &this->top();}
		iterator end() {return (&this->top() - this->size());}
};

#endif
