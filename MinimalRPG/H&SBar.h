#pragma once
#include "MapPosition.h"

void ProgressBarHealth(int current, int max) {
	const int barWidth = 10;
	int barLength = barWidth * current / max;

	std::cout << "[";
	for (int i = 0; i < barWidth; ++i) {
		std::cout << (i < barLength ? "=" : " ");
	}
	std::cout << "] ";

}

void ProgressBarStamina(int current, int max) {
	const int barWidth = 10;
	int barLength = barWidth * current / max;

	std::cout << "[";
	for (int i = 0; i < barWidth; ++i) {
		std::cout << (i < barLength ? ">" : " ");
	}
	std::cout << "] ";

}