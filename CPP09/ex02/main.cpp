/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:40:39 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 23:40:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		std::cout << "you need to provide at least one argument" << std::endl;
		return 1;
	}
	std::vector<int> vector;
	std::list<int> list;
	for(int i = 1; i < argc; i++)
	{
		int value = std::atoi(argv[i]);
		vector.push_back(value);
		list.push_back(value);
	}
	std::clock_t time_vector = std::clock();
	std::vector<int> vectorsort = algosort(vector);
	std::clock_t time_final_vector = std::clock() - time_vector;
	std::clock_t time_list = std::clock();
	std::list<int> listsort = algosortlist(list);
	std::clock_t time_final_list = std::clock() - time_list;

}