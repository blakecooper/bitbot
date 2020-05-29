#include "file.h"
#include <stdlib.h>
#include <time.h>
#include "macros.h"

void readSaveData(FILE *save, struct Data *data) {
	save = fopen("save", "rb");

	if (!save) {
		data->processors = STARTING_PROCESSORS;
		data->processor_power = STARTING_PROCESSOR_POWER;
		data->coins = STARTING_COINS;	
		data->bots = STARTING_BOTS;
		data->seconds_between_mining = STARTING_SECONDS_BETWEEN_MINING;
		data->number_available_hashes = STARTING_NUMBER_POSSIBLE_HASHES;
		data->cost_bitbot = 1;
		data->last_login = time(NULL);
	} else {
		fread ((void *) data, sizeof(struct Data), 1, save);
	};
};

void writeSaveData(FILE *save, struct Data *data) {
	save = fopen("save", "wb");
	fwrite((void *) data, sizeof(struct Data), 1, save);
};

void updateLastLogin(struct Data *data) {
	data->last_login = time(NULL);
};
