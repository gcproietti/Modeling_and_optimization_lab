#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Proc) {
	sc_out<int>	out;	// declare an output port
	sc_in<int>	in;	// declare an input port

	SC_CTOR(Proc) {
		SC_METHOD(proc_method);
		sensitive << in;
	}

	void proc_method(void);
};
