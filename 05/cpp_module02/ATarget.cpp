#include "ATarget.hpp"

ATarget::ATarget(): _t("") {}
ATarget::ATarget(std::string const &_t): _t(_t) {}
ATarget::ATarget(ATarget const &t_) { *this = t_; }
ATarget &ATarget::operator = (ATarget const &t_)  { _t = t_._t; return *this; }
ATarget::~ATarget() {}

std::string const &ATarget::getType() const { return _t; }

void    ATarget::getHitBySpell(ASpell const &a_) const { std::cout << getType() << " has been " << a_.getEffects() << "!\n"; } 