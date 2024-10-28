#include"simpleMachine.h"
#include<vector>
#include<string>
#include<format>

SimpleMachine::SimpleMachine(std::vector<int> inputStorage)
{
	if (inputStorage.size() > STORAGE_SIZE)
	{
		perror("Input storage too large for internal storage.");
		quick_exit(-1);
	}

	for (int i = 0; i < inputStorage.size(); i++)
	{
		_storage[i] = inputStorage[i];
	}
}

std::string SimpleMachine::GetState()
{
	std::string state;

	int lastMemPos = GetLastMemoryposition();
	if (lastMemPos == -1)
	{
		return "0: 0\n";
	}
	
	for (int i = 0; i <= fminf(lastMemPos + 1, STORAGE_SIZE - 1); i++)
	{
		state.append(std::format("{}: {}\n", i, _storage[i]));
	}
	return state;
}

void SimpleMachine::ExecuteInstruction()
{
	int instructionPos = _storage[0];
	int instructionId = _storage[instructionPos];

	//instructionHandling here
}

int SimpleMachine::GetLastMemoryposition()
{
	for (int i = _storage.size() - 1; i >= 0; i--)
	{
		if (_storage[i] != 0)
			return i;
	}
	return -1;
}