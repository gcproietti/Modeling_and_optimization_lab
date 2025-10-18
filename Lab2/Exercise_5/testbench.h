#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(testbench) {
    // corrected port directions: TB drives A,B,Cin and monitors sum,Cout
    sc_out<int>	A;	// drive input A
    sc_out<int>	B;	// drive input B
    sc_out<int>	Cin;	// drive input Cin
    sc_in<int>	sum;	// read sum output
    sc_in<int>	Cout;	// read carry-out output

    SC_CTOR(testbench) {
        // register a thread to generate stimulus; do NOT add a sensitivity list here
        SC_THREAD(test);
        // SC_THREAD will start at time 0 and can use wait()
    }

    void test(void); 
    //void react_method(void);
};