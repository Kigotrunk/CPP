/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:03:13 by marvin            #+#    #+#             */
/*   Updated: 2024/05/21 19:03:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stack>

class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
		void rpn_result(std::string str);
	private:
		std::stack<double> _stack;
		double _result;
};