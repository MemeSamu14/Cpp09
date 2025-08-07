/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 11:09:03 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/07 13:00:45 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange
{
	private:

	public:
		BitcoinExchange();
		static checkFormatDateValue();
		static checkValue(); // positive integers beetween 0 and 100
		
		~BitcoinExchange();
};


#endif