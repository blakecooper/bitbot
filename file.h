#include <time.h>
#include <stdio.h>

struct Data {
	int cores;
	int processor_power;
	unsigned long long int coins;
	unsigned long long int total_coins_mined;
	unsigned long long int bots; 
	float seconds_between_mining;
	int number_available_hashes;
	int cost_bitbot;
	int cost_cores;
	int cost_power;
	int cost_speed;
	time_t last_login;
};

void readSaveData(FILE *save, struct Data *data);

void writeSaveData(FILE *save, struct Data *data);

void updateLastLogin(struct Data *data); 
