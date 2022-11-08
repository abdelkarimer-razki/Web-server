/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routes.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aer-razk <aer-razk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:48:36 by aer-razk          #+#    #+#             */
/*   Updated: 2022/11/08 17:02:41 by aer-razk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/routes.hpp"

routes::routes()
{
}

routes::~routes()
{
}

void	routes::set_path(std::string path)
{
	this->path = path;
}

void	routes::set_file(std::string file)
{
	this->file = file;
}

std::string routes::get_path(void)
{
	return (this->path);
}

std::string routes::get_file(void)
{
	return (this->file);
}
