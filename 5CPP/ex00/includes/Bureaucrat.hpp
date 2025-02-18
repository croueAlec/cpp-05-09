#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
  private:
	const std::string name;
	size_t grade;
  public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat(const std::string& name, size_t grade);
	
	~Bureaucrat();
	
	Bureaucrat & operator=(const Bureaucrat &other);
	
	const std::string getName() const;
	size_t getGrade() const;

	void incrementGrade();
	void decrementGrade();

	class GradeTooHighException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat);
