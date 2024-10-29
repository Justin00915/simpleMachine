#pragma once
#include<string>
#include<vector>

const int STORAGE_SIZE = 1024;

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