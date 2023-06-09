#pragma once
#include <fstream>
#include "Processor.h"
#include <cstdlib>
#include <time.h>
#include"UI.h"




class Scheduler {
	enum { maxProcessorsCount = 500 }; // maximum number of processors
	enum processorType {FCFS_processor, SJF_processor, RR_processor};
	UI ui ; 
private:
	int processorsCount, processessCount, timeSteps, NF, NS, NR, RR_timeSlice, RTF, maxW, STL, forkProbability;
	Processor* processorsArray[maxProcessorsCount];
	LinkedQueue<Process*> newList, trmList, blkList;
	int maxID; 
	LinkedQueue<pair<int, int>> sigKillTimes;
	ifstream inputFile;
	Process * currentIo ;
	ofstream outputFile;
	double avgWT;
	double avgRT;
	double avgTRT;
	int totalWT; 
	int totalTRT;
	int totalRT;
	int modeOfOperation;
	int workStealCount ;
	int forkCount;
	int killedCount;
	double TotalUtiliz;
	int RTFCount; 
	int MaxwCount;
public:
	Scheduler(const char* fileName,const char * fileoutput, int mode): inputFile(fileName),outputFile(fileoutput), modeOfOperation(mode){
		timeSteps = processorsCount = processessCount = 0;
		RTFCount =MaxwCount = 0; 
		totalWT =0;
		totalTRT=0;
		totalRT=0;
		maxID = 0;
		workStealCount=0;
		forkCount=0;
		killedCount=0;
		currentIo = nullptr ;
		TotalUtiliz =0;
	}
	Scheduler(){
		timeSteps = processorsCount = processessCount = 0;
	}
	void loadInputFile();
	void simulator();

	//////////////////////////start coding for phase 2 ///////////////////////////////////////////////////////
	int gettimestep()const{
		return timeSteps ; 
	}

	void output();
	void setAvgRT();
	void setAvgTRT();
    int getAvgWT();
	int getAvgRT();
	int getAvgTRT();
	
	void addToTotalWT(int x ){
	totalWT+=x;
	}
	int getTotalWT(){return totalWT ; }
	void addToTotalTRT(int x){
	totalTRT+=x;
	}
	int getTotalTRT(){return totalTRT ; }
	void addToTotalRT(int x){
	totalRT+=x;
	}
	int getTotalRT(){return totalRT ; }

	void calcTotalUtiliz(){
		for (int i = 0; i < processorsCount; i++)
		{
			TotalUtiliz+=(1.0*processorsArray[i]->getBusyTime())/(processorsArray[i]->getBusyTime()+processorsArray[i]->getIdelTime());
		}
	}
	void NewToRdy();
	void ToBLK(Process * ptr );
	void ToTRM(Process * ptr );
	void BLKToRDY();
	void doFork(Process*& running); 
	void killProcess(int id);
	void doWorkStealing();
	void doMigrationRR (Process * ptr) ;
	void doMigrationFCFS (Process * ptr) ;
	int getRTF(){return RTF ; } 
	int getMaxw(){return maxW ;}
};                                                                    