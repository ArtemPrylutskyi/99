#include "TrafficLight.h"

int main()
{
	TrafficLight light;

	light.changeSignal(State::GREEN);
	light.changeSignal(State::YELLOW);
	light.changeSignal(State::RED);
	light.changeSignal(State::GREEN);
	light.changeSignal(State::RED); // Valid
	light.changeSignal(State::YELLOW); // Valid
	light.changeSignal(State::GREEN); // Valid
}
