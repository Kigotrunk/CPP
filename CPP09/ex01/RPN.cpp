/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:03:08 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 19:03:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


RPN::RPN() : _result(0) {}

RPN::~RPN() {}

RPN::RPN(const RPN &obj) {
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj) {
	if (this != &obj) {
		_stack = obj._stack;
		_result = obj._result;
	}
	return *this;
}

void RPN::rpn_result(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
		{
			this->_stack.push(str[i] - '0');
		}
		else if (str[i] == '-')
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error : invalid operator, you need at least 2 numbers before an operator" << std::endl;
				return ;
			}
			double second = this->_stack.top();
			this->_stack.pop();
			double first = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(first - second);
		}
		else if (str[i] == '+')
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error : invalid operator, you need at least 2 numbers before an operator" << std::endl;
				return ;
			}
			double second = this->_stack.top();
			this->_stack.pop();
			double first = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(first + second);
		}
		else if (str[i] == '*')
		{
			if (_stack.size() < 2)
			{
				std::cout << "Error : invalid operator, you need at least 2 numbers before an operator" << std::endl;
				return ;
			}
			double second = this->_stack.top();
			this->_stack.pop();
			double first = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(first * second);
		}
		else if (str[i] == '/')
		{
			if (this->_stack.size() < 2)
			{
				std::cout << "Error : invalid operator, you need at least 2 numbers before an operator" << std::endl;
				return ;
			}
			double second = this->_stack.top();
			this->_stack.pop();
			double first = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(first / second);
		}
	}
	if (this->_stack.size() > 1)
		std::cout << "Error : invalid calcul" << std::endl;
	else
		std::cout << this->_stack.top() << std::endl;
	return ;
}