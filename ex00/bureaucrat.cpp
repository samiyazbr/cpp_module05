/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:55:26 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/24 16:04:22 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():Name("none") 
{
    this->Grade = MIN_GRADE;
}

Bureaucrat::Bureaucrat(std::string Name, int Grade):Name(Name) 
{
    if (Grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (Grade > MIN_GRADE)
        throw  Bureaucrat::GradeTooLowException();
    this->Grade = Grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) 
{
    *this = src;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs) 
{
    if (rhs.Grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (rhs.Grade > MIN_GRADE)
        throw  Bureaucrat::GradeTooLowException();
    this->Grade = rhs.Grade;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const &bureaucrat) 
{
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return o;
}

std::string Bureaucrat::getName() const 
{
    return this->Name;
}

int Bureaucrat::getGrade() const 
{
    return this->Grade;
}

void Bureaucrat::raise_Grade() 
{
    this->Grade--;
    if (this->Grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::lower_Grade() 
{
    this->Grade++;
    if (this->Grade > MIN_GRADE)
        throw  Bureaucrat::GradeTooLowException();
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
    return "Bureaucrat's Grade is Too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Bureaucrat's Grade is too low";
}