/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:10:57 by adrian            #+#    #+#             */
/*   Updated: 2025/02/25 19:11:24 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Error: invalid arguments." << std::endl;
        return 1;
    }
    PmergeMe sorter;
    sorter.loadData(argc, argv);
    double startVector = sorter.getCurrentTime();
    sorter.sortVector();
    double endVector = sorter.getCurrentTime();
    double startDeque = sorter.getCurrentTime();
    sorter.sortDeque();
    double endDeque = sorter.getCurrentTime();
    sorter.printResult(endVector - startVector, endDeque - startDeque);
    return 0;
}