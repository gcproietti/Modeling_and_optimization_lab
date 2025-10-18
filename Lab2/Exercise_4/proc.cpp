#include "proc.h"

void Proc::proc_method(void) {
	cout << "Proc object '" << name() << "' receives a value: " << in->read()  << " @ " << sc_time_stamp() << endl;
	out->write(2*in->read());
}
