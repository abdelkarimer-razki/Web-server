/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:10:58 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/13 14:51:29 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP
#include "includes.hpp"
#include "location.hpp"
#define PORT 8000

class location;

class server {
	private:
		int						port;
		std::string				server_name;
		std::string				error_page;
		std::string				root;
		bool					autoindex;
		int						client_body_limit;
		std::string				path;
	public:
		std::vector<location>	locations;
		std::vector<std::string>	cont_server;
		//orthodox canonical class methods
		server();
		~server();
		//getters
		int						get_port();
		std::string				get_server_name();
		std::string				get_error_page();
		std::string				get_root();
		bool					get_autoindex();
		int						get_client_body_limit();
		std::string				get_path();
		std::vector<location>	get_locations();
		//setters
		void	set_port(int port);
		void	set_server_name(std::string server_names);
		void	set_root(std::string root);
		void	set_autoindex(bool autoindex);
		void	set_client_body_limit(std::string cbl);
		//methods
		
		bool		check_brackets(std::string config);
		void		port_accessed(int fd);
		std::string	search_file(std::string path);
		void		get_page(int c_fd ,std::string path);
		std::string	read_text(std::string path);
		//parsers
		void	split_locations(); // split locations and store it inside locations
};

#endif
