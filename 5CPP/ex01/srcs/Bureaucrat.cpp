#include "Bureaucrat.hpp"

// Constructors
Bureaucrat::Bureaucrat() : name("default")
{
	grade = 0;
	std::cout << "\e[0;33mDefault Constructor called for Bureaucrat class\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName())
{
	grade = other.getGrade();
	std::cout << "\e[0;33mCopy Constructor called for Bureaucrat class\e[0m" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, size_t grade) : name(name), grade(grade)
{
	if (grade < 1) {
		throw GradeTooHighException();
	}
	if (grade > 150) {
		throw GradeTooLowException();
	}
	std::cout << "\e[0;33mParameter Constructor called for Bureaucrat class\e[0m" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\e[0;31mDestructor called for Bureaucrat class\e[0m" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other) {
		grade = other.getGrade();
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
	return name;
}
size_t Bureaucrat::getGrade() const
{
	return grade;
}

void	Bureaucrat::incrementGrade() {
	if (grade-- == 0) {
		throw GradeTooHighException();
	}
	else
	{
		grade--;
	}
}

void	Bureaucrat::decrementGrade() {
	if (grade++ == 151) {
		throw GradeTooLowException();
	}
	else
	{
		grade++;
	}
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The Bureaucrat can't have a grade above 1";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The Bureaucrat can't have a grade below 150";
}

std::ostream& operator<<(std::ostream& ostream, const Bureaucrat& bureaucrat) {
	ostream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return ostream;
}
