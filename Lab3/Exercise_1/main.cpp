/*
 * main.cpp
 *
 *  Created on: Aug 27, 2010
 *      Author: songzhenyu
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
#include "signal_ex.h"

unsigned errors = 0;
string simulation_name = "signal_ex";

int sc_main(int argc, char* argv[]) {
	cout << "INFO: Elaborating " << simulation_name << endl;
	signal_ex signal_ex_i("signal_ex_i");
	cout << "INFO: Simulating " << simulation_name << endl;
	sc_start();

	cout << "INFO: Post-processing " << simulation_name << endl;
	cout << "INFO: Simulation " << simulation_name
		 << " " << (errors? "FAILED":"PASSED")
		 << " with " << errors << " errors"
		 << endl;

	return 0;
}
