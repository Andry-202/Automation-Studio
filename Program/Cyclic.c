
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _CYCLIC ProgramCyclic(void)
{
	if(Enable)
	{
		if  (counter == 800)
		{
			Speed = 0;
			counter = 0;
		}
		if (counter == 400)
		{
			Speed = 40;
		}
		
		fb_motor1.u = Speed * fb_motor1.ke;
		FB_Motor(& fb_motor1);
		
		fb_controller.e = Speed - fb_motor2.w;
		FB_Regulator(& fb_controller);
		fb_motor2.u = fb_controller.u;
		FB_Motor(& fb_motor2);
		counter++;
		
	}
}



