//
#include <iostream>
#include "die.h"
#include "roll.h"
#include <vector>
#ifndef SHOOTER_H
#define SHOOTER_H

class Shooter
{
public:
    Roll* throw_die(Die& a,Die& b);
    friend std::ostream& operator<<(std::ostream& out, const Shooter& );
    ~Shooter(){for(auto& n:rolls){delete n;}}
private:
std::vector <Roll*> rolls;

};


#endif