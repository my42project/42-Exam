#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell {
protected:
	std::string _name;
	std::string _effects;
public:
	ASpell();
	ASpell(std::string const &, std::string const &);
	ASpell(ASpell const &);
	ASpell &operator = (ASpell const &);
	virtual ~ASpell();

	std::string const &getName() const;
	std::string const &getEffects() const;

	virtual ASpell *clone() const = 0;

	void	launch(ATarget const &) const;

};