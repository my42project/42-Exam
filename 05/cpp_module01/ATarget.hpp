#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget {
protected:
	std::string _type;
public:
	ATarget();
	ATarget(std::string const &);
	ATarget(ATarget const &);
	ATarget &operator = (ATarget const &);
	virtual ~ATarget();

	std::string const &getType() const;

	virtual ATarget *clone() const = 0;


	void	getHitBySpell(ASpell const &) const;
};