# include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        std::cout << "******SHRUBBERY CREATION SUCCESS TEST********" << std::endl;
        Bureaucrat b = Bureaucrat("Samiya", 137);
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
    try
    {
        std::cout << "**SHRUBBERY CREATION INVALID EXEC_GRADE TEST**" << std::endl;
        Bureaucrat b = Bureaucrat("Samiya", 138);
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
    try
    {
        std::cout << "**SHRUBBERY CREATION INVALID SIGN_GRADE TEST**" << std::endl;
        Bureaucrat b = Bureaucrat("Samiya", 146);
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
    try
    {
        std::cout << "**ROBOTOMY SIGN FAIL TEST**" << std::endl;
        Bureaucrat b = Bureaucrat("Samiya", 146);
        RobotomyRequestForm robot("Robot");
        b.signForm(robot);
        b.executeForm(robot);
        std::cout << b << std::endl;
        std::cout << robot << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "**ROBOTOMY SIGN SUCCESS TEST**" << std::endl;
        Bureaucrat b = Bureaucrat("Samiya", 41);
        RobotomyRequestForm robot("Robot");
        b.signForm(robot);
        b.executeForm(robot);
        std::cout << b << std::endl;
        std::cout << robot << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "PRESIDENTIAL PARDON SIGN TEST POSITIVE" << std::endl;
        Bureaucrat b = Bureaucrat("Samiya", 4);
        PresidentialPardonForm pardon("Class A");
        b.signForm(pardon);
        b.executeForm(pardon);
        std::cout << b << std::endl;
        std::cout << pardon << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}
