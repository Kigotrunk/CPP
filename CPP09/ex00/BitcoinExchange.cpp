/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 14:06:29 by marvin            #+#    #+#             */
/*   Updated: 2024/01/04 14:06:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::map<std::string, double> filecsv(std::string name)
{
	std::map<std::string, double> value;
	std::string stock;
	std::string split;


	std::ifstream file(name.c_str());
	if (file.is_open())
	{
		std::getline(file, stock);
		while (std::getline(file, stock))
		{
			Bitcoin coin;
			std::istringstream splitline(stock);
			std::getline(splitline, split, ',');
			coin.date = split;
			std::getline(splitline, split);
			std::stringstream split_value(split);
			split_value >> coin.value;
			value[coin.date] = coin.value;
		}
		file.close();
	}
	else
		std::cout << "invalid file" << std::endl;
	return value;
}

int	size_file(std::string &name)
{
	std::ifstream file(name.c_str());
	std::string line;
	int	x = 0;

	if (file.is_open())
	{
		while (std::getline(file, line))
			x++;
		file.close();
	}
	return x;
}

Bitcoin *filetxt(std::string &name)
{
	std::ifstream file(name.c_str());
	std::string line;
	std::string date;
	double		quantity;
	Bitcoin *info = NULL;
	int x = 0;

	if (file.is_open())
	{
		info = new Bitcoin[size_file(name) - 1];
		std::getline(file, line);
		while (std::getline(file, line))
		{
			std::istringstream split(line);
			if (std::getline(split, date, '|'))
			{
				info[x].date = date;
				if (split >> quantity)
				{
					info[x].value = quantity;
					info[x].present_value = true;
				}
				else
				{
					info[x].value = -19;
					info[x].present_value = false;
				}
			}
			else
				info[x].date = line;
			/*if(info[x].value != -19)
				std::cout << info[x].date << " | " << info[x].value << std::endl;*/
			x++;
		}
		file.close();
	}
	else
	{
		std::cout << "Error: could not open file." << std::endl;
		return NULL;
	}
	return info;
}

void fusion(std::map<std::string, double>& filecsv, Bitcoin *filetxt, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        bool date_found = false;
        std::string last_date = "";
        double last_value = 0.0;

        filetxt[i].date = trim(filetxt[i].date);
        if (filetxt[i].value == -19 && filetxt[i].present_value == false) {
            std::cout << "Error: bad input => " << filetxt[i].date << std::endl;
            continue;
        }
        if (filetxt[i].value < 0 && filetxt[i].present_value == true) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (filetxt[i].value > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }

        for (std::map<std::string, double>::iterator it = filecsv.begin(); it != filecsv.end(); ++it) {
            std::string map_date = trim(it->first);

            if (filetxt[i].date == map_date) {
                std::cout << filetxt[i].date << " => " << filetxt[i].value << " = " << it->second * filetxt[i].value << std::endl;
                date_found = true;
                break;
            } else if (filetxt[i].date < map_date) {
                if (!last_date.empty()) {
                    std::cout << filetxt[i].date << " => " << filetxt[i].value << " = " << last_value * filetxt[i].value << std::endl;
                    date_found = true;
                } else {
                    std::cout << "Error: bad input => " << filetxt[i].date << std::endl;
                }
                break;
            }

            last_date = map_date;
            last_value = it->second;
        }

        if (!date_found && !last_date.empty()) {
            std::cout << filetxt[i].date << " => " << filetxt[i].value << " = " << last_value * filetxt[i].value << std::endl;
        } else if (!date_found) {
            std::cout << "Error: date not found => " << filetxt[i].date << std::endl;
        }
    }
}


std::string trim(const std::string& str) 
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}



void displayBitcoinData(Bitcoin* data, int size) 
{
    for (int i = 0; i < size - 1; i++) {
		if (data[i].value >= 0)
		{
        	std::cout  << data[i].date << std::endl;
		}
		else if (data[i].value == -19 && data[i].present_value == false)
		{
			std::cout <<  data[i].date << std::endl;
		}
		else
		{
			std::cout << data[i].date << std::endl;
		}
    }
}