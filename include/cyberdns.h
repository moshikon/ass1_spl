#ifndef CYBERDNS_H
#define CYBERDNS_H
#include <iostream>
#include <string>
#include <map>
#include "../include/cyberpc.h"
using namespace std;

class CyberPC; //Forward deceleration

class CyberDNS
{
private:
	map<const string, CyberPC &> cyber_DNS_;	//Hash map to hold PC names and pointers
public:
    CyberDNS();
    ~CyberDNS();
    void AddPC(CyberPC & cyber_pc_);
	CyberPC & GetCyberPC(const string & cyber_pc_name) const;
	vector<string> GetCyberPCList();

};
#endif
