/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:10:58 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/09 08:33:56 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEBSERV_HPP
#define WEBSERV_HPP
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "routes.hpp"
#define PORT 8000

class routes;

class webserv
{
	private:
		int port;
		std::string server_name;
		std::string error_page;
		int n_routes;
		int response_code;
		int client_body_size;
		std::string path;
		routes *route;
	public:
		webserv();
		~webserv();
		void	set_port(int port);
		void	set_server_name(std::string server_names);
		void	set_error_page(std::string error_page);
		void	set_client_body_size(int client_body_size);
		void	set_path(std::string path);
		std::string get_path();
		int		get_response_code();
		void	port_accessed(int fd);
		std::string search_file(std::string path);
		void	get_page(int c_fd ,std::string path);
		std::string read_text(std::string path);
};

#endif
