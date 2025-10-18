#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(adder) {
	sc_out<int>	sum;	// declare an output port
    sc_out<int>	Cout;	// declare an output port
	sc_in<int>	A;	// declare an input port
    sc_in<int>	B;	// declare an input port
	sc_in<int>	Cin;	// declare an input port


	SC_CTOR(adder) {
		SC_THREAD(calc);
        sensitive << A << B << Cin;
		//SC_METHOD(react_method);
		//sensitive << in;
	}

	void calc(void); 
	//void react_method(void);
};
