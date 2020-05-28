struct Data {
	int processors;
	int coins;
	int bots;
	time_t last_login;
};


//How precise the processor is at finding the hash (lower number is better)
const int PROCESSOR_POWER = 10;

//How many possible hashes are there (more means harder to mine)
const int NUMBER_OF_POSSIBLE_HASHES = 2;

//How frequently do bots mine?
const int SECONDS_BETWEEN_BOTS_MINING = 10;

char getPlural(int number) {
	if (number != 1) {
		return 's';
	} else {
		return '\0';
	};
};

void readSaveData(FILE *savefile, struct Data *data) {
	savefile = fopen("savefile", "rb");

	if (!savefile) {
		data->processors = 1;
		data->coins = 0;	
		data->bots = 1;
		data->last_login = time(NULL);
	} else {
		fread ((void *) data, sizeof(struct Data), 1, savefile);
	};
};

void writeSaveData(FILE *savefile, struct Data *data) {
	savefile = fopen("savefile", "wb");
	fwrite((void *) data, sizeof(struct Data), 1, savefile);
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

int getMinesSinceLastCheck(struct Data *data) {
	time_t now = time(NULL);
	double seconds_elapsed = difftime(now, data->last_login);

	return (seconds_elapsed / SECONDS_BETWEEN_BOTS_MINING);
};

void printOpData(struct Data *data) {
	fprintf(stdout, "You currently have %d coin%c in your wallet.\n", data->coins, getPlural(data->coins));
	fprintf(stdout, "%d bot%c mined %d time%c since you last checked.\n", data->bots, getPlural(data->bots),getMinesSinceLastCheck(data),getPlural(getMinesSinceLastCheck(data)));
	fprintf(stdout, "Your processor has %d core%c and a power rating of %d.\n", data->processors, getPlural(data->processors), PROCESSOR_POWER);
};

void printNewLine() {
	fprintf(stdout, "\n");
};

