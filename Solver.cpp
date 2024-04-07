#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Solver.h"

using namespace std;

Solver::Solver (ifstream &f_in): DB(f_in){
}
    
void Solver::solve(){
    for (int i=0; i<size_pl; i++){
        int m=0, f=0;
        while (m==f){
            m=rand()%size_pl;
            f=rand()%size_pl;
        }
        person p1, p2;
        vector<long> d1=popul[m].dnk;
        vector<long> d2=popul[f].dnk;
        for (int i=0; i<N; i++){
            if (i<N/2){
                p1.dnk.push_back(d1[i]);
                p2.dnk.push_back(d2[i]);
            }
            else {
                p1.dnk.push_back(d2[i]);
                p2.dnk.push_back(d1[i]);
            }
        }
        int mut=rand()%100;
        if (mut<=10){
            if (rand()%2==1) p1.dnk[rand()%N]=rand()%2;
            else p2.dnk[rand()%N]=rand()%2;
        }
        int s1=0, w_a1=0, s2=0, w_a2=0;
        for (int k=0; k<N; k++){
            w_a1=w_a1+p1.dnk[k]*w[k];
            w_a2=w_a2+p2.dnk[k]*w[k];
        }
        if (w_a1<=max_w)
            for (int k=0; k<N; k++)
                s1=s1+p1.dnk[k]*v[k];
        if (w_a2<=max_w)
            for (int k=0; k<N; k++)
                s2=s2+p2.dnk[k]*v[k];
        p1.health=s1;
        p2.health=s2;
        popul.push_back(p1);
        popul.push_back(p2);
        sort(popul.begin(), popul.end(), greater<person>());
        popul.pop_back();
        popul.pop_back();
    }
}
