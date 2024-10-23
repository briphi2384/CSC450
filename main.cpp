//  main.cpp
//  CTAmod7
//  Created by Brian Phipps on 10/23/24.

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
std::condition_variable var;
bool isDone = false; //will indicate when first thread finishes

//first thread counts up to 20
void countUp(){
    for (int i =0; i <=20; i++){ // repeat 20 times
        std::lock_guard<std::mutex> lock(mtx); //locks mutex
        std::cout<<"Count: "<<i << std::endl;
    }//end for
    //set flag and notify second thread
    std::lock_guard<std::mutex> lock(mtx); //lock mutex
    isDone = true;
    var.notify_one(); //notifies second thread to start counting down
}

//second thread counts down to 0
void countDown() {
    std::unique_lock<std::mutex> lock(mtx); //locks mutex for synchronization
    var.wait(lock, [] {return isDone;}); //waits for first thread to finish
    
    //when notified, begin counting down
    for (int i =20; i >=0; --i){
        std::cout <<"Count: " << i << std::endl;
    }
}

int main() {
    //create and join the two threads
    std::thread t1(countUp);
    std::thread t2(countDown);
    
    t1.join();
    t2.join();
    
    return 0;
}
