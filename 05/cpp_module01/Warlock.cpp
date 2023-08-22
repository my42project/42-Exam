#include "Warlock.hpp"

Warlock::Warlock(std::string const &n_, std::string const &t_):
	_name(n_), _title(t_) {
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const &Warlock::getName() const { return _name; }
std::string const &Warlock::getTitle() const { return _title; }

void	Warlock::setTitle(std::string const &t_) { _title = t_; }

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *s_ ) {
	if (s_)
		_as.insert(std::pair<std::string, ASpell *>(s_->getName(), s_->clone()));
}

void Warlock::forgetSpell(std::string spellName ) {
	std::map<std::string, ASpell *>::iterator it = _as.find(spellName);

	if (it != _as.end())
		delete it->second;
	_as.erase(spellName);
}

void Warlock::launchSpell(std::string spellName, ATarget const &t_ ) {
	ASpell* spell = _as[spellName];

	if (spell)
		spell->launch(t_);

}