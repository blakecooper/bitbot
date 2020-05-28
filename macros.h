struct Data {
	int processors;
	int coins;
};

//Total number of items that need to be saved
const int TOTAL_DATA = 2;

//Indeces of data in save file
const int PROCESSORS = 0;
const int COINS = 1;

//How precise the processor is at finding the hash (lower number is better)
const int PROCESSOR_POWER = 10;

//How many possible hashes are there (more means harder to mine)
const int NUMBER_OF_POSSIBLE_HASHES = 2;

void readSaveData(FILE *savefile, struct Data *data) {
	savefile = fopen("savefile", "rb");

	if (!savefile) {
		data->processors = 1;
		data->coins = 0;	
	} else {
		fread ((void *) data, sizeof(struct Data), 1, savefile);
	};
};

void writeSaveData(FILE *savefile, struct Data *data) {
	savefile = fopen("savefile", "wb");
	fwrite((void *) data, sizeof(struct Data), 1, savefile);
};

void printSuccessfulMiningConfirmation() {
	fprintf(stdout, "You successfully mined a coin!\n");
};

void printCurrentCoinsStored(struct Data *data) {
	fprintf(stdout, "You currently have %d coins in your wallet.\n", data->coins);
};

void printNumberOfProcessors(struct Data *data) {
	fprintf(stdout, "You have %d processors total.\n", data->processors);
};

void printFailedMiningConfirmation() {
	fprintf(stdout, "Mining unsuccessful.\n");
};
