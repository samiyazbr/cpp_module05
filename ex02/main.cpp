# include "AForm.hpp"
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std::cout <<"***********GRADE TOO LOW TO SIGN TEST**********" << std::endl;
        AForm form("Contract Form", 4, 6);
        Bureaucrat bureaucrat("samiya", 10);
        bureaucrat.signForm(form);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "****************GRADE OK SIGN TEST************" << std::endl;
        AForm form("Contract Form", 4, 6);
        Bureaucrat bureaucrat("samiya", 3);
        bureaucrat.signForm(form);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout<< "************GRADE BELOW MINIMUM TEST*************" << std::endl;
        AForm form("Contract Form", 151, 6);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "***************GRADE ABOVE MAXIMUM TEST**********"<< std::endl;
        AForm form("Contract Form", 10, 0);
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "**************BE-SIGNED GRADE TOO LOW TEST********" << std::endl;
        Bureaucrat bureaucrat("samiya", 89);
        AForm form("Contract Form", 25, 12);
        form.beSigned(bureaucrat);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    try
    {
        std::cout << "**********BE-SIGNED GRADE NORMAL TEST****************" << std::endl;
        Bureaucrat bureaucrat("samiya", 1);
        AForm form("Contract Form", 25, 12);
        form.beSigned(bureaucrat);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    
}
