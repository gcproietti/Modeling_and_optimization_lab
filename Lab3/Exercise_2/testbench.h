#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

//const int GREEN = 0;
//const int YELLOW = 1;
//const int RED = 2;

SC_MODULE(testbench) {

    sc_out<bool>	car1;	
    sc_out<bool>	car2;	
    sc_in<int>	light1;	
    sc_in<int>	light2;

    SC_CTOR(testbench) {
        // register a thread to generate stimulus; do NOT add a sensitivity list here
        SC_THREAD(test);
        // SC_THREAD will start at time 0 and can use wait()
    }

    void test(void); 
    //void react_method(void);
};