#include <iostream>
#include <string>
#include "../include/cyberpc.h"
#include "../include/cyberworm.h"
#include "../include/cyberdns.h"
using namespace std;

CyberPC::CyberPC(string os, string name):
		cyber_pc_os_(os),cyber_pc_name_(name),cyber_pc_time_to_infect_(-1){}

CyberPC::CyberPC(const CyberPC & other):
		cyber_pc_os_(other.getOs()),
		cyber_pc_name_(other.getName()),
		cyber_pc_time_to_infect_(other.cyber_pc_time_to_infect_){}

CyberPC::~CyberPC(){
	if (cyber_worm_ != NULL){
		delete cyber_worm_;
		cyber_worm_=NULL;
	}
	cyber_pc_connections_.clear();
	dns=NULL;
}

void CyberPC::AddConnection(string  second_pc){
	cout << "Connecting "+ this->getName()+ " to " +second_pc << endl;
	cyber_pc_connections_.push_back(second_pc);
	cout << "	" +  this->cyber_pc_name_ +" now connected to " + second_pc << endl;
	dns->GetCyberPC(second_pc).getconnections().push_back(cyber_pc_name_);
	cout << "	" + second_pc + " now connected to " + this->cyber_pc_name_<< endl;
}

void CyberPC::Infect(CyberWorm & worm){
	if (this->getOs()==worm.getOs()){
		cout << "		" + this->cyber_pc_name_ +" infected by " + worm.getName()<< endl;
		cyber_pc_time_to_infect_=worm.getDormancyTime();
		if (cyber_worm_ != NULL){
			delete cyber_worm_;
			cyber_worm_=NULL;
		}
		cyber_worm_ = new CyberWorm (worm);

	}else{
		cout <<"		" + worm.getName() +" is incompatible with " + this->getName()<< endl;
	}
}

void CyberPC::Run(const CyberDNS & server){
	if (cyber_pc_time_to_infect_!=-1){
		if(cyber_pc_time_to_infect_==0){
			cout << "	" + cyber_pc_name_ + " infecting..." << endl;
			for (int i=0 ; (unsigned)i < cyber_pc_connections_.size() ; i++){
				string const &temp = cyber_pc_connections_[i];
				CyberPC & b = server.GetCyberPC(temp);
				b.Infect(*cyber_worm_);
			}
			return;
		}
		cyber_pc_time_to_infect_=cyber_pc_time_to_infect_-1;
		if(this->getworm()!=NULL){
			if (this->getworm()->getDormancyTime()>0){
				cout << "	" + cyber_pc_name_ +": Worm "+ this->getworm()->getName() +" is dormant"<< endl;
			}
		}
	}
}

void CyberPC::Disinfect(){
	if (cyber_worm_ != NULL){
		cout << "		Worm " +cyber_worm_->getName() +" successfully removed from " + cyber_pc_name_ << endl;
		delete cyber_worm_;
		cyber_worm_=NULL;
		}
		cyber_pc_time_to_infect_=-1;
	}


CyberWorm * CyberPC::getworm() const {
	if(cyber_worm_ != NULL){
			return cyber_worm_;
	}else{
		return NULL;
	}
}

string CyberPC::getName() const{
	return cyber_pc_name_;
}

string CyberPC::getOs() const {
	return cyber_pc_os_;
}

vector<string> & CyberPC::getconnections()  {
	return cyber_pc_connections_;
}
