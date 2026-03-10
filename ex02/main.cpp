#include "inc/Bureaucrat.hpp"
#include <iostream>
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/AForm.hpp"
#include "inc/RobotomyRequestForm.hpp"
#include "inc/PresidentialPardonForm.hpp"

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
	{
		////////////////////// Shrubbery tests
		std::cout << "\n---Shrubbery tests---" << std::endl;

		Bureaucrat max("max", 1);
		Bureaucrat low("low",  138);
		Bureaucrat high("high",  137);

		ShrubberyCreationForm shrubForm("shrub_target");

		// execute without signing
		std::cout << "\nTest execute without signing" << std::endl;
		exec_helper(shrubForm, high);

		// sign form
		max.signForm(shrubForm);

		// too low exec
		std::cout << "\nTest execute with too low grade" << std::endl;
		exec_helper(shrubForm, low);

		//  high enough exec
		std::cout << "\nTest execute with high enough grade" << std::endl;
		exec_helper(shrubForm, high);
		std::cout << "\n" << std::endl;
	}
	{
		////////////////////// Robotomy tests
		std::cout << "\n---Robotomy tests---" << std::endl;

		Bureaucrat max("max", 1);
		Bureaucrat low("low",  46);
		Bureaucrat high("high",  45);

		RobotomyRequestForm roboForm("shrub_target");

		// execute without signing
		std::cout << "\nTest execute without signing" << std::endl;
		exec_helper(roboForm, high); // Should throw: form not signed

		// sign form
		max.signForm(roboForm);

		// too low exec
		std::cout << "\nTest execute with too low grade" << std::endl;
		exec_helper(roboForm, low);

		//  high enough exec
		std::cout << "\nTest execute with high enough grade" << std::endl;
		for (int i = 0; i < 10; i++) {exec_helper(roboForm, high);}
		std::cout << "\n" << std::endl;
	}
	{
		////////////////////// Presidential tests
		std::cout << "\n---Presidential tests---" << std::endl;

		Bureaucrat max("max", 1);
		Bureaucrat low("low",  6);
		Bureaucrat high("high",  5);

		PresidentialPardonForm presidentialForm("shrub_target");

		// execute without signing
		std::cout << "\nTest execute without signing" << std::endl;
		exec_helper(presidentialForm, high); // Should throw: form not signed

		// sign form
		max.signForm(presidentialForm);

		// too low exec
		std::cout << "\nTest execute with too low grade" << std::endl;
		exec_helper(presidentialForm, low);

		//  high enough exec
		std::cout << "\nTest execute with high enough grade" << std::endl;
		exec_helper(presidentialForm, high);
		std::cout << "\n" << std::endl;
	}

	{
		////////////////////// Bureaucrat::executeForm tests
		std::cout << "\n---Bureaucrat::executeForm tests---" << std::endl;

		Bureaucrat high("high", 1);
		Bureaucrat low("low", 150);


		ShrubberyCreationForm shrubForm("execute_shrub");
		RobotomyRequestForm roboForm("execute_robot");
		PresidentialPardonForm pardonForm("execute_president");

		high.signForm(shrubForm);
		high.signForm(roboForm);
		high.signForm(pardonForm);

		std::cout << "\nTesting executeForm with ShrubberyCreationForm too low" << std::endl;
		low.executeForm(shrubForm);

		std::cout << "\nTesting executeForm with ShrubberyCreationForm high enough" << std::endl;
		high.executeForm(shrubForm);

		std::cout << "\nTesting executeForm with RobotomyRequestForm too low" << std::endl;
		low.executeForm(roboForm);

		std::cout << "\nTesting executeForm with RobotomyRequestForm high enough" << std::endl;
		high.executeForm(roboForm);

		std::cout << "\nTesting executeForm with PresidentialPardonForm too low" << std::endl;
		low.executeForm(pardonForm);

		std::cout << "\nTesting executeForm with PresidentialPardonForm high enough" << std::endl;
		high.executeForm(pardonForm);
		std::cout << "\n" << std::endl;
	}

	
	return 0;
}
