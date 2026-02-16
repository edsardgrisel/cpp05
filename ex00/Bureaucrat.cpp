#include "Bureaucrat.hpp"
#include <iostream>


Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	
	this->grade = grade;

	std::cout << "Bureaucrat constructor called. Name: " << name << ", Grade: " << grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	std::cout << "Bureaucrat copy constructor called\n";
}


Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	std::cout << "Bureaucrat assignment operator overload called\n";
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}


std::string	Bureaucrat::getName() const
{
	return this->name;
}

int			Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::decrement()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		grade++;
}

void	Bureaucrat::increment()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		grade--;
}

std::ostream&	operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat)
{
	outputStream << bureaucrat.getGrade() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (outputStream);
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade too high exception thrown.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade too low exception thrown.";
}
