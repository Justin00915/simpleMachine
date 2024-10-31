#pragma once
#include<string>
#include<vector>

//Machine storage Size
const int STORAGE_SIZE = 1024;

//Run iteration Count
const int MAX_ITERATIONCOUNT = 64;

class SimpleMachine
{
public:
	SimpleMachine(std::vector<int> storage, std::vector<void (*) (SimpleMachine& machine)> inputInstructions);
	void ProcessIteration();
	std::string GetDisplayState();

	std::vector<int> storage = std::vector<int>(STORAGE_SIZE, 0);
	bool halting = false;

private:
	void SetInstruction();
	void ExecuteInstruction();

	int GetLastMemoryposition();

	void (*_instruction) (SimpleMachine& machine) = nullptr;
	std::vector<void (*) (SimpleMachine& machine)> _instructions;
};

void Run(SimpleMachine machine);