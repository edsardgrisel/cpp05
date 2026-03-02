#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, int requiredSignGrade, int requiredExecuteGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();

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
	
	protected:
		virtual void execute(Bureaucrat const & executor) const = 0;

	private:
		AForm();

		const std::string	name;
		const int			requiredSignGrade;
		const int			requiredExecuteGrade;
		bool				isSigned;
};

std::ostream&	operator<<(std::ostream& outputStream, const AForm& aForm);

#endif // AFORM_HPP