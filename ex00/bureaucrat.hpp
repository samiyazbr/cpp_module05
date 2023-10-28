/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szubair <szubair@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:01 by samiyazubai       #+#    #+#             */
/*   Updated: 2023/10/24 16:01:46 by szubair          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

// Define constants LOWEST and HIGHEST with specific values. These will be used later in the class.
#define MIN_GRADE 150
#define MAX_GRADE 1

// Define a C++ class named Bureaucrat.
class Bureaucrat 
{
public:
    // Default constructor for the Bureaucrat class.
    Bureaucrat();
    
    // Constructor with parameters for the Bureaucrat class.
    Bureaucrat(std::string Name, int Grade);
    
    // Copy constructor for the Bureaucrat class.
    Bureaucrat(Bureaucrat const & src);
    
    // Destructor for the Bureaucrat class.
    ~Bureaucrat();
    
    // Assignment operator for the Bureaucrat class.
    Bureaucrat & operator=(Bureaucrat const &rhs);
    
    // Public member function to get the name of a bureaucrat.
    std::string getName() const;
    
    // Public member function to get the grade of a bureaucrat.
    int getGrade() const;
    
    // Public member function to increment the grade of a bureaucrat.
    void raise_Grade();
    
    // Public member function to decrement the grade of a bureaucrat.
    void lower_Grade();
    
    // Nested class representing an exception for when the grade is too high.
    class GradeTooHighException : public std::exception {
    public:
        // Define a "what" function to describe the exception.
        const char *what() const throw();
    };
    
    // Nested class representing an exception for when the grade is too low.
    class GradeTooLowException : public std::exception {
    public:
        // Define a "what" function to describe the exception.
        const char *what() const throw();
    };
    
private:
    // Private member variable for the name of the bureaucrat (constant).
    std::string const Name;
    
    // Private member variable for the grade of the bureaucrat.
    int Grade;
};

// Overload the output stream operator to allow printing a Bureaucrat object.
std::ostream & operator<<(std::ostream & o, Bureaucrat const &bureaucrat);
