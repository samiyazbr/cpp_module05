# ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		Form();
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		~Form();

		Form &operator=(Form const &rhs);

		std::string get_name(void) const;
		int get_gradeToSign(void) const;
		int get_gradeToExecute(void) const;
		void beSigned(Bureaucrat const &bureaucrat);

		std::string signed_status(void) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif