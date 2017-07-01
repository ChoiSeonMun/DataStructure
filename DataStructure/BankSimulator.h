#pragma once

#ifndef __BANKSIMULATOR_H__
#define __BANKSIMULATOR_H__

#include "CustomerQueue.h"

class BankSimulator {
public:
	BankSimulator()
		: nCustomers(0), totalWaitTime(0), nServedCustomers(0) { }

	void readSimulationParameters();
	void run();
	void printStat();
private:
	int nSimulation;
	double probArrival;
	int tMaxService;
	int totalWaitTime;
	int nCustomers;
	int nServedCustomers;
	CustomerQueue que;

	double Random() { return rand() / (double)RAND_MAX; }
	bool IsNewCustomer() { return Random() > probArrival; }
	int RandServiceTime() { return (int)(tMaxService * Random()) + 1; }

	void InsertCustomer(int arrivalTime);
};

void BankSimulator::readSimulationParameters()
{
	printf("시뮬레이션 할 최대 시간(예:10) = ");
	scanf_s("%d", &nSimulation);
	printf("단위시간에 도착하는 고객 수 (예:0.7) = ");
	scanf_s("%lf", &probArrival);
	printf("한 고객에 대한 최대 서비스 시간 (예:5) = ");
	scanf_s("%d", &tMaxService);
	printf("=====================================================\n");
}

void BankSimulator::run()
{
	int clock = 0;
	int serviceTime = -1;
	while (clock < nSimulation)
	{
		++clock;
		printf("현재시각 = %d\n", clock);

		if (IsNewCustomer()) InsertCustomer(clock);
		if (serviceTime > 0) --serviceTime;
		else
		{
			if (que.isEmpty()) continue;
			Customer a = que.dequeue();
			++nServedCustomers;
			totalWaitTime += clock - a.tArrival;
			printf("\t고객 %d 서비스 시작 (대기시간:%d분)\n", a.id, clock - a.tArrival);
			serviceTime = a.tArrival - 1;
		}
	}
}

void BankSimulator::printStat()
{
	printf("===========================================\n");
	printf("  서비스 받은 고객 수 = %d\n", nServedCustomers);
	printf("  전체 대기 시간      = %d분\n", totalWaitTime);
	printf("  서비스 고객 평균 대기 시간 = %-5.2f분\n", (double)totalWaitTime / nServedCustomers);
	printf("  현재 대기 고객 수 = %d\n", nCustomers - nServedCustomers);
}

inline void BankSimulator::InsertCustomer(int arrivalTime)
{
	Customer a(++nCustomers, arrivalTime, RandServiceTime());
	printf("  고객 %d 방문 (서비스 시간:%d분)\n", a.id, a.tService);
	que.enqueue(a);
}
#endif