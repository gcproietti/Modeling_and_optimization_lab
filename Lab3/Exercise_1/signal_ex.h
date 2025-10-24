/*
 * signal_ex.h
 *
 *  Created on: Aug 27, 2010
 *      Author: songzhenyu
 */

#ifndef SIGNAL_EX_H_
#define SIGNAL_EX_H_
#include <iostream>
#include <string>
using namespace std;
#include <systemc.h>
SC_MODULE(signal_ex) {
	enum color {
		BLACK,
		RED,
		GREEN,
		BLUE,
		YELLOW,
		MAGENTA,
		CYAN,
		WHITE
	};

	// local data declarations
	int 				count;
	color				traffic_temp;

	// local channels
	sc_signal<int>			count_sig;
	sc_signal<color>		traffic_sig;

	SC_CTOR(signal_ex){
		SC_THREAD(signal_ex_thread);
		SC_METHOD(signal_ex_method);
			sensitive << count_sig << traffic_sig;
	}

	void signal_ex_thread(void);
	void signal_ex_method(void);
};
#endif /* SIGNAL_EX_H_ */
