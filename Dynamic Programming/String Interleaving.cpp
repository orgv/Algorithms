#include<iostream>
#include<vector>
#include <chrono> // milliseconds
#include <thread> // sleep_for
   
using namespace std;


// A Dynamic Programming based program to check whether a string Z is
// an interleaving of two other strings X and Y.

// BOTTOM UP SOLUTION
bool isInterleaved(string& X, string& Y, string& Z)
{

    int Xlen = X.size();
    int Ylen = Y.size();
    int Zlen = Z.size();

    // Let us create a 2D table
    // to store solutions of
    // subproblems. dp[i][j] will
    // be true if Z[0..i+j-1]
    // is an interleaving of
    // X[0..i-1] and Y[0..j-1].

    // Xlen+1 rows, and Ylen+1 columns with each cell initialized to false(0)
    // Initialize all values as false.
    vector<vector<bool>> dp(Xlen + 1, vector<bool>(Ylen + 1, false));


    // the last character of Z has to be ended with either last character of X or last charcter of Y

    // Z can be an interleaving of
    // X and Y only of the sum
    // of lengths of X & Y is equal
    // to the length of Z.
    if ((Xlen + Ylen) != Zlen)
        return false;


    // From this point, (Xlen + Ylen) = Zlen !!!


    // two empty strings have an
    // empty string as interleaving
    dp[0][0] = true;



    // X[0...Xlen-1]
    // Y[0...Ylen-1]
    // Z[0...(Xlen+Ylen)-1]

    // If the last character of X, y, Z are different, it will remain false(by our initialization...)


    // Base Case: X is empty, compare Y and Z. Ylen=Zlen (Xlen=0)
    for (int i = 1; i <= Ylen; i++)
    {
        if (Y[i - 1] == Z[i - 1])
            dp[0][i] = dp[0][i - 1];
    }

    // Base Case: Y is empty, compare X and Z. Xlen=Zlen (Ylen=0)
    for (int i = 1; i <= Xlen; i++)
    {
        if (X[i - 1] == Z[i - 1])
            dp[i][0] = dp[i - 1][0];
    }


    for (int i = 1; i <= Xlen; i++)
    {
        for (int j = 1; j <= Ylen; j++)
        {
            if (Z[i + j - 1] == X[i - 1] && Z[i + j - 1] != Y[j - 1])
                dp[i][j] = dp[i - 1][j];

            else if (Z[i + j - 1] == Y[j - 1] && Z[i + j - 1] != X[i - 1])
                dp[i][j] = dp[i][j - 1];

            else if (Z[i + j - 1] == X[i - 1] && Z[i + j - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }


    // dp[i][j] will be true if Z[0..i+j-1]  is an interleaving of X[0..i-1] and Y[0..j-1].
    // So, our original problem is of course consisted of X[0..(Xlen-1)] and Y[0..(Ylen-1)]

    // then, we have to obtain the value of dp[Xlen][Ylen] // whole X[0..(Xlen-1)], whole Y[0..(Ylen-1)]

    // After we have obtained it, our solution is of course located at the cell dp[Xlen][Ylen]
    // So, we return it and DONE!

    return dp[Xlen][Ylen];
}


void test(string X, string Y,string Z)
{
    if (isInterleaved(X, Y, Z))
        cout << Z << " is interleaved of " << X << " and " << Y << endl<<flush;
    else
        cout << Z << " is not interleaved of " << X << " and " << Y << endl<<flush;
}


int main()
{

    //test("", "ABC", "ABC");
    //test("", "BA", "BA");
    //cout << "\n";

    string x, y, z;

    while (1)
    {
        cout << "X = "<<flush;
        cin >> x;

        cout << "\nY = "<<flush;
        cin >> y;

        cout << "\nZ = "<<flush;
        cin >> z;

        test(x, y, z);
        cout << "\nClearing...";
        std::this_thread::sleep_for(std::chrono::milliseconds(1300));
        system("cls");
    }
    return 0;
}