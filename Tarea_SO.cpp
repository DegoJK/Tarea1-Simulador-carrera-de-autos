#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <random>

std::mutex coutMutex;
std::vector<std::string> rank;

void funcionHebra(int id){
	std::cout << "Hebra" << id << " esta ejecutandose.\n";
}

void carRace(int carId, int raceDistance){
	int actualDistance = 0;
	
	// Inicializar un generador de números aleatorios independiente para cada hilo
	srand(std::time(0) + carId);
    	
    	
	while(true){
		//Calcular la distancia a avanzar
    	int avanzar = rand() % 9 + 1;
    	int dormir = rand() % 400 + 100;
		
		actualDistance = actualDistance + avanzar;
		
		std::lock_guard<std::mutex> lock(coutMutex);
		
		if(actualDistance >= raceDistance){
			actualDistance = raceDistance;
			std::cout << "Auto " << carId << " ha terminado la carrera!" << std::endl;
			rank.push_back("Auto" + std::to_string(carId));

			break;
		}
		
		std::cout << "Auto " << carId << ": " << actualDistance << " metros." << std::endl;
		
		std::this_thread::sleep_for(std::chrono::milliseconds(dormir));
	}
}

int main(){
	
	
	std::thread auto1(carRace, 1, 100);
	std::thread auto2(carRace, 2, 100);
	
	auto1.join();
	auto2.join();
	
	std::cout << "\n\n..:: ORDEN DE LLEGADA ::.." << std::endl;
	for(int i=0;i<rank.size();i++){
		std::cout << (i + 1) << ". " << rank[i] << std::endl;
	}

	return 0;
}