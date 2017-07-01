#include <ctime>
#include "BankSimulator.h"

int main()
{
	srand(time(NULL));
	BankSimulator sim;
	sim.readSimulationParameters();
	sim.run();
	sim.printStat();

	return 0;
}