#include "geesespotter_lib.h"

char *createBoard (std::size_t xdim, std::size_t ydim){
	char *board{new char [xdim*ydim]{}};
	for (std::size_t k{0}; k < (xdim*ydim); ++k){
		board[k] = 0;
	}
	return board;
}

void computeNeighbors (char *board, std::size_t xdim, std::size_t ydim){
	for (int r{0}; r < ydim; ++r){
		for (int c{0}; c < xdim; ++c){
			if ((board[r*xdim+c]&valueMask()) == 9){
				for (int com_y{r-1}; com_y <= (r+1); ++com_y){
					for (int com_x{c-1}; com_x <= (c+1); ++com_x){
						// check if still on the board
						if (com_x < xdim && com_y < ydim && com_x >= 0 && com_y >= 0){
							if ((board[com_y*xdim + com_x]&valueMask()) != 9){
								board[com_y*xdim + com_x] += 1;

							}
						}
					}
				}
			}
		}
	}
	for (std::size_t i{0}; i < (xdim*ydim); ++i){
		if ((board[i]&valueMask()) > 9){
			board[i] = 9;
		}
	}
} //end of function

void hideBoard (char *board, std::size_t xdim, std::size_t ydim){
	for (std::size_t r{0}; r < (xdim*ydim); r++){
		board[r] = board[r] | hiddenBit();
	}
}

void cleanBoard (char *board){
	delete []board;
	board = nullptr;
}

void printBoard (char *board, std::size_t xdim, std::size_t ydim){
	int index{0};
	for (std::size_t r{0}; r < ydim; r++){
		for (std::size_t c{0}; c < xdim; c++){
			if ((board[index] & markedBit()) == markedBit()) {
				std::cout << 'M';
			} else if ((board[index] & hiddenBit()) == hiddenBit()) {
				std::cout << '*';
			} else {
				std::cout << (int)board[index];
			}
			++index;
		}
		std::cout<< std::endl;
	}
}

int reveal (char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	int x = (int) xloc;
	int y = (int) yloc;
	if ((board[yloc*xdim + xloc]&markedBit()) == markedBit()) {
		return 1;
	} else if ((board[yloc*xdim + xloc]&hiddenBit()) != hiddenBit()){
		return 2;
	} else if ((board[yloc*xdim + xloc]&valueMask()) == 9) {
		board[yloc*xdim + xloc] = board[yloc*xdim + xloc]&valueMask();
		return 9;
	} else {
		if ((board[yloc*xdim + xloc]&valueMask()) != 0) {
			board[yloc*xdim + xloc] = board[yloc*xdim + xloc]&valueMask();
			return 0;
		} else {
			for (int reveal_y{y-1}; reveal_y <= (y+1); ++reveal_y){
				for (int reveal_x{x-1}; reveal_x <= (x+1); ++reveal_x){
					// check if still on the board
					if (reveal_x < xdim && reveal_y < ydim && reveal_x >= 0 && reveal_y >= 0){
						if ((board[reveal_y*xdim + reveal_x] & markedBit()) == 0){
							//form the statement to reveal the space
							board[reveal_y*xdim + reveal_x] = board[reveal_y*xdim + reveal_x] & valueMask();
						}
					}
				}
			}
			return 0;
		}
	}
}

int mark (char *board, std::size_t xdim, std::size_t ydim, std::size_t xloc, std::size_t yloc){
	if ((board[yloc*xdim + xloc] & hiddenBit()) == hiddenBit()) {
		if ((board[yloc*xdim + xloc] & markedBit()) == markedBit()) {
			board[yloc*xdim + xloc] = (board[yloc*xdim + xloc]&valueMask()) | hiddenBit();
		} else {
			board[yloc*xdim + xloc] = (board[yloc*xdim + xloc] | markedBit());
		}
		return 0;
	} else {
		return 2;
	}
}

bool isGameWon (char *board, std::size_t xdim, std::size_t ydim){
	for (std::size_t k{0}; k < (xdim*ydim); ++k){
		if (board[k] == 9){
			return false;
		}
		if (((board[k]&markedBit()) == markedBit()) || ((board[k]&hiddenBit()) == hiddenBit())){
			if ((board[k]&valueMask()) != 9){
				return false;
			}
		}
	}
	return true;
}





