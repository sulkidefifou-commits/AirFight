#pragma once

using namespace std;
#include <iostream>;
#include <cstdint>;

class TileData {

public:
	static constexpr unsigned int Wight = 8;
	static constexpr unsigned int Height = 8;
	static constexpr unsigned int TwoBitPerBit = 2;
	static constexpr unsigned int DataSize = 16;

	static constexpr uint8_t maskWhitePixel = 0b00;
	static constexpr uint8_t maskGrayPixel = 0b001;
	static constexpr uint8_t maskDarkPixel = 0b10;
	static constexpr uint8_t maskBlackPixel = 0b11;

	int compteur = 0;

	int octetNumber = 1;

	void AnalyseOctet(uint8_t* octetPtr);

};