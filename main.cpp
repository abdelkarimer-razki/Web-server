/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:10:56 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/06 08:15:10 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include <iostream>

std::string read_text(char *filename)
{
	std::string text;
	std::string buffer;
	std::ifstream	fn(filename);

	while(getline(fn, buffer))
		text += buffer;
	return (text);
}

int main(int arc, char **arv)
{
	int s_fd, ns_fd, valread;
	std::string http = "HTTP/1.1 200 OK\n";
	std::string t_content = "Content-Type: text/html\n";
	std::string l_content = "Content-Length:";
	std::string text;
	if (arc == 2)
		text = read_text(arv[1]);
	else
	{
		std::cout << "Add file to the server\n";
		return (1);
	}
	l_content += std::to_string(text.length()) + "\n\n";
	std::string everything = http + t_content + l_content + text;
	struct sockaddr_in address;
	int l_address = sizeof(address);

	s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s_fd < 0)
		return (1);

	memset((char *)&address, 0, sizeof(address)); 
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	if (bind(s_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("unavailable port");
		return (1);
	}
	if (listen(s_fd, 10) < 0)
		return (1);
	int i = -1;
	while (1)
	{
		if (++i == 0)
			std::cout << "listening on port : " << PORT << std::endl;
		//char buffer[30000];
		ns_fd = accept(s_fd, (struct sockaddr *)&address, (socklen_t*)&l_address);
		if (ns_fd < 0)
			return (1);
		/*read(ns_fd, buffer, 30000);
		std::cout << buffer;
		std::cout << "----------------------------\n";*/
        write(ns_fd , everything.c_str() , everything.length());
	}
}
