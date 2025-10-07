
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */

REAL LimitValue(REAL max, REAL x)
{
	if (x > max)
	{
		x = max;
	}
	if (x < -max)
	{
		x = -max;
	}
	return x;
}

void FB_Regulator(struct FB_Regulator* inst)
{
	/*TODO: Add your code here*/
	REAL signal_1 = inst->e * inst->k_p;

	REAL signal_2 = inst->e * inst->k_i*inst->dt;

	signal_1 = LimitValue(inst->max_abs_value, signal_1);
	
	inst->integrator.in = signal_2 + inst->iyOld;
	FB_Integrator(&inst->integrator);
	
	signal_1 = signal_1 + inst->integrator.out;
	
	inst->u = LimitValue(inst->max_abs_value, signal_1);
	
	inst->iyOld = inst->u - signal_1;
	
}


