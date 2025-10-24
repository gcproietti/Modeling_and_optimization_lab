#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(testbench) {

    sc_out<int>	car1;	
    sc_out<int>	car2;	
    sc_in<color>	light1;	
    sc_in<color>	light2;	

    SC_CTOR(testbench) {
        // register a thread to generate stimulus; do NOT add a sensitivity list here
        SC_THREAD(test);
        // SC_THREAD will start at time 0 and can use wait()
    }

    void test(void); 
    //void react_method(void);
};