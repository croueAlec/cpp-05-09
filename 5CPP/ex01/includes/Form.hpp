#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
  private:
	const std::string name;
	bool sign;
	const size_t gradeToSign;
	const size_t gradeToExecute;
  public:

	Form();
	Form(const std::string name, int sign, int exectute);
	Form(const Form& other);
	~Form();
	Form& operator=(const Form& other);

	const std::string getName();
	bool getSign();
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;

	class GradeTooHighException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	void beSigned(const Bureaucrat& bureaucrat);
};
