#pragma once

#include "AForm.hpp"

#include <iostream>
#include <fstream>

const std::string TREE("       ccee88oo\n  C8O8O8Q8PoOb o8oo\n dOB69QO8PdUOpugoO9bD\nCgggbU8OU qOp qOdoUOdcb\n    6OuU  /p u gcoUodpP\n      \\\\\\//  /douUP\n        \\\\\\////\n         |||/\\\n         |||\\/\n         |||||\n   .....//||||\\....\n");

class ShrubberyCreationForm : public AForm {
  private:
	std::string target;
	void executeForm(Bureaucrat const & executor) const;
  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

};
