#pragma once

#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__

struct Customer {
	int id;
	int tArrival;
	int tService;
	Customer(int ID = 0, int arrival = 0, int service = 0)
		: id(ID), tArrival(arrival), tService(service) { }
};

#endif