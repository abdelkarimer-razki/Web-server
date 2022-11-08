/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:21:21 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/08 14:07:30 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTES_HPP
#define ROUTES_HPP
#include "webserv.hpp"

class webserv;

class routes
{
	private:
		std::string path;
		std::string file;
	public:
		routes();
		~routes();
		void	set_path(std::string path);
		void	set_file(std::string file);
};

#endif