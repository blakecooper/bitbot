#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "macros.h"

void mine(struct Data *data, int number_of_passes) {
	srand(time(NULL));
	int coins_mined = 0;

	for (int i = 0; i < number_of_passes * data->bots; i++) {
		int hash = rand() % NUMBER_OF_POSSIBLE_HASHES;
		int processor_guess = rand() % PROCESSOR_POWER;

		if (processor_guess == hash) {
			coins_mined++;
		};
	};

	if (coins_mined > 0) {
		data->coins += coins_mined;
		printSuccessfulMiningConfirmation(coins_mined);
	} else {
		printFailedMiningConfirmation();
	};
};

int main (int argc, const char* argv[]) {
	FILE *savefile;
	struct Data *data = (struct Data *) malloc(sizeof(struct Data));
	
	readSaveData (savefile, data);

	mine(data, getMinesSinceLastCheck(data));
	printNewLine();

	printOpData(data);
	printNewLine();

	data->last_login = time(NULL);

	writeSaveData(savefile, data);

	return 0;
};
