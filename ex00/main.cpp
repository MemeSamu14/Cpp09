/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:09:37 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/08 16:09:38 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

#include <map>
#include <string>
#include <cstdlib>
#include <fstream>

void	fill_data(std::ifstream& data_file, std::map<std::string, float>& data)
{
	std::string str;
	std::string data_str;
	std::string value_str;
	while (std::getline(data_file, str))
	{
		if (!(static_cast<int>(str.find(',')) == static_cast<int>(str.size())))
		{
			for (int i = 0; i < static_cast<int>(str.find(',')); i++)
				data_str.push_back(str[i]);
			for (int i = str.find(',') + 1; i < static_cast<int>(str.size()); i++)
				value_str.push_back(str[i]);
			data[data_str] = atof(value_str.c_str());
			data_str.clear();
			value_str.clear();
		}
	}
}

bool	correct_opening(std::ifstream& data_file, std::ifstream& input_file, char *argv)
{
	data_file.open("data.csv");
	if(!data_file)
	{
		std::cout << "error opening data file" << std::endl;
		return (false);
	}

	input_file.open(argv);
	if(!input_file)
	{
		std::cout << "error opening input file" << std::endl;
		return (false);
	}
	return (true);
}

void	fill_input(std::vector<std::string>& input, std::ifstream& input_file)
{
	std::string	str;
	while (std::getline(input_file, str))
	{
		if (str != "date | value")
			input.push_back(str);
	}
}

std::string*	getInputData(std::vector<std::string>& input, int index)
{
	std::string* str = new std::string;
	for (int j = 0; j < static_cast<int>(input[index].find('|')); j++)
	{
		if (input[index][j] != ' ')
			(*str).push_back(input[index][j]);
	}
	return (str);
}

std::string*	getInputValue(std::vector<std::string>& input, int index)
{
	std::string* str = new std::string;
	int start = static_cast<int>(input[index].find('|') + 1);
	for (int j = start; j < static_cast<int>(input[index].size()); j++)
	{
		(*str).push_back(input[index][j]);
	}
	return (str);
}

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::map<std::string, float>	data;
		std::vector<std::string>		input;

		std::ifstream	data_file;
		std::ifstream	input_file;
		if (correct_opening(data_file, input_file, argv[1]) == false)
			return (-1);
		fill_data(data_file, data);
		fill_input(input, input_file);
		try
		{
			std::string	*data_str;
			std::string	*value_str;
			for (int i = 0; i < static_cast<int>(input.size()); i++)
			{
				data_str = getInputData(input, i);
				if (BitCoinExchange::checkData(*data_str) == false)
					std::cout << "Invalid Data Format" << std::endl;
				else
				{
					value_str = getInputValue(input, i);
					std::cout << "input value: " << *value_str << std::endl;
					delete value_str;
				}
				delete data_str;
			}
		}
		catch(const std::exception& e) { std::cerr << e.what() << std::endl; return (-1);}
		// for (int i = 0; i < input.size(); i++)
		// {
		// 	if (BitCoinExchange::checkValidity(input[i]))
		// }
	}
	else
		std::cout << "invalid number of arguments" << std::endl;

	return (0);
}
