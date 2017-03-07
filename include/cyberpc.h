#ifndef CYBER_PC
#define CYBER_PC
#include <iostream>
#include <string>
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"
using namespace std;

class CyberDNS; // Forward decleration

class CyberPC
{
private:
    const string cyber_pc_os_;
    const string cyber_pc_name_;
    vector<string> cyber_pc_connections_;
    CyberWorm * cyber_worm_ = NULL;
    CyberPC();
    int cyber_pc_time_to_infect_;
 
public:
    ~CyberPC();
    CyberPC(string cyber_pc_os_, string cyber_pc_name_);// Only use this constructor
    CyberPC(const CyberPC & other);
    string getName() const;
	void AddConnection(string  second_pc);					// Add a connection to this PC
	void Infect(CyberWorm & worm); 								// Add a worm to this PC
	void Run(const CyberDNS & server); 							// Activate PC and infect others if worm is active
	void Disinfect();											// called by cyber expert, disinfect PC
	string getOs() const ;
	CyberWorm * getworm() const ;
	vector<string> & getconnections()  ;
    CyberDNS * dns;
};

#endif
