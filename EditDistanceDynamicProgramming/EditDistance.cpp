//  Name: Matthew Jensen
//  Assignment Number: 7
//  Assignment: Edit Distance Dynamic Programming
//  File name: EditDistance.cpp
//  Date last modified: November 21, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment.

#include <iostream>
#include <vector>  // std::vector
#include <iomanip> // std::setw

// prings a formatted table of edit distances
void print(std::vector<std::vector<int>> &matrix)
{
    // iterate through the matrix and print each row
    for (int i = 0; i < matrix.size(); i++)
    {
        // iterate through the row and print each element
        for (int j = 0; j < matrix[i].size(); j++)
        {
            // print the number with proper alignment
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

// calculates the edit distance between two strings as well as their edit operations
void editInstructions(std::string s1, std::string s2)
{
    // Create a vector of vectors of ints to store the edit distance between the two strings
    std::vector<std::vector<int>> editDistanceMatrix(s1.length() + 1, std::vector<int>(s2.length() + 1));

    // Initialize the first row and column of the matrix to 0
    for (int i = 0; i <= s1.length(); i++)
    {
        editDistanceMatrix[i][0] = i;
    }
    for (int j = 0; j <= s2.length(); j++)
    {
        editDistanceMatrix[0][j] = j;
    }

    // Calculate the edit distance between the two strings
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            // If the characters are the same, the edit distance is the edit distance of the previous row and column
            if (s1[i - 1] == s2[j - 1])
            {
                editDistanceMatrix[i][j] = editDistanceMatrix[i - 1][j - 1];
            }
            // If the characters are different, the edit distance is the minimum of the edit distance of the previous row and column, plus 1
            else
            {
                editDistanceMatrix[i][j] = 1 + std::min(editDistanceMatrix[i - 1][j], std::min(editDistanceMatrix[i][j - 1], editDistanceMatrix[i - 1][j - 1]));
            }
        }
    }

    std::cout << editDistanceMatrix[s1.length()][s2.length()] << ":   ";

    // get the edit instructions
    int i = s1.length();
    int j = s2.length();

    std::string backwardsInstructions = "";

    while (i > 0 || j > 0)
    {

        // find the minimum of the three edit distances
        int min = std::min(editDistanceMatrix[i][j - 1], std::min(editDistanceMatrix[i - 1][j], editDistanceMatrix[i - 1][j - 1]));
        if (min == editDistanceMatrix[i - 1][j - 1])
        {
            if (s1[i - 1] == s2[j - 1])
            {
                backwardsInstructions.append("^"); // keep the character the same
                i--;
                j--;
            }
            else
            {
                backwardsInstructions.append(s2, j - 1, 1);
                backwardsInstructions.append("/"); //replace with
                i--;
                j--;
            }
        }
        else if (min == editDistanceMatrix[i][j - 1])
        {
            backwardsInstructions.append(s2, j - 1, 1);
            backwardsInstructions.append("+");
            j--;
        }
        else// (min == editDistanceMatrix[i - 1][j])
        {
            backwardsInstructions.append("-"); // detlete
            i--;
        }
    }

    // print the edit instructions
    reverse(backwardsInstructions.begin(), backwardsInstructions.end());
    std::cout << backwardsInstructions << "\n";
    //print(editDistanceMatrix);
}

// loops for user input
void input_loop()
{
    // Loop to allow the user to input strings
    while (true)
    {
        // Get the first string
        std::string s1;
        std::cout << "Enter the first string: ";
        //std::cin.ignore();
        getline(std::cin, s1);

        // Get the second string
        std::string s2;
        std::cout << "Enter the second string: ";
        //std::cin.ignore();
        getline(std::cin, s2);

        // Calculate the edit distance between the two strings
        editInstructions(s1, s2);
    }
}

int main()
{
    input_loop();
    return 0;
}
