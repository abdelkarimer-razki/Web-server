/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:15 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/13 14:45:02 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/server.hpp"

server::server()
{
	
}

server::~server()
{}

void server::split_locations()
{
	int x = 0;
	int y = 0;
	int a = 0;
    for (int i = 0; i < cont_server.size(); i++) 
    {
        if (cont_server[i].length() > cont_server[i].find("location")) // search location inside server content
        {
            a++;
            x = i;
        }
        else if (cont_server[i].length() > cont_server[i].find("}")) // search } inside server content
        {
            a++;
            y = i;
        }
        if (a == 2) // when he find the location and } hes gonna create a new location a store data
        {
            a = 0;
            location tmp;
            for (int j = x; j <= y; j++)
                tmp.cont_location.push_back(cont_server[j]);
            locations.push_back(tmp);
            tmp.cont_location.clear();
        }
    }
}