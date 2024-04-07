#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "DB.h"

using namespace std;

DB::DB (ifstream &f_in): Parcer(f_in){
    size_pl=4000;
    for (int i=0; i<size_pl; i++) {
        person p;
        for (int j=0; j<N; j++) {
            if (rand()%100>25) p.dnk.push_back(0);
            else p.dnk.push_back(1);
        }
        long s=0, w_a=0;
        for (int i=0; i<N; i++) {
            w_a=w_a+p.dnk[i]*w[i];
        }
        if (w_a<=max_w){
            for (int i=0; i<N; i++)
                s=s+p.dnk[i]*v[i];
        }
        p.health=s;
        popul.push_back(p);
    }
}

void DB::write_file(){
    ofstream out;
    out.open("answer.txt");
    if (out.is_open()){
        long w_a=0;
        for (int i=0; i<N; i++)
            w_a=w_a+popul[0].dnk[i]*w[i];
        out<<popul[0].health<<" "<<max_w-w_a<<"\n";
        for (int i=0; i<N; i++)
            out<<popul[0].dnk[i]<<" ";
    }
    out.close();
}

