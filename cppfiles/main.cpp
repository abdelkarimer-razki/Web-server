/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:10:56 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/10 11:39:42 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/webserv.hpp"
#include "../headers/routes.hpp"


void	port_accessed(int fd)
{
	char buffer[30000];
	read(fd, buffer, 30000);
	std::string sbuffer = buffer;
	std::cout << sbuffer.substr(sbuffer.find("/"), sbuffer.substr(sbuffer.find("/"), sbuffer.length()).find(" ")) << std::endl;
}

int main(int arc, char **arv)
{
	std::time_t end_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::cout << "DO3AFAE 0.0.0 Development Server started at " << std::ctime(&end_time);
	int s_fd, c_fd;
	webserv doafae;
	fd_set	server_fds, ready_fds;

	struct sockaddr_in s_address;
	int sl_address = sizeof(s_address);
	//INITILATION A INTERNET SOCKET WITH 'AF_INET' DOMAINE THAT WILL USE TCP PROTOCOL 'SOCK_STREAM'
	s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s_fd < 0)
	{
		perror("socket");
		return (1);
	}
	//SETTING PORT AND IPADDRESS IN SOCKADDR_IN STRUCT
	memset((char *)&s_address, 0, sizeof(s_address)); 
	s_address.sin_family = AF_INET;
	s_address.sin_addr.s_addr = htonl(INADDR_ANY);
	s_address.sin_port = htons(PORT);

	//BINDING THE ADDRESS STRUCT WITH THE SOCKET
	if (bind(s_fd, (struct sockaddr *)&s_address, sizeof(s_address)) < 0)
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
	std::cout << "\033[1;32mlistening on port : " << PORT << "\033[0m\n" ;
	while (1)
	{
		//SAVING THE FD SET THAT WILL BE SENT TO SELECT CUZ SELECT IS DISTRUCTIVE
		ready_fds = server_fds;
		if (select(FD_SETSIZE, &ready_fds, NULL, NULL, NULL) < 0)
		{
			perror("select");
			return (1);
		}
		for (int i = 0; i < FD_SETSIZE; i++)
		{
			if (FD_ISSET(i, &ready_fds))
			{
				if (i == s_fd)
				{
					std::cout << "\033[1;32mserver : connection request\033[0m\n" ;
					c_fd = accept(s_fd, (struct sockaddr *)&s_address, (socklen_t*)&sl_address);
					if (c_fd < 0)
					{
						perror("accept");
						return (1);
					}
					FD_SET(c_fd, &server_fds);
				}
				else
				{
					doafae.port_accessed(c_fd);
					doafae.get_page(c_fd, doafae.get_path());
					std::cout << "\033[1;33mserver [" << doafae.get_response_code() << "]: " << doafae.get_path() << "\033[0m\n" ;
					FD_CLR(i, &server_fds);
					std::cout << "\033[1;32mserver : connection closed\033[0m\n";
				}
			}
		}
	}
}
