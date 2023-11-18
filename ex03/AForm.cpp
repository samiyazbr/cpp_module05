#include "AForm.hpp"

 AForm::AForm():_name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150){
    std::cout << "Form Default Constructor called" << std::endl;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
        : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "Form Constructor called" << std::endl;
    if (gradeToSign > 150 || gradeToExecute > 150){
        throw(GradeTooLowException());
    }
    else if (gradeToSign < 1 || gradeToExecute < 1){
        throw(GradeTooHighException());
    }
}

AForm::AForm(AForm const &copy)
    : _name(copy._name), _signed(copy._signed), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute){
         std::cout << "Form Copy Constructor called" << std::endl;
    }

AForm &AForm::operator=(AForm const &rhs){
    std::cout << "Form Copy Assignment Constructor called" << std::endl;
    if (this != &rhs) {
		const_cast<std::string&>(_name) = rhs._name;
		_signed = rhs._signed;
        const_cast<int&>(_gradeToSign) = rhs._gradeToSign;
        const_cast<int&>(_gradeToExecute) = rhs._gradeToExecute;
	}
	return *this;
}

AForm::~AForm(){
    std::cout << "Form Destructor called" << std::endl;
}

std::string AForm::get_name() const{ return _name; }

int AForm::get_gradeToSign()const{ return _gradeToSign; }

bool AForm::get_signed()const{ return _signed; }

int AForm::get_gradeToExecute()const { return _gradeToExecute; }

const char * AForm::GradeTooHighException::what() const throw(){
     return "Grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw(){
    return "Grade is too low";
}

std::ostream& operator<<(std::ostream& o, const AForm &form)
{
	o << "Form: " << form.get_name() << std::endl;
	o << std::boolalpha << "Status :" << form.get_signed() << std::endl;
	o << "Grade to sign: " << form.get_gradeToSign() << std::endl;
	o << "Grade to execute: " << form.get_gradeToExecute();
    return (o);
}

void AForm::beSigned(Bureaucrat const &bureaucrat){
    if (bureaucrat.getGrade() <= _gradeToSign){
        _signed = true;
    }
    else {
        throw GradeTooLowException();
    }
}

