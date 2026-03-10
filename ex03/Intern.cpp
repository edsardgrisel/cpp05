#include "inc/Intern.hpp"
#include <iostream>
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::Intern(const Intern& other)
{
	(void)other;
	std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	std::cout << "Intern assignment operator overload called\n";
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called\n";
}

AForm* Intern::createShrubbery(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target) const
{
	std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*formConstructors[3])(const std::string&) const = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == name)
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return (this->*formConstructors[i])(target);
		}
	}
	std::cout << "Intern failed to create form with name: " << name << std::endl;
	return NULL;
}