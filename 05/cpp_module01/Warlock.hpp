#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class Warlock {
private:
	std::string	_name;
	std::string	_title;

	std::map<std::string, ASpell *> _as;
public:
	Warlock();
	Warlock(std::string const &, std::string const &);
	Warlock(Warlock const &);
	Warlock &operator = (Warlock const &);
	virtual ~Warlock();

	std::string const	&getName() const;
	std::string const	&getTitle() const;

	void	setTitle(std::string const &);
	void	introduce() const;

	void	learnSpell(ASpell *);
	void	forgetSpell(std::string);
	void	launchSpell(std::string, ATarget const &);
};