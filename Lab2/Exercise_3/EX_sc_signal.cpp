#include "EX_sc_signal.h"
using namespace sc_core;

void EX_sc_signal::tx_proc_thread(void) {
	wait(20, SC_NS);
	sig_int.write(20);		// write to sc_signal<int>
	cout << "tx_proc_thread writes value \"20\" to sig_int @ " << sc_time_stamp() << endl;

	wait(20, SC_NS);
	sig_bool.write(true);		// write to sc_signal<bool>
	cout << "tx_proc_thread writes value \"true\" to sig_bool @ " << sc_time_stamp() << endl;

	/* int, bool values can be received simultaneously */
	wait(20, SC_NS);
	sig_int.write(20);
	cout << "tx_proc_thread writes value \"20\" to sig_int @ " << sc_time_stamp() << endl;
	sig_bool.write(true);
	cout << "tx_proc_thread writes value \"true\" to sig_bool @ " << sc_time_stamp() << endl;

	/* int, bool values can be received simultaneously */
	wait(20, SC_NS);
	sig_int.write(30);
	cout << "tx_proc_thread writes value \"30\" to sig_int @ " << sc_time_stamp() << endl;
	sig_bool.write(false);
	cout << "tx_proc_thread writes value \"false\" to sig_bool @ " << sc_time_stamp() << endl;

}

void EX_sc_signal::rx_proc_method(void) {
	if(sig_int.event()) {	// to determine if the value stored in sig_int has changed
		cout << "rx_proc_method read value " << sig_int.read() << " @ " << sc_time_stamp() << endl;
	}
	if(sig_bool.event()) {	// to determine if the value stored in sig_bool has changed
		cout << "rx_proc_method read value " << sig_bool.read() << " @ " << sc_time_stamp() << endl;
	}
}
	
