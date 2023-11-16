# include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        std::cout << "SHRUBBERY SIGN & EXEC TEST POSITIVE" << std::endl;
        Bureaucrat b = Bureaucrat("samiya", 120);
        ShrubberyCreationForm shrub("Shrub");
        b.signForm(shrub);
        b.executeForm(shrub);
        std::cout << b << std::endl;
        std::cout << shrub << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}