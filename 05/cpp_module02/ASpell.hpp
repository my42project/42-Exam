#pragma once

#include "ATarget.hpp"
#include <iostream>

class ATarget;

class ASpell {
private:
    std::string _n;
    std::string _e;
public:
    ASpell();
    ASpell(std::string const &, std::string const &);
    ASpell(ASpell const &);
    ASpell &operator = (ASpell const &);
    virtual ~ASpell();

    std::string const &getName() const;
    std::string const &getEffects() const;

    void    launch(ATarget const &) const;
    virtual ASpell *clone() const = 0;

};