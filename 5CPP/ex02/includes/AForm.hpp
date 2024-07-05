#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
  private:
	const std::string name;
	bool sign;
	const size_t gradeToSign;
	const size_t gradeToExecute;
  protected:
	virtual void executeForm(Bureaucrat const & executor) const = 0;
  public:

	AForm();
	AForm(const std::string name, int sign, int exectute);
	AForm(const AForm& other);
	virtual ~AForm() = 0;
	AForm& operator=(const AForm& other);

	const std::string getName();
	bool getSign();
	size_t getGradeToSign() const;
	size_t getGradeToExecute() const;

	void execute(Bureaucrat const & executor) const;

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
