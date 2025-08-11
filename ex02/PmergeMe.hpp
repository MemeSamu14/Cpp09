/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:57:30 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/11 10:24:35 by sfiorini         ###   ########.fr       */
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
		void	dqMerge(int left, int mid, int right);
		void	dqMergeSort(int left, int right);
		void	vetMerge(int left, int mid, int right);
		void	vetMergeSort(int left, int right);
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
		void	sort(const std::string &str);
};

#endif