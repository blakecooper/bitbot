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

int reduceAvailableHashesByRatioOfCoins(struct Data *data, int coinsMined) {
	data->number_available_hashes -= (coinsMined % 1000);
	return 1;
};

int generateHash (struct Data *data) {
	if (data->number_available_hashes > 0) {
		return rand() % data->number_available_hashes;
	} else {
		return 0;
	};	
};

int generateProcessorGuess (struct Data *data) {
	if (data->processor_power > 0) {
		return rand() % data->processor_power;
	} else {
		return 0;
	};
};

void mine (struct Data *data, int number_of_passes) {
	int coins_mined = 0;
	int hashes_reduced = 0;

	if (number_of_passes < RANDOMNESS_THRESHOLD) {
		srand(time(NULL));
		
		for (int i = 0; i < number_of_passes; i++) {
			int hash = generateHash(data);
			int processor_guess = generateProcessorGuess(data);
	
			if (processor_guess < hash) {
				coins_mined++;
				if (data->number_available_hashes > 1) {
					hashes_reduced += reduceAvailableHashes(data, coins_mined);
				};
			};
		};
	} else {
		float odds = (float) data->number_available_hashes / (float) data->processor_power;
		coins_mined = number_of_passes * odds;
		if (coins_mined > 1) {
			hashes_reduced = reduceAvailableHashesByRatioOfCoins(data, coins_mined);
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
	
	if (hashes_reduced) {
		printHashReduction();
	};
};
