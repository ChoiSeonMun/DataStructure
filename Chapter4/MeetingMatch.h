#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef __MEETINGMATCH_H__
#define __MEETINGMATCH_H__

//Problem Programming Project 1-1, 1-3
#include "MeetingQueue.h"
#include "MeetingDeque.h"

class MeetingMatch {
public:
	void initialize() { puts("���� �ּ� ���α׷��Դϴ�.\n"); }
	void match();
private:
	MeetingQueue men;
	MeetingQueue women;
	MeetingDeque menDeq;
	MeetingDeque womenDeq;
};

void MeetingMatch::match()
{
	char* name = new char[7];
	char gender, answer;
	fputs("�� �̸� : ", stdout);
	scanf("%s", name);
	getc(stdin);	//���๮�� ����
	fputs("������ �Է��ϼ���(f or m) : ", stdout);
	scanf("%c", &gender);
	getc(stdin);	//���๮�� ����
	//if (gender == 'm') men.enqueue(name);
	//else			   women.enqueue(name);
	//1-3
	fputs("��� �����ñ� ���Ͻʴϱ�?(y or n) : ", stdout);
	scanf("%c", &answer);
	getc(stdin);	//���๮�� ����
	if (gender == 'm' && answer == 'y')
		menDeq.addFront(name);
	else if (gender == 'm')
	{
		menDeq.addRear(name);
		puts("\n\n"); //���� ����
		return;
	}
	else if (gender == 'f' && answer == 'y')
		womenDeq.addFront(name);
	else if (gender == 'f')
	{
		womenDeq.addRear(name);
		puts("\n\n"); //���� ����
		return;
	}

	//check
	/*if (gender == 'm' && women.isEmpty())
		puts("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
	else if (gender == 'm')
	{
		char* man = men.dequeue();
		char* woman = women.dequeue();
		printf("Ŀ���� ź���߽��ϴ�! %s��(��) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}
	else if (gender == 'f' && men.isEmpty())
		puts("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
	else if (gender == 'f')
	{
		char* man = men.dequeue();
		char* woman = women.dequeue();
		printf("Ŀ���� ź���߽��ϴ�! %s��(��) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}*/

	//1-3
	if (gender == 'm' && womenDeq.isEmpty())
		puts("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
	else if (gender == 'm')
	{
		char* man = menDeq.deleteFront();
		char* woman = womenDeq.deleteFront();
		printf("Ŀ���� ź���߽��ϴ�! %s��(��) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}
	else if (gender == 'f' && menDeq.isEmpty())
		puts("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n\n");
	else if (gender == 'f')
	{
		char* man = menDeq.deleteFront();
		char* woman = womenDeq.deleteFront();
		printf("Ŀ���� ź���߽��ϴ�! %s��(��) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}
}

#endif