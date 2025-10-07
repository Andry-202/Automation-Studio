
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
void FB_Motor(struct FB_Motor* inst)
{
	REAL state_1 = (inst->u) / inst->ke - inst->w;
	REAL state_2 = state_1 / inst->Tm;
	
	inst->w_integrator.in = state_2;
	FB_Integrator(&inst->w_integrator);
	inst->w = inst->w_integrator.out;
	
	inst->phi_integrator.in = inst->w;
	FB_Integrator(&inst->phi_integrator);
	inst->phi = inst->phi_integrator.out;
}
