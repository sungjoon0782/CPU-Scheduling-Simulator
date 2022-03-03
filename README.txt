*Name: Sungjoon Kim
*Student ID: 107951338
*Class: CSCI 3453 (Operating System Concept)
*Lab #: 2

*Description: 

main.cpp: It reads input file, and store information of process control blocks.
	  With input 0, it does FCFS(First Come First Serve)
	  With input 1, it does SJF(Shortest Job First)
	  With input 2, it does PP(Preemptive Priority)
	  With input 3, it does RR(Round Robin) with second input quantum



PCB.h: It has information of 'PCB' class.
	1) Getters and Setters
	2) 'printPCB' that prints out information of PCB.
	3) 'increment_context' that increments the number of context switching of PCB.
	4) 'increment_process' that increments the number of processed CPU burst of PCB.
	5) 'responsed' changes 'response' to true if PCB has get responsed.
	6) 'check_finish' checks if the PCB has been finished or not.
	
	
	
PCB.cpp: It has implementation of PCB.h 



ready_queue.h: It has implementation of queue.
		1) Enqueue, Dequeue, Peek, isFull, isEmpty, size (basic functions of queue)
		2) 'get_front' returns the front object / 'get_rear' returns the rear object
		3) 'pri_sort' sorts the queue with priority of PCB
		4) 'sort_back' sorts it back to the original order, which is ordered with arrival time of PCB.






*Sample output:

sungjoon@sungjoon-VirtualBox:~/Downloads/Lab2/Kim1338$ ./Kim1338 input10 0
********************************************
******** Scheduling Algorithm: FCFS ********
********************************************
       pid   arrival CPU-burst      Pri.    finish   waiting      t.a.     resp.   Context
         1         0        10        37        10         0        10         0         0
         2         1         3         0        13         9        12         9         0
         3         2         8        51        21        11        19        11         0
         4         4         4        84        25        17        21        17         0
         5         5         5        44        30        20        25        20         0
         6         6         7        28        37        24        31        24         0
         7         9         2        97        39        28        30        28         0
         8        10         6        70        45        29        35        29         0
         9        13         1        15        46        32        33        32         0
        10        15         9         7        55        31        40        31         0
Average CPU burst time = 5.5 ms,      Average waiting time = 20.1 ms
Average turn around time = 25.6 ms,   Average response time = 20.1 ms
Total No. of Context Switching Performed = 0



sungjoon@sungjoon-VirtualBox:~/Downloads/Lab2/Kim1338$ ./Kim1338 input10 1
********************************************
******** Scheduling Algorithm: SJF *********
********************************************
       pid   arrival CPU-burst      Pri.    finish   waiting      t.a.     resp.   Context
         1         0        10        37        10         0        10         0         0
         2         1         3         0        15        11        14        11         0
         3         2         8        51        46        36        44        36         0
         4         4         4        84        20        12        16        12         0
         5         5         5        44        25        15        20        15         0
         6         6         7        28        38        25        32        25         0
         7         9         2        97        12         1         3         1         0
         8        10         6        70        31        15        21        15         0
         9        13         1        15        16         2         3         2         0
        10        15         9         7        55        31        40        31         0
Average CPU burst time = 5.5 ms,      Average waiting time = 14.8 ms
Average turn around time = 20.3 ms,   Average response time = 14.8 ms
Total No. of Context Switching Performed = 0



sungjoon@sungjoon-VirtualBox:~/Downloads/Lab2/Kim1338$ ./Kim1338 input10 2
********************************************
******** Scheduling Algorithm: PP *********
********************************************
       pid   arrival CPU-burst      Pri.    finish   waiting      t.a.     resp.   Context
         1         0        10        37        32        22        32         0         4
         2         1         3         0       4.5       0.5       3.5       0.5         0
         3         2         8        51        45        35        43        35         0
         4         4         4        84        55        47        51        47         0
         5         5         5        44        37        27        32        27         0
         6         6         7        28        14         1         8         1         0
         7         9         2        97        57        46        48        46         0
         8        10         6        70        51        35        41        35         0
         9        13         1        15      15.5       1.5       2.5       1.5         0
        10        15         9         7        26         2        11         2         0
Average CPU burst time = 5.5 ms,      Average waiting time = 21.7 ms
Average turn around time = 27.2 ms,   Average response time = 19.5 ms
Total No. of Context Switching Performed = 4



sungjoon@sungjoon-VirtualBox:~/Downloads/Lab2/Kim1338$ ./Kim1338 input10 3 4
********************************************
******** Scheduling Algorithm: RR ********
******** Quantum = 4              ********
********************************************
       pid   arrival CPU-burst      Pri.    finish   waiting      t.a.     resp.   Context
         1         0        10        37      47.5      37.5      47.5         0         2
         2         1         3         0       7.5       3.5       6.5       3.5         0
         3         2         8        51        40        30        38       5.5         1
         4         4         4        84        16         8        12         8         0
         5         5         5        44      48.5      38.5      43.5      15.5         1
         6         6         7        28      51.5      38.5      45.5        19         1
         7         9         2        97      31.5      20.5      22.5      20.5         0
         8        10         6        70      53.5      37.5      43.5      21.5         1
         9        13         1        15        41        27        28        27         0
        10        15         9         7        59        35        44        26         2
Average CPU burst time = 5.5 ms,      Average waiting time = 27.6 ms
Average turn around time = 33.1 ms,   Average response time = 14.65 ms
Total No. of Context Switching Performed = 8
