#include "inc/Bureaucrat.hpp"
#include <iostream>
#include "inc/ShrubberyCreationForm.hpp"
#include "inc/AForm.hpp"


void	exec_helper(AForm &form, Bureaucrat b)
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
		std::cout << "\n---Test construct valid form---" << std::endl;

		Bureaucrat max("max", 1);
		Bureaucrat low("low",  138);
		Bureaucrat high("high",  137);

		ShrubberyCreationForm shrubForm("shrub_target");

		// execute without signing
		std::cout << "\nTest execute without signing" << std::endl;
		exec_helper(shrubForm, high); // Should throw: form not signed

		// sign form
		max.signForm(shrubForm);

		// too low exec
		std::cout << "\nTest execute with too low grade" << std::endl;
		exec_helper(shrubForm, low);

		//  high enough exec
		std::cout << "\nTest execute with high enough grade" << std::endl;
		exec_helper(shrubForm, high);
	}





	return 0;
}
