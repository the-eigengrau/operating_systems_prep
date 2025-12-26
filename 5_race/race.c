/*

Project 5: The "Race Condition" Simulator
Goal: Understand why we need locks. Concepts: pthread_create, pthread_join, Race Conditions. The Project:

Create a global variable int counter = 0;.

Spawn 2 threads. Each thread runs a loop 1,000,000 times performing counter++.

Print the final value.

Observation: It won't be 2,000,000. It will be random and lower. This is a race condition.

The Fix: Introduce pthread_mutex_t. Lock before incrementing, unlock after. Verify the result is now exactly 2,000,000.

*/