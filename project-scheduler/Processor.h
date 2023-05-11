#pragma once
#include"QueueADT.h"
#include"Process.h"
#include"Scheduler.h"



class Processor{
protected:
int QueueTimeLeft;
Process * run ;
QueueADT<Process*>*ReadyQ;
bool busy;
int RDYCount;
public:
	Processor(){
		busy=false;
		QueueTimeLeft=0;
		RDYCount=0;
	}
	virtual bool setRun(int TS)=0 ; 
	virtual int Run(Process * & ptr) = 0 ;
	virtual bool  isBusy() {
		return busy;
	}
	virtual int exist(int id, Process*& ptr) = 0;

	
	virtual int  GetTimeLeft(){
		return QueueTimeLeft;
	}
	Process* getRunning(){
		return run;
	}
	void AddToQueue(Process*ToAdd){
		QueueTimeLeft+=ToAdd->getCPUtime();
		ReadyQ->enqueue(ToAdd);
        
	}
	virtual void  PrintReadyQ() = 0;
	virtual int  getRDYCount() =0 ;
	virtual Process * getrun(){
		return run ;
	}
	virtual QueueADT<Process*>*  getReadyQ() = 0; 
		//////////////////////////start coding for phase 2 ///////////////////////////////////////////////////////
	//virtual void SchedAlgo(Scheduler * sch) = 0 ;
};