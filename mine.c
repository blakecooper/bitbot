#include <time.h>
#include <stdlib.h>
#include "text.h"
#include "file.h"
#include "macros.h"

int getMinesSinceLastCheck(struct Data *data) {
	time_t now = time(NULL);
	double seconds_elapsed = difftime(now, data->last_login);

	return (seconds_elapsed / data->seconds_between_mining) * data->bots * data->cores;
};

int reduceAvailableHashes(struct Data *data, int coinsMined) {
	if ((data->total_coins_mined + coinsMined) % 1000 == 0) {
		data->number_available_hashes--;
		return 1;
	} else {
		return 0;
	};
};

void mine(struct Data *data, int number_of_passes) {
	srand(time(NULL));
	int coins_mined = 0;
	int clock = data->processor_power;
	int hashesReduced = 0;

	for (int i = 0; i < number_of_passes; i++) {
		int hash;
		if (data->number_available_hashes > 0) {
			hash = rand() % data->number_available_hashes;
		} else {
			hash = 0;
		};

		int processor_guess;
		if (clock > 0) {
			processor_guess = rand() % clock;
		} else {
			processor_guess = 0;
		};

		if (processor_guess < hash) {
			coins_mined++;
			if (data->number_available_hashes > 1) {
				hashesReduced += reduceAvailableHashes(data, coins_mined);
			};
		};
	};

	if (coins_mined > 0) {

		int lottery = rand() % LOTTERY_CHANCES;
		if (lottery == 1) {
			printLotteryConfirmation();
			coins_mined *= LOTTERY_MULTIPLIER;
		};
		
		data->coins += coins_mined;
		data->total_coins_mined += coins_mined;
		printSuccessfulMiningConfirmation(coins_mined);
		
	} else {
		printFailedMiningConfirmation();
	};
	
	if (hashesReduced) {
		printHashReduction();
	};
};
