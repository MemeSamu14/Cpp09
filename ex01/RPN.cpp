/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:08:27 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/09 17:59:21 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

int		RPN::calculate(const std::string &str)
{
	int		result = 0;
	int		first = 0;
	int		second = 0;
	// int times = static_cast<int>(this->operators.size());
	// for (int i = 0; i < times; i++)
	// {
	// 	this->numbers.pop();
	// 	second = this->numbers.top() - '0';
	// 	op = operators.top();
	// 	if (op == '+')
	// 		result = addition(result, second);
	// 	else if (op == '-')
	// 		result = subtraction(result, second);
	// 	else if (op == '*')
	// 		result = multiplication(result, second);
	// 	else if (op == '/')
	// 		result = division(result, second);
	// 	operators.pop();
	// }
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
			this->stack.push(str[i]);
		else
		{
			first = 
			if (str[i] == '+')
				result = addition(first, second);
			else if (str[i] == '-')
				result = subtraction(first, second);
			else if (str[i] == '*')
				result = multiplication(first, second);
			else if (str[i] == '/')
				result = division(first, second);
			operators.pop();
		}
	}
	return (result);
}

int		RPN::addition(int a, int b) const
{
	return (a + b);
}

int		RPN::subtraction(int a, int b) const
{
	return (a - b);
}

int		RPN::multiplication(int a, int b) const
{
	return (a * b);
}

int		RPN::division(int a, int b) const
{
	return (a / b);
}
