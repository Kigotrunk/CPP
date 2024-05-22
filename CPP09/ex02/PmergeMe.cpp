/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 23:28:37 by marvin            #+#    #+#             */
/*   Updated: 2024/05/22 23:28:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void insertOptivector(std::vector<int> &listsort, int value)
{
	std::vector<int>::iterator index = std::lower_bound(listsort.begin(), listsort.end(), value);
	listsort.insert(index, value);
}

void insertOptilist(std::list<int> &listsort, int value)
{
	std::list<int>::iterator index = std::lower_bound(listsort.begin(), listsort.end(), value);
	listsort.insert(index, value);
}

std::vector<int> algosort(std::vector<int>& vector)
{
	if(vector.size() < 2)
	{
		return vector;
	}
	std::vector<int> listsort;
	listsort.push_back(std::min(vector[0], vector[1]));
	listsort.push_back(std::max(vector[0], vector[1]));
	for(size_t i = 2; i < vector.size(); i++)
	{
		insertOptivector(listsort, vector[i]);
	}
	return listsort;
}

std::list<int> algosortlist(std::list<int>& list)
{
	if(list.size() < 2)
	{
		return list;
	}
	std::list<int> listsort;
	std::list<int>::iterator it = list.begin();
	listsort.push_back(std::min(*it, *(++it)));
	listsort.push_back(std::max(*it, *(--it)));
	for(it = ++it; it != list.end(); it++)
	{
		insertOptilist(listsort, *it);
	}
	return listsort;
}

