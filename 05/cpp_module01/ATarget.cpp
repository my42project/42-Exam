#include "ATarget.hpp"

ATarget::ATarget(): _type() {}
ATarget::ATarget(std::string const &t_): _type(t_) {}
ATarget::ATarget(ATarget const &a_) : _type(a_._type) {
	// or *this = a; 
}
ATarget &ATarget::operator=(ATarget const &a_) {
	_type = a_._type;
	return *this;
}

ATarget::~ATarget() {}

std::string const &ATarget::getType() const { return _type; }

void	ATarget::getHitBySpell(ASpell const &a ) const {
	std::cout << _type << " has been " << a.getEffects() << "!" << std::endl;
}
