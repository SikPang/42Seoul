#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern::~Intern()
{

}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

AForm* Intern::getPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::getRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::getShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string names[FORM_NUM] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm* (Intern::*funcs[FORM_NUM])(const std::string& target) = {&Intern::getPresidential, &Intern::getRobotomy, &Intern::getShrubbery};

	for (int i = 0; i < FORM_NUM; ++i)
	{
		if (names[i] == formName)
			return (this->*(funcs[i]))(target);
	}
	return NULL;
}