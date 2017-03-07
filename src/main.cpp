#include <iostream>
#include <string>
#include <map>
using namespace std;
#include "../include/cyberpc.h"
#include "../include/cyberdns.h"
#include "../include/cyberworm.h"
#include "../include/cyberexpert.h"
#include "../include/cyberschedule.h"

#define XML_PATH1 "./computers.xml"
#define XML_PATH2 "./network.xml"
#define XML_PATH3 "./events.xml"
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/strong_typedef.hpp>
#include <boost/lexical_cast.hpp>
using boost::property_tree::ptree;

ptree ptComputers;
ptree ptNetwork;
ptree ptEvents;
int counter = 1;
int day =0;
int dayOfTermination ;
bool running= true;
CyberSchedule schedule = CyberSchedule();
CyberDNS dns = CyberDNS();
int expert = 0 ;
int pc = 0 ;

void loadComp (const string &file, const CyberDNS & server){
	read_xml(file , ptComputers);
	CyberPC * pc;

	BOOST_FOREACH(ptree::value_type & v, ptComputers){
			string name = v.second.get<string>("name");
			string os = v.second.get<string>("os");
			pc = new CyberPC (os, name);
			dns.AddPC( *pc); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			delete pc;
	}
}

void loadNetwork (const string &file, const CyberDNS & server){
	read_xml(file , ptNetwork);
	BOOST_FOREACH(ptree::value_type & v, ptNetwork){
		dns.GetCyberPC(v.second.get<string>("pointA")).AddConnection(v.second.get<string>("pointB"));
	}
}

void loadEvents (const string &file, const CyberDNS & server){

	read_xml(file , ptEvents);
	BOOST_FOREACH(ptree::value_type & v, ptEvents){
		CyberWorm * worm;

		cout << "Day : " << day << endl;

		if (v.first=="hack"){
			CyberPC & temp = dns.GetCyberPC(v.second.get<string>("computer"));
			cout <<"	Hack occured on " + temp.getName() << endl;
			string name = v.second.get<string>("wormName");
			string dormancy = v.second.get<string>("wormDormancy");
			int dormancy1 = atoi(dormancy.c_str());
			string os = v.second.get<string>("wormOs");
			worm = new CyberWorm (os, name,dormancy1);
			temp.Infect(*worm);      //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			delete worm;
		}
		else if (v.first=="clock-in"){
				expert = expert+1;
				string name = v.second.get<string>("name");
				string work = v.second.get<string>("workTime");

				int work1 = atoi(work.c_str());
				string rest = v.second.get<string>("restTime");
				int rest1 = atoi(rest.c_str());

				string efficiency = v.second.get<string>("efficiency");
				int efficiency1 = atoi(efficiency.c_str());
				schedule.AddExpert(*new CyberExpert (name, work1, rest1 , efficiency1) ); //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
				cout << "	Clock-In: " + name + " began working"  << endl;
		}
		else if (v.first=="termination"){
				string dayOfTermination1 = v.second.get<string>("time");
				dayOfTermination = atoi(dayOfTermination1.c_str());
		}

		schedule.Scan(dns);
		map<const string, CyberExpert &>::iterator it;
		for (it = schedule.cyber_schedule_.begin(); it!=schedule.cyber_schedule_.end(); ++it){
			(it)->second.run();
		}
		vector<string> PCList = dns.GetCyberPCList();				// running all the computers
			for (int i=0 ; (unsigned)i< PCList.size() ; i++){					// and infecting
				string const &temp = PCList[i];
				CyberPC & b = dns.GetCyberPC(temp);
				b.Run(dns);
		}day=day+1;
	}

}

int main() {
	loadComp(XML_PATH1, dns);
	loadNetwork (XML_PATH2, dns);
	loadEvents (XML_PATH3, dns);

	while(day<=dayOfTermination){
		cout << "Day : " << day << endl;
		schedule.Scan(dns);
		map<const string, CyberExpert &>::iterator it;
		for (it = schedule.cyber_schedule_.begin(); it!=schedule.cyber_schedule_.end(); ++it){
			(it)->second.run();
		}
		vector<string> PCList = dns.GetCyberPCList();				// running all the computers
			for (int i=0 ; (unsigned)i < PCList.size() ; i++){					// and infecting
				string const &temp = PCList[i];
				CyberPC & b = dns.GetCyberPC(temp);
				b.Run(dns);

		}day=day+1;
	}
	cout << "" << endl;
	cout << "<<<<<<<<<<<<<<<<<<<<<<< termination >>>>>>>>>>>>>>>>>>>>>>>>" << endl;
	if (expert > 0){
		for(int i = 0 ; (unsigned)i <= schedule.GetCyberExpertList().size()-1 ; i++){ //deleting experts
			delete (&schedule.GetCyberExpert(schedule.GetCyberExpertList()[i]));
			}
	}
	for(int i = 0 ; (unsigned)i <= dns.GetCyberPCList().size()-1 ; i++){ //deleting pc's
			delete (&dns.GetCyberPC(dns.GetCyberPCList()[i]));
		}
return 0;
}

