/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:55:26 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/23 17:55:36 by samiyazubai      ###   ########.fr       */
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

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & obj) 
{
    if (obj.Grade < MAX_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (obj.Grade > MIN_GRADE)
        throw  Bureaucrat::GradeTooLowException();
    this->Grade = obj.Grade;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj) 
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
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
    return "Grade Too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
    return "Grade too low";
}