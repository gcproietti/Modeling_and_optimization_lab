#include "systemc.h"
#include "stim.h"
#include "proc.h"

int sc_main(int argc, char * argv[]) {
	sc_signal<int>	channel1;	// define a channel
	sc_signal<int>	channel2;

	Stim	Stim_inst("Stim Obj");
	Proc	Proc_inst("Proc Obj");

	Stim_inst.out(channel1);	// connect Stim_inst's output port "out" to channel1
	Stim_inst.in(channel2);		// connect Stim_inst's input port "in" to channel2

	Proc_inst.in(channel1);
	Proc_inst.out(channel2);

	sc_start();

	return 0;
}

