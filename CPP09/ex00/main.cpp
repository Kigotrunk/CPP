/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:35:02 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 14:35:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void displayMap(const std::map<std::string, double>& myMap) {
    std::map<std::string, double>::const_iterator it;
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << std::endl;
    }
}


int main(int argc, char **argv) 
{
    if (argc == 1 || argc > 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::string file_name = argv[1];
    std::string file_csv = "data.csv";
    Bitcoin *file_txt_map;
    std::map<std::string, double> file_csv_map = filecsv(file_csv);
    file_txt_map = filetxt(file_name);
    if (!file_txt_map)
        return 1;
    size_t size = size_file(file_name);
    fusion(file_csv_map, file_txt_map, size - 1);
    
    return 0;
}