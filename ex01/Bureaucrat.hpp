/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samiyazubair <samiyazubair@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:01 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/11/15 12:40:30 by samiyazubai      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include "Form.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat 
{
    private:
        std::string const Name;
        int Grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string Name, int Grade);
        Bureaucrat(Bureaucrat const & src);
        ~Bureaucrat();
        
        Bureaucrat & operator=(Bureaucrat const &rhs);
        std::string getName() const;
        int getGrade() const;
        void raise_Grade();
        void lower_Grade();

        void signForm(Form &form);
        
        // Nested class representing an exception.
        class GradeTooHighException : public std::exception {
        public:
            // Define a "what" function to describe the exception.
            // The function what() return a null terminated character sequence that is used to identify the exception.
            virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
        public:
            // Define a "what" function to describe the exception.
            virtual const char *what() const throw();
        };
    
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const &bureaucrat);

#endif