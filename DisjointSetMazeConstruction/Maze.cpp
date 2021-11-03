//  Name: Matthew Jensen
//  Assignment number: 5
//  Assignment: Disjoint Set Maze Construction
//  File name: Maze.cpp
//  Date last modified: November 3, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include <iostream>
#include "Maze.h"


// Creates a Maze object with the given number of rows and columns
// This is a minimal functional constructor; you will need to 
// augment the constructor initalizer list and add code to the
// body.
Maze::Maze(int rows, int columns) : rows(rows), columns(columns), rooms(std::vector<std::vector<int>>(rows, std::vector<int>(columns, ALL_WALLS))),
	                                set(rows*columns) {

}


// Returns the room information at the given row, column location, encoded
// as bit patterns specifies above (LEFT_WALL, RIGHT_WALL, etc.)
int Maze::operator()(int row, int column) const {
    return rooms[row][column];
}


// Randomly generates a maze
void Maze::build_maze() {
    std::cout << "building maze";

    // reset
    set.Split();
    for(int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            rooms[i][j] = ALL_WALLS;
        }
    }

    // remove entrance wall
    rooms[0][0] = ~LEFT_WALL;
    // remove exit wall
    rooms[rows-1][columns-1] = ~RIGHT_WALL;

    while(set.Cardinality() > 1){
        int room_col = rand()%columns;
        int room_row = rand()%rows;
        //int room = rooms[room_row][room_col];
        int adj_col = room_col;
        int adj_row = room_row;
        int room_remove = NO_WALLS;
        int adj_remove  = NO_WALLS;
        // picks a random adjacent room
        if (rand()%2){
            if (rand()%2 && (adj_row != rows - 1)){
                adj_row++; // should remove 
                room_remove = TOP_WALL;
                adj_remove  = BOTTOM_WALL;
            }else if (adj_row != 0){
                adj_row--;
                room_remove = BOTTOM_WALL;
                adj_remove  = TOP_WALL;
            }else{
                adj_row++; // should remove 
                room_remove = TOP_WALL;
                adj_remove  = BOTTOM_WALL;
            }
        }else{
            if (rand()%2 && (adj_col != columns - 1)){
                adj_col++;
                room_remove = RIGHT_WALL;
                adj_remove  = LEFT_WALL;
            }else if (adj_col != 0){
                adj_col--;
                room_remove = LEFT_WALL;
                adj_remove  = RIGHT_WALL;
            }else{
                adj_col++;
                room_remove = RIGHT_WALL;
                adj_remove =  LEFT_WALL;
            }
        }
        //int adjacent = rooms[adj_row][adj_col];

        if(set.Find(room_row*columns + room_col) != set.Find(adj_row*columns + adj_col)){
            set.Union((room_row*columns + room_col), (adj_row*columns + adj_col));
            rooms[room_row][room_col] &= ~room_remove;
            rooms[adj_row][adj_col] &= ~adj_remove;            
        }

    }
}
