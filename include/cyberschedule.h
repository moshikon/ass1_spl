#ifndef CYBERSCHEDULE_H
#define CYBERSCHEDULE_H
#include <iostream>
#include <string>
#include <map>
#include "../include/cyberexpert.h"
#include "../include/cyberdns.h"
using namespace std;

class CyberExpert; // Forward decleration

class CyberSchedule
{
public:
	map<const string, CyberExpert &> cyber_schedule_;	//Hash map to hold Experts names and pointers
	CyberSchedule();
	~CyberSchedule();
    void AddExpert(CyberExpert & expert);
	void Scan( CyberDNS & server);
	CyberExpert & GetCyberExpert(const string & cyber_expert_name) const;
	vector<string> GetCyberExpertList();

};
#endif
