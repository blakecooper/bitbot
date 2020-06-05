//Definitions for various things in the game, to clean up code
#define BOTS 1
#define CORES 2
#define POWER 3
#define SPEED 4

//How many processors does the player start with (more is better)?
#define STARTING_CORES 1

//How powerful are the processors (lower is better, it's an inverse)?
#define STARTING_PROCESSOR_POWER 30000000

//How many bots does the player start with (more is better)?
#define STARTING_BOTS 1

//How many coins does the player start with?
#define STARTING_COINS 0

//How many possible hashes are there (fewer means harder to mine)
#define STARTING_NUMBER_POSSIBLE_HASHES 1000000

//How frequently do bots mine?
#define STARTING_SECONDS_BETWEEN_MINING 20

//Starting cost for a bitbot
#define STARTING_COST_BITBOT 1

//Starting costs for processor upgrades
#define STARTING_COST_CORES 50
#define STARTING_COST_POWER 10
#define STARTING_COST_SPEED 10

//Cost multiplier every time something is purchased
//Applies to all buys and upgrades (for now)
#define COST_MULTIPLIER 1.5

//Odds of winning the lottery (one out of...)
#define LOTTERY_CHANCES 100000

//Lottery multiplier
#define LOTTERY_MULTIPLIER 10

//How long can the name of a buy option be?
#define MAX_STRING_LENGTH 32

//Save location
#define SAVE_FILE_PATH "save"
