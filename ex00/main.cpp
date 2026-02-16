#include "Bureaucrat.hpp"
#include <iostream>

void	constructorTryCatchHelper(std::string name, int grade)
{
	try
	{
		Bureaucrat a(name, grade);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

}

void	incrementHelper(std::string name, int grade)
{
	Bureaucrat* a = nullptr;
	try
	{
		a = new Bureaucrat(name, grade);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Old grade: " << a->getGrade() << std::endl;
	try
	{
		a->increment();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "New grade: " << a->getGrade() << std::endl;
	delete a;
}

void	decrementHelper(std::string name, int grade)
{
	Bureaucrat* a = nullptr;
	try
	{
		a = new Bureaucrat(name, grade);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return;
	}
	std::cout << "Old grade: " << a->getGrade() << std::endl;
	try
	{
		a->decrement();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "New grade: " << a->getGrade() << std::endl;
	delete a;
}

int main()
{
	// constructor tests
	std::cout << "\n---Test construct valid bureaucrat---" << std::endl;
	constructorTryCatchHelper("john", 1);

	std::cout << "\n---Test construct grade 0 bureaucrat---" << std::endl;
	constructorTryCatchHelper("john", 0);

	std::cout << "\n---Test construct grade 151 bureaucrat---" << std::endl;
	constructorTryCatchHelper("john", 151);

	// increment tests
	std::cout << "\n---Test valid increment from 2---" << std::endl;
	incrementHelper("john", 2);

	std::cout << "\n---Test invalid increment from 1---" << std::endl;
	incrementHelper("john", 1);

	// decrement tests
	std::cout << "\n---Test valid decrement from 149---" << std::endl;
	decrementHelper("john", 149);

	std::cout << "\n---Test invalid increment from 150---" << std::endl;
	decrementHelper("john", 150);
	return 0;
}
