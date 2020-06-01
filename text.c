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

char getArticle(int number) {
	if (number == 8) {
		return 'n';
	} else {
		return '\0';
	};
};

void printSuccessfulMiningConfirmation(int coins_mined) {
	fprintf(stdout, "Your bots mined %d coin%c!\n", coins_mined, getPlural(coins_mined));
};

void printCurrentCoinsStored(struct Data *data) {
	if (getPlural(data->coins) == 's') {
		fprintf(stdout, "There are %d coins in your wallet.\n", data->coins);
	} else {
		fprintf(stdout, "There is %d coin in your wallet.\n", data->coins);
	};
};

void printNumberOfProcessors(struct Data *data) {
	fprintf(stdout, "You have %d processors total.\n", data->cores);
};

void printFailedMiningConfirmation() {
	fprintf(stdout, "No new coins mined.\n");
};

void printOpData(struct Data *data) {
	printCurrentCoinsStored(data);
	fprintf(stdout, "%d bot%c mined %d time%c since you last checked.\n", data->bots, getPlural(data->bots), getMinesSinceLastCheck(data),getPlural(getMinesSinceLastCheck(data)));
};

void printNewLine() {
	fprintf(stdout, "\n");
};

void printNotEnough() {
	fprintf(stdout, "You can't afford that!\n");
};

void printCostBitbot (struct Data *data) {
	fprintf(stdout, "A bitbot costs %d coin%c\n", data->cost_bitbot, getPlural(data->cost_bitbot));
};

void printCostUpgrade (struct Data *data) {
	fprintf(stdout, "Upgrading your processors costs %d coin%c\n", data->cost_cores, getPlural(data->cost_bitbot));
};

void printCostUpgradePower (struct Data *data) {
	fprintf(stdout, "Upgrading your processor power costs %d coin%c\n", data->cost_power, getPlural(data->cost_power));
};

void printCostUpgradeSpeed (struct Data *data) {
	fprintf(stdout, "Upgrading your processor speed costs %d coin%c\n", data->cost_speed, getPlural(data->cost_speed));
};

void printBuyConfirmationBitbot() {
	fprintf(stdout, "You bought a bitbot!\n");
};

void printNumberBots(struct Data *data) {
	fprintf(stdout, "You currently have %d bot%c.\n", data->bots, getPlural(data->bots));
};

void printUpgradeConfirmationCores() {
	fprintf(stdout, "You doubled your processor cores!\n");
};

void printUpgradeConfirmationPower() {
	fprintf(stdout, "Your processors are 10 percent more powerful!\n");
};

void printUpgradeConfirmationSpeed() {
	fprintf(stdout, "Your processors are 10 percent faster!\n");
};

void printProcessorInfo(struct Data *data) {
	fprintf(stdout, "Each bot has a%c %d-core Mackerel brand processor.\n", getArticle(data->cores), data->cores);
	fprintf(stdout, "Your processors have a power rating of 1/%d.\n", data->processor_power);
	fprintf(stdout, "Your bots mine for coins every %.2f seconds.\n", data->seconds_between_mining);
};

void printUpgradeInputError() {
	fprintf(stdout, "What do you want to upgrade? [cores, power, speed]\n");
};

void printHashReduction() {
	fprintf(stdout, "Number of possible hashes reduced.\n");
};

void printLotteryConfirmation() {
	fprintf(stdout, "You won the lottery! Your mined coins multiplied by 10!\n");
};
