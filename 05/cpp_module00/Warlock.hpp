#pragma once

#include <iostream>

class Warlock {
private:
	std::string _name;
	std::string _title;
public:
	Warlock();
	Warlock(std::string const &, std::string const &);
	Warlock &operator = (Warlock const &);
	Warlock(Warlock const &);
	virtual ~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;

	void	setTitle(std::string const &);
	void	introduce() const;
};