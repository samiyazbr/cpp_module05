#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) 
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs){
	std::cout << "RobotomyRequestForm Assignment Constructor called" << std::endl;
	if (this != &rhs) {
		_target = rhs._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const{
	if (get_signed() == true && executor.getGrade() <= get_gradeToExecute())
	{
		std::cout << "*Drilling noises* " << _target << " has been robotomized successfully" << std::endl;
	}
	else if (executor.getGrade() <= get_gradeToExecute()) {
		throw GradeTooLowException();
	}
	else {
		throw std::out_of_range( "Bureaucrat cannot execute this form");
	}
}