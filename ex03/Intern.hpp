#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *(Intern::*_makeForm[3])(std::string target);
		AForm *makeShrubberyCreationForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		AForm *makePresidentialPardonForm(std::string target);
	public:
		Intern();
		Intern(const Intern &copy);
		Intern &operator=(const Intern &rhs);
		~Intern();

		AForm *makeForm(std::string const &formName, std::string const &target);
};

#endif