#include "TrafficLight.h"
#include <iostream>

TrafficLight::TrafficLight() : _currentState(State::RED)
{
	std::cout << "Traffic light started. Current state: RED\n";

	addTransition(State::RED, State::GREEN);
	addTransition(State::RED, State::YELLOW);
	addTransition(State::GREEN, State::RED);
	addTransition(State::GREEN, State::YELLOW);
	addTransition(State::YELLOW, State::RED);
	addTransition(State::YELLOW, State::GREEN);
}

void TrafficLight::addTransition(State from, State to)
{
	_transitions[from].push_back(to);
}

void TrafficLight::changeSignal(State newState)
{
	auto& allowedTransitions = _transitions[_currentState];
	if (std::find(allowedTransitions.begin(), allowedTransitions.end(), newState) != allowedTransitions.end())
	{
		_currentState = newState;
		std::cout << "Changed to ";
		currentState();
	}
	else
	{
		std::cout << "Transition from ";
		currentState();
		std::cout << " to ";
		switch (newState)
		{
			case State::RED: std::cout << "RED"; break;
			case State::YELLOW: std::cout << "YELLOW"; break;
			case State::GREEN: std::cout << "GREEN"; break;
		}
		std::cout << " is not allowed!\n";
	}
}

void TrafficLight::currentState() const
{
	switch (_currentState)
	{
	case State::RED:
		std::cout << "RED\n";
		break;
	case State::YELLOW:
		std::cout << "YELLOW\n";
		break;
	case State::GREEN:
		std::cout << "GREEN\n";
		break;
	}
}
