#include "bitboard.h"

void printBoard(ChessBoard chess_board){

    char board[64];
    memset(board,'-', 64);
    //these will be used to classify the pawns
    int pos = 0x0;
    while (chess_board.WhitePawns){
        if (chess_board.WhitePawns & 1)
            board[pos] = 'P';
        chess_board.WhitePawns = chess_board.WhitePawns >> 1;
        ++pos;
    }
    pos = 0x0;
    while (chess_board.BlackPawns){
        if (chess_board.BlackPawns & 1)
            board[pos] = 'P';
        chess_board.BlackPawns = chess_board.BlackPawns >> 1;
        ++pos;
    }


    //printing the rooks
    pos = 0x0;
    while (chess_board.WhiteRooks){
        if (chess_board.WhiteRooks & 1)
            board[pos] = 'R';
        chess_board.WhiteRooks = chess_board.WhiteRooks >> 1;
        ++pos;
    }
    pos = 0x0;
    while (chess_board.BlackRooks){
        if (chess_board.BlackRooks & 1)
            board[pos] = 'R';
        chess_board.BlackRooks = chess_board.BlackRooks >> 1;
        ++pos;
    }
    //printing the knights
    pos = 0x0;
    while (chess_board.WhiteKnights){
        if (chess_board.WhiteKnights & 1)
            board[pos] = 'N';
        chess_board.WhiteKnights = chess_board.WhiteKnights >> 1;
        ++pos;
    }
    pos = 0x0;
    while (chess_board.BlackKnights){
        if (chess_board.BlackKnights & 1)
            board[pos] = 'N';
        chess_board.BlackKnights = chess_board.BlackKnights >> 1;
        ++pos;
    }
    //printing the bishops
    pos = 0x0;
    while (chess_board.WhiteBishops){
        if (chess_board.WhiteBishops & 1)
            board[pos] = 'B';
        chess_board.WhiteBishops = chess_board.WhiteBishops >> 1;
        ++pos;
    }
    pos = 0x0;
    while (chess_board.BlackBishops){
        if (chess_board.BlackBishops & 1)
            board[pos] = 'B';
        chess_board.BlackBishops = chess_board.BlackBishops >> 1;
        ++pos;
    }

    //printing the bishops
    pos = 0x0; 
    while (chess_board.WhiteBishops){
        if (chess_board.WhiteBishops & 1)
            board[pos] = 'B';
        chess_board.WhiteBishops = chess_board.WhiteBishops >> 1;
        ++pos;
        
    }
    pos = 0x0;
    while (chess_board.BlackBishops){
        if (chess_board.BlackBishops & 1)
            board[pos] = 'B';
        chess_board.BlackBishops = chess_board.BlackBishops >> 1;
        ++pos;
    }

    //printing the queens
    pos = 0x0;
    while (chess_board.WhiteQueen){
        if (chess_board.WhiteQueen & 1)
            board[pos] = 'Q';
        chess_board.WhiteQueen = chess_board.WhiteQueen >> 1;
        ++pos;
    }
    pos = 0x0;
    while (chess_board.BlackQueen){
        if (chess_board.BlackQueen & 1)
            board[pos] = 'Q';
        chess_board.BlackQueen = chess_board.BlackQueen>> 1;
        ++pos;
    }

    //printing the kings
    pos = 0x0;
    while (chess_board.WhiteKing){
        if (chess_board.WhiteKing & 1)
            board[pos] = 'K';
        chess_board.WhiteKing = chess_board.WhiteKing >> 1;
        ++pos;
    }
    pos = 0x0;
    while (chess_board.BlackKing){
        if (chess_board.BlackKing& 1)
            board[pos] = 'K';
        chess_board.BlackKing = chess_board.BlackKing>> 1;
        ++pos;
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

uint64_t get_bishops_attacks(const ChessBoard &board, const uint64_t &position){
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

uint64_t get_pawn_attacks(const ChessBoard &board, const uint_fast8_t &side, const uint64_t &pos){
    uint64_t possible_moves = 0x0;
    uint64_t pawn_positions = 0x0;

    if (side){
        
        //checks to see if this is the first move that the 
        //pawn can move, if os we allow the pawn to move forward two
        //squares
        if (pos & Rank[1]){
            
            possible_moves |= pawn_positions << 16;
        }
        possible_moves |= pawn_positions << 8;

        //checks to see that there are no collisions
        possible_moves &= board.EmptyBoard;
        
        //checks to see if we can attack a piece as a pawn
        possible_moves |= pawn_positions << 7 & board.BlackPieces;
        possible_moves |= pawn_positions << 9 & board.BlackPieces;

        return possible_moves;
    }
        //checks to see if this is the first move that the 
        //pawn can move, if os we allow the pawn to move forward two
        //squares
        if (pos & Rank[6]){
            
            possible_moves |= pawn_positions << 16;
        }

        possible_moves |= pawn_positions << 8;

        //checks to see that there are no collisions
        possible_moves &= board.EmptyBoard;
        
        //checks to see if we can attack a piece as a pawn
        possible_moves |= pawn_positions << 7 & board.BlackPieces;
        possible_moves |= pawn_positions << 9 & board.BlackPieces;

        return possible_moves;
    }

uint64_t get_queen_attacks(const ChessBoard &board, const uint64_t &position){
    uint64_t queen_attack = get_bishops_attacks(board, position) |
                            get_rook_attacks(board, position);
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
uint64_t get_knights_attacks(const ChessBoard &board, const uint64_t &position){
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
    
    return possible_moves;
}
/**
 * @brief Get the king attacks object
 * TODO: Need to add checkmate checking
 * 
 * @param board 
 * @param side 
 * @return uint64_t 
 */
uint64_t get_king_attacks(const ChessBoard &board, const uint64_t &position){
    uint64_t king_moves = 0x0;

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

void generate_ne_rays(const uint64_t &pos){
    uint64_t ray = 0x0;
    uint64_t curr_step = pos << 9;
    while (curr_step & ~File[7] & ~Rank[7]){
        ray |= curr_step;
        curr_step << 9;
    }
    ne_rays[pos] = ray;
}

void generate_nw_rays(const uint64_t &pos){
    uint64_t ray =0x0;
    uint64_t curr_step = pos << 7;
    while (curr_step & ~File[0] & ~Rank[7]){
        ray |= curr_step;
        curr_step << 7;
    }
    nw_rays[pos] = ray;
}

void generate_se_rays(const uint64_t &pos){
    uint64_t ray = 0x0;
    uint64_t curr_step = pos >> 9;
    while (curr_step & ~File[7] & ~Rank[0]){
        ray |= curr_step;
        curr_step >> 9;
    }
    se_rays[pos] = ray;
}

void generate_sw_rays(const uint64_t &pos){
    uint64_t ray =0x0;
    uint64_t curr_step = pos >> 7;
    while (curr_step & ~File[0] & ~Rank[0]){
        ray |= curr_step;
        curr_step >> 7;
    }
    sw_rays[pos] = ray;
}

void generate_bishops_masks(){
    uint64_t curr_pos = 0x0;
    while (curr_pos < 64){
    //get ne
    generate_ne_rays(curr_pos);
    //get nw
    generate_nw_rays(curr_pos);
    //get sw
    generate_sw_rays(curr_pos);
    //get se
    generate_sw_rays(curr_pos);

    composite_rays[curr_pos] = ne_rays[curr_pos] |
                               nw_rays[curr_pos] |
                               sw_rays[curr_pos] |
                               se_rays[curr_pos];
    }
}

int main(){
    struct ChessBoard board;

    printBoard(board);
    
    return 0;

}