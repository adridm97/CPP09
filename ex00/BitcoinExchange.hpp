/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:24:55 by adrian            #+#    #+#             */
/*   Updated: 2025/02/20 17:32:58 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> btcPrices;
    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &csvFile);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        void processInputFile(const std::string &inputFile);
        double getBitcoinPrice(const std::string &date);
        bool isValidDate(const std::string &date);
        bool isValidValue(const std::string &value);
};