/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:09:37 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/19 18:08:50 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

#include <map>
#include <string>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>

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
		std::cout << "Error: could not open file." << std::endl;
		return (false);
	}

	input_file.open(argv);
	if(!input_file)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (false);
	}
	return (true);
}

std::string* getPreviusDay(std::string& str)
{
	std::string year;
	std::string month;
	std::string days;
	std::string* final = new std::string;

	int i;
	for (i = 0; i < static_cast<int>(str.find('-')); i++)
		year.push_back(str[i]);
	for (i++; i < static_cast<int>(str.find('-',  i + 1)); i++)
		month.push_back(str[i]);
	for (i++; i < static_cast<int>(str.size()); i++)
		days.push_back(str[i]);
	int	year_int = std::atoi(year.c_str());
	int	month_int = std::atoi(month.c_str());
	int	days_int = std::atoi(days.c_str());

	days_int--;
	if (days_int == 0)
	{
		month_int--;
		if (month_int == 0)
		{
			year_int--;
			month_int = 12;
		}
		if (month_int == 1 || month_int == 3 || month_int == 5 || month_int == 7 || month_int == 8 || month_int == 10 || month_int == 12)
			days_int = 31;
		else if (month_int != 2)
			days_int = 30;
		else
		{
			if ((std::atoi(year.c_str()) % 4) != 0)
				days = 28;
			else
				days = 29;
		}
	}
	year.clear();
	month.clear();
	days.clear();

    char buffer[10];
    char buffer1[10];
    char buffer2[10];
	sprintf(buffer, "%d", year_int);
	std::string year1(buffer);
	sprintf(buffer1, "%d", month_int);
	std::string month1(buffer1);
	sprintf(buffer2, "%d", days_int);
	std::string days1(buffer2);
	
	for (int i = 0; i < static_cast<int>(year1.size()); i++)
		(*final).push_back(year1[i]);
	(*final).push_back('-');
	for (int i = 0; i < static_cast<int>(month1.size()); i++)
	{
		if (static_cast<int>(month1.size()) == 1)
			(*final).push_back('0');
		(*final).push_back(month1[i]);
	}
	(*final).push_back('-');
	for (int i = 0; i < static_cast<int>(days1.size()); i++)
	{
		if (static_cast<int>(days1.size()) == 1)
			(*final).push_back('0');
		(*final).push_back(days1[i]);
	}
	return (final);
}

int	main(int argc, char** argv)
{
	if (argc == 2)
	{
		std::map<std::string, float>	data;
	
		std::ifstream	data_file;
		std::ifstream	input_file;
		if (correct_opening(data_file, input_file, argv[1]) == false)
			return (-1);
		fill_data(data_file, data);
		std::string	str;
		std::string	data_str;
		std::string	value_str;
		while(std::getline(input_file, str))
		{
			if (str != "date | value")
			{
				for (int z = 0; z < static_cast<int>(str.find('|')); z++)
					data_str.push_back(str[z]);
				if (BitCoinExchange::checkData(data_str) == false)
					std::cout << "Invalid Data Format" << std::endl;
				else
				{
					for (int z = data_str.size() + 2; z < static_cast<int>(str.size()); z++)
						value_str.push_back(str[z]);	
					if (std::atof(value_str.c_str()) < 0)
						std::cout << "Error: not a positive number." << std::endl;
					else if (std::atof(value_str.c_str()) > 1000)
						std::cout << "Error: too large a number." << std::endl;
					else if (data[data_str])
						std::cout << data_str << " =>" << value_str << " = " << std::atof(value_str.c_str()) * data[data_str] << std::endl;
					else
					{
						int flag = 0;
						std::string *tmp;
						data_str.erase(data_str.length() - 1);
						std::string ref = data_str;
						tmp = &ref;
						std::string *tmp1;
						int i = 0;
						while (data[*tmp] == 0)
						{
							flag = 1;
							if (i == 4)
								break ;
							tmp1 = tmp;
							tmp = getPreviusDay(*tmp1);
							if (i != 0)
								delete tmp1;
							i++;
						}
						std::cout << data_str << " => " << value_str << " = " << \
						std::atof((value_str).c_str()) * data[*tmp] << std::endl;
						if (flag == 1)
							delete tmp;
					}
					value_str.clear();
				}
				data_str.clear();
			}
		}
	}
	else
		std::cout << "invalid number of arguments" << std::endl;

	return (0);
}
