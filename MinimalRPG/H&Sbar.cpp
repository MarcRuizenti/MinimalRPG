#include "H&SBar.h"

void ProgressBarHealth(int current, int max) {
	const int barWidth = 10;
	int barLength = barWidth * current / max;

	cout << "[";
	if (barLength < 1) {
		cout << "=";
	}
	for (int i = 0; i < barWidth; ++i) {
		cout << (i < barLength ? "=" : " ");
	}
	cout << "] ";

}

void ProgressBarStamina(int current, int max) {
	const int barWidth = 10;
	int barLength = barWidth * current / max;

	cout << "[";
	for (int i = 0; i < barWidth; ++i) {
		cout << (i < barLength ? ">" : " ");
	}
	cout << "] ";

}