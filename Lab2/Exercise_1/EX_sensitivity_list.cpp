#include "EX_sensitivity_list.h"

void EX_sensitivity_list::ex_thread(void) {
	int cnt = 10; 		// define a conuter
	while(cnt--) {
		wait(10, SC_NS);
		cout << "cnt = " << cnt << ", ex_thread @ " << sc_time_stamp() << endl; 
		evt2.notify(SC_ZERO_TIME);
	}
}

void EX_sensitivity_list::ex_method(void) {
	cout <<  "ex_method @ " << sc_time_stamp() << endl;
}	
