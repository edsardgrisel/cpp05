#include "string"
#include "AForm.hpp"

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

	protected:
		void executeFormAction() const override;

	private:
		RobotomyRequestForm();
		std::string target;


};

#endif // ROBOTOMYREQUESTFORM_HPP