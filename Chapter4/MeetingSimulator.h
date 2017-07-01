#pragma once

#ifndef __MEETINGSIMULATOR_H__
#define __MEETINGSIMULATOR_H__

//Problem Programming Project 1-4
#include "CircularQueue.h"
#include <ctime>

class MeetingSimulator {
public:
	MeetingSimulator()
		: numOfCouple(0), totalWaitTime(0), totalMeetingNum(0) { }

	void readSimulationParameters();
	void run();
	void printStat();
private:
	int maxStudent;
	double studentPerClock;

	int numOfCouple;
	int totalWaitTime;
	int totalMeetingNum;

	CircularQueue men;
	CircularQueue women;

	double Random() { return rand() / (double)RAND_MAX; }
	bool IsNewStudent() { return Random() > studentPerClock; }
	void InsertStudent(int emergingTime);
	void match(int currentTime);
};

void MeetingSimulator::readSimulationParameters()
{
	printf("시뮬레이션 할 최대 인원 (예: 100 [명]) = ");
	scanf_s("%d", &maxStudent);
	printf("단위시간에 등록하는 학생 수 (예: 0.5 [학생/단위 시간]) = ");
	scanf_s("%lf", &studentPerClock);
	printf("=====================================================\n");
}

void MeetingSimulator::run()
{
	srand(time(NULL));
	int clock = 0, studentNum = 1;
	while (studentNum <= maxStudent)
	{
		++clock;
		printf("현재 시각=%d\n", clock);

		if (IsNewStudent())
		{
			InsertStudent(clock);
			++studentNum;
		}
		match(clock);
	}
}

void MeetingSimulator::printStat()
{
	printf("=====================================================\n");
	printf("  미팅 주선에 성공한 커플의 쌍의 번호 = %d\n", numOfCouple);
	printf("  전체 미팅 주선 횟수 = %d회\n", totalMeetingNum);
	printf("  남녀 학생의 평균 대기 시간 = %-5.2f분\n", (double)totalWaitTime / numOfCouple);
}

inline void MeetingSimulator::InsertStudent(int emergingTime)
{
	char gender = (rand() % 2) ? 'm' : 'f';
	if (gender == 'm')
		men.enqueue(emergingTime);
	else
		women.enqueue(emergingTime);
}

void MeetingSimulator::match(int currentTime)
{
	if (!men.isEmpty() && !women.isEmpty())
	{
		int manID = men.dequeue(), womanID = women.dequeue();
		totalWaitTime += currentTime - manID + currentTime - womanID;
		printf("매칭 성공 : %d번과 %d번\n", manID, womanID);
		++numOfCouple;
	}
	else
		printf("매칭 실패\n");
	++totalMeetingNum;
}
#endif