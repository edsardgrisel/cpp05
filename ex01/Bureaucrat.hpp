#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
	Bureaucrat();
	
public:
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat&	operator=(const Bureaucrat &other);
	~Bureaucrat();

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

	std::string	getName() const;
	int			getGrade() const;

	void	increment();
	void	decrement();

	void	signForm(Form& form);

};

std::ostream&	operator<<(std::ostream& outputStream, const Bureaucrat& bureaucrat);


#endif // BUREAUCRAT_HPP



