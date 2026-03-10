#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	AForm* makeForm(std::string name, std::string target) const;

private:
	AForm* createShrubbery(const std::string& target) const;
	AForm* createRobotomy(const std::string& target) const;
	AForm* createPresidential(const std::string& target) const;
	
};

#endif // INTERN_HPP