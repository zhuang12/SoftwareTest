#include <iostream>
#include <cmath>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

#define N 12
#define RUN_TIME 100

int x[N+1] = {0};
bool place(int k);
void backtrace(int step);
int QueenLV(int StepVegas);

int main()
{
    int StepVegas, time_now, time_end;
    for(int StepVegas=1; StepVegas<=N; StepVegas++){
        int j = 0, sucess = 0;
        time_now = clock();
        do{
            while (!QueenLV(StepVegas));
            backtrace(StepVegas+1);
            if(x[N]!=0){
                sucess++;
                cout << "sucess =  " << sucess << endl;
                for(int i = 1; i<= N; i++){
                    x[i] = 0;
                }
            }
            j++;
        }while(j < RUN_TIME);

    cout << "StepVegas = " << StepVegas << endl;
    cout << "Run " << RUN_TIME << " times,";
    cout << "sucess " << sucess << " times!";
    cout << "sucess rate is " << 100*sucess / RUN_TIME << endl;
    time_end = clock();
    cout << (time_end-time_now)*1000/CLOCKS_PER_SEC/sucess << endl;
    }
    return 0;
}

bool place(int k){
    for(int j = 1; j<k; j++){
        if((abs(k-j)==abs(x[j]-x[k])) || x[j] == x[k])
            return false;
    }
    return true;
}

void backtrace(int step){
    if(step>N) return ;
    for(int i=1; i<=N; i++){
        x[step] = i;
        if(place(step))
            backtrace(step+1);
    }
}

int QueenLV(int StepVeags){
    random_device rd;
    int line = 1, nb = 1, j = 0;
    while((line<=StepVeags)&&nb>0){
        nb = 0;
        j = 0;
        for(int i=1; i<=N; i++){
            x[line] = i;
            if(place(line)){
                nb++;
                uniform_int_distribution<>dist(1,nb);
                if(dist(rd) == 1) j = i;
            }
        }
        if(nb>0) x[line++] = j;
    }
    if(nb>0) return false;
    else return true;
}

