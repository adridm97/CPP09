/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:35:00 by adrian            #+#    #+#             */
/*   Updated: 2025/02/25 19:10:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}
PmergeMe::PmergeMe(const PmergeMe &other) : vectorData(other.vectorData), dequeData(other.dequeData){}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vectorData = other.vectorData;
        dequeData = other.dequeData;
    }
    return *this;
}
PmergeMe::~PmergeMe(){}
double PmergeMe::getCurrentTime()
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return(time.tv_sec * 1000000.0 + time.tv_usec);
}
void PmergeMe::loadData(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        char *end;
        long num = std::strtol(argv[i], &end, 10);
        if (*end != '\0' || num <= 0)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        vectorData.push_back(num);
        dequeData.push_back(num);
    }
}
void mergeInsertionSortVector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return ;
    std::vector<int> left(v.begin(), v.begin() + v.size() / 2);
    std::vector<int> right(v.begin() + v.size() / 2, v.end());

    mergeInsertionSortVector(left);
    mergeInsertionSortVector(right);
    v.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(v));
}
void PmergeMe::sortVector()
{
    mergeInsertionSortVector(vectorData);
}
void mergeInsertionSortDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return ;
    std::deque<int> left(d.begin(), d.begin() + d.size() / 2);
    std::deque<int> right(d.begin() + d.size() / 2, d.end());
    mergeInsertionSortDeque(left);
    mergeInsertionSortDeque(right);
    d.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(d));
}
void PmergeMe::sortDeque()
{
    mergeInsertionSortDeque(dequeData);
}
void PmergeMe::printResult(double vTime, double dTime)
{
    std::cout << "Before: ";
    for(size_t i = 0; i < vectorData.size(); i++)
        std::cout << vectorData[i] << " ";
    std::cout << std::endl;
    std::cout << "After: ";
    for(size_t i = 0; i < vectorData.size(); i++)
        std::cout << vectorData[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process " << vectorData.size() << " elements with std::vector: " << vTime << " us" << std::endl;
    std::cout << "Time to process " << dequeData.size() << " elements with std::deque: " << dTime << " us" << std::endl;
}