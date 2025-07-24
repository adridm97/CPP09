/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:02:37 by adrian            #+#    #+#             */
/*   Updated: 2025/07/23 16:39:31 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <cstdlib>
#include <climits>
#include <sys/time.h>

class PmergeMe
{
public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();
    void loadData(int argc, char **argv);
    void printBefore() const;
    void printAfter() const;
    void sortVector();
    void sortDeque();
    void printTimes(double vTime, double dTime) const;
    double getCurrentTime() const;
    const std::vector<int>& getVectorSorted() const;
    const std::deque<int>& getDequeSorted() const;
    
private:
    std::vector<int> vectorData;
    std::vector<int> vectorSorted;
    std::deque<int> dequeData;
    std::deque<int> dequeSorted;

    // Ford-Johnson:
    void fordJohnsonSortVector(std::vector<int> &v);
    void fordJohnsonSortDeque(std::deque<int> &d);

    size_t jacobsthal(size_t n) const;

};
