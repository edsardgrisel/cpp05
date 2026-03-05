#include "AForm.hpp"

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();


	protected:
		void executeFormAction() const override;

	private:
		ShrubberyCreationForm();
		std::string target;

};

#endif // SHRUBBERYCREATIONFORM_HPP