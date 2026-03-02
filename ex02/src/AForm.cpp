#include "AForm.hpp"
#include <iostream>

#include <string>


AForm::AForm(std::string name, int requiredSignGrade, int requiredExecuteGrade)
	: name(name), requiredSignGrade(requiredSignGrade), requiredExecuteGrade(requiredExecuteGrade), isSigned(false)
{
	if (requiredSignGrade < 1 || requiredExecuteGrade < 1)
		throw GradeTooHighException();
	if (requiredSignGrade > 150 || requiredExecuteGrade > 150)
		throw GradeTooLowException();
	
	std::cout << "AForm constructor called. Name: " << name << ", requiredSignGrade: " << requiredSignGrade << ", requiredExecuteGrade: " << requiredExecuteGrade << std::endl;
}

AForm::AForm(const AForm &other)
	: name(other.name), requiredSignGrade(other.requiredSignGrade), requiredExecuteGrade(other.requiredExecuteGrade), isSigned(other.isSigned)
{
	std::cout << "AForm copy constructor called\n";
}


AForm&	AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	std::cout << "AForm assignment operator overload called\n";
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called\n";
}


std::string	AForm::getName() const
{
	return this->name;
}

int	AForm::getRequiredSignGrade() const
{
	return this->requiredSignGrade;
}

int	AForm::getRequiredExecuteGrade() const
{
	return this->requiredExecuteGrade;
}

bool	AForm::getIsSigned() const
{
	return this->isSigned;
}

void	 AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (this->isSigned)
	{
		std::cout << "AForm " << this->getName() << " has already been signed." << std::endl;
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


std::ostream&	operator<<(std::ostream& outputStream, const AForm& aForm)
{
	outputStream << aForm.getName()
	<< ", requiredSignGrade: " << aForm.getRequiredSignGrade()
	<< ", requiredExecuteGrade: " << aForm.getRequiredExecuteGrade()
	<< ", isSigned: " << (aForm.getIsSigned() ? "true" : "false");
	return (outputStream);
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Grade too high exception thrown.";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Grade too low exception thrown.";
}
