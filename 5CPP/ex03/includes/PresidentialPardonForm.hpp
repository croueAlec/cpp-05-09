#pragma once

#include "AForm.hpp"



class PresidentialPardonForm : public AForm {
  private:
	std::string target;
	void executeForm(Bureaucrat const & executor) const;
  public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
};
