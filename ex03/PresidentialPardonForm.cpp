#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

 PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs){
    std::cout << "PresidentialPardonForm Assignment Constructor called" << std::endl;
    if (this != &rhs) {
		_target = rhs._target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
    if (get_signed() == true && executor.getGrade() <= get_gradeToExecute())
	{
		std::cout << _target << " has been granted a presidential pardon by Galactic Council" << std::endl;
	}
	else if (executor.getGrade() <= get_gradeToExecute()) {
		throw GradeTooLowException();
	}
	else {
		throw std::out_of_range( "Bureaucrat cannot execute this form");
	}
}