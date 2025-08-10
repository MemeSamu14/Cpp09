/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:08:27 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/10 10:51:14 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int>	stack;
	public:
		class ErrorNotation: public std::exception
		{
			public:
				ErrorNotation();
				const char *what() const throw();
		};
		RPN();
		void	setValues(const std::string &str);
		int		calculate(const std::string &newStr);
		int		addition(int a, int b) const;
		int		subtraction(int a, int b) const;
		int		multiplication(int a, int b) const;
		int		division(int a, int b) const;
		~RPN();
};


#endif