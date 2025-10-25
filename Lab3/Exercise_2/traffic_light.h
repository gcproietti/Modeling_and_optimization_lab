#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

const int GREEN = 0;
const int YELLOW = 1;
const int RED = 2;

SC_MODULE(traffic_light) {

    sc_in<bool> car1;
    sc_in<bool> car2;
    sc_out<int> light1;
    sc_out<int> light2;

    SC_CTOR(traffic_light){
		SC_THREAD(light_thread);
			sensitive << car1 << car2;
	};

    void light_thread(void);

};