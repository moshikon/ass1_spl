#ifndef CYBER_EXPERT
#define CYBER_EXPERT
#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberpc.h"
using namespace std;

class CyberExpert
{
private:
	const string cyber_expert_name_;
    const int cyber_expert_work_time_;
    const int cyber_expert_rest_time_;
    const int cyber_expert_efficiency_;

public:
    int work;
    int rest;
    bool working;

    CyberExpert(); // Prevent the use of an empty constructor
    ~CyberExpert();
    CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_);
 	void Clean(CyberPC & cyber_pc);
 	void run();
 	CyberExpert(const CyberExpert& other); //copy constructor;
	string getName() const ;
	int getWork() const ;
	int getRest() const ;
	int getEfficiency() const ;

};

#endif
