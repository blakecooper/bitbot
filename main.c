#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "mine.h"
#include "text.h"
#include "macros.h"

struct Data *data;

int buy () {
	if (data->cost_bitbot <= data->coins) {
		data->coins -= data->cost_bitbot;
		data->bots ++;
		data->cost_bitbot = data->cost_bitbot * COST_MULTIPLIER;
		return 1;
	} else {
		return 0;
	};
};

void buyOne() {
	if (buy()) {
		printBuyConfirmationBitbot();
		printNumberBots(data);
		printCurrentCoinsStored(data);
	} else {
		printNotEnough();
		printCurrentCoinsStored(data);
		printCostBitbot(data);
	};
};

void buyMax() {
	int buyCount = 0;

	while (buy()) {
		buyCount++;
	};

	if (buyCount > 0) {
		printBuyConfirmationBitbotNumber(buyCount);
		printNumberBots(data);
		printCurrentCoinsStored(data);
	} else {
		printNotEnough();
		printCurrentCoinsStored(data);
		printCostBitbot(data);
	};
};

void upgrade(char* arg) {
	printNewLine();
	if (strcmp(arg, "cores") == 0) {
		if (data->cost_cores <= data->coins) {
			data->coins -= data->cost_cores;
			data->cores *= 2;
			data->cost_cores *= COST_MULTIPLIER;
			printUpgradeConfirmationCores();
			printProcessorInfo(data);
		} else {
			printNotEnough();
			printCurrentCoinsStored(data);
			printCostUpgrade(data);
		};
	} else if (strcmp(arg, "power") == 0) {
		if (data->cost_power <= data->coins) {
			data->coins -= data->cost_power;
			int fewer_power = data->processor_power/5;
			if ((data->processor_power - fewer_power) > data->number_available_hashes) {
				data->processor_power -= fewer_power;
				data->cost_power *= COST_MULTIPLIER;
				printUpgradeConfirmationPower();
				printProcessorInfo(data);
			} else {
				fprintf(stdout, "Processors already at maximum efficiency!");
			};
		} else {
			printNotEnough();
			printCurrentCoinsStored(data);
			printCostUpgradePower(data);
		};
	} else if (strcmp(arg, "speed") == 0) {
		if (data->cost_speed <= data->coins) {
			data->coins -= data->cost_speed;
			float fewer_seconds = data->seconds_between_mining/10;
			if (fewer_seconds > 1) {
				data->seconds_between_mining -= fewer_seconds;
				data->cost_speed *= COST_MULTIPLIER;
				printUpgradeConfirmationSpeed();
				printProcessorInfo(data);
			} else {
				fprintf(stdout, "Processors already at maximum speed!");
			};
		} else {
			printNotEnough();
			printCurrentCoinsStored(data);
			printCostUpgradeSpeed(data);
		};
	} else {
		printUpgradeInputError();
	};
	printNewLine();
};

void read() {
	printNewLine();
	fprintf(stdout,"Coins in wallet: %d\n", data->coins);
	fprintf(stdout,"Total coins mined: %d\n", data->total_coins_mined);
	fprintf(stdout,"Number of bots: %d\n", data->bots);
	fprintf(stdout,"Bot speed: %.2f seconds\n", data->seconds_between_mining);
	fprintf(stdout,"Bot power: 1/%d\n", data->processor_power);
	fprintf(stdout,"Processor cores per bot: %d\n", data->cores);
	fprintf(stdout,"Number of available hashes: %d\n", data->number_available_hashes);
	fprintf(stdout,"Cost per bitbot: %d\n", data->cost_bitbot);
	fprintf(stdout,"Cost to double cores: %d\n", data->cost_cores);
	fprintf(stdout,"Cost to upgrade power: %d\n", data->cost_power);
	fprintf(stdout,"Cost to upgrade speed: %d\n", data->cost_speed);
	printNewLine();
};

void commands () {
	printNewLine();
	printCommands();
	printNewLine();
};

void parse (int argc, char* argv[]) {
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i],"buy") == 0) {
			printNewLine();
			if (i+1 < argc && argv[i+1] == "max") {
				buyMax();
			} else {
				buyOne();
			};
			printNewLine();
		} else if (strcmp(argv[i],"upgrade") == 0) {
			if (i+1 < argc) {
				upgrade(argv[i+1]);
			} else {
				printUpgradeInputError();
			};
		} else if (strcmp(argv[i],"read") == 0) {
			read();
		} else if (strcmp(argv[i],"commands") == 0) {
			commands();
		} else {
		};
	};
};

int main (int argc, char* argv[]) {
	FILE *savefile;
	data = (struct Data *) malloc(sizeof(struct Data));

	readSaveData (savefile, data);

	if (argc > 1) {
		parse(argc, argv);
	} else {

		printNewLine();
		mine(data, getMinesSinceLastCheck(data));
		printNewLine();

		printOpData(data);
		printNewLine();

		updateLastLogin(data);
	};

	writeSaveData(savefile, data);
	
	return 0;
};
