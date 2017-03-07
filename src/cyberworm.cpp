#include <iostream>
#include <string>
#include <vector>
#include "../include/cyberworm.h"
using namespace std;

//constructor
CyberWorm::CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time):
   	cyber_worm_os_(cyber_worm_os),
	cyber_worm_name_(cyber_worm_name),
	cyber_worm_dormancy_time_(cyber_worm_dormancy_time)
{}

//copy constructor
CyberWorm::CyberWorm(const CyberWorm& other):
   	cyber_worm_os_(other.getOs()),
    cyber_worm_name_(other.getName()),
	cyber_worm_dormancy_time_(other.getDormancyTime())
{}

CyberWorm::~CyberWorm(){
}

//getters
string CyberWorm::getOs() const {
	return cyber_worm_os_;
}

string CyberWorm::getName() const{
	return cyber_worm_name_;
}

int CyberWorm::getDormancyTime() const{
	return cyber_worm_dormancy_time_;
}

