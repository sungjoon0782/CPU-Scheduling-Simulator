//
// Created by Sungjoon Kim on 2020-10-19.
//


#include "PCB.h"

PCB::PCB(){
    pid = 0;
    arrival = 0;
    CPU_burst = 0;
    priority = 0;
    finish = 0.0;
    waiting_time = 0.0;
    turn_around = 0.0;
    response_time = 0.0;
    first_response = 0.0;
    num_of_context = 0;
    response = false;
}

PCB::PCB(int new_pid, int new_arrival, int new_CPU_burst, int new_priority){
    pid = new_pid;
    arrival = new_arrival;
    CPU_burst = new_CPU_burst;
    priority = new_priority;
    finish = 0.0;
    waiting_time = 0.0;
    turn_around = 0.0;
    response_time = 0.0;
    first_response = 0.0;
    num_of_context = 0;
    response = false;
}

const int PCB::get_pid(){return pid;}
const int PCB::get_arrival(){return arrival;}
const int PCB::get_CPU_burst(){return CPU_burst;}
const int PCB::get_priority(){return priority;}
const float PCB::get_finish(){return finish;}
const float PCB::get_waiting_time(){return waiting_time;}
const float PCB::get_turn_around(){return turn_around;}
const float PCB::get_response_time(){return response_time;}
const float PCB::get_first_response(){return first_response;}
const int PCB::get_num_of_context(){return num_of_context;}
const int PCB::get_process(){return process;}
const bool PCB::get_response(){return response;}

void PCB::set_pid(int new_pid){pid = new_pid;}
void PCB::set_arrival(int new_arrival){arrival = new_arrival;}
void PCB::set_CPU_burst(int new_CPU_burst){CPU_burst = new_CPU_burst;}
void PCB::set_priority(int new_priority){priority = new_priority;}
void PCB::set_finish(float new_finish){finish = new_finish;}
void PCB::set_waiting_time(float new_waiting_time){waiting_time = new_waiting_time;}
void PCB::set_turn_around(float new_turn_around){turn_around = new_turn_around;}
void PCB::set_response_time(float new_response_time){response_time = new_response_time;}
void PCB::set_first_response(float new_first_response){first_response = new_first_response;}
void PCB::set_num_of_context(int new_num_of_context){num_of_context = new_num_of_context;}
void PCB::set_procesS(int new_process){process = new_process;}

void PCB::increment_context(){
    ++num_of_context;
}

void PCB::increment_process(){
    ++process;
}

void PCB::printPCB(){
    std::cout << std::setw(10) << pid << std::setw(10) << arrival << std::setw(10) << CPU_burst << std::setw(10) << priority 
              << std::setw(10) << finish << std::setw(10) << waiting_time << std::setw(10) << turn_around 
              << std::setw(10) << response_time << std::setw(10) << num_of_context << std::endl;

}

bool PCB::check_finish(){
    if (process == CPU_burst){
        return true;
    }
    else {return false;}
}

void PCB::responsed(){
    response = true;
}
