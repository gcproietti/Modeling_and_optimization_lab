#include "systemc.h"
#include <iostream>
using std::cout;
using std::endl;

SC_MODULE(traffic_light) {
    

    sc_in<bool> car1;
    sc_in<bool> car2;
    sc_out<color> light1 == GREEN;
    sc_out<color> light2 == RED;

    SC_CTOR(traffic_light){
		SC_THREAD(light_thread);
			sensitive << car;
	}

    void light_thread(void);

}