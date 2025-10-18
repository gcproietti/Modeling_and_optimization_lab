#include "systemc.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using namespace sc_core;

SC_MODULE(EX_sc_signal) {
	sc_signal<int>		sig_int;
	sc_signal<bool>		sig_bool;

	SC_CTOR(EX_sc_signal) {
		SC_THREAD(tx_proc_thread);		// register a sender process

		SC_METHOD(rx_proc_method);		// register a receiver process
		sensitive << sig_int.default_event()	// rx_process is sensitive to sig_int's value changed event
			  << sig_bool;			// the "default_event()" can be neglected
	}

	void tx_proc_thread(void);
	void rx_proc_method(void);
};
