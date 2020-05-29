#include <time.h>
#include <stdio.h>

struct Data {
	int processors;
	int processor_power;
	int coins;
	int bots; 
	int seconds_between_mining;
	int number_available_hashes;
	int cost_bitbot;
	time_t last_login;
};

void readSaveData(FILE *save, struct Data *data);

void writeSaveData(FILE *save, struct Data *data);

void updateLastLogin(struct Data *data); 
