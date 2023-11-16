/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:55:26 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/11/16 11:49:49 by samiyazubai      ###   ########.fr       */
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

void Bureaucrat::signForm(AForm &form)
{
    try
    {
    	form.beSigned(*this);
		std::cout  << Name << " signed " << form.get_name() << std::endl;
    }
    catch(const std::exception &error)
    {
		std::cout << Name << " couldn't sign " << form.get_name() << " because " << error.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const & form) {
	try
	{
		form.execute(*this);
		std::cout  << Name << " executed " << form.get_name() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Could not execute form" << " because " << e.what() << std::endl;
	}
}