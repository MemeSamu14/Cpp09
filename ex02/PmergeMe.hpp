/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:57:30 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/18 16:48:11 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
	private:
		std::deque<int>		dq;
		std::vector<int>	vet;
		void	dqFordJhonsonSort();
		void	vetFordJhonsonSort();
	public:
		class ErrorProgram: public std::exception
		{
			public:
				ErrorProgram();
				const char *what() const throw();
		};
		PmergeMe();
		~PmergeMe();
		void	setValues(const std::string &str);
		void	sort();
};

#endif