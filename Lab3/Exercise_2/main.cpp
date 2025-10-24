/*
 * main.cpp
 *
 *  Created on: Oct 24, 2025
 *      Author: gcproietti
 * 
 */

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
using std::cout;
using std::endl;
using std::setw;
using std::string;
#include <systemc.h>
#include "traffic_light.h"



int sc_main(int argc, char* argv[]) {
    enum color {
        GREEN,
        YELLOW,
        RED
    };
	sc_signal<bool>	sig_car1;
	sc_signal<bool>	sig_car2;
    sc_signal<color>	sig_light1;
    sc_signal<color>	sig_light2;

    testbench	tb_inst("tb");
	traffic_light	light_inst("light");
	
	light_inst.car1(sig_car1);	
    light_inst.car2(sig_car2);

    tb_inst.A(sig_A);
    tb_inst.B(sig_B);
    tb_inst.Cin(sig_Cin);
    tb_inst.sum(sig_sum);
    tb_inst.Cout(sig_Cout);	

	sc_start();


	cout << "INFO: Post-processing " << simulation_name << endl;

	return 0;
}