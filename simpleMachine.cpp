#include"simpleMachine.h"
#include<vector>
#include<string>
#include<format>

SimpleMachine::SimpleMachine(std::vector<int> inputStorage, std::vector<void (*) (SimpleMachine& machine)> inputInstructions)
{
	if (inputStorage.size() > STORAGE_SIZE)
	{
		perror("Input storage too large for internal storage.");
		quick_exit(-1);
	}

	for (int i = 0; i < inputStorage.size(); i++)
	{
		storage[i] = inputStorage[i];
	}

	_instructions = inputInstructions;
}

//Leaves a trailing zero for user friendlyness. When this trailing zero would be out of bounds, don't add it, instead end on the actual last storage value
std::string SimpleMachine::GetDisplayState()
{
	std::string state;

	int lastUsedStorPos = GetLastMemoryposition();
	
	if (lastUsedStorPos == -1)
	{
		state.append("0: 0\n");
	}
	else
	{
		for (int i = 0; i <= fminf(lastUsedStorPos + 1, STORAGE_SIZE - 1); i++)
		{
			state.append(std::format("{}: {}\n", i, storage[i]));
		}
	}

	if (halting)
		state.append("halted\n");
	return state;
}

void SimpleMachine::ProcessIteration()
{
	SetInstruction();
	ExecuteInstruction();
}

void SimpleMachine::SetInstruction()
{
	int instructionPos = storage[0];
	int instructionId = storage[instructionPos];

	if (instructionId >= _instructions.size())
	{
		_instruction = _instructions[0];
		return;
	}
	_instruction = _instructions[instructionId];
}

void SimpleMachine::ExecuteInstruction()
{
	_instruction(*this);
}

int SimpleMachine::GetLastMemoryposition()
{
	for (int i = storage.size() - 1; i >= 0; i--)
	{
		if (storage[i] != 0)
			return i;
	}
	return -1;
}

#include<iostream>
void Run(SimpleMachine machine)
{
	std::cout << "Initial state" << std::endl << machine.GetDisplayState() << "Press enter to continue\n";
	std::cin.get();

	int i = 0;
	while (true)
	{
		if (i >= MAX_ITERATIONCOUNT)
		{
			std::cout << "Reached max iterations." << std::endl;
			break;
		}

		if (machine.halting)
			break;

		machine.ProcessIteration();
		std::cout << std::format("Iteration {}", i + 1) << std::endl << machine.GetDisplayState() << "Press enter to continue\n";
		std::cin.get();

		i++;
	}
}