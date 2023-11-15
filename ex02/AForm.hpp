# ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		virtual ~AForm();

		AForm &operator=(AForm const &rhs);

		std::string get_name(void) const;
		bool get_signed(void) const;
		int get_gradeToSign(void) const;
		int get_gradeToExecute(void) const;
		void beSigned(Bureaucrat const &bcrat);

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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif