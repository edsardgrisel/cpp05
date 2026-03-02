#include "Bureaucrat.hpp"
#include <iostream>

void	constructorFormTryCatchHelper(std::string formName, int requiredSignGrade, int requiredExecuteGrade)
{
	try
	{
		Form form(formName, requiredSignGrade, requiredExecuteGrade);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}


int main()
{
	////////////////////// constructor tests
	std::cout << "\n---Test construct valid form---" << std::endl;
	constructorFormTryCatchHelper("formA", 1, 150);

	// construct sign grade edge cases
	std::cout << "\n---Test construct too high requiredSignGrade form---" << std::endl;
	constructorFormTryCatchHelper("formA", 0, 150);
	std::cout << "\n---Test construct too low requiredSignGrade form---" << std::endl;
	constructorFormTryCatchHelper("formA", 151, 150);

	// construct execute grade edge cases
	std::cout << "\n---Test construct too hight requiredExecuteGrade form---" << std::endl;
	constructorFormTryCatchHelper("formA", 1, 0);
	std::cout << "\n---Test construct too low requiredExecuteGrade form---" << std::endl;
	constructorFormTryCatchHelper("formA", 1, 151);


	/////////////////////// Form signing tests
	std::cout << "\n---Test form signing---" << std::endl;
	Form		form("formA", 10, 130);

	std::cout << "\n---Attempt to sign with too low level---" << std::endl;
	Bureaucrat	bNotHighEnough("low level", 11);
	bNotHighEnough.signForm(form);
	std::cout << form << std::endl;

	std::cout << "\n---Attempt to sign with high enough level---" << std::endl;
	Bureaucrat	bHighEnough("high level", 10);
	bHighEnough.signForm(form);
	std::cout << form << std::endl;

	std::cout << "\n" << std::endl;




	return 0;
}
