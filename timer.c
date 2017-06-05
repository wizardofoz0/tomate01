/*
 * timer.c
 *
 * Created: 04.06.2017 20:19:36
 *  Author: Ivan Kireev
 * Description:
 *  - Timer 1 tick each 1/32 seconds
 *  - Timer 1 wake up CPU when interrupt
 *  - Timer 1 manage local time.
 */ 

void timer_init(void)
{
	//Set time and date
	t_tick		= 0;		//00-31. non BCD
	//Local time
	t_seconds	= 0x00;		//00-59. BCD
	t_minutes	= 0x00;		//00-59. BCD
	t_hours		= 0x00;		//00-23. BCD
	t_day		= 0x01;		//1-7.   BCD

	//Set timer mode and period
	;
	
	//Timer on
	;
}

TIMER1_OVF_vect
{
	t_tick++;
	if (t_tick >= 32) then {
		t_tick = 0;
		t_seconds++;
	
		if (t_seconds >= 60) then {
			t_seconds = 0;
			t_minutes++;
	
			if (t_minutes >= 60) then {
				t_minutes =0;
				t_hours++;
	
				if (t_hours >= 24) then {
					t_hours = 0;
					t_day++;
	
					if (t_day > 7) then {
						t_day = 1
					}
				}
			}
		}
	}
}