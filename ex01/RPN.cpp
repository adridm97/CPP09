/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:08:02 by adrian            #+#    #+#             */
/*   Updated: 2025/02/25 16:39:49 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) : stack(other.stack) {}
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        stack = other.stack;
    return *this;
}
RPN::~RPN() {}
void RPN::evaluateRPN(const std::string &expression)
{
    std::istringstream iss(expression);
    std::string token;
    while(iss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
            stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return ;
            }
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();
            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(a - b);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return ;
                }
                stack.push(a / b);
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return ;
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::cout << stack.top() << std::endl;
}