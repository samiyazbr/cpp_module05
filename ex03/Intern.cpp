# include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
	this->_makeForm[0] = &Intern::makeShrubberyCreationForm;
	this->_makeForm[1] = &Intern::makeRobotomyRequestForm;
	this->_makeForm[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern assignation operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm * Intern::makeForm(std::string const & formName, std::string const &target){
    std::string forms[3] = { "Shrubbery Creation",
                             "Robotomy Request",
                             "Presidential Pardon"};
    
    for(int i = 0; i < 3; i++) {
        if (forms[i] == formName){
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*_makeForm[i])(target));
        }
    }
    std::cout << "This Form is Non-Existent" << std::endl;
    return (0);
}

AForm *Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}