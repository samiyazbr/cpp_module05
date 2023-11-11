/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:38:57 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/11/11 14:43:32 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) 
{
	try 
	{
        Bureaucrat bureaucrat("john", 2);
        std::cout << bureaucrat << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &e) 
	{
        std::cerr << "Bureaucrat's Grade is Too High" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e) 
	{
        std::cerr << "Bureaucrat's Grade is too low" << std::endl;
    }

    try 
	{
        Bureaucrat bureaucrat1("alex", 1);
        bureaucrat1.raise_Grade();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &error) 
	{
        std::cerr << "Bureaucrat's Grade is Too High" << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &error) 
	{
        std::cerr << "Bureaucrat's Grade is too low" << std::endl;
    }

    try 
	{
        Bureaucrat bureaucrat2("helen", 150);
        bureaucrat2.lower_Grade();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException &error) 
	{
        std::cerr << error.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &error) 
	{
        std::cerr << error.what() << std::endl;
    }
}