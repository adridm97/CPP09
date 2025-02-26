/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:33:26 by adrian            #+#    #+#             */
/*   Updated: 2025/02/24 18:35:00 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const std::string &csvFile)
{
    std::ifstream file(csvFile);
    if (!file)
    {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }
    std::string line;
    std::string date;
    double price;
    while(std::getline(file, line))
    {
        std::istringstream ss(line);
        if (std::getline(ss, date, ',') && (ss >> price))
            btcPrices[date] = price;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : btcPrices(other.btcPrices) {}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        btcPrices = other.btcPrices;
    return(*this);
}
BitcoinExchange::~BitcoinExchange(){}
double BitcoinExchange::getBitcoinPrice(const std::string &date)
{
    std::map<std::string, double>::iterator it = btcPrices.lower_bound(date);
    if (it == btcPrices.end())
        return((--it)->second);
    if (it->first != date && it != btcPrices.begin())
        --it;
    return(it->second);
}
bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return(false);
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());
    return(year >= 2009 && month >= 1 && month <= 12 && day >= 1 && day <= 31);
}
bool BitcoinExchange::isValidValue(const std::string &value)
{
    double val = atof(value.c_str());
    return(val >= 0 && val <= 1000);
}
void BitcoinExchange::processInputFile(const std::string &inputFile)
{
    std::ifstream file(inputFile);
    if (!file)
    {   
        std::cerr << "Error: could not open file" << std::endl;
        return ;
    }
    std::string line, date, value;
    std::getline(file, line);
    while(std::getline(file, line))
    {
        if (line.empty())
            continue ;
        std::istringstream ss(line);
        if (!std::getline(ss, date, '|') || (!std::getline(ss, value)))
        {
            std::cerr << "Error: Bad input => " << line << std::endl;
            continue ;
        }
        if (date.empty() || value.empty())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        value.erase(0, value.find_first_not_of(" \t"));
        value.erase(value.find_last_not_of(" \t") + 1);
        if (!isValidDate(date))
        {
            std::cerr << "Error: Bad input => " << date << std::endl;
            continue ;
        }
        if (!isValidValue(value))
        {
            if (atof(value.c_str()) < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: too large a number." << std::endl;
            continue ;
        }
        double price = getBitcoinPrice(date);
        double amount = atof(value.c_str());
        std::cout << date << " => " << amount << " = " << (amount * price) << std::endl;
    }
}
