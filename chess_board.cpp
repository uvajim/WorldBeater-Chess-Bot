#include <stdint.h>

/**
 * @brief 
 * 
 */


struct ChessBoard{
    //All pieces are initialized to their initial positons.
    uint64_t WhitePawns = 0x0000ff00;
    uint64_t WhiteRooks = 0x00000081;
    uint64_t WhiteKnights = 0x00000042;
    uint64_t WhiteBishops = 0x00000024;
    uint64_t WhiteQueen = 0x00000008;
    uint64_t WhiteKing = 0x00000010;

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
};