/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:10:56 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/07 10:36:28 by aer-razk         ###   ########.fr       */
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

void	user_request(int fd)
{
	char buffer[30000];
	read(fd, buffer, 30000);
	std::cout << buffer << std::endl << "------------------------------\n";
}

int main(int arc, char **arv)
{
	int s_fd, c_fd;
	std::string http = "HTTP/1.1 200 OK\n";
	std::string t_content = "Content-Type: text/html\n";
	std::string l_content = "Content-Length:";
	std::string text;
	fd_set	server_fds, ready_fds;

	//READING HTML PAGE AND SETTING IT IN THE HEADER
	if (arc == 2)
		text = read_text(arv[1]);
	else
	{
		std::cerr << "read_text : Add file to the server\n";
		return (1);
	}
	l_content += std::to_string(text.length()) + "\n\n";
	std::string everything = http + t_content + l_content + text;
	struct sockaddr_in address;
	int l_address = sizeof(address);
	//INITILATION A INTERNET SOCKET WITH 'AF_INET' DOMAINE THAT WILL USE TCP PROTOCOL 'SOCK_STREAM'
	s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s_fd < 0)
	{
		perror("socket");
		return (1);
	}
	//SETTING PORT AND IPADDRESS IN SOCKADDR_IN STRUCT
	memset((char *)&address, 0, sizeof(address)); 
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);

	//BINDING THE ADDRESS STRUCT WITH THE SOCKET
	if (bind(s_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
	{
		perror("bind");
		return (1);
	}
	//MARKING SOCKET AS PASSIVE 'ABLE TO ACCEPTE INCOMING CONNECTIONS' AND MAKING A QUEUE OF CONNECTION REQUESTS TO BE EXTRACTED USING ACCEPT
	if (listen(s_fd, 10) < 0)
	{
		perror("listen");
		return (1);
	}
	//SETTING FD_SET
	FD_ZERO(&server_fds);
	FD_SET(s_fd, &server_fds);
	while (1)
	{
		//SAVING THE FD SET THAT WILL BE SENT TO SELECT CUZ SELECT IS DISTRUCTIVE
		ready_fds = server_fds;
		if (select(FD_SETSIZE, &ready_fds, NULL, NULL, NULL) < 0)
		{
			perror("select");
			return (1);
		}
		std::cout << "test test\n";
		for (int i = 0; i < FD_SETSIZE; i++)
		{
			if (FD_ISSET(i, &ready_fds))
			{
				if (i == s_fd)
				{
					std::cout << i << "\n";
					c_fd = accept(s_fd, (struct sockaddr *)&address, (socklen_t*)&l_address);
					if (c_fd < 0)
					{
						perror("accept");
						return (1);
					}
					//FD_SET(c_fd, &ready_fds);
					FD_SET(c_fd, &server_fds);
				}
				else
				{
					std::cout << i << "\n";
					user_request(c_fd);
					write(c_fd , everything.c_str() , everything.length());
					FD_CLR(i, &server_fds);
				}
			}
		}
	}
}
