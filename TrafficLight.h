#pragma once

enum class State
{
	RED,
	YELLOW,
	GREEN
};

class TrafficLight
{
public:
	TrafficLight();

	void addTransition(State from, State to);

	void changeSignal(State newState);

	void currentState() const;

private:
	State _currentState;
	std::map<State, std::vector<State>> _transitions;
};
