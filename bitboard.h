#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>
#include <iostream>


struct ChessBoard{


    //All pieces are initialized to their initial positons.
    uint64_t WhitePawns = 0x000000000000ff00;
    uint64_t WhiteRooks = 0x0000000000000081;
    uint64_t WhiteKnights = 0x0000000000000042;
    uint64_t WhiteBishops = 0x0000000000000024;
    uint64_t WhiteQueen = 0x0000000000000008;
    uint64_t WhiteKing = 0x0000000000000010;

    uint64_t BlackPawns = 0x00ff000000000000;
    uint64_t BlackRooks = 0x8100000000000000;
    uint64_t BlackKnights = 0x4200000000000000;
    uint64_t BlackBishops = 0x2400000000000000;
    uint64_t BlackQueen = 0x0800000000000000;
    uint64_t BlackKing = 0x1000000000000000;

    uint64_t BlackPieces = BlackPawns | 
                           BlackRooks |
                           BlackKnights|
                           BlackBishops|
                           BlackQueen|
                           BlackKing;

    uint64_t WhitePieces = WhitePawns |
                            WhiteRooks|
                            WhiteKnights|
                            WhiteBishops |
                            WhiteQueen|
                            WhiteKing;

    uint64_t AllPieces = WhitePieces | 
                         BlackPieces;

    uint64_t EmptyBoard = AllPieces ^
                          0xffffffffffffffff;
};

/**
 * @brief: an array of unsigned integers to bitmask the files
 * 
 */
uint64_t File[] = {
    0x0101010101010101,
    0x0202020202020202,
    0x0404040404040404,
    0x0808080808080808,
    0x1010101010101010,
    0x2020202020202020,
    0x4040404040404040,
    0x8080808080808080
};


/**
 * @brief an array of 64-bit unsigned integers to represent the different ranks
 * Rank[0] = 1
 * Rank[1] = 2
 * Rank[3] = 3
 * .... etc
 */
uint64_t Rank[] = {
    0x00000000000000ff,
    0x000000000000ff00,
    0x0000000000ff0000,
    0x00000000ff000000,
    0x000000ff00000000,
    0x0000ff0000000000,
    0x00ff000000000000,
    0xff00000000000000
};

void printBoard(ChessBoard chess_board);

uint64_t pop_LSB(uint64_t num);

void generate_rook_moves(const int &side);

#endif