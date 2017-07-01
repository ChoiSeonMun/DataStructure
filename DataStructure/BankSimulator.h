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
	printf("�ùķ��̼� �� �ִ� �ð�(��:10) = ");
	scanf_s("%d", &nSimulation);
	printf("�����ð��� �����ϴ� �� �� (��:0.7) = ");
	scanf_s("%lf", &probArrival);
	printf("�� ���� ���� �ִ� ���� �ð� (��:5) = ");
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
		printf("����ð� = %d\n", clock);

		if (IsNewCustomer()) InsertCustomer(clock);
		if (serviceTime > 0) --serviceTime;
		else
		{
			if (que.isEmpty()) continue;
			Customer a = que.dequeue();
			++nServedCustomers;
			totalWaitTime += clock - a.tArrival;
			printf("\t�� %d ���� ���� (���ð�:%d��)\n", a.id, clock - a.tArrival);
			serviceTime = a.tArrival - 1;
		}
	}
}

void BankSimulator::printStat()
{
	printf("===========================================\n");
	printf("  ���� ���� �� �� = %d\n", nServedCustomers);
	printf("  ��ü ��� �ð�      = %d��\n", totalWaitTime);
	printf("  ���� �� ��� ��� �ð� = %-5.2f��\n", (double)totalWaitTime / nServedCustomers);
	printf("  ���� ��� �� �� = %d\n", nCustomers - nServedCustomers);
}

inline void BankSimulator::InsertCustomer(int arrivalTime)
{
	Customer a(++nCustomers, arrivalTime, RandServiceTime());
	printf("  �� %d �湮 (���� �ð�:%d��)\n", a.id, a.tService);
	que.enqueue(a);
}
#endif