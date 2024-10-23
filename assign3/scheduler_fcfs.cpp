/**
* Assignment 3: CPU Scheduler
 * @file scheduler_fcfs.cpp
 * @author : Alejandro Zuniga and Sierra Norris
 * @brief This Scheduler class implements the FCSF scheduling algorithm.
 * @version 0.1
 */
//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

//You must complete the all parts marked as "TODO". Delete "TODO" after you are done.
// Remember to add sufficient and clear comments to your code

#include "scheduler_fcfs.h"
#include <iostream>
#include <vector>

// Constructor
SchedulerFCFS::SchedulerFCFS() {
    curr_proc = nullptr;  // No active process at start
    wait_sum = 0;         // Initialize total wait time
    turn_sum = 0;         // Initialize total turnaround time
}

// Destructor
SchedulerFCFS::~SchedulerFCFS() {}

// Initialization function
void SchedulerFCFS::init(std::vector<PCB>& procs) {
    // Add all processes to the ready queue
    for (auto& p : procs) {
        queue.push_back(p);
    }
}

// Print simulation results
void SchedulerFCFS::print_results() {
    time = 0;  // Reset simulation time
    for (auto& p : queue) {
        // Calculate and display turnaround and wait time
        std::cout << p.name << " turnaround time = "
                  << (p.burst_time + time) - p.arrival_time
                  << ", wait time = " << (time - p.arrival_time) << std::endl;
        time += p.burst_time;
    }
    // Display average wait and turnaround times
    std::cout << "Average wait time: "
              << static_cast<double>(wait_sum) / queue.size() << std::endl;
    std::cout << "Average turnaround time: "
              << static_cast<double>(turn_sum) / queue.size() << std::endl;
}

// Simulate the FCFS scheduling process
void SchedulerFCFS::simulate() {
    // Execute each process in arrival order
    for (auto& p : queue) {
        std::cout << "Running Process " << p.name
                  << " for " << p.burst_time << " time units" << std::endl;
        wait_sum += (time - p.arrival_time);
        turn_sum += (p.burst_time + time);
        time += p.burst_time;
    }
}
