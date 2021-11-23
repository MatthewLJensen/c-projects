//  Name: Matthew Jensen
//  Assignment Number: 7
//  Assignment: Edit Distance Dynamic Programming
//  File name: EditDistance.cpp
//  Date last modified: November 21, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include <iostream>
#include <vector>    // std::vector

// Function: editDistance
// Description: Calculates the edit distance between two strings, using dynamic programming. A character can be removed, inserted, or replaced.
// Parameters:
//      string s1: The first string
//      string s2: The second string
// Return: The edit distance between the two strings
int editDistance(std::string s1, std::string s2)
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

    // Return the edit distance between the two strings
    return editDistanceMatrix[s1.length()][s2.length()];
}

// Function: edit instructions
// Description: interprets the edit distance between two strings and prints out the instructions to get from one string to the other
// Parameters:
//      string s1: The first string
//      string s2: The second string
// Return: void
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

    // Print out the instructions to get from one string to the other
    std::cout << "The edit distance between " << s1 << " and " << s2 << " is " << editDistanceMatrix[s1.length()][s2.length()] << ".\n";
    std::cout << "The instructions to get from " << s1 << " to " << s2 << " are: ";
    int i = s1.length();
    int j = s2.length();
    while (i > 0 || j > 0)
    {
        // If the characters are the same, the edit distance is the edit distance of the previous row and column
        if (s1[i - 1] == s2[j - 1])
        {
            i--;
            j--;
        }
        // If the characters are different, the edit distance is the minimum of the edit distance of the previous row and column, plus 1
        else
        {
            // If the edit distance of the previous row and column is the same as the edit distance of the previous row and the previous column, the character was inserted
            if (editDistanceMatrix[i - 1][j] == editDistanceMatrix[i][j - 1])
            {
                std::cout << "insert ";
                j--;
            }
            // If the edit distance of the previous row and column is the same as the edit distance of the previous row and the previous column, the character was removed
            else if (editDistanceMatrix[i - 1][j] == editDistanceMatrix[i - 1][j - 1])
            {
                std::cout << "remove ";
                i--;
            }
            // If the edit distance of the previous row and column is the same as the edit distance of the previous row and the previous column, the character was replaced
            else
            {
                std::cout << "replace ";
                i--;
                j--;
            }
        }
    }
    std::cout << "with " << s2 << ".\n";
}

void test_edit_distance(){
    // Test the edit distance function
    std::cout << "Edit distance between \"Hello\" and \"Hello\" is: " << editDistance("Hello", "Hello") << std::endl;
    std::cout << "Edit distance between \"Hello\" and \"Helli\" is: " << editDistance("Hello", "Helli") << std::endl;
    std::cout << "Edit distance between \"Hello\" and \"\" is: " << editDistance("Hello", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"Hello\" is: " << editDistance("", "Hello") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
    std::cout << "Edit distance between \"\" and \"\" is: " << editDistance("", "") << std::endl;
}

void input_loop(){
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

        // Print the edit distance between the two strings
        //std::cout << "Edit distance between \"" << s1 << "\" and \"" << s2 << "\" is: " << editDistanceLength << std::endl;
    }
}

int main()
{
    input_loop();
    return 0;

}

