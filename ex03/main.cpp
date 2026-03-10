#include "inc/Bureaucrat.hpp"
#include <iostream>
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/AForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"
#include "inc/Intern.hpp"

void	exec_helper(AForm &form, Bureaucrat &b)
{
	try
	{
		form.execute(b);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}


int main()
{
	////////////////////// Test intern creates forms
	std::cout << "\n---Test intern creates forms---" << std::endl;

	Bureaucrat max("max", 1);
	Bureaucrat min("min", 150);


	Intern intern;

	std::cout << "\n\nIntern create Shrubbery. Valid sign. Valid exec" << std::endl;
	AForm* shrubForm = intern.makeForm("shrubbery creation", "shrub target");
	max.signForm(*shrubForm);
	max.executeForm(*shrubForm);

	std::cout << "\n\nIntern create Robotomy. Valid sign. Invalid exec" << std::endl;
	AForm* roboForm = intern.makeForm("robotomy request", "robo target");
	max.signForm(*roboForm);
	min.executeForm(*shrubForm);


	std::cout << "\n\nIntern create Presidential. Invalid sign. Invalid exec" << std::endl;
	AForm* presiForm = intern.makeForm("presidential pardon", "robo target");
	min.signForm(*presiForm);
	min.executeForm(*presiForm);
	
	return 0;
}
