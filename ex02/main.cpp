/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 19:10:57 by adrian            #+#    #+#             */
/*   Updated: 2025/07/23 16:40:42 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;

    sorter.loadData(argc, argv);

    sorter.printBefore();

    // Vector
    double startVec = sorter.getCurrentTime();
    sorter.sortVector();
    double endVec = sorter.getCurrentTime();
    double vecTime = endVec - startVec;

    sorter.printAfter();

    // Deque
    double startDeq = sorter.getCurrentTime();
    sorter.sortDeque();
    double endDeq = sorter.getCurrentTime();
    double deqTime = endDeq - startDeq;

    // Output con decimales al estilo subject (microsegundos pero en decimal)
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << sorter.getVectorSorted().size()
              << " elements with std::vector : " << vecTime / 1000000.0 << " us" << std::endl;
    std::cout << "Time to process a range of " << sorter.getDequeSorted().size()
              << " elements with std::deque : " << deqTime / 1000000.0 << " us" << std::endl;

    return 0;
}
