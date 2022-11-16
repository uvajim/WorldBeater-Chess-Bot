TODO:

1. Finish move generation,
    a. Finish generate_bishop_masks
    b. generate blockers and be able to init the rook and bishop 
       tables
    c. testing 

2. Look into checkmates/ discovered checkmates/ valid moves


INTRO:

This project combines two passions of mine. Chess and computing.


 This implementation uses a bitboard to represent board pieces, 
 bitwise operations and bit shifts to represent movements on the 
 board. The main reason is that the performance of a bitboard is 
 unmatched and I also enjoy the experience of working in binary/
 hexadecimal and the logical operations needed to make all of the 
 movements work. 

 For move generation, we are using static checks to look at jump 
 pieces (knights, pawns, and the king), and using magic bitboards 
 to efficiently calculate the movements of sliding pieces
 (bishops, rooks, and queens). The reason being is that this is 
 the technique that world class chess engines use and so I will 
 using that technique as that is reason enough for me. 

 For search we plan to use Depth-First-Search with Alpha-Beta
 pruning to reduce the number of branches we must go down.  Various other enhancements will be made such as parallelism. Other possible improvements include integrating a Monte Carlo Search or some derivation of a Best-First search. 

