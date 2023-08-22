#include "ASpell.hpp"

ASpell::ASpell(): _n(""), _e("") {}
ASpell::ASpell(std::string const &n_, std::string const &e_): _n(n_), _e(e_) {}
ASpell::ASpell(ASpell const &a_) { *this = a_; }
ASpell &ASpell::operator = (ASpell const &a_)  { _n = a_._n; _e = a_._e; return *this; }
ASpell::~ASpell() {}

std::string const &ASpell::getName() const { return _n; }
std::string const &ASpell::getEffects() const { return _e; }

void    ASpell::launch(ATarget const &a_) const { a_.getHitBySpell(*this); } 