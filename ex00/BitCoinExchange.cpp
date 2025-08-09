/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:09:03 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/09 14:13:08 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

bool BitCoinExchange::checkData(const std::string &str)
{
	std::string year;
	std::string month;
	std::string days;

	int i;
	for (i = 0; i < static_cast<int>(str.find('-')); i++)
		year.push_back(str[i]);
	for (i++; i < static_cast<int>(str.find('-',  i + 1)); i++)
		month.push_back(str[i]);
	for (i++; i < static_cast<int>(str.size()); i++)
		days.push_back(str[i]);
	if (year.size() > 4)
		return (false);
	else if (std::atoi(year.c_str()) >= 2009 && std::atoi(year.c_str()) <= 2022)
	if (std::atoi(month.c_str()) <= 0 || std::atoi(month.c_str()) > 12)
		return (false);
	if (std::atoi(month.c_str()) <= 0 || std::atoi(month.c_str()) > 31)
		return (false);
	if (std::atoi(month.c_str()) == 4 || std::atoi(month.c_str()) == 6 || \
		std::atoi(month.c_str()) == 9 || std::atoi(month.c_str()) == 11)
	{
		if (std::atoi(days.c_str()) > 30)
			return (false);
	}
	if (std::atoi(month.c_str()) == 2)
	{
		if (std::atoi(days.c_str()) > 29)
			return (false);
		else
		{
			if ((std::atoi(year.c_str()) % 4) != 0)
			{
				if (std::atoi(days.c_str()) > 28)
					return (false);
			}
		}
	}
	return (true);
}
