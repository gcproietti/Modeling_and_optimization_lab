/*
 * signal_ex.cpp
 *
 *  Created on: Aug 27, 2010
 *      Author: songzhenyu
 */

#include "signal_ex.h"

void signal_ex::signal_ex_thread(void) {
	cout << "NOTE: signal_ex_thread is initializing" << endl;
	count_sig.write(10);
	traffic_sig.write(BLACK);
	count = 11;
	traffic_temp = RED;
	wait(SC_ZERO_TIME);

	// 2nd delta cycle
	cout << "NOTE: signal_ex_thread is done initializing" << endl;
	count = 20;
//	count = 11;
	count_sig.write(count);
	cout << "----: count is " << count << " "
		 << "count_sig is " << count_sig.read()
		 << endl;
	cout << "NOTE: signal_ex_thread is waiting" << endl;

	// 3rd delta cycle
	wait(SC_ZERO_TIME);
	cout << "----: count is " << count << " "
		 << "count_sig is " << count_sig.read()
		 << endl;
	traffic_sig.write(traffic_temp = WHITE);
	cout << "----: traffic_temp is '" << traffic_temp << "' "
		 << "traffic_temp is '" << traffic_sig.read() << "' "
		 <<endl;

	// 4th delta cycle
	wait(SC_ZERO_TIME);
	// 5th delta cycle
	wait(SC_ZERO_TIME);
	cout << "NOTE: signal_ex_thread done" << endl;
}

void signal_ex::signal_ex_method(void) {
	cout << "NOTE: signal_ex_method detected an EVENT!" << endl;
	cout << "----: count is " << count << " "
		 << "and count_sig is " << count_sig.read() << endl;
	cout << "----: traffic_temp is " << traffic_temp << " "
		 << "and traffic_sig is " << traffic_sig.read() << endl;
}
