#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "macros.h"

void mine(int *data, int number_of_passes) {
	srand(time(NULL));
	int coins_mined = 0;

	for (int i = 0; i < number_of_passes; i++) {
		int hash = rand() % NUMBER_OF_POSSIBLE_HASHES;
		int processor_guess = rand() % PROCESSOR_POWER;

		if (processor_guess == hash) {
			coins_mined++;
		};
	};

	if (coins_mined > 0) {
		data[COINS] += coins_mined;
		printSuccessfulMiningConfirmation();
		printCurrentCoinsStored(data);
	} else {
		printFailedMiningConfirmation();
	};
};

int main (int argc, const char* argv[]) {
	FILE *savefile;
	int *data = (int *) malloc(TOTAL_DATA * sizeof(int));
	
	readSaveData (savefile, data);

	mine(data, data[PROCESSORS]);

	writeSaveData(savefile, data);
};
