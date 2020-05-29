#include <stdio.h>
#include "file.h"
#include "mine.h"
#include "macros.h"

char getPlural(int number) {
	if (number != 1) {
		return 's';
	} else {
		return '\0';
	};
};


void printSuccessfulMiningConfirmation(int coins_mined) {
	fprintf(stdout, "You successfully mined %d coin%c!\n", coins_mined, getPlural(coins_mined));
};

void printCurrentCoinsStored(struct Data *data) {
	fprintf(stdout, "You currently have %d coins in your wallet.\n", data->coins);
};

void printNumberOfProcessors(struct Data *data) {
	fprintf(stdout, "You have %d processors total.\n", data->processors);
};

void printFailedMiningConfirmation() {
	fprintf(stdout, "No new coins mined.\n");
};

void printOpData(struct Data *data) {
	fprintf(stdout, "You currently have %d coin%c in your wallet.\n", data->coins, getPlural(data->coins));
	fprintf(stdout, "%d bot%c mined %d time%c since you last checked.\n", data->bots, getPlural(data->bots),getMinesSinceLastCheck(data),getPlural(getMinesSinceLastCheck(data)));
	fprintf(stdout, "Your processor has %d core%c and a power rating of %d.\n", data->processors, getPlural(data->processors), data->processor_power);
};

void printNewLine() {
	fprintf(stdout, "\n");
};

void printNotEnoughBitbot() {
	fprintf(stdout, "You don't have enough coins to buy a bitbot!\n");
};

void printCostBitbot (struct Data *data) {
	fprintf(stdout, "A bitbot costs %d coin%c\n", data->cost_bitbot, getPlural(data->cost_bitbot));
};

void printBuyConfirmationBitbot() {
	fprintf(stdout, "Purchase successful.\n");
};

void printNumberBots(struct Data *data) {
	fprintf(stdout, "You currently have %d bots.\n", data->bots);
};
