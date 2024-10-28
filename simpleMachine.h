#pragma once
#include<string>
#include<vector>

const int STORAGE_SIZE = 5;

class SimpleMachine
{
public:
	SimpleMachine(std::vector<int> storage);
	std::string GetState();

private:
	int GetLastMemoryposition();

	std::vector<int> _storage = std::vector<int>(STORAGE_SIZE, 0);
};