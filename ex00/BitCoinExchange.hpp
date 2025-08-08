/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:09:03 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/08 15:16:59 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

class BitCoinExchange
{
	public:
		class WrongFormat: public std::exception
		{
			public:
				WrongFormat(){};
				const char *what() const throw(){return ("Error file");};
		};
		BitCoinExchange();
		static void	checkFormatDateValue();
		static void	checkValue(); // positive integers beetween 0 and 100
		static bool checkValidity(const std::vector<std::string> &a);
		static bool checkData(const std::string &str);
		~BitCoinExchange();
};


#endif