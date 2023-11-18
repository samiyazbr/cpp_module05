#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
        Intern someRandomIntern;
        AForm *ppf;
        ppf = someRandomIntern.makeForm("Presidential Pardon", "Samiya");
        Bureaucrat b = Bureaucrat("Zubair", 1);
        b.signForm(*ppf);
        b.executeForm(*ppf);
        delete ppf;
}