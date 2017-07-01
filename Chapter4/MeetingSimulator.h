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
	printf("�ùķ��̼� �� �ִ� �ο� (��: 100 [��]) = ");
	scanf_s("%d", &maxStudent);
	printf("�����ð��� ����ϴ� �л� �� (��: 0.5 [�л�/���� �ð�]) = ");
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
		printf("���� �ð�=%d\n", clock);

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
	printf("  ���� �ּ��� ������ Ŀ���� ���� ��ȣ = %d\n", numOfCouple);
	printf("  ��ü ���� �ּ� Ƚ�� = %dȸ\n", totalMeetingNum);
	printf("  ���� �л��� ��� ��� �ð� = %-5.2f��\n", (double)totalWaitTime / numOfCouple);
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
		printf("��Ī ���� : %d���� %d��\n", manID, womanID);
		++numOfCouple;
	}
	else
		printf("��Ī ����\n");
	++totalMeetingNum;
}
#endif