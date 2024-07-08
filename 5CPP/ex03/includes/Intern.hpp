#pragma once
#include <iostream>

#include "AForm.hpp"

class Intern {
  private:
	
  public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);

	class BadFormNameException : public std::exception {
	  public:
		virtual const char* what() const throw();
	};

	AForm* makeForm(const std::string& formName, const std::string& target);
};
