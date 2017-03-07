#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberexpert.h"
#include "../include/cyberpc.h"
using namespace std;

CyberExpert::CyberExpert(string cyber_expert_name_, int cyber_expert_work_time_, int cyber_expert_rest_time_, int cyber_expert_efficiency_):
cyber_expert_name_(cyber_expert_name_),
cyber_expert_work_time_(cyber_expert_work_time_),
cyber_expert_rest_time_(cyber_expert_rest_time_),
cyber_expert_efficiency_ (cyber_expert_efficiency_)
{
work =cyber_expert_work_time_;
rest = cyber_expert_rest_time_;
working = true;
}

CyberExpert::~CyberExpert(){
}

void CyberExpert::Clean(CyberPC & cyber_pc){
	cyber_pc.Disinfect();
}

string CyberExpert::getName() const {
	return cyber_expert_name_;
}

int CyberExpert::getWork() const {
	return cyber_expert_work_time_;
}

int CyberExpert::getRest() const {
	return cyber_expert_rest_time_;
}

int CyberExpert::getEfficiency() const {
	return cyber_expert_efficiency_;
}

CyberExpert::CyberExpert(const CyberExpert& other) :
	cyber_expert_name_(other.getName()),
	cyber_expert_work_time_(other.getWork()),
	cyber_expert_rest_time_(other.getRest()),
	cyber_expert_efficiency_(other.getEfficiency()),
	work(other.work),
	rest(other.rest),
	working(other.working)
{}

void CyberExpert::run(){
	if (work>0){
		work--;
		if (work == 0){
			cout << "	" + this->getName() + " is taking a break" << endl;
			working=false;
			rest=cyber_expert_rest_time_;
		}
	}else if (rest > 0){
		rest--;
		if (rest == 0){
			cout << "	" + this->getName() + " is back to work" << endl;
			working=true;
			work=cyber_expert_work_time_;
		}
	}
	else if (rest == 0){
		working=true;
		}
}
