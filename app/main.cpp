#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "ready_queue.h"
#include "PCB.h"

void FCFS(std::vector<PCB> PCBs, ready_queue<PCB> ready){

    for (int i = 0; i < PCBs.size(); ++i){
    	ready.enqueue(PCBs[i]);
    }


    std::vector<PCB> PCB_vector;
    int total_burst_time = 0;
    int finish_time = 0;
    int waiting_time = 0;
    int response_time = 0;
    
    while(!ready.isEmpty()){
        PCB pcb = ready.dequeue();
        
        if(pcb.get_pid() == 1){
            pcb.set_waiting_time(0);
            pcb.set_response_time(0);
            total_burst_time += pcb.get_CPU_burst();
            pcb.set_finish(total_burst_time);
            finish_time = total_burst_time;
            pcb.set_turn_around(finish_time - pcb.get_arrival());
            PCB_vector.push_back(pcb);
        }
    
        else{
            pcb.set_waiting_time(finish_time - pcb.get_arrival());
            pcb.set_response_time(finish_time - pcb.get_arrival());
            total_burst_time += pcb.get_CPU_burst();
            pcb.set_finish(total_burst_time);
            finish_time = total_burst_time;
            pcb.set_turn_around(finish_time - pcb.get_arrival());
            PCB_vector.push_back(pcb);
        }
    }
    
    std::cout << "********************************************" << std::endl
    	      << "******** Scheduling Algorithm: FCFS ********" << std::endl
    	      << "********************************************" << std::endl;
    	      
    std::cout << std::setw(10) << "pid" << std::setw(10) << "arrival" << std::setw(10) << "CPU-burst" << std::setw(10)
    	      << "Pri." << std::setw(10) << "finish" << std::setw(10) << "waiting" << std::setw(10) 
    	      << "t.a." << std::setw(10) << "resp." << std::setw(10) << "Context" << std::endl;
    float cpu_sum = 0, wait_sum = 0, turn_sum = 0, resp_sum = 0, cont_sum = 0;    	      
    int size = PCB_vector.size();
    for(int i = 0; i < size; i++){
    	    cpu_sum += PCB_vector[i].get_CPU_burst();
    	    wait_sum += PCB_vector[i].get_waiting_time();
    	    turn_sum += PCB_vector[i].get_turn_around();
    	    resp_sum += PCB_vector[i].get_response_time();
    	    cont_sum += PCB_vector[i].get_num_of_context();
    	    PCB_vector[i].printPCB();
    }
    std::cout << "Average CPU burst time = " << cpu_sum/size << " ms,      "
    		  << "Average waiting time = " << wait_sum/size << " ms" << std::endl
    		  << "Average turn around time = " << turn_sum/size << " ms,   "
    		  << "Average response time = " << resp_sum/size << " ms" << std::endl
    		  << "Total No. of Context Switching Performed = " << cont_sum << std::endl;
}

void SJF(std::vector<PCB> PCBs){
    std::vector<PCB> temp_vec = PCBs;
    std::vector<PCB> PCB_vector;

    int total_burst_time = 0;
    int finish_time = 0;
    int waiting_time = 0;
    int response_time = 0;
    
    sort(temp_vec.begin(), temp_vec.end(), [](PCB& left, PCB& right){
    	if(left.get_CPU_burst() == right.get_CPU_burst()){
    	    return left.get_arrival() < right.get_arrival();
    	}
    	else{
        return left.get_CPU_burst() < right.get_CPU_burst();
        }
    });
    
    PCB pcb;
    
    for(int i = 0; i < temp_vec.size(); ++i){
    	if(temp_vec[i].get_arrival() == 0){
    	    pcb = temp_vec[i];
    	    temp_vec.erase(temp_vec.begin()+i);
    	}
    }
    pcb.set_waiting_time(0);
    pcb.set_response_time(0);
    total_burst_time += pcb.get_CPU_burst();
    pcb.set_finish(total_burst_time);
    finish_time = total_burst_time;
    pcb.set_turn_around(finish_time - pcb.get_arrival());
    PCB_vector.push_back(pcb);
    
    while(!temp_vec.empty()){
    	for(int i = 0; i < temp_vec.size(); ++i){
    	    if(temp_vec[i].get_arrival() <= total_burst_time){
    	    	pcb = temp_vec[i];
    	    	temp_vec.erase(temp_vec.begin()+i);
    	    	pcb.set_waiting_time(finish_time - pcb.get_arrival());
            	pcb.set_response_time(finish_time - pcb.get_arrival());
            	total_burst_time += pcb.get_CPU_burst();
            	pcb.set_finish(total_burst_time);
            	finish_time = total_burst_time;
            	pcb.set_turn_around(finish_time - pcb.get_arrival());
            	PCB_vector.push_back(pcb);
            	break;
    	    }
    	}
    }
    
    sort(PCB_vector.begin(), PCB_vector.end(), [](PCB& left, PCB& right){    	
        return left.get_pid() < right.get_pid();
    });
    
    std::cout << "********************************************" << std::endl
    	      << "******** Scheduling Algorithm: SJF *********" << std::endl
    	      << "********************************************" << std::endl;
    	      
    std::cout << std::setw(10) << "pid" << std::setw(10) << "arrival" << std::setw(10) << "CPU-burst" << std::setw(10)
    	      << "Pri." << std::setw(10) << "finish" << std::setw(10) << "waiting" << std::setw(10) 
    	      << "t.a." << std::setw(10) << "resp." << std::setw(10) << "Context" << std::endl;
    float cpu_sum = 0, wait_sum = 0, turn_sum = 0, resp_sum = 0, cont_sum = 0;    	      
    int size = PCB_vector.size();
    for(int i = 0; i < PCB_vector.size(); i++){
    	    cpu_sum += PCB_vector[i].get_CPU_burst();
    	    wait_sum += PCB_vector[i].get_waiting_time();
    	    turn_sum += PCB_vector[i].get_turn_around();
    	    resp_sum += PCB_vector[i].get_response_time();
    	    cont_sum += PCB_vector[i].get_num_of_context();
    	    PCB_vector[i].printPCB();
    }
    std::cout << "Average CPU burst time = " << cpu_sum/size << " ms,      "
    		  << "Average waiting time = " << wait_sum/size << " ms" << std::endl
    		  << "Average turn around time = " << turn_sum/size << " ms,   "
    		  << "Average response time = " << resp_sum/size << " ms" << std::endl
    		  << "Total No. of Context Switching Performed = " << cont_sum << std::endl;
}

void PP(std::vector<PCB> &PCBs, ready_queue<PCB> ready_queue, int total_burst){
    std::vector<PCB> complete_vec;
    	int burst_count = 0;
    	float time = 0;
    	

    	PCB current;
    	
    	while(total_burst > burst_count){
    	
    	    if(burst_count == 0 && PCBs.front().get_arrival() == 0){
    	    	current = PCBs.front();
    	    	PCBs.erase(PCBs.begin());
    	    	current.set_first_response(time);
    	    	current.responsed();
    	    }
    	    
    	    else if(burst_count == PCBs.front().get_arrival()){
    	    	if(current.get_priority() <= PCBs.front().get_priority()){
    	    	    ready_queue.enqueue(PCBs.front());
    	    	    PCBs.erase(PCBs.begin());
    	    	}
    	    	else if(current.get_priority() > PCBs.front().get_priority()){
    	    	    time += 0.5;
    	    	    current.increment_context();
    	    	    ready_queue.enqueue(current);
    	    	    current = PCBs.front();
    	    	    current.set_first_response(time);
    	    	    current.responsed();
    	    	    PCBs.erase(PCBs.begin());
    	    	}
    	    }
    	    
    	    ++burst_count;
    	    ++time;
    	    current.increment_process();
    	  
    	    if(current.check_finish()){
    	        current.set_finish(time);
    	        current.set_waiting_time(time - current.get_CPU_burst() - current.get_arrival());
    	        current.set_turn_around(current.get_finish() - current.get_arrival());
    	        current.set_response_time(current.get_first_response() - current.get_arrival());
    	        complete_vec.push_back(current);
    	        if(total_burst == burst_count){break;}
    	        int a = ready_queue.get_front();
    		int b = ready_queue.get_rear();
    	        ready_queue.pri_sort(a, b);
    	        current = ready_queue.dequeue();
    	        if(current.get_response() == false){
    	            current.responsed();
    	            current.set_first_response(time);
    	        }
    	    }
    	}
    	
    	std::sort(complete_vec.begin(), complete_vec.end(), [](auto && lhs, auto && rhs){return lhs.get_arrival() < rhs.get_arrival();});
    	
    	
    	std::cout << "********************************************" << std::endl
    	      << "******** Scheduling Algorithm: PP *********" << std::endl
    	      << "********************************************" << std::endl;
    	      
    std::cout << std::setw(10) << "pid" << std::setw(10) << "arrival" << std::setw(10) << "CPU-burst" << std::setw(10)
    	      << "Pri." << std::setw(10) << "finish" << std::setw(10) << "waiting" << std::setw(10) 
    	      << "t.a." << std::setw(10) << "resp." << std::setw(10) << "Context" << std::endl;
    	float cpu_sum = 0, wait_sum = 0, turn_sum = 0, resp_sum = 0, cont_sum = 0;  
    	int size = complete_vec.size();
    	for(int i = 0; i < size; i++){
    	    cpu_sum += complete_vec[i].get_CPU_burst();
    	    wait_sum += complete_vec[i].get_waiting_time();
    	    turn_sum += complete_vec[i].get_turn_around();
    	    resp_sum += complete_vec[i].get_response_time();
    	    cont_sum += complete_vec[i].get_num_of_context();
    	    complete_vec[i].printPCB();
    	}
    	std::cout << "Average CPU burst time = " << cpu_sum/size << " ms,      "
    		  << "Average waiting time = " << wait_sum/size << " ms" << std::endl
    		  << "Average turn around time = " << turn_sum/size << " ms,   "
    		  << "Average response time = " << resp_sum/size << " ms" << std::endl
    		  << "Total No. of Context Switching Performed = " << cont_sum << std::endl;
    	

}


void RR(std::vector<PCB> PCBs, ready_queue<PCB> ready_queue, int quantum, int total_burst){
    	
    	std::vector<PCB> complete_vec;
    	int burst_count = 0;
    	float time = 0;
    	PCB current;

    	while(total_burst > burst_count){
            bool did_finish = false;
    	    if(burst_count == 0 && PCBs.front().get_arrival() == 0){
    	        current = PCBs.front();
    	        PCBs.erase(PCBs.begin());
    	        current.set_first_response(time);
    	        current.responsed();
    	    } 
    	    
    	    for(int i = 0; i < quantum; ++i){
    	        current.increment_process();
    	        ++burst_count;
    	        ++time;
    	        
    	        if(burst_count == PCBs.front().get_arrival()){
    	            ready_queue.enqueue(PCBs.front());
    	            PCBs.erase(PCBs.begin());
    	    	}
    	    
    	        if(current.check_finish()){
    	            current.set_finish(time);
    	            current.set_waiting_time(time - current.get_CPU_burst() - current.get_arrival());
    	            current.set_turn_around(current.get_finish() - current.get_arrival());
    	            current.set_response_time(current.get_first_response() - current.get_arrival());
    	            complete_vec.push_back(current);
    	            if(ready_queue.isEmpty()){
    	                break;
    	            }
    	            else{
    	                current = ready_queue.dequeue();
    	                if(!current.get_response()){
    	                    current.responsed();
    	                    current.set_first_response(time);
    	                } 
    	            }
    	            did_finish = true;
    	            break;
    	        }
    	    }
    	    
    	    if(!did_finish){
    	        current.increment_context();
    	        time += 0.5;
    	        ready_queue.enqueue(current);
    	        current = ready_queue.dequeue();
    	        if(!current.get_response()){
    	            current.responsed();
    	            current.set_first_response(time);
    	        }
    	    }
    	}
    	
    	std::sort(complete_vec.begin(), complete_vec.end(), [](auto && lhs, auto && rhs){return lhs.get_arrival() < rhs.get_arrival();});
    	
    	
    	std::cout << "********************************************" << std::endl
    	      << "******** Scheduling Algorithm: RR ********" << std::endl
    	      << "******** Quantum = " << quantum << "              ********" << std::endl
    	      << "********************************************" << std::endl;
    	      
    std::cout << std::setw(10) << "pid" << std::setw(10) << "arrival" << std::setw(10) << "CPU-burst" << std::setw(10)
    	      << "Pri." << std::setw(10) << "finish" << std::setw(10) << "waiting" << std::setw(10) 
    	      << "t.a." << std::setw(10) << "resp." << std::setw(10) << "Context" << std::endl;
    	      
    	float cpu_sum = 0, wait_sum = 0, turn_sum = 0, resp_sum = 0, cont_sum = 0;
    	int size = complete_vec.size();
    	for(int i = 0; i < size; i++){
    	    cpu_sum += complete_vec[i].get_CPU_burst();
    	    wait_sum += complete_vec[i].get_waiting_time();
    	    turn_sum += complete_vec[i].get_turn_around();
    	    resp_sum += complete_vec[i].get_response_time();
    	    cont_sum += complete_vec[i].get_num_of_context();
    	    complete_vec[i].printPCB();
    	}
    	
    	std::cout << "Average CPU burst time = " << cpu_sum/size << " ms,      "
    		  << "Average waiting time = " << wait_sum/size << " ms" << std::endl
    		  << "Average turn around time = " << turn_sum/size << " ms,   "
    		  << "Average response time = " << resp_sum/size << " ms" << std::endl
    		  << "Total No. of Context Switching Performed = " << cont_sum << std::endl;

}



int main(int argc, char* argv[]) {

    int type = atoi(argv[2]);
    std::string input_file = argv[1];
    std::ifstream infile;
    std::string line;
    std::vector<PCB> PCBs;
    int total_burst = 0;
    int count = 0;    
    
    infile.open(input_file);
    if(!infile){
    	std::cout << "Error with openning the file" << std::endl;
    	return -1;
    }

    while(std::getline(infile, line)){
    	std::istringstream iss(line);
    	int a, b, c, d;
    	if(!(iss >> a >> b >> c >> d)) {break;}
    	PCB temp(a, b, c, d);
    	total_burst += c;
    	PCBs.push_back(temp);
    	++count;
    }
    infile.close();
	
    ready_queue<PCB> ready_queue(count);
    
    if(type == 0){
        FCFS(PCBs, ready_queue);
    }
    
    else if(type == 1){
    	SJF(PCBs);
    }
    
    else if(type == 2){
        PP(PCBs, ready_queue, total_burst);	
    }
    
    
    
    else if(type == 3){
    	if(argv[3] == NULL){
    	    std::cout << "No quantum size was entered." << std::endl;
    	    return -1;
    	}    	
    	int quantum = atoi(argv[3]);    	
    	RR(PCBs, ready_queue, quantum, total_burst);
    }
    
    
    return 0;
}
