//
#include "roll.h"



#ifndef ROLL_OUTCOME_H
#define ROLL_OUTCOME_H
enum class RollOutcome{natural,craps,point,seven_out,nopoint};
#endif


#ifndef PHASE_H
#define PHASE_H
class Phase
{
virtual RollOutcome get_outcome(Roll* roll)=0;
};
#endif
