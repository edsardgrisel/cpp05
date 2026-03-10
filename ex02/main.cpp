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

		// cant exec
		std::cout << "\nTest execute with too low grade" << std::endl;
		max.signForm(shrubForm); // max can sign (grade 1)
		exec_helper(shrubForm, low); // low (138) cannot execute (required: 137)

		// 3. Execute with high enough grade
		std::cout << "\nTest execute with high enough grade" << std::endl;
		exec_helper(shrubForm, high); // high (137) can execute
	}





	return 0;
}
