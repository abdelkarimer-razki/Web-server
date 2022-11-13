/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:21 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/12 12:27:41 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTES_HPP
#define ROUTES_HPP
#include "includes.hpp"

class location
{
	private:
		std::string	root;
		std::string	index;
		int			response_code;
		std::string	method;
		bool		autoindex;
		std::string	cgi_path;
		std::string	cgi_extension;
		
	public:
		//orthodox canonical class methods
		location();
		~location();
		//getters
		std::string	get_root(void);
		std::string	get_index(void);
		int			get_response_code();
		std::string	get_method();
		bool		get_autoindex();
		std::string	get_cgi_path();
		std::string	get_cgi_extension();
		//setters
		void	set_root(std::string root);
		void	set_index(std::string index);
		void	set_response_code(int response_code);
		void	set_method(std::string method);
		void	set_autoindex(bool autoindex);
		void	set_cgi_path(std::string cgi_path);
		void	set_cgi_extension(std::string cgi_extension);
};

#endif