#pragma once
#include<string>
#include<vector>

const int STORAGE_SIZE = 1024;

class SimpleMachine
{
public:
	SimpleMachine(std::vector<int> storage);

	std::string GetState();
	void ExecuteInstruction();

private:
	int GetLastMemoryposition();

	std::vector<int> _storage = std::vector<int>(STORAGE_SIZE, 0);
};