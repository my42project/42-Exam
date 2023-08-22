#include "Warlock.hpp"


Warlock::Warlock(std::string const &n_, std::string const &t_): _name(n_), _title(t_) {
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {
	std::cout << _name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const {return _name; }
std::string const &Warlock::getTitle() const {return _title; }


void	Warlock::setTitle(std::string const &t_) {
	_title = t_;
}

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}