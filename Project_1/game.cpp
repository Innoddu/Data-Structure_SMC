#include "game.h"
#include "world.h"
#include "globals.h"
#include <iostream>
#include <thread>
#include <string>

///////////////////////////////////////////////////////////////////////////
// Game Implemention
///////////////////////////////////////////////////////////////////////////

Game::Game(Life **life, int numLife) {

	m_steps = 0;
	m_automate = false;
	m_world = new World();

	if (life != nullptr) {
		for (int i = 0; i < numLife; i++) {
			if (life[i] != nullptr) {
				bool success = m_world->init(life[i]);
				if (!success) {
					std::cout << "Failed to add life to the world" << std::endl;
				}
			}

		}
	}

}
Game::~Game() {
	delete m_world;
}

void Game::gameLoop() {
	while (true) {
		m_world->print();

		if (!m_automate) {
			std::cout << "command (<space> to step, <a> to automate, <q> to quit): ";

			std::string action;
			std::getline(std::cin, action);

			switch (action[0])
			{

			default:
				std::cout << '\a' << std::endl;  // beep
				continue;
			case 'q':
				std::cout << "Quitting Game." << std::endl;
				return;
			case 's':

				continue;
			case ' ':

				break;
			case 'a':
				m_automate = true;
				break;

			}
		}
		else {
			if (m_steps >= MAX_STEPS) {
				std::cout << "Reached max steps, quitting." << std::endl;
				return;
			}
			delay(300);
		}
		m_steps++;
		m_world->update();
	}
}

void Game::report() {
	std::string msg = "1. If it is not compiled, an error may occur because the header guard is not written in each header file.\n2. The world class does not exist in the game.h file. If you declare #include \"world.h\"  in the game.h file, it will be compiled successfully. \n3. In the game.h file, only class Life is declared and there is no class content for Life. This means that you need a life.h file. In addition, the world class is compiled in advance without the world.h file, resulting in an error. You must declare  #include \"life.h\"  and #include \"world.h\" in the game.h file to be compiled successfully."; // Replace Hello World with your answer.
	std::cout << msg << std::endl;
}


void Game::delay(int ms) const{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}


