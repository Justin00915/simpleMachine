#include<iostream>
#include<format>
#include"simpleMachine.h"

const int MAX_ITERATIONCOUNT = 64;

void main() {
	std::vector<int> storage{ 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };

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
		},

		//INC
		[](SimpleMachine& machine)
		{
			int instructionPos = machine.storage[0];
			int incPos = machine.storage[instructionPos + 1];

			machine.storage[incPos]++;

			machine.storage[0] += 2;
		},

		//DEC
		[](SimpleMachine& machine)
		{
			int instructionPos = machine.storage[0];
			int incPos = machine.storage[instructionPos + 1];

			if (machine.storage[incPos] > 0)
				machine.storage[incPos]--;

			machine.storage[0] += 2;
		},

		//JNZ
		[](SimpleMachine& machine)
		{
			int instructionPos = machine.storage[0];
			int decisionVar = machine.storage[instructionPos + 1];
			int jumpPos = machine.storage[instructionPos + 2];

			if (decisionVar != 0)
			{
				machine.storage[0] = jumpPos;
				return;
			}

			machine.storage[0] += 3;
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