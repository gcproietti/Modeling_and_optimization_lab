#include "traffic_light.h"

void traffic_light :: light_thread(void){
    while(1){
        //light1.write(GREEN);
        wait();  //wait until coming of one car
        if(car2.read() == 1  && light2.read() == RED ){
            light1.write(YELLOW);
            wait(5, SC_SEC);
            light1.write(RED);
            light2.write(GREEN);
            wait(10, SC_SEC);
        }

        if(car1.read() == 1 && light2.read() == GREEN){
            light2.write(YELLOW);
            wait(5, SC_SEC);
            light2.write(RED);
            light1.write(GREEN);
            wait(10, SC_SEC);
        }

        if(car1.read() == 0 && car2.read() == 0 && light2.read() == GREEN){
            light2.write(YELLOW);
            wait(5, SC_SEC);
            light2.write(RED);
            light1.write(GREEN);
            wait(10, SC_SEC);
        }
        
    }
}