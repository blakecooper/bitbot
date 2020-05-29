#include <stdlib.h>
#include <string.h>
#include "file.h"
#include "mine.h"
#include "text.h"

struct Data *data;

void buy () {
	printNewLine();
	if (data->cost_bitbot <= data->coins) {
		data->coins -= data->cost_bitbot;
		data->bots ++;
		data->cost_bitbot = data->cost_bitbot * 2;
		printBuyConfirmationBitbot();
		printNumberBots(data);
		printCurrentCoinsStored(data);
	} else {
		printNotEnoughBitbot();
		printCurrentCoinsStored(data);
		printCostBitbot(data);
	};
	printNewLine();
};

void parse (int argc, char* argv[]) {
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i],"buy")) {
			buy();
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

		mine(data, getMinesSinceLastCheck(data));
		printNewLine();

		printOpData(data);
		printNewLine();

		updateLastLogin(data);
	};

	writeSaveData(savefile, data);
	
	return 0;
};
