/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:43:04 by adrian            #+#    #+#             */
/*   Updated: 2025/02/25 16:45:37 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: invalid arguments. Usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.evaluateRPN(argv[1]);
    return 0;
}