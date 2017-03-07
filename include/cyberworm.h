#ifndef CYBER_WORM
#define CYBER_WORM
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class CyberWorm
{
private:
    const string cyber_worm_os_;
    const string cyber_worm_name_;
    const int cyber_worm_dormancy_time_;
    CyberWorm();

public:
    CyberWorm(string cyber_worm_os, string cyber_worm_name, int cyber_worm_dormancy_time);
	CyberWorm(const CyberWorm& other);
	~CyberWorm();
	string getName() const;
	string getOs()  const;
	int getDormancyTime() const;
	void setOs(string str);
	void setName(string str);
	void setDormancyTime(int i);

};
#endif
