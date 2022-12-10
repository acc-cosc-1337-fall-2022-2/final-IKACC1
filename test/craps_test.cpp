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





TEST_CASE("test ComeOutPhase class")
{//result is random, so use loop that won't end until all tests positive to test.
//not infinite loop: we know statistically, the values will come up
//even the least likely is 2/12. 
//in practice it validates all 3 in an average of 5 loops
    srand(time(NULL));
    bool flag_natural=false;
    bool flag_craps=false;
    bool flag_point=false;
    while (flag_natural==false|| flag_craps==false||
    flag_point==false)
    {
    Die d;
    Die d2;
    Shooter s;
    Roll* u;
    u=(s.throw_die(d,d2));
    ComeOutPhase c;
    auto r=c.get_outcome(u);
    auto n = RollOutcome::natural;
    auto c1 = RollOutcome::craps;
    auto p = RollOutcome::point;
    REQUIRE((r==n||r==c1||r==p));
    if(r==n)
    {
        flag_natural=true;
    }
    if(r==c1)
    {
        flag_craps=true;
    }
    if(r==p)
    {
        flag_point=true;
    }
    delete  u;
    }

}


TEST_CASE("test PointPhase class")
{//same logic as above.
    srand(time(NULL));
    bool flag_seven_out=false;
    bool flag_nopoint=false;
    bool flag_point=false;
    while (flag_seven_out==false|| flag_nopoint==false||
    flag_point==false)
    {
    Die d;
    Die d2;
    Shooter s;
    Roll* u;
    u=(s.throw_die(d,d2));
    PointPhase c(6);
    auto r=c.get_outcome(u);
    auto so = RollOutcome::seven_out;
    auto np = RollOutcome::nopoint;
    auto p = RollOutcome::point;
    REQUIRE((r==np||r==so||r==p));
    if(r==so)
    {
        flag_seven_out=true;
    }
    if(r==np)
    {
        flag_nopoint=true;
    }
    if(r==p)
    {
        flag_point=true;
    }
    delete  u;
    }

}
