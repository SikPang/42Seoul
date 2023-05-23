#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>

#define FORM_NUM 3

class Intern
{
private:
	AForm* getPresidential(const std::string& target);
	AForm* getRobotomy(const std::string& target);
	AForm* getShrubbery(const std::string& target);

public:
	Intern();
	Intern(const Intern& other);
	~Intern();
	Intern& operator=(const Intern& other);
	AForm* makeForm(const std::string& formName, const std::string& target);
};