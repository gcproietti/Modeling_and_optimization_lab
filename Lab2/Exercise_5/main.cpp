#include "systemc.h"
#include "adder.h"
#include "testbench.h"

int sc_main(int argc, char * argv[]) {
	sc_signal<int>	sig_A;
	sc_signal<int>	sig_B;
    sc_signal<int>	sig_Cin;
    sc_signal<int>	sig_Cout;
    sc_signal<int>	sig_sum;

    testbench	tb_inst("tb");
	adder	adder_inst("add");
	
	adder_inst.A(sig_A);	
    adder_inst.B(sig_B);		
    adder_inst.Cin(sig_Cin);
    adder_inst.sum(sig_sum);
    adder_inst.Cout(sig_Cout);

    tb_inst.A(sig_A);
    tb_inst.B(sig_B);
    tb_inst.Cin(sig_Cin);
    tb_inst.sum(sig_sum);
    tb_inst.Cout(sig_Cout);	

	sc_start();

	return 0;
}