#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int requiredSignGrade, int requiredExecuteGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		// Getters
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getRequiredSignGrade() const;
		int			getRequiredExecuteGrade() const;

		void	 beSigned(Bureaucrat& bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const noexcept override;
		};

	private:
		Form();

		const std::string	name;
		const int			requiredSignGrade;
		const int			requiredExecuteGrade;
		bool				isSigned;
};

std::ostream&	operator<<(std::ostream& outputStream, const Form& form);

#endif // FORM_HPP