/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:57:30 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/18 10:53:52 by sfiorini         ###   ########.fr       */
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
					std::cout << "str[i]: " << str[i] << std::endl;
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

void	PmergeMe::sort(const std::string &str)
{
	std::cout << "Before: " << str << std::endl;
	
	int	left = 0;
	int	right = this->dq.size() - 1;

	struct timeval dqTimeStart;
	struct timeval dqTimeEnd;
	gettimeofday(&dqTimeStart, NULL);
	dqMergeSort(left, right);
	gettimeofday(&dqTimeEnd, NULL);
	double dqTime = static_cast<double>((dqTimeEnd.tv_sec - dqTimeStart.tv_sec) * 1000000LL + (dqTimeEnd.tv_usec - dqTimeStart.tv_usec)) / 1000000.0;

	struct timeval vetTimeStart;
	struct timeval vetTimeEnd;
	gettimeofday(&vetTimeStart, NULL);
	vetMergeSort(left, right);
	gettimeofday(&vetTimeEnd, NULL);
	double vetTime = static_cast<double>((vetTimeEnd.tv_sec - vetTimeStart.tv_sec) * 1000000LL + (vetTimeEnd.tv_usec - vetTimeStart.tv_usec)) / 1000000.0;

	std::cout << "After:  ";
	for (int i = 0; i < static_cast<int>(this->vet.size()); i++)
		std::cout << this->vet[i] << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << std::fixed << std::setprecision(10) << this->vet.size() << " elements with std::vector : " << vetTime << " us" << std::endl;
	std::cout << "Time to process a range of " << std::fixed << std::setprecision(10) << this->vet.size() << " elements with std::deque : "  << dqTime << " us" << std::endl;
}

void	PmergeMe::vetMergeSort(int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	vetMergeSort(left, mid);
	vetMergeSort(mid + 1, right);
	vetMerge(left, mid, right);
}

void	PmergeMe::vetMerge(int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = this->vet[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = this->vet[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			this->vet[k] = L[i];
			i++;
		}
		else
		{
			this->vet[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		this->vet[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		this->vet[k] = R[j];
		j++;
		k++;
	}
	
}



void	PmergeMe::dqMergeSort(int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	dqMergeSort(left, mid);
	dqMergeSort(mid + 1, right);
	dqMerge(left, mid, right);
}

void	PmergeMe::dqMerge(int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> L(n1), R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = this->dq[left + i];
	for (int j = 0; j < n2; j++)
		R[j] = this->dq[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < n1 && j < n2) 
	{
		if (L[i] <= R[j]) 
		{
			this->dq[k] = L[i];
			i++;
		}
		else
		{
			this->dq[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1)
	{
		this->dq[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		this->dq[k] = R[j];
		j++;
		k++;
	}
	
}
