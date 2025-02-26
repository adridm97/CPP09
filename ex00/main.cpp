/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:50:57 by adrian            #+#    #+#             */
/*   Updated: 2025/02/24 11:59:19 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid arguments. Usage: ./btc <input_file>" << std::endl;
        return 1;
    }
    BitcoinExchange btc("data.csv");
    btc.processInputFile(argv[1]);
    return 0;
}