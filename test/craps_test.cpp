#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "come_out_phase.h"
#include "point_phase.h"
#include <memory>
#include <iostream>

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test die class") 
{
	srand(time(NULL));
	for(int i =0; i<10;i++)
		{
			
			Die d;
			d.roll();
			std::cout<<"\n rolled value: "<<d.rolled_value();
			REQUIRE((d.rolled_value()>=1));
			REQUIRE((d.rolled_value()<=6));
		}
	
}


TEST_CASE("test roll class")
{
    srand(time(NULL));
    for (int i=0;i<10;i++)
    {
    Die d;
    Die d2;
    Roll r(d,d2);
    r.roll_die();
    REQUIRE(r.roll_value()>=2);
    REQUIRE(r.roll_value()<=12);
    }

}


TEST_CASE("Shooter Class")
{
    srand(time(NULL));
    for (int i=0;i<10;i++)
    {
    Die d;
    Die d2;
    Shooter s;
    Roll* u;
    u=(s.throw_die(d,d2));
    REQUIRE(u);// check that we have indeed returned the pointer
    REQUIRE(u->roll_value()>=2);//check value in correct range
    REQUIRE(u->roll_value()<=12);
    delete  u;
    }

}


