#include "ASpell.hpp"

ASpell::ASpell(): _name(), _effects() {}
ASpell::ASpell(std::string const &n_, std::string const &e_):
	_name(n_), _effects(e_) {}

ASpell::ASpell(ASpell const &a_):
	_name(a_._name), _effects(a_._effects) {
	// or *this = a; 
}
ASpell &ASpell::operator=(ASpell const &a_) {
	_name = a_._name;
	_effects = a_._effects;
	return *this;
}

ASpell::~ASpell() {}

std::string const &ASpell::getName() const { return _name; }
std::string const &ASpell::getEffects() const { return _effects; }

void	ASpell::launch( ATarget const &o ) const { o.getHitBySpell(*this); }
