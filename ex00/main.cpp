/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:38:57 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/11/15 14:07:05 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) 
{
    std::cout << " **********BUREAUCRAT WITH NORMAL GRADE********** " << std::endl;
	try 
	{
        Bureaucrat bureaucrat("john", 2);
        std::cout << bureaucrat << std::endl;
    }
    catch (std::exception &error) 
	{
        std::cout  << error.what() << std::endl;
    }

    std::cout << " **********BUREAUCRAT WITH HIGHER GRADE********** " << std::endl;
    try 
	{
        Bureaucrat bureaucrat1("alex", 1);
        bureaucrat1.raise_Grade();
        std::cout << bureaucrat1 << std::endl;
    }
    catch (std::exception &error) 
	{
        std::cout  << error.what() << std::endl;
    }

    std::cout << " **********BUREAUCRAT WITH LOWER GRADE*********** " << std::endl;
    try 
	{
        Bureaucrat bureaucrat2("helen", 150);
        bureaucrat2.lower_Grade();
        std::cout << bureaucrat2 << std::endl;
    }
    catch (std::exception &error) 
	{
        std::cout  << error.what() << std::endl;
    }
}