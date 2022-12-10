//
#include<memory>
#include"roll.h"
#include "shooter.h"


    Roll* Shooter::throw_die(Die& a,Die& b)
    {
        Roll* roll1= new Roll(a,b);
        roll1->roll_die();
        rolls.push_back(roll1);
        return roll1;        
    }
    std::ostream& operator<<(std::ostream& out, const Shooter& s)
    {
        for(auto c: s.rolls)
        std::cout<<c->roll_value()<<"\n";
    }