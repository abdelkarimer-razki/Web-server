/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:15 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/08 14:08:47 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/webserv.hpp"

webserv::webserv()
{
	this->route = new routes[2];
	route[1].set_path("/");
	route[1].set_file("website/index.html");
}

webserv::~webserv()
{
}

void webserv::set_path(std::string path)
{
	this->path = path;
}


void webserv::set_port(int port)
{
	this->port = port;
}

void webserv::set_server_name(std::string server_name)
{
	this->server_name = server_name;
}

void webserv::set_error_page(std::string error_page)
{
	this->error_page = error_page;
}

void webserv::set_client_body_size(int client_body_size)
{
	this->client_body_size = client_body_size;
}

void	webserv::port_accessed(int fd)
{
	char buffer[30000];
	read(fd, buffer, 30000);
	std::string sbuffer = buffer;
	this->path = sbuffer.substr(sbuffer.find("/"), sbuffer.substr(sbuffer.find("/"), sbuffer.length()).find(" "));
}

void	webserv::get_page(int c_fd ,std::string path)
{
	std::string http = "HTTP/1.1 200 OK\n";
	std::string t_content = "Content-Type: text/html\n";
	std::string l_content = "Content-Length:";
	std::string text = read_text(path);

	l_content += std::to_string(text.length()) + "\n\n";
	std::string everything = http + t_content + l_content + text;
	write(c_fd , everything.c_str() , everything.length());
}

std::string webserv::read_text(std::string path)
{
	std::string text;
	std::string buffer;
	std::ifstream	fn(path);

	while(getline(fn, buffer))
		text += buffer;
	return (text);
}

std::string webserv::get_path()
{
	return (this->path);
}