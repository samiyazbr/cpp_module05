#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "AForm.hpp"
# include <fstream>

#define ASCII_TREE \
"               ^\n"\
"              ^^^\n"\
"             ^^^^^\n"\
"            ^^^^^^^\n"\
"           ^^^^^^^^^\n"\
"          ^^^^^^^^^^^\n"\
"         ^^^^^^^^^^^^^\n"\
"        ^^^^^^^^^^^^^^^\n"\
"       ^^^^^^^^^^^^^^^^^\n"\
"              |||        \n"\
"              |||         "

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		virtual ~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
};
# endif