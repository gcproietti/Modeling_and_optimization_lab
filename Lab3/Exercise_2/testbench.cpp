#include "testbench.h"


void testbench::test(void) {

//    car1.write(0);
//    car2.write(0);
    cout << "car1: " << car1.read() << "car2: " << car2.read() << endl;
    wait(20, SC_SEC);
    car2.write(1);

    wait(20, SC_SEC);
    car1.write(1);

    wait(20, SC_SEC);
    car2.write(0);

    wait(5, SC_SEC);
    car1.write(0);

    wait(20, SC_SEC);
    car1.write(1);
    car2.write(1);

    wait(30, SC_SEC);
   sc_stop(); // End simulation
}