#include "bitboard.h"

void printBoard(ChessBoard chess_board){

    
    char board[64];
    memset(board,'-', 64);
    //these will be used to classify the pawns
    int rank = 0;
    int file = 0;
    while (chess_board.WhitePawns){
        if (chess_board.WhitePawns & 1)
            board[8*file + rank] = 'P';
        ++rank;
        chess_board.WhitePawns = chess_board.WhitePawns >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackPawns){
        if (chess_board.BlackPawns & 1)
            board[8*file + rank] = 'P';
        ++rank;
        chess_board.BlackPawns = chess_board.BlackPawns >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }


    //printing the rooks
    rank = 0;
    file = 0;
    while (chess_board.WhiteRooks){
        if (chess_board.WhiteRooks & 1)
            board[8*file + rank] = 'R';
        ++rank;
        chess_board.WhiteRooks = chess_board.WhiteRooks >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackRooks){
        
        if (chess_board.BlackRooks & 1)
            board[8*file + rank] = 'R';
        ++rank;
        chess_board.BlackRooks = chess_board.BlackRooks >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    //printing the knights
    rank = 0;
    file = 0;
    while (chess_board.WhiteKnights){
        if (chess_board.WhiteKnights & 1)
            board[8*file + rank] = 'N';
        ++rank;
        chess_board.WhiteKnights = chess_board.WhiteKnights >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackKnights){
        if (chess_board.BlackKnights & 1)
            board[8*file + rank] = 'N';
        ++rank;
        chess_board.BlackKnights = chess_board.BlackKnights >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    //printing the bishops
    rank = 0;
    file = 0;
    while (chess_board.WhiteBishops){
        if (chess_board.WhiteBishops & 1)
            board[8*file + rank] = 'B';
        ++rank;
        chess_board.WhiteBishops = chess_board.WhiteBishops >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackBishops){
        if (chess_board.BlackBishops & 1)
            board[8*file + rank] = 'B';
        ++rank;
        chess_board.BlackBishops = chess_board.BlackBishops >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }

    //printing the bishops
    rank = 0;
    file = 0;
    while (chess_board.WhiteBishops){
        if (chess_board.WhiteBishops & 1)
            board[8*file + rank] = 'B';
        ++rank;
        chess_board.WhiteBishops = chess_board.WhiteBishops >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackBishops){
        if (chess_board.BlackBishops & 1)
            board[8*file + rank] = 'B';
        ++rank;
        chess_board.BlackBishops = chess_board.BlackBishops >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }

    //printing the queens
    rank = 0;
    file = 0;
    while (chess_board.WhiteQueen){
        if (chess_board.WhiteQueen & 1)
            board[8*file + rank] = 'Q';
        ++rank;
        chess_board.WhiteQueen = chess_board.WhiteQueen >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackQueen){
        if (chess_board.BlackQueen & 1)
            board[8*file + rank] = 'Q';
        ++rank;
        chess_board.BlackQueen = chess_board.BlackQueen>> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }

    //printing the kings
    rank = 0;
    file = 0;
    while (chess_board.WhiteKing){
        if (chess_board.WhiteKing & 1)
            board[8*file + rank] = 'K';
        ++rank;
        chess_board.WhiteKing = chess_board.WhiteKing >> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }
    rank = 0;
    file = 0;
    while (chess_board.BlackKing){
        if (chess_board.BlackKing& 1)
            board[8*file + rank] = 'K';
        ++rank;
        chess_board.BlackKing = chess_board.BlackKing>> 1;
        if (rank == 8){
            rank = 0;
            ++file;
        }
    }

    int i = 0;
    for (char c: board){
        printf("%c ", c);
        
        if (i++ + 1 == 8){
            i = 0;
            printf("%c", '\n');
        }
        
    }
}

uint64_t pop_LSB(uint64_t num){
    uint64_t LSB = 0x1;
    while (!(num & 1)){
        LSB = LSB << 1;
        num = num >> 1;
    }
    return LSB;
}

uint64_t get_bishops_attacks(const ChessBoard &board, const uint_fast8_t &side, const uint64_t &position){
    uint64_t possible_moves = bishops_masks[position];
    uint64_t blockers = possible_moves & board.AllPieces;
    uint64_t key = (blockers * bishopMagics[position]) >> (64 - bishopIndexBits[position]);
    return BishopTable[position][key];

}

uint64_t get_rook_attacks(const ChessBoard &board, const uint64_t &position){
    uint64_t rank = Rank[position >> 3];
    uint64_t file = File[position % 8];
    uint64_t possible_moves = (rank | file) & ~position;
    possible_moves = possible_moves & ~(Rank[0] | Rank[7] | File[0] | File[7]);
    uint64_t blockers = possible_moves & board.AllPieces;
    uint64_t key = (blockers * rookMagics[position]) >> (64 - rookIndexBits[position]);
    return RookTable[position][key];

    
}

uint64_t get_pawn_attacks(const ChessBoard &board, const uint_fast8_t &side){
    uint64_t possible_moves = 0x0;
    uint64_t pawn_positions = 0x0;

    if (side){
        
        pawn_positions = board.WhitePawns;

        //checks to see if this is the first move that the 
        //pawn can move, if os we allow the pawn to move forward two
        //squares
        possible_moves |= (pawn_positions & Rank[1]) << 16;

        //adds the move forward one square move
        possible_moves |= pawn_positions << 8;

        //checks to see that there are no collisions
        possible_moves &= board.EmptyBoard;
        
        //checks to see if we can attack a piece as a pawn
        possible_moves |= pawn_positions << 7 & board.BlackPieces;
        possible_moves |= pawn_positions << 9 & board.BlackPieces;

        return possible_moves;
    }

    pawn_positions = board.BlackPawns;

        //checks to see if this is the first move that the 
        //pawn can move, if os we allow the pawn to move forward two
        //squares
        possible_moves |= (pawn_positions & Rank[6]) >> 16;

        //adds the move forward one square move
        possible_moves |= pawn_positions >> 8;
        //checks to see if there are any collisions for moving fowards
        possible_moves &= board.EmptyBoard;
        
        //checks to see if we can attack on that side 
        possible_moves |= pawn_positions >> 7 & board.WhitePieces;
        possible_moves |= pawn_positions >> 9 & board.WhitePieces;

        return possible_moves;

    }

uint64_t get_queen_attacks(const ChessBoard &board, const uint_fast8_t &side, const uint64_t &position){
    uint64_t queen_attack = get_bishops_attacks(board, side, position) |
                            get_rook_attacks(board, side, position);
    return queen_attack;
}

/**
 * @brief Get the knights attacks object
 * this will return all valid moves of a knight
 * 
 * @param board : the current state of the board
 * @param side : the : 1 for white, 0 for black
 * @param position : the position of the piece in question
 * @return uint64_t 
 */
uint64_t get_knights_attacks(const ChessBoard &board, const uint_fast8_t &side, const uint64_t &position){


    uint64_t possible_moves = 0x0;
    if (position << 17 & ~File[0])
        possible_moves |= position << 17;
    if (position << 15 & ~File[6])
        possible_moves |= position << 15;
    if (position << 6 & ~(File[6] | File[5]))
        possible_moves |= position << 6;
    if(position << 10 & ~(File[0] | File[1]))
        possible_moves |= position << 10;

    if(position >> 17 & ~File[6])
        possible_moves |= position >> 17;
    if (position << 15 & ~File[0])
        possible_moves |= position >> 15;
    if (position << 6 & ~(File[0] | File[1]))
        possible_moves |= position >> 6;
    if(position << 10 & ~(File[5] | File[6]))
        possible_moves |= position >> 10;
    
    return side ? possible_moves & board.WhitePieces ^ possible_moves:
                  possible_moves & board.BlackPieces ^ possible_moves;
}
/**
 * @brief Get the king attacks object
 * TODO: Need to add checkmate checking
 * 
 * @param board 
 * @param side 
 * @return uint64_t 
 */
uint64_t get_king_attacks(const ChessBoard &board, const uint_fast8_t &side){
    uint64_t king_moves = 0x0;
    if (side){
        uint64_t position = board.WhiteKing;
        if (position << 1 & ~File[0])
            king_moves |= position << 1;
        if (position >> 1 & ~File[6])
            king_moves |= position >> 1;


        if (position << 7 & ~File[6])
            king_moves |= position << 7;
            if (position >> 7 & ~File[0])
            king_moves |= position >> 7;

        //move forward and move backwards
        if (position << 8)
            king_moves |= position << 8;
        if (position >> 8)
            king_moves |= position >> 8;

        if (position << 9 & ~File[0])
            king_moves |= position << 9;
        if (position << 9 & ~File[6])
            king_moves |= position >> 9;
        return king_moves;
    }
    uint64_t position = board.BlackKing;
        if (position << 1 & ~File[0])
            king_moves |= position << 1;
        if (position >> 1 & ~File[6])
            king_moves |= position >> 1;


        if (position << 7 & ~File[6])
            king_moves |= position << 7;
            if (position >> 7 & ~File[0])
            king_moves |= position >> 7;

        //move forward and move backwards
        if (position << 8)
            king_moves |= position << 8;
        if (position >> 8)
            king_moves |= position >> 8;

        if (position << 9 & ~File[0])
            king_moves |= position << 9;
        if (position << 9 & ~File[6])
            king_moves |= position >> 9;
        return king_moves;
}




int main(){
    struct ChessBoard board;

    printBoard(board);
    uint64_t LSB = pop_LSB(board.WhiteKnights);
    uint64_t knight_attacks = get_knights_attacks(board, 1, LSB);
    uint64_t other_knight_attacks = get_knights_attacks(board, 1, LSB ^ board.WhiteKnights);
    uint64_t pawn_moves = get_pawn_attacks(board, 1);
    printf("%llx \n", knight_attacks);
    printf("%llx \n", other_knight_attacks);
    printf("%llx \n", pawn_moves);
    return 0;

}