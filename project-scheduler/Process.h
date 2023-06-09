#pragma once
#include "LinkedQueue.h"
#include "IO.h"
#include<iostream>
using namespace std;
class Process{
private:
	int ID;
	int AT;
	int RT;
	int CT;
	int TimeDone;
	int TT;
	int TurnAroundTime;
	int WaitingTime;
	int IO_n;
	int timeLeft;
	LinkedQueue <IO * > IOs;
	IO* nextIO;
	Process* children[2];
	Process * parent;
	bool isKilled;
	int totalIO_D ; 
public:

Process(int at = 0, int id = 0, int ct = 0, int IOn = 0) {
		AT=at;
		ID=id;
		CT=ct;
		IO_n=IOn;
		timeLeft=ct;
		TimeDone = 0;
		isKilled = 0;
		totalIO_D=0 ; 
		RT=0;
		nextIO = nullptr;
		children[0] = nullptr;
		children[1] = nullptr;
		parent = nullptr; 
	}
 
void setChild(Process *child){
	if(children[0] && children[1]) return;
	if(children[0]) children[1] = child;
	else children[0] = child;
}

void setParent( Process * Par ){
	parent = Par;
}

Process * getParent () const {
	return parent ; 
}

Process* getFirstChild(){
	return children[0];
}


Process* getSecondChild(){
	return children[1];
}


void setID(int x){
	ID=x;
}
void setArrivalTime(int x){
	AT=x;
}
void setResponseTime(int x){
	RT=x;
}
void setCPUtime(int x){
	CT=x;
}
void setTimeDone(int x){
	TimeDone=x;
}
void setTerminateTime(int x){
	TT=x;	
}
void setTurnAroundTime(int x){
	TurnAroundTime=x;
}
void setWaitingTime(int x){
	WaitingTime=x;
}
void setIONumber(int x){
	IO_n=x;
}
void setTimeLeft(int x){
	timeLeft=x;
}
void SetNextIO(IO* io){
	nextIO=io;
}

int getTotalIO_D()const{
return totalIO_D ; 
}
void setIsKilled(bool state){
	isKilled = state;
}

bool getIsKilled(){
	return isKilled;
}

int getID(){
	return ID;
}
int getArrivalTime(){
	return AT;
}
int getResponseTime(){
	return RT;
}
int getCPUtime(){
	return CT;
}
int getTimeDone(){
	return TimeDone;
}
int getTerminationTime(){
	return TT;
}
int getTurnAroundTime(){
	return TurnAroundTime;
}

int getWaitingTime(){
	return WaitingTime;
}
int getIO_n(){ //////////////
	return IO_n;
}
int getTimeLeft(){
	return timeLeft;
}
IO* &getNextIO(){ ///////////
	if(!nextIO){
	
		IOs.dequeue(nextIO);
	}
	
	return nextIO;

}
bool operator >(Process x){
	return CT>x.CT;
}
void AddIO(IO * io){ ///////////
	IOs.enqueue(io);
	totalIO_D+=io->getDuration();
}
void popIO(){    ////////////////
		IO* ret;
		if (IOs.isEmpty())
			return;
		IOs.dequeue(ret);
		if (ret->isDone())
			return;
		IO * back = ret;
		nextIO = new IO(*ret);
	
		back->setDone(true);
		IOs.enqueue(back);
		return;
}
void Print() {
		cout << "Arrival: " << AT << ", PID: " << ID << ", CPU Time: " << CT << ", IOs: " << IO_n<<endl;
	}
	friend ostream& operator << (ostream& out, Process* ptr){
		out << ptr->ID;
		return out;
	}

	~Process(){
	}
};