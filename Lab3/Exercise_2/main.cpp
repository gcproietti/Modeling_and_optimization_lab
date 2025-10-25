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
#include "testbench.h"


int sc_main(int argc, char* argv[]) {
    

	sc_signal<bool>	sig_car1;
	sc_signal<bool>	sig_car2;
    sc_signal<int>	sig_light1;
    sc_signal<int>	sig_light2;

    sig_car1.write(false);
    sig_car2.write(false);
    sig_light1.write(GREEN);
    sig_light2.write(RED);

    testbench	tb_inst("testbench");
	traffic_light	light_inst("traffic_light");
	
	light_inst.car1(sig_car1);	
    light_inst.car2(sig_car2);
    light_inst.light1(sig_light1);
    light_inst.light2(sig_light2);

    tb_inst.car1(sig_car1);
    tb_inst.car2(sig_car2);
    tb_inst.light1(sig_light1);
    tb_inst.light2(sig_light2);

	sc_start();


	//cout << "INFO: Post-processing " << simulation_name << endl;

	return 0;
}