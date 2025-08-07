/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:09:37 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/07 16:56:06 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::ifstream	data_file;    
		data_file.open("data.csv");
		if(!data_file)
		{
			std::cout << "error opening data file" << std::endl;
			return (-1);
		}
	
		std::ifstream	input_file;    
		input_file.open(argv[1]);
		if(!input_file)
		{
			std::cout << "error opening input file" << std::endl;
			return (-1);
		}
		
		std::vector<std::string>	input;
		std::string	str;
		while (std::getline (input_file, str))
		{
			std::cout << "pise: " << str << std::endl;
			input.push_back(str);
		}

		std::vector<std::string>	data;
		while (std::getline (data_file, str))
			data.push_back(str);

		try
		{ 
			BitCoinExchange::checkDataFile(data); 
			BitCoinExchange::checkInputFile(input);
		}
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; return (-1);}
		

		for (int i = 0; i < input.size(); i++)
		{
			if (BitCoinExchange::checkValidity(input[i]))
		}
	}
	else
		std::cout << "invalid number of arguments" << std::endl;

	return (0);
}