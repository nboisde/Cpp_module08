/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nboisde <nboisde@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 23:36:19 by nboisde           #+#    #+#             */
/*   Updated: 2021/08/03 23:36:23 by nboisde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <stdexcept>

template< typename T >
void easyfind(T cont, int i)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw std::exception();
	else
		std::cout << *it << std::endl;
}

#endif
