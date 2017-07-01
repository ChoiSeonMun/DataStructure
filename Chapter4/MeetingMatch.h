#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef __MEETINGMATCH_H__
#define __MEETINGMATCH_H__

//Problem Programming Project 1-1, 1-3
#include "MeetingQueue.h"
#include "MeetingDeque.h"

class MeetingMatch {
public:
	void initialize() { puts("미팅 주선 프로그램입니다.\n"); }
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
	fputs("고객 이름 : ", stdout);
	scanf("%s", name);
	getc(stdin);	//개행문자 삭제
	fputs("성별을 입력하세요(f or m) : ", stdout);
	scanf("%c", &gender);
	getc(stdin);	//개행문자 삭제
	//if (gender == 'm') men.enqueue(name);
	//else			   women.enqueue(name);
	//1-3
	fputs("즉시 만나시길 원하십니까?(y or n) : ", stdout);
	scanf("%c", &answer);
	getc(stdin);	//개행문자 삭제
	if (gender == 'm' && answer == 'y')
		menDeq.addFront(name);
	else if (gender == 'm')
	{
		menDeq.addRear(name);
		puts("\n\n"); //서식 정렬
		return;
	}
	else if (gender == 'f' && answer == 'y')
		womenDeq.addFront(name);
	else if (gender == 'f')
	{
		womenDeq.addRear(name);
		puts("\n\n"); //서식 정렬
		return;
	}

	//check
	/*if (gender == 'm' && women.isEmpty())
		puts("아직 대상자가 없습니다. 기다려주십시요.\n\n");
	else if (gender == 'm')
	{
		char* man = men.dequeue();
		char* woman = women.dequeue();
		printf("커플이 탄생했습니다! %s과(와) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}
	else if (gender == 'f' && men.isEmpty())
		puts("아직 대상자가 없습니다. 기다려주십시요.\n\n");
	else if (gender == 'f')
	{
		char* man = men.dequeue();
		char* woman = women.dequeue();
		printf("커플이 탄생했습니다! %s과(와) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}*/

	//1-3
	if (gender == 'm' && womenDeq.isEmpty())
		puts("아직 대상자가 없습니다. 기다려주십시요.\n\n");
	else if (gender == 'm')
	{
		char* man = menDeq.deleteFront();
		char* woman = womenDeq.deleteFront();
		printf("커플이 탄생했습니다! %s과(와) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}
	else if (gender == 'f' && menDeq.isEmpty())
		puts("아직 대상자가 없습니다. 기다려주십시요.\n\n");
	else if (gender == 'f')
	{
		char* man = menDeq.deleteFront();
		char* woman = womenDeq.deleteFront();
		printf("커플이 탄생했습니다! %s과(와) %s\n\n\n", man, woman);
		delete[] man;
		delete[] woman;
	}
}

#endif