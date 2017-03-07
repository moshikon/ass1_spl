#include <iostream>
#include <string>
#include <map>
#include "../include/cyberschedule.h"
#include "../include/cyberexpert.h"
#include "../include/cyberdns.h"
using namespace std;

CyberSchedule::CyberSchedule(){
}

CyberSchedule::~CyberSchedule(){
}

void CyberSchedule::AddExpert(CyberExpert & expert){
	const string cyber_expert_name=expert.getName();
	cyber_schedule_.insert(pair<const string, CyberExpert &>(cyber_expert_name, expert));
}

CyberExpert & CyberSchedule::GetCyberExpert(const string & cyber_expert_name) const{
	return cyber_schedule_.find(cyber_expert_name)->second;
}

vector<string> CyberSchedule::GetCyberExpertList(){ // Return list of Experts as a vector of strings
	vector<string> expertList;
	map<const string, CyberExpert &>::reverse_iterator it;
	for (it = cyber_schedule_.rbegin(); it!= cyber_schedule_.rend(); ++it)
		expertList.push_back(it->first);
	return expertList;
}

void CyberSchedule::Scan(CyberDNS & server){
	vector<string> PCList = server.GetCyberPCList();
	int counter=0;
	map<const string, CyberExpert &>::reverse_iterator it;
	for (it = cyber_schedule_.rbegin(); it!=cyber_schedule_.rend(); ++it){
		CyberExpert & curr= it->second;
		if (curr.working){
			int iterates=0;
			for (int j=counter ; (unsigned)j < curr.getEfficiency()+(unsigned)counter && (unsigned)j < PCList.size() ; j++){
				string const &temp = PCList[j];
				CyberPC & pc = server.GetCyberPC(temp);
				cout <<"	" +  curr.getName() + " examining " + pc.getName() << endl;
				curr.Clean(pc);
				iterates++;
			}
			counter= counter + iterates;
		}
	}
}
