#include<iostream>
#include<format>
#include"simpleMachine.h"

const int MAX_ITERATIONCOUNT = 64;

void main() {
	std::vector<int> storage{ 1, 1, 1, 0, 0 };

	std::vector<void(*)(SimpleMachine& machine)> instructions
	{
		//HALT
		[](SimpleMachine& machine)
		{
			machine.halting = true;
		},

		//NOP
		[](SimpleMachine& machine)
		{
			machine.storage[0]++;
		}
	};

	SimpleMachine machine(storage, instructions);

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