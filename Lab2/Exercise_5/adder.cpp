#include "adder.h"

void adder::calc(void) {

    while(1){
        wait(); // wait for any input change

        int a = A.read();
        int b = B.read();
        int cin = Cin.read();

        int s = a ^ b ^ cin; // sum calculation
        int cout = (a & b) ^ (cin & (a ^ B)); // carry-out calculation

        sum.write(s);
        Cout.write(cout);

        std::cout << "Adder calculated: A=" << a << " B=" << b << " Cin=" << cin 
             << " => Sum=" << s << " Cout=" << cout << " @ " << sc_time_stamp() << std::endl;
    }
}