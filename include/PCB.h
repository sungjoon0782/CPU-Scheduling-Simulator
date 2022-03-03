//
// Created by Sungjoon Kim on 2020-10-19.
//

#ifndef LAB2_PCB_H
#define LAB2_PCB_H
#include <iostream>
#include <iomanip>

class PCB {
private:
    int pid;
    int arrival;
    int CPU_burst;
    int priority;
    float finish;
    float waiting_time;
    float turn_around;
    float response_time;
    float first_response;
    int num_of_context;
    int process;
    bool response;
    
public:
    PCB();
    PCB(int new_pid, int new_arrival, int new_CPU_burst, int new_priority);
    
    const int get_pid();
    const int get_arrival();
    const int get_CPU_burst();
    const int get_priority();
    const float get_finish();
    const float get_waiting_time();
    const float get_turn_around();
    const float get_response_time();
    const float get_first_response();
    const int get_num_of_context();
    const int get_process();
    const bool get_response();

    void set_pid(int new_pid);
    void set_arrival(int new_arrival);
    void set_CPU_burst(int new_CPU_burst);
    void set_priority(int new_priority);
    void set_finish(float new_finish);
    void set_waiting_time(float new_waiting_time);
    void set_turn_around(float new_turn_around);
    void set_response_time(float new_response_time);
    void set_first_response(float new_first_response);
    void set_num_of_context(int new_num_of_context);
    void set_procesS(int new_process);

    void printPCB();
    void increment_context();
    void increment_process();
    void responsed();
    
    bool check_finish();
};


#endif //LAB2_PCB_H
