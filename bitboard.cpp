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

void generate_rook_moves(const int &side, const ChessBoard &board){
    uint64_t rook_one;
    uint64_t rook_two;
    uint64_t possible_moves;
    //if white
    if (side){
        rook_one = pop_LSB(board.WhiteRooks);
        rook_two = rook_one ^ board.WhiteRooks;
        
    }
    

}