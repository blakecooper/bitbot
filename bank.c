#include <time.h>
#include <stdlib.h>
#include "text.h"
#include "file.h"
#include "macros.h"

void calculateMarketRate(struct Data *data) {
	time_t now = time(NULL);
	if ((now - data->rate_last_changed) > ONE_DAY) {
		data->rate_last_changed = now;

		float new_rate;

		int chances_of_market_direction = rand() % 10;

		int market_movement;

		if (chances_of_market_direction < 6) {
			market_movement = data->rate_last_movement;
		} else {
			if (data->rate_last_movement & 1) {
				market_movement = 0;
			} else {
				market_movement = 1;
			};

			data->rate_last_movement = market_movement;
		};

		int chances_of_rate_change = rand() % 100;
		float rate_change;

		if (chances_of_rate_change < 80) {
			rate_change = 0.5;
		} else if (chances_of_rate_change < 95) {
			rate_change = 1.3;
		} else if (chances_of_rate_change < 98) {
			rate_change = 5.2;
		} else {
			rate_change  = 9.8;
		};

		if (market_movement) {
			data->rate += rate_change;
		} else {
			data->rate -= rate_change;
		};
	};
};

unsigned long long int convertToUSD(struct Data *data) {
	calculateMarketRate(data);
	return data->coins * data->rate;
};

unsigned long long int convertToCoins(struct Data *data)  {
	calculateMarketRate(data);
	return data->account / data->rate;
};

void deposit(struct Data *data) {
	data->account += convertToUSD(data);
	data->coins = 0;
};

void withdraw(struct Data *data) {
	data->coins += convertToCoins(data);
	data->account = 0;
};
