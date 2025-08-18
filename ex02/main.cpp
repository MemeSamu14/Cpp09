/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:57:02 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/18 16:48:20 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return (-1);
	}
	else
	{
		PmergeMe	a;

		try
		{ a.setValues(argv[1]); }
		catch(const PmergeMe::ErrorProgram& e)
		{ std::cerr << e.what() << '\n'; }

		a.sort();
	}
	return (0);
}