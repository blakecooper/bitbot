#include "file.h"
#include <stdlib.h>
#include <time.h>
#include "macros.h"
#include "text.h"

void readSaveData(FILE *save, struct Data *data) {
	save = fopen(SAVE_FILE_PATH, "rb");

	if (!save) {
		data->cores = STARTING_CORES;
		data->processor_power = STARTING_PROCESSOR_POWER;
		data->coins = STARTING_COINS;	
		data->total_coins_mined = STARTING_COINS;
		data->bots = STARTING_BOTS;
		data->seconds_between_mining = STARTING_SECONDS_BETWEEN_MINING;
		data->number_available_hashes = STARTING_NUMBER_POSSIBLE_HASHES;
		data->cost_bitbot = STARTING_COST_BITBOT;
		data->cost_cores = STARTING_COST_CORES;
		data->cost_power = STARTING_COST_POWER;
		data->cost_speed = STARTING_COST_SPEED;
		data->last_login = time(NULL);
		printNewLine();
		printIntro();
		printNewLine();
		printCommands();
	} else {
		fread ((void *) data, sizeof(struct Data), 1, save);
	};
};

void writeSaveData(FILE *save, struct Data *data) {
	save = fopen(SAVE_FILE_PATH, "wb");
	fwrite((void *) data, sizeof(struct Data), 1, save);
};

void updateLastLogin(struct Data *data) {
	data->last_login = time(NULL);
};
