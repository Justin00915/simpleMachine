#include<iostream>
#include"simpleMachine.h"

void main() {
	SimpleMachine machine({1, 2, 0, 4, 5});
	std::cout << machine.GetState();
}