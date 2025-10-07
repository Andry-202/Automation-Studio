
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
void FB_Integrator(struct FB_Integrator* inst)
{
	inst->dt=0.02;
	inst->out = inst->dt * inst->in + inst->state;
	inst->state = inst->out;
}
