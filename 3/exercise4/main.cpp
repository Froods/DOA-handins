#include <iostream>

#define ROWS 5
#define COLS 5

bool recursiveMaze(char maze[ROWS][COLS], int row = 1, int col = 1) {
	if (row == ROWS || col == COLS) return false; // Hvis du har bevæget dig uden fra labyrinten, returner false
    if (maze[row][col] == 'E') return true;       // Returner true hvis du står på udgangen
	bool rtn = false;                             // Initialiser standatd returværdi som false

    
    if (maze[row][col] == 'V') return false;      // Hvis vi har tjekket denne plads, returner false (og dermed undgå evigt loop)
    maze[row][col] = 'V';    					  // Bekræft at pladsen nu er besøgt                  

    //Hvis en af pladserne som ligger rundt omkring den nuværende position er tom eller indeholder 'E', kalder vi recursive funktionskald
	if ((maze[row][col+1] == ' ' || maze[row][col+1] == 'E') && !rtn) rtn = recursiveMaze(maze, row, col+1);
	if ((maze[row+1][col] == ' ' || maze[row+1][col] == 'E') && !rtn) rtn = recursiveMaze(maze, row+1, col);
	if ((maze[row][col-1] == ' ' || maze[row][col-1] == 'E') && !rtn) rtn = recursiveMaze(maze, row, col-1);
	if ((maze[row-1][col] == ' ' || maze[row-1][col] == 'E') && !rtn) rtn = recursiveMaze(maze, row-1, col);

    //Returnerer vores recursive kald af funktionen med opdateret parameter (pladsændring i maze)
	return rtn;
}

int main() {    

    //Eksempel maze fra opgaven: Bør returnere true
    char mazeTrue[ROWS][COLS] = {
    {'X', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X'},
    {'X', 'E', 'X', 'X', 'X'}
    };

    //Nyt eksempel: Denne gang bør den returnere false
    char mazeFalse[ROWS][COLS] = {
    {'X', 'X', 'X', 'X', 'X'},
    {'X', ' ', ' ', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X'},
    {'X', 'X', 'X', ' ', 'X'},
    {'X', 'E', 'X', 'X', 'X'}
    };

    //Udskriver resultater
    std::cout << "Expected true at the solvable maze: " << recursiveMaze(mazeTrue) << "\n";
    std::cout << "Expected false at the unsolvable maze: " << recursiveMaze(mazeFalse) << "\n";

    return 0;

}