#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(EX_sensitivity_list) {
	sc_event evt2;

	SC_CTOR(EX_sensitivity_list){
		SC_THREAD(ex_thread);

		SC_METHOD(ex_method);
		sensitive << evt2;	// ex_method() is sensitive to evt2
	}

	void ex_thread(void);
	void ex_method(void);
};
