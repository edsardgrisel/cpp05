#include "Form.hpp"
#include <iostream>

#include <string>


Form::Form(std::string name, int requiredSignGrade, int requiredExecuteGrade)
	: name(name), requiredSignGrade(requiredSignGrade), requiredExecuteGrade(requiredExecuteGrade), isSigned(false)
{
	if (requiredSignGrade < 1 || requiredExecuteGrade < 1)
		throw GradeTooHighException();
	if (requiredSignGrade > 150 || requiredExecuteGrade > 150)
		throw GradeTooLowException();
	
	std::cout << "Form constructor called. Name: " << name << ", requiredSignGrade: " << requiredSignGrade << ", requiredExecuteGrade: " << requiredExecuteGrade << std::endl;
}

Form::Form(const Form &other)
	: name(other.name), requiredSignGrade(other.requiredSignGrade), requiredExecuteGrade(other.requiredExecuteGrade), isSigned(other.isSigned)
{
	std::cout << "Form copy constructor called\n";
}


Form&	Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout << "Form assignment operator overload called\n";
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}


std::string	Form::getName() const
{
	return this->name;
}

int	Form::getRequiredSignGrade() const
{
	return this->requiredSignGrade;
}

int	Form::getRequiredExecuteGrade() const
{
	return this->requiredExecuteGrade;
}

bool	Form::getIsSigned() const
{
	return this->isSigned;
}

void	 Form::beSigned(Bureaucrat& bureaucrat)
{
	if (this->isSigned)
	{
		std::cout << "Form " << this->getName() << " has already been signed." << std::endl;
		return;
	}
	if (bureaucrat.getGrade() <= this->getRequiredSignGrade())
	{
		this->isSigned = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}


std::ostream&	operator<<(std::ostream& outputStream, const Form& Form)
{
	outputStream << Form.getName()
	<< ", requiredSignGrade: " << Form.getRequiredSignGrade()
	<< ", requiredExecuteGrade: " << Form.getRequiredExecuteGrade()
	<< ", isSigned: " << (Form.getIsSigned() ? "true" : "false");
	return (outputStream);
}

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Grade too high exception thrown.";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Grade too low exception thrown.";
}
