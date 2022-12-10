#include "time.h"
#include<cstdlib>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <memory>
#include <iostream>
int main() 

{
	srand(time(0));
	Die die1;
	Die die2;
	Shooter shooter;
	Roll* roll;
	roll=shooter.throw_die(die1,die2);
	ComeOutPhase come_out_phase;
	while (come_out_phase.get_outcome(roll)==RollOutcome::natural||come_out_phase.get_outcome(roll)==RollOutcome::craps)
	{
		std::cout<<"Rolled: "<<roll->roll_value();
		std::cout<<"\t Roll Again \n";
		roll= shooter.throw_die(die1,die2);
	}
	std::cout<<"Rolled "<<roll->roll_value()<<" Start of Point Phase\n";
	std::cout<<"Roll until "<<roll->roll_value()<<" or a 7 is rolled \n";	
	int point= roll->roll_value();
	roll = shooter.throw_die(die1,die2);
	PointPhase point_phase(point);
	while( point_phase.get_outcome(roll)==RollOutcome::point||point_phase.get_outcome(roll)==RollOutcome::nopoint)//this doesn't make sense, it should only continue while the outcome is nopoint. however this is what the instructions say to do.
	{
		std::cout<<roll->roll_value()<<" Roll Again\n";
		roll= shooter.throw_die(die1,die2);
	}
	std::cout<<roll->roll_value()<<" End of Point Phase\n";
	std::cout<<shooter;
	return 0;
}