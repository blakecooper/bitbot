#include <time.h>
#include <stdlib.h>
#include "text.h"
#include "file.h"

int getMinesSinceLastCheck(struct Data *data) {
	time_t now = time(NULL);
	double seconds_elapsed = difftime(now, data->last_login);

	return (seconds_elapsed / data->seconds_between_mining);
};

void mine(struct Data *data, int number_of_passes) {
	srand(time(NULL));
	int coins_mined = 0;

	for (int i = 0; i < number_of_passes * data->bots; i++) {
		int hash = rand() % data->number_available_hashes;
		int processor_guess = rand() % data->processor_power;

		if (processor_guess < hash) {
			coins_mined++;
			if (data->number_available_hashes > 1) {
				data->number_available_hashes--;
			};
		};
	};

	if (coins_mined > 0) {
		data->coins += coins_mined;
		printSuccessfulMiningConfirmation(coins_mined);
	} else {
		printFailedMiningConfirmation();
	};
};
