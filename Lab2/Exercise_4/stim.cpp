#include "stim.h"

void Stim::gen_thread(void) {
	int cnt = 10;	// define a counter

	while(cnt--) {
		wait(10, SC_NS);
		out->write(cnt);	// write a value to the port
		cout << "Stim object '" << name() << "' sends out a value : " << cnt << " @ " << sc_time_stamp() << endl;
	}
}

void Stim::react_method(void) {
	cout << "Stim object '" << name() << "' receives a value : " << in->read() << " @ " << sc_time_stamp() << endl;
}
