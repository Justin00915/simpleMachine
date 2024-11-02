#include<iostream>
#include<format>
#include"simpleMachine.h"

int main() {
	std::vector<int> storage
	{ 2, 7, 3, 1, 4, 1, 2, 0 };

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
			int decisionVarPos = machine.storage[instructionPos + 1];
			int jumpPos = machine.storage[instructionPos + 2];

			if (machine.storage[decisionVarPos] != 0)
			{
				machine.storage[0] = jumpPos;
				return;
			}

			machine.storage[0] += 3;
		}
	};

	SimpleMachine machine(storage, instructions);
	Run(machine);
}
