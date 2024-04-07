#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "Parcer.h"

using namespace std;

class DB;

class person{
    friend class DB;
    friend class Solver;
    vector<int long> dnk;
    long health;
public:
    bool operator> (const person& a) const{
        return (health>a.health);
    };
};

class DB:public Parcer{
protected:
    vector<person> popul;
    int size_pl;
public:
    DB (ifstream &f_in);
    void write_file();
};
