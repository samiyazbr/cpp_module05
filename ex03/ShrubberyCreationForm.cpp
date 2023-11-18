# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145, 137), _target("none")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):AForm(copy), _target(copy._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm assignation operator called" << std::endl;
	if (this != &rhs)
	{
		_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const{
    if (get_signed() == true && executor.getGrade() <= get_gradeToExecute())
	{
		std::ofstream file;
		file.open((_target + "_shrubbery").c_str());
		file << ASCII_TREE << std::endl;
		file.close();
	}
	else if (executor.getGrade() <= get_gradeToExecute())
	{
		throw GradeTooLowException();
	}
	else
	{
		throw std::out_of_range("Bureaucrat cannot execute this form");
	}
}