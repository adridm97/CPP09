/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:02:37 by adrian            #+#    #+#             */
/*   Updated: 2025/07/19 16:07:52 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <sys/time.h>
#include <algorithm>

class PmergeMe
{
    private:
        std::vector<int> vectorData;
        std::deque<int> dequeData;
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe &other);
        ~PmergeMe();
        void loadData(int argc, char **argv);
        void sortVector();
        void sortDeque();
        double getCurrentTime();
        void printResult(double vectorTime, double dequeTime);
};
