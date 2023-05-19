#ifndef NR_LDPC_H
#define NR_LDPC_H

// Included libraries
#include <stdint.h> // uint8_t, uint16_t
#include<numeric> // size_t
#include<vector>
#include <assert.h>
#include <iostream>
#include <array>
#include <algorithm> // sort, transform, rotate
#include <functional> // xor

// 3GPP LDPC related tables
extern const uint16_t liftSizeTable[8][8];
extern const uint16_t shiftTableBgn_1[316][10];
extern const uint16_t shiftTableBgn_2[197][10];

// Definition of a Tanner Graph edge
struct edge_t {
	uint16_t cNodeIdx; // Check node index
	uint16_t vNodeIdx; // Variable node index
	uint16_t nShifts;  // Shift value
};

// Definition of a layer in a Tanner Graph
struct layer_t {
	uint16_t edgeStart; // Start edge
	uint16_t edgeEnd;   // End edge
};

// NR LDPC Class definition
class nrLDPC {
public:
	// Class variables
	std::size_t mKBar;          // info length excluding fillers
	std::size_t mK;             // info length including fillers
	double      mR;             // code rate
	uint8_t     mBGn;           // base graph identifier
	uint16_t    mZc;            // lifting size
	uint8_t     mSetIdx;        // the set that shift coefficients belongs to 0-7
	std::size_t mF;             // number of fillers to make info length is 22*Zc 0r 10*Zc
	std::size_t mN;             // mother code word length

	// Tanner Graph variables
	std::vector<edge_t> mEdges;   // edges are sorted by check node idx and variable node idx
	std::vector<layer_t> mLayers; // the i-th layer stores all the connections(edges) to the i-th check node

public:
	// Class methods
	nrLDPC(std::size_t infoLen, double codeRate);    // Constructor
	std::vector<bool> encode(const std::vector<bool>& msg);    // encoding
	std::vector<bool> decode(const std::vector<double>& llr, const unsigned nMaxIter);    // decoding
	std::vector<bool> rateMatch(const std::vector<bool>& bitsIn, std::size_t nOfBitOut);  // rate matching
	std::vector<double> rateRecover(const std::vector<double>& softBitsIn);   // rate recovery
	bool checkSumCodeWord(std::vector<bool>& cw);   // checkSum a code word
	size_t getFillerLength() { return mF; }         // filler length

public:
	// Static methods
	static uint8_t selectBaseGraph(std::size_t KBar, double R);
	static uint16_t selectLiftSize(std::size_t KBar, uint8_t BGn);
	static uint8_t selectShiftSet(uint16_t Zc);
    std::vector<std::vector<bool>> makeParityCheckMatrix(uint8_t BGn, uint16_t Zc); // Method to make parity check matrix

private:
    // Core decoding module
    std::vector<std::vector<double>> checkNodeOperation(const std::vector<std::vector<double>>& msgIn); 
    template<typename T>
    inline std::vector<std::size_t> sort_indexes(const std::vector<T>& v); // Sorting function

    std::vector<std::vector<double>> transposeMat(const std::vector<std::vector<double>>& mat); // Function to transpose matrix

    // Wrapper functions to enhance readability
    template<typename T>
    inline std::vector<T> circShift(const std::vector<T>& vecIn, const unsigned nShifts); // Function for circular shifting
    inline std::vector<bool> eleWiseXor(const std::vector<bool>& vec1, const std::vector<bool>& vec2); // Function for elementwise XOR operation
    inline std::vector<double> eleWisePlus(const std::vector<double>& vec1, const std::vector<double>& vec2); // Function for elementwise addition
    inline std::vector<double> eleWiseMinus(const std::vector<double>& vec1, const std::vector<double>& vec2); // Function for elementwise subtraction
};

#endif // NR_LDPC_H
