/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:08:27 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/10 10:55:06 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(/* args */)
{
}

RPN::~RPN()
{
}

RPN::ErrorNotation::ErrorNotation()
{
	return ;
}

const char *RPN::ErrorNotation::what() const throw()
{
	return ("Error");
}

int		RPN::calculate(const std::string &str)
{
	int		result = 0;
	int		first = 0;
	int		second = 0;
	int		times = 0;

	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		times = 0;
		if (str[i] >= '0' && str[i] <= '9')
		{
			this->stack.push(str[i] - '0');
			times++;
		}
		else
		{
			if (str[i] != ' ')
			{
				if (stack.size() < 2)
					throw	RPN::ErrorNotation();
				if (times > 1)
				{
					first = this->stack.top();
					this->stack.pop();
					second = this->stack.top();
					this->stack.pop();
				}
				else
				{
					second = this->stack.top();
					this->stack.pop();
					first = this->stack.top();
					this->stack.pop();
				}
				if (str[i] == '+')
					result = addition(first, second);
				else if (str[i] == '-')
					result = subtraction(first, second);
				else if (str[i] == '*')
					result = multiplication(first, second);
				else if (str[i] == '/')
					result = division(first, second);
				stack.push(result);
			}
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
