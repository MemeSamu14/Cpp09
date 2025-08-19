/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:57:30 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/19 17:41:46 by sfiorini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return ;
}

PmergeMe::~PmergeMe()
{
	return ;
}

PmergeMe::ErrorProgram::ErrorProgram()
{
	return ;
}

const char *PmergeMe::ErrorProgram::what() const throw()
{
	return ("Error");
}

void	PmergeMe::setValues(const std::string &str)
{
	int j = 0;
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (str[i] != ' ')
		{
			j = 0;
			while (str[i + j] >= '0' && str[i + j] <= '9')
				j++;
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (j == 1)
				{
					this->dq.push_back(str[i] - 48);
					this->vet.push_back(str[i] - 48);
				}
				else
				{
					std::string	num;
					int z;
					for (z = 0; z < j; z++)
					{
						num.push_back(str[i + z]);
					}
					this->dq.push_back(std::atoi(num.c_str()));
					this->vet.push_back(std::atoi(num.c_str()));
					i += z;
				}
			}
			else
				throw	PmergeMe::ErrorProgram();
		}
	}
}

void	PmergeMe::sort()
{
	std::cout << "Before: ";
	for (int i = 0; i < static_cast<int>(this->vet.size()); i++)
		std::cout << this->vet[i] << " ";
	std::cout << std::endl;
	struct timeval dqTimeStart;
	struct timeval dqTimeEnd;
	gettimeofday(&dqTimeStart, NULL);
	dqFordJhonsonSort();
	gettimeofday(&dqTimeEnd, NULL);
	double dqTime = static_cast<double>((dqTimeEnd.tv_sec - dqTimeStart.tv_sec) * 1000000LL + (dqTimeEnd.tv_usec - dqTimeStart.tv_usec)) / 1000000.0;

	struct timeval vetTimeStart;
	struct timeval vetTimeEnd;
	gettimeofday(&vetTimeStart, NULL);
	vetFordJhonsonSort();
	gettimeofday(&vetTimeEnd, NULL);
	double vetTime = static_cast<double>((vetTimeEnd.tv_sec - vetTimeStart.tv_sec) * 1000000LL + (vetTimeEnd.tv_usec - vetTimeStart.tv_usec)) / 1000000.0;

	std::cout << "After:  ";
	for (int i = 0; i < static_cast<int>(this->vet.size()); i++)
		std::cout << this->vet[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << std::fixed << std::setprecision(10) << this->vet.size() << " elements with std::vector : " << vetTime << " us" << std::endl;
	std::cout << "Time to process a range of " << std::fixed << std::setprecision(10) << this->vet.size() << " elements with std::deque : "  << dqTime << " us" << std::endl;
}


void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void	PmergeMe::vetFordJhonsonSort()
{
	std::vector<int>	bigs;
	std::vector<int>	lows;

		
	for (int i = 0; i < static_cast<int>(this->vet.size() - 1); i += 2)
	{
		if (this->vet[i] > this->vet[i + 1])
		{
			bigs.push_back(this->vet[i]);
			lows.push_back(this->vet[i + 1]);
		}
		else
		{
			bigs.push_back(this->vet[i + 1]);
			lows.push_back(this->vet[i]);
		}
	}

	int	size = static_cast<int>(bigs.size());
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (bigs[j] > bigs[j + 1])
			{
				std::swap(bigs[j], bigs[j + 1]);
				std::swap(lows[j], lows[j + 1]);
			}
		}
	}
	bigs.insert(bigs.begin(), lows[0]);
	int	i;
	while (static_cast<int>(lows.size()) > 1)
	{
		i = static_cast<int>(bigs.size()) - 1;
		while (i >= 0 && bigs[i] > lows[static_cast<int>(lows.size()) - 1])
			i--;
		bigs.insert(bigs.begin() + i + 1, lows[static_cast<int>(lows.size()) - 1]);
		lows.pop_back();
	}
	if (static_cast<int>(this->vet.size()) % 2 == 1)
	{
		i = static_cast<int>(bigs.size()) - 1;
		while (i >= 0 && bigs[i] > vet[static_cast<int>(this->vet.size()) - 1])
			i--;
		bigs.insert(bigs.begin() + i + 1, vet[static_cast<int>(this->vet.size()) - 1]);
	}
	this->vet = bigs;
}


void	PmergeMe::dqFordJhonsonSort()
{
	std::deque<int>	bigs;
	std::deque<int>	lows;

	for (int i = 0; i < static_cast<int>(this->dq.size() - 1); i += 2)
	{
		if (this->dq[i] > this->dq[i + 1])
		{
			bigs.push_back(this->dq[i]);
			lows.push_back(this->dq[i + 1]);
		}
		else
		{
			bigs.push_back(this->dq[i + 1]);
			lows.push_back(this->dq[i]);
		}
	}

	int	size = static_cast<int>(bigs.size());
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (bigs[j] > bigs[j + 1])
			{
				std::swap(bigs[j], bigs[j + 1]);
				std::swap(lows[j], lows[j + 1]);
			}
		}
	}
	bigs.insert(bigs.begin(), lows[0]);
	int	i;
	while (static_cast<int>(lows.size()) > 1)
	{
		i = static_cast<int>(bigs.size()) - 1;
		while (i >= 0 && bigs[i] > lows[static_cast<int>(lows.size()) - 1])
			i--;
		bigs.insert(bigs.begin() + i + 1, lows[static_cast<int>(lows.size()) - 1]);
		lows.pop_back();
	}
	this->dq = bigs;
}