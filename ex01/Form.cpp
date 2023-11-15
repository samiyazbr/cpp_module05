#include "Form.hpp"

Form::Form():_name("none"), _signed(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MIN_GRADE) 
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	else if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
	else if (gradeToSign > gradeToExecute)
		throw Form::GradeTooHighException();
	else
	{
		std::cout << "Form " << this->_name << "Created" << std::endl;
	}
}

Form::Form(Form const &copy): _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute) 
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form &Form::operator=(Form const &rhs)
{
	std::cout << "Form assignation operator called" << std::endl;
	this->_signed = rhs._signed;
	const_cast<std::string&>(this->_name) = rhs._name;
	const_cast<int&>(this->_gradeToSign) = rhs._gradeToSign;
	const_cast<int&>(this->_gradeToExecute) = rhs._gradeToExecute;
	return *this;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
	o << "Form: " << rhs.get_name() << std::endl;
	o << "Signed: " << rhs.signed_status() << std::endl;
	o << "Grade to sign: " << rhs.get_gradeToSign() << std::endl;
	o << "Grade to execute: " << rhs.get_gradeToExecute() << std::endl;

	return o;
}

std::string Form::get_name(void) const
{
	return this->_name;
}

int Form::get_gradeToSign(void) const
{
	return this->_gradeToSign;
}

int Form::get_gradeToExecute(void) const
{
	return this->_gradeToExecute;
}

std::string Form::signed_status(void) const
{
	if (this->_signed)
		return "Signed";
	else
		return "Not Signed";
}

void Form::beSigned(Bureaucrat const & bureaucrat){
    if (bureaucrat.getGrade() <= _gradeToSign){
        _signed = true;
    }
    else {
        throw GradeTooLowException();
    }
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return("Bureucrats Grade is too low and cant sign this form");
} 

const char *Form::GradeTooHighException::what(void) const throw()
{
    return("Grade is too high should be between 1 & 150");
}