#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(Stim) {
	sc_out<int>	out;	// declare an output port
	sc_in<int>	in;	// declare an input port

	SC_CTOR(Stim) {
		SC_THREAD(gen_thread);

		SC_METHOD(react_method);
		sensitive << in;
	}

	void gen_thread(void); 
	void react_method(void);
};
