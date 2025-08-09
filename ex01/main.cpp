/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 14:40:53 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/09 14:57:28 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>


bool	errorHandling(const std::string &argv)
{
	for (int i = 0; i < static_cast<int>(argv.size()); i++)
	{
		if (argv[i] != ' ')
		{
			std::cout << argv[i] << std::endl;
			if (argv[i] >= '0' && argv[i] <= '9')
				return (true);
			else if (argv[i] != '-' || argv[i] != '+' || argv[i] != '*' || argv[i] != '/')
				return (false);
			else
				return (true);
		}
	}
	return (true);
}

int	main(int argc, char **argv)
{
	// std::stack<char> operators;
	if (argc == 2)
	{
		std::string	newStr;
		for (int i = 0; argv[1][i]; i++)
		{
			if (argv[1][i] != '\"' || argv[1][i] != ' ')
				newStr.push_back(argv[1][i]);
		}
		if (errorHandling(newStr) == false)
			return (std::cout << "Error" << std::endl, -1);
	}
	return (0);
}