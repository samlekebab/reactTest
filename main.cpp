#include <stdio.h>
#include <iostream>
//#ifdef __unix__
#include <time.h>
//#endif
#include <cmath>
#include <list>
#include <thread>
using namespace std;
int main(void){
	int sum=0;
	unsigned long timer=0;
	long localMax=0;
	int c=0;
	int d=0;
	timespec time;
	list<long> maxs {};
	while(d<40){
		sum++;
//#ifdef __unix__
		clock_gettime(CLOCK_MONOTONIC_RAW,&time);
		long newTimer = (long)time.tv_sec*1'000'000 + time.tv_nsec/1000 ;
		sum+=newTimer;

		if (++c>5'000'000){
			//printf("%d, %d\n",localMax,sum);
			c=0;
			maxs.push_back(localMax);
			localMax=0;
			d++;
			//this_thread::yield();
		}
		localMax=(localMax>newTimer-timer)?localMax:newTimer-timer;
		timer=newTimer;
//#endif


	
	}
	for (auto it=maxs.begin();it!=maxs.end();it++){
		cout << *it <<endl;
	}

}
