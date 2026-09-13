#ifndef TILE_H
#define TILE_H
using namespace std;

#include <cstdint>

class Tile {

public:
	static constexpr unsigned int Wight = 8;
	static constexpr unsigned int Height = 8;
	static constexpr unsigned int TwoBitPerBit = 2;
	static constexpr unsigned int DataSize = 16;

	static constexpr unsigned int CharWhitePixel = 176;
	static constexpr unsigned int CharGrayPixel = 177;
	static constexpr unsigned int CharDarkPixel = 178;
	static constexpr unsigned int CharBlackPixel = 219;

	static constexpr uint8_t maskWhitePixel = 0b00;
	static constexpr uint8_t maskGrayPixel = 0b001;
	static constexpr uint8_t maskDarkPixel = 0b10;
	static constexpr uint8_t maskBlackPixel = 0b11;

};
#endif // TILE_H
