#include <stdio.h>
#include "file.h"
#include "mine.h"
#include "macros.h"

float getConversionRate(struct Data *data) {
	return ((float) 1/data->rate);
};

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
		fprintf(stdout, "There are %lld coins in your wallet.\n", data->coins);
	} else {
		fprintf(stdout, "There is %lld coin in your wallet.\n", data->coins);
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
	fprintf(stdout, "%lld bot%c mined a total of %d time%c since you last checked.\n", data->bots, getPlural(data->bots), getMinesSinceLastCheck(data),getPlural(getMinesSinceLastCheck(data)));
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
	fprintf(stdout, "Upgrading your processors costs $%d\n", data->cost_cores);
};

void printCostUpgradePower (struct Data *data) {
	fprintf(stdout, "Upgrading your processor power costs $%d\n", data->cost_power);
};

void printCostUpgradeSpeed (struct Data *data) {
	fprintf(stdout, "Upgrading your processor speed costs $%d\n", data->cost_speed);
};

void printBuyConfirmationBitbot() {
	fprintf(stdout, "You bought a bitbot!\n");
};

void printBuyConfirmationBitbotNumber(int number) {
	fprintf(stdout, "You bought %d bitbot%c!\n", number, getPlural(number));
};

void printNumberBots(struct Data *data) {
	fprintf(stdout, "You currently have %lld bot%c.\n", data->bots, getPlural(data->bots));
};

void printUpgradeConfirmationCores() {
	fprintf(stdout, "You doubled your processor cores!\n");
};

void printUpgradeConfirmationPower() {
	fprintf(stdout, "Your processors are 20 percent more powerful!\n");
};

void printUpgradeConfirmationSpeed() {
	fprintf(stdout, "Your processors are 10 percent faster!\n");
};

void printProcessorInfo(struct Data *data) {
	fprintf(stdout, "Your bots have a power rating of 1/%d.\n", data->processor_power);
	fprintf(stdout, "Your bots mine for coins every %.2f seconds.\n", data->seconds_between_mining);
	fprintf(stdout, "Each bot has a%c %d-core processor.\n", getArticle(data->cores), data->cores);
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

void printIntro() {
	fprintf(stdout, "Congratulations! You're the proud owner of a bitbot!\n");
	fprintf(stdout, "Your bitbot will mine cryptocurrency for you in the background.\n");
	fprintf(stdout, "For better results, buy more bitbots or upgrade their processors.\n");
};

void printCommands() {
	fprintf(stdout, "'bitbot': see how many coins your bitbots have mined\n");
	fprintf(stdout, "'bitbot buy': buy another bitbot\n");
	fprintf(stdout, "'bitbot buy max': buy as many bitbots as you can afford\n");
	fprintf(stdout, "'bitbot upgrade cores': double the cores in your bitbots' processors\n");
	fprintf(stdout, "'bitbot upgrade power': each bitbot works harder to mine coins\n");
	fprintf(stdout, "'bitbot upgrade speed': each bitbot works faster to mine coins\n");
	fprintf(stdout, "'bitbot read': see all your stats\n");
	fprintf(stdout, "'bitbot bank deposit': convert coins to cash\n");
	fprintf(stdout, "'bitbot bank withdraw': convert cash to coins\n");
	fprintf(stdout, "'bitbot bank rate': see today's conversion rate\n");
	fprintf(stdout, "'bitbot bank account': see your bank account balance\n");
};

void printAccount(struct Data *data) {
	fprintf(stdout, "You currently have $%lld USD in your bank account\n", data->account);
};

void printRate(struct Data *data) {
	fprintf(stdout, "One coin is currently worth $%.2f\n", data->rate);
	fprintf(stdout, "$1 currently buys %.4f coins\n", getConversionRate(data));
};

void printBankInputError() {
	fprintf(stdout, "What do you want to do [deposit, withdraw, rate, account]?\n");
};
void printDepositConfirmation(struct Data *data) {
	fprintf(stdout, "Deposit successful at %f rate! You have $%lld USD in your account\n", data->rate, data->account);
};

void printDepositError() {
	fprintf(stdout, "You don't have any coins to deposit!\n");
};
void printWithdrawConfirmation(struct Data *data) {
	fprintf(stdout, "Withdraw successful at %f rate! You have %lld coins in your wallet\n", data->rate, data->coins);
};
void printWithdrawError() {
	fprintf(stdout, "You don't have any cash in your accont to withdraw!\n");
};
