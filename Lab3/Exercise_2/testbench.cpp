#include "testbench.h"


void testbench::test(void) {
    // Test vectors
    int test_vectors[8][2] = {
        {0, 0}, //car2, car1
        {0, 1},
        {1, 0},
        {1, 1},
    };

    for (int i = 0; i < 8; ++i) {
        A.write(test_vectors[i][0]);
        B.write(test_vectors[i][1]);
        Cin.write(test_vectors[i][2]);

        std::cout << "Testbench applied: A=" << test_vectors[i][0]
             << " B=" << test_vectors[i][1]
             << " Cin=" << test_vectors[i][2]
             << " @ " << sc_time_stamp() << std::endl;

        wait(10, SC_NS); // wait for 10 ns before applying next vector
    }

    sc_stop(); // End simulation
}