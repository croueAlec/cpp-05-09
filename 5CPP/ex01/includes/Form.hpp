#pragma once
#include <iostream>
#include <string>

class Form {
  private:
	const std::string name;
	bool sign;
	const size_t gradeToSign;
	const size_t gradeToExecute;
  public:
	
	Form();
	Form(const Form& other);
	~Form();
	Form& operator=(const Form& other);

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
};
