#define SIZE 10
#include <iostream>
#include <cstdlib>

template <class C>
class ready_queue {
private:
    C *arr;
    int front, rear, count, capacity;

public:
    ready_queue(int size = SIZE);
    C dequeue();
    void enqueue(C c);
    C peek();
    int size();
    bool isEmpty();
    bool isFull();
    void pri_sort(int low, int high);
    void sort_back(int low, int high);
    int get_front();
    int get_rear();
};

template <class C>
ready_queue<C>::ready_queue(int size){
    arr = new C[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}


template <class C>
C ready_queue<C>::dequeue(){
    if(isEmpty()){
    	std::cout << "The queue is empty. Can't dequeue" << std::endl;
    	exit(EXIT_FAILURE);
    }
    
    C a = arr[front];
    
    front = (front + 1) % capacity;
    count--;
    return a;
}

template <class C>
void ready_queue<C>::enqueue(C item){
    if(isFull()){
        std::cout << "The queue is full." << std::endl;
        exit(EXIT_FAILURE);
    }
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    ++count;
}

template <class C>
C ready_queue<C>::peek(){
    if(isEmpty()){
    	std::cout << "The queue is empty. Can't get the peek" << std::endl;
    	exit(EXIT_FAILURE);
    }
    return arr[front];
}

template <class C>
int ready_queue<C>::size(){
    return count;
}

template <class C>
bool ready_queue<C>::isEmpty(){
    return (size() == 0);
}

template <class C>
bool ready_queue<C>::isFull(){
    return (size() == capacity);
}

template <class C>
int ready_queue<C>::get_front(){
    return front;
}

template <class C>
int ready_queue<C>::get_rear(){
    return rear;
}

template <class C>
void ready_queue<C>::pri_sort(int low, int high){

    if(isEmpty()){
    	std::cout << "The queue is empty. Can't get the peek" << std::endl;
    	exit(EXIT_FAILURE);
    }

    if (low < high){
    C pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 
    
    for (int j = low; j <= high - 1; j++) {
	// If current element is smaller than the pivot 
	if (arr[j].get_priority() < pivot.get_priority()) { 
	    i++; // increment index of smaller element 
	    C t = arr[i]; 
	    arr[i] = arr[j]; 
	    arr[j] = t; 
	}
    } 

    C t = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = t; 

    int pi = i+1;
    
    pri_sort(low, pi - 1); 
    pri_sort(pi + 1, high); 
    }
}

template <class C>
void ready_queue<C>::sort_back(int low, int high){

    if(isEmpty()){
    	std::cout << "The queue is empty. Can't get the peek" << std::endl;
    	exit(EXIT_FAILURE);
    }

    if (low < high){
    C pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 
    
    for (int j = low; j <= high - 1; j++) {
	// If current element is smaller than the pivot 
	if (arr[j].get_arrival() < pivot.get_arrival()) { 
	    i++; // increment index of smaller element 
	    C t = arr[i]; 
	    arr[i] = arr[j]; 
	    arr[j] = t; 
	}
    } 

    C t = arr[i + 1]; 
    arr[i + 1] = arr[high]; 
    arr[high] = t; 

    int pi = i+1;
    
    sort_back(low, pi - 1); 
    sort_back(pi + 1, high); 
    }
}
