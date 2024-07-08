#pragma once

#include "AForm.hpp"

#include <cstdlib>

class RobotomyRequestForm : public AForm {
  private:
	std::string target;
	void executeForm(Bureaucrat const & executor) const;
  public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
};
