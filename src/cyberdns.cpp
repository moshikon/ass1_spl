#include <iostream>
#include <string>
#include <map>
#include "../include/cyberdns.h"
#include "../include/cyberpc.h"
using namespace std;

 CyberDNS::CyberDNS(){
 }

 CyberDNS::~CyberDNS(){
 }

void CyberDNS::AddPC(CyberPC & cyber_pc_){
	CyberPC * pc = new CyberPC (cyber_pc_);
	const string pcName=pc->getName();
	cyber_DNS_.insert(pair<const string, CyberPC &>(pcName, *pc));
	pc->dns=this;
	cout <<"Adding to server: "+ pc->getName()<< endl;
	cout <<pc->getName()+ " connected to server" << endl;
	pc=NULL;
}

CyberPC & CyberDNS::GetCyberPC(const string & cyber_pc_name) const{
	return cyber_DNS_.find(cyber_pc_name)->second;
}

vector<string> CyberDNS::GetCyberPCList(){ // Return list of PC's as a vector of strings
	vector<string> PCList;
	map<const string, CyberPC &>::reverse_iterator it;
	for (it = cyber_DNS_.rbegin(); it!= cyber_DNS_.rend(); ++it)
		PCList.push_back(it->first);
	return PCList;
}
