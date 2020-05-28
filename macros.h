//Total number of items that need to be saved
const int TOTAL_DATA = 2;

//Indeces of data in save file
const int PROCESSORS = 0;
const int COINS = 1;

//How precise the processor is at finding the hash (lower number is better)
const int PROCESSOR_POWER = 10;

//How many possible hashes are there (more means harder to mine)
const int NUMBER_OF_POSSIBLE_HASHES = 2;

void readSaveData(FILE *savefile, int *data) {
	savefile = fopen("savefile", "rb");

	if (!savefile) {
		data[PROCESSORS] = 1;
		data[COINS] = 0;	
	} else {
		fread ((void *) data, sizeof(int), TOTAL_DATA, savefile);
	};
};

void writeSaveData(FILE *savefile, int *data) {
	savefile = fopen("savefile", "wb");
	fwrite((void *) data, sizeof(int), TOTAL_DATA, savefile);
};

void printSuccessfulMiningConfirmation() {
	fprintf(stdout, "You successfully mined a coin!\n");
};

void printCurrentCoinsStored(int *data) {
	fprintf(stdout, "You currently have %d coins in your wallet.\n", data[COINS]);
};

void printNumberOfProcessors(int *data) {
	fprintf(stdout, "You have %d processors total.\n", data[PROCESSORS]);
};

void printFailedMiningConfirmation() {
	fprintf(stdout, "Mining unsuccessful.\n");
};
