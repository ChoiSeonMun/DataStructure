#include "MeetingSimulator.h"

int main()
{
	MeetingSimulator program;
	program.readSimulationParameters();
	program.run();
	program.printStat();

	return 0;
}