/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfiorini <sfiorini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:57:30 by sfiorini          #+#    #+#             */
/*   Updated: 2025/08/10 12:22:16 by sfiorini         ###   ########.fr       */
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
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		if (str[i] != ' ')
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				this->dq.push_back(str[i] - 48);
				this->lis.push_back(str[i] - 48);
			}
			else
				throw	PmergeMe::ErrorProgram();
		}
	}
}

void	PmergeMe::sort(const std::string &str)
{
	std::cout << "Before: " << str << std::endl;
	
	// int	dqTimeStart = 0;
	// int	lisTimeStart = 0;
	// int	dqTimeEnd = 0;
	// int	lisTimeEnd = 0;
	
	int	left = 0;
	int	right = this->dq.size() - 1;

	struct timeval dqTimeStart;
	struct timeval dqTimeEnd;
	gettimeofday(&dqTimeStart, NULL);
	dqMergeSort(left, right);
	gettimeofday(&dqTimeEnd, NULL);
	double dqTime = static_cast<double>((dqTimeEnd.tv_sec - dqTimeStart.tv_sec) * 1000000LL + (dqTimeEnd.tv_usec - dqTimeStart.tv_usec)) / 1000000.0;

	struct timeval lisTimeStart;
	struct timeval lisTimeEnd;
	gettimeofday(&lisTimeStart, NULL);
	// lisMergeSort(left, right);
	this->lis.sort();
	gettimeofday(&lisTimeEnd, NULL);
	double lisTime = static_cast<double>((lisTimeEnd.tv_sec - lisTimeStart.tv_sec) * 1000000LL + (lisTimeEnd.tv_usec - lisTimeStart.tv_usec)) / 1000000.0;

	std::cout << "Tempo trascorso in millisecondi: " << std::fixed << std::setprecision(10) << dqTime << std::endl;
	std::cout << "Tempo trascorso in millisecondi: " << std::fixed << std::setprecision(10) << lisTime << std::endl;
	
	std::cout << "After:  ";
	
	for (int i = 0; i < static_cast<int>(dq.size()); i++)
		std::cout << dq[i] << " ";
	std::cout << std::endl;
	
	for (std::list<int>::iterator it = this->lis.begin(); it != this->lis.end(); ++it)
	{
		std::cout << *it << " ";
	}
	// lisMergeSort(left, right);
	
	// std::cout << "Time to process a range of " << this->dq.size() << " with std::dque : " << dqTime;
	// std::cout << "Time to process a range of " << this->dq.size() << " with std::list : " << lisTime;
}

void	PmergeMe::lisMergeSort(int left, int right)
{
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	dqMergeSort(left, mid);
	dqMergeSort(mid + 1, right);
	dqMerge(left, mid, right);
}

// void	PmergeMe::lisMerge(int left, int mid, int right)
// {
// 	int n1 = mid - left + 1;
// 	int n2 = right - mid;

// 	std::list<int> L(n1), R(n2);

// 	for (int i = 0; i < n1; i++)
// 		L[i] = this->lis[left + i];
// 	for (int j = 0; j < n2; j++)
// 		R[j] = this->lis[mid + 1 + j];

// 	int i = 0, j = 0;
// 	int k = left;

// 	while (i < n1 && j < n2) 
// 	{
// 		if (L[i] <= R[j]) 
// 		{
// 			this->lis[k] = L[i];
// 			i++;
// 		}
// 		else
// 		{
// 			this->lis[k] = R[j];
// 			j++;
// 		}
// 		k++;
// 	}
	
// 	while (i < n1)
// 	{
// 		this->lis[k] = L[i];
// 		i++;
// 		k++;
// 	}

// 	while (j < n2)
// 	{
// 		this->lis[k] = R[j];
// 		j++;
// 		k++;
// 	}
	
// }



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
