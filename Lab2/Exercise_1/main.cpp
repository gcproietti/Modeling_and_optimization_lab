#include "systemc.h"
#include "EX_sensitivity_list.h"

int sc_main(int argc, char * argv[]) {
	EX_sensitivity_list inst("instance");

	sc_start();

	return 0;
}
