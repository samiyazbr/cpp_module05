# include "Form.hpp"

int main(void)
{
	std::cout << "--------------Test 1--------------" << std::endl;
	try
	{
		Form form("Contract Form 1", 150, 150);
		Bureaucrat bureaucrat("Bureaucrat1", 1);
		form.beSigned(bureaucrat);
		bureaucrat.raise_Grade();
	}
	catch(std::exception &error)
	{
		std::cout << "Exeption caused" << std::endl;
		std::cout << error.what() << std::endl;
	}

	std::cout << "--------------Test 2--------------" << std::endl;

	try
	{
		Form form("Contract Form 2", 4, 6);
        Bureaucrat bureaucrat("Samiya", 3);
        bureaucrat.signForm(form);
        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;
	}
	catch(const std::exception &error)
	{
		std::cerr << error.what() << '\n';
	}
	

}