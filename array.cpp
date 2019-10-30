//
//  main.cpp
//
//  Created by Megan Cho on 5/8/19.
//  Copyright © 2019 Yuna Cho. All rights reserved.
//

#include <string>
#include <iostream>
#include <cassert>
using namespace std;

//return number of strings in the array that are equal to target
int countMatches (const string a[], int n, string target)
{
    if (n < 0)
        return -1; //if n is negative, function returns -1
    int total = 0; //total number of target strings
    for (int i = 0; i != n; i++) //read through each string
    {
        if (a[i] == target)
            total += 1; //add to total for every target string
    }
    return total;
}

//return position of a string in the array that is equal to target
int detectMatch (const string a[], int n, string target)
{
    if (n < 0)
        return -1; //if n is negative, function returns -1
    for (int i = 0; i != n; i++)
    {
        if (a[i] == target)
            return i; //return position of first position matching target string
    }
    return -1; //the string does not exist
}

//find earliest occurence in a of consecutive strings that are equal to target, set begin to first occurrence and end to the last occurence
bool detectSequence (const string a[], int n, string target, int& begin, int& end)
{
    if (n < 0)
        return -1;
    int counter = 0; //counter from begin to calculate end position
    for (int i = 0; i < n; i++)
    {
        if (a[i] == target) //locate first string equal to target
        {
            begin = i; //set begin as the first string detected
            for (int k = i+1; k < n; k++) //check consecutive strings
            {
                if (a[k] == target) //if next string is also equal to target
                {
                    counter++; //increment counter to calculate end
                }
                else //if next string is not equal to target
                {
                    end = begin + counter; //calculate end position
                    return true;
                }
            }
        }
    }
    return false; //if no string equal to target
}

//return position of a string that is <= every string in the array
int detectMin (const string a[], int n)
{
    if (n <= 0)
        return -1; //if n is negative or no elements are examined, function returns -1
    string min = a[0]; //initialize to know what the smallest string is
    int minPos = 0; //initialize to know where the smallest string is
    
    for (int i = 0; i != n; i++)
    {
        if (min <= a[i]) //if smallest string is <= than current string, no changes
            continue;
        else //if smallest string isn't <= than current string, update string and position
        {
            min = a[i];
            minPos = i;
        }
    }
    return minPos;
}

//eliminate item at pos and copy elements after it one place to the left and place eliminated item into the last position, return original position of item
int moveToBack(string a[], int n, int pos)
{
    if (n < 0 || pos < 0 || pos >= n)
        return -1; //if n is negative or no elements are examined, function returns -1
    string newPos = a[pos]; //stores element at pos into new variable
    for (int i = pos; i < n-1; i++) //n-1 so a[i+1] doesn't evaluate out of bound
    {
        a[i] = a[i+1]; //set elements to position on the left
    }
    a[n-1] = newPos; //store last element in new position
    return pos; //return old position of element
}

//eliminate item at pos and copy elements after it one place to the right and place eliminated item into the first position, return original position of iem
int moveToFront (string a[], int n, int pos)
{
    if (n < 0 || pos < 0 || pos >= n)
        return -1; //if n is negative or no elements are examined, function returns -1
    string newPos = a[pos]; //stores element at into new variable
    for (int i = pos; i > 0; i--) //n+1 so a[i-1] doesn't evaluate out of bound
    {
        a[i] = a[i-1]; //set elements to position on right
    }
    a[0] = newPos; //set element to the beginning of the array
    return pos; //return old position of element
}

//return position of first corresponding elements of a1 and a1 that are not equal
int detectDifference( const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0)
        return -1;
    
    int differPos = 0; //initialize new variable to find smaller array
    if (n1 <= n2)
        differPos = n1; //use n1 if it runs out before n2
    else
        differPos = n2; //use n2 if it runs out before n1
    for (int i = 0; i < differPos; i++) //find first position that is unequal by looping at the end of the smaller array
    {
        if (a1[i] != a2[i]) //return unequal position
            return i;
        if (a1[i] == a2[i]) //reiterate loop until elements are not equal
            continue;
    }
    return differPos; //return value of n1 or n2 that is <= to the other
}

//retain one item of consecutive identical strings and return number of retained items
int deleteDups(string a[], int n)
{
    if (n < 0)
        return -1; //if n is negative, function returns -1
    int removed = 0; //count extra duplicates to subtract from total number of elements
    for (int i = 0; i < n-1; i++) //(n-1) so array doesn't go out of bounds
    {
        if (a[i] == a[i+1]) //check for duplicate
            removed++; //increment duplicate count
    }
    for (int i = 0; i < n-1; i++) //reevaluate entire array after duplicates are counted for
    {
        if (a[i] == a[i+1]) //check for duplicate
        {
            moveToBack(a, n, i); //move elements to the left after duplicates are removed
            i--; //evaluate previous element
        }
    }
    return (n - removed); //retained items = total items - removed items
}

//check if all n2 elements of a2 appear in a1
bool contains(const string a1[], int n1, const string a2[], int n2)
{
    if (n1 < 0 || n2 < 0) //if n1 or n2 are negative, return -1
        return -1;
    if (n2 == 0) //if n2 has no elements, there are no elements to be evaluated
        return true;
    int position = 0; //used to compare elements of a1 with a2
    for (int i = 0; i < n1; i++)
    {
        if (a1[i] == a2[position] && position < (n2-1))
        { //when there is more to read in an array
            position++; //continue to next element of a2
        }
        else if (a1[i] == a2[position] && position == (n2-1))
        { //when you reach the end of an array
            return true;
        }
    }
    return false; //function is passed bad arguments
}

//merge nondecreasing a1 and a2 into result string to sort them in ascending order and return number of rearranged elements
int meld(const string a1[], int n1, const string a2[], int n2, string result[], int max)
{
    if (n1 < 0 || n2 < 0 || max < 0) //if input values are negative, return -1
        return -1;
    for (int i = 1; i < n1; i++) //evaluate if n1 elements are nondecreasing
    {
        if (a1[i] < a1[i-1])
            return -1; //return -1 if a1 is not in nondecreasing order
    }
    for (int i = 1; i < n2; i++) //evaluate if n2 elements are nondecreasing
    {
        if (a2[i] < a2[i-1])
            return -1; //return -1 if a2 is not in nondecreasing order
    }
    int total = n1+n2; //initialize total number of elements so we can store original n1 and n2
    if ((n1 + n2) > max) //if result would have more than max elements
    {
        return -1;
    }
    else //if result would have <= max elements
    {
        //evaluate two arrays until one of them reaches boundary
        for (int i = 0; i < n1; i++)
        {
            result[i] = a1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            result[n1+i] = a2[i]; //combine a2 elements with a1 elements
        }
    }
    for (int i = 0; i < total; i++) //reassign positions to the result string
    { //use calculated result to rearrange elements so strings are <= the following string(s)
        moveToBack(result, total, (detectMin(result, total-i)));
    }
    return (n1+n2);
}

//rearrange elements so elements that are <splitter come before all others, and >splitter come after all others, return position of first element after rearrangement
int split (string a[], int n, string splitter)
{
    if (n > 0)
    {
        int smaller = 0; //counts elements that are less than splitter
        for (int i = 0; i < n; i++)
        {
            if (a[i] < splitter)
                smaller++; //increment smaller counter if elements are less than splitter
        }
        for (int j = 0; j < n; j++)
        {
            if (a[j] > splitter) //evaluates elements that are greater than splitter
            {
                string newPos; //if element is greater than splitter move to right of splitter position
                for (int k = smaller; k < n; k++)
                {
                    if (a[k] < splitter) //reassign positions
                    {
                        string newPos = a[k];
                        a[k] = a[j];
                        a[j] = newPos;
                    }
                }
            }
            if(a[j] < splitter) //evaluates elements that are smaller than splitter
            {
                string newPos; // if element is less than splitter move to the left of splitter
                for (int x = smaller; x < n; x++)
                {
                    if (a[x] > splitter) //reassign positions
                    {
                        string newPos = a[x];
                        a[x] = a[j];
                        a[x] = newPos;
                    }
                }
            }
        }
        return smaller; // return position of the first element that is not less than splitter
    }
    else
        return -1; //if n is negative, return -1
    
}

int main()
{
    string h[5] = { "hi", "hello", "bye", "hi", "hi" };
    assert(countMatches(h, 5, "hi") == 3);
    assert(countMatches(h, 4, "hi") == 2);
    assert(countMatches(h, 5, "hey") == 0);
    assert(countMatches(h, 5, "hI") == 0);
    assert(countMatches(h, -2, "hi") == -1);
    
    assert(detectMatch(h, 5, "hello") == 1);
    assert(detectMatch(h, 5, "hi") == 0);
    assert(detectMatch(h, -1, "hi") == -1);
    assert(!(detectMatch(h, 5, "hi") == 3));
    
    int bg;
    int en;
    assert(detectSequence(h, 5, "hi", bg, en) && bg == 0 && en == 0);
    assert(detectSequence(h, 5, "bye", bg, en) && bg == 2 && en == 2);
    
    string g[6] = { "hi", "hello", "bye", "hi", "bye", "bye" };
    string r[3] = { "hello", "bye", "hi" };
    assert(detectMin(g, 6) == 2);
    assert(detectMin(g, 0) == -1);
    assert(!(detectMin(g, 6) == 4));
    
    string w[4] = { "abcd", "abc", "ab", "a" };
    assert(detectMin(w, 4) == 3);
    string q[5] = { "abc", "a", "b", "a", "a" };
    assert(detectMin(q, 5) == 1);
     
    assert(contains(h, 5, r, 3));
    assert(contains(h, 0, r, 0));
    assert((contains(h, 5, r, 0)));
    
    assert(moveToBack(g, 6, 1) == 1 && g[1] == "bye" && g[5] == "hello");
    assert(moveToBack(g, 6, 2) == 2 && g[2] == "bye" && g[5] == "hi");
    assert(moveToBack(g, -2, 2) == -1);
    
    string f[4] = { "hi", "hello", "bye", "hi" };
    assert(moveToFront(f, 4, 2) == 2 && f[0] == "bye" && f[2] == "hello");
    assert(moveToFront(f, -2, 2) == -1);
    
    string c[4] = { "hi", "bye", "hi", "hi" };
    string d[5] = { "hi", "bye", "hi", "bye", "hi" };
    string j[5] = { "hi", "bye", "hi", "hi", "hi" };
    assert(detectDifference(c, 4, d, 5) == 3);
    assert(detectDifference(c, 4, j, 5) == 4);
    assert(detectDifference(c, 0, j, 0) == 0);
    
    string m[4] = { "hi", "bye", "hi", "hi" };
    string o[5] = { "hi", "bye", "hi", "bye", "hi" };
    assert(deleteDups(m, 4) == 3 && m[2] == "hi");
    assert(deleteDups(o, 5) == 5 && o[0] == "hi");
    
    string x[4] = { "rhodes", "rhodes", "tchalla", "thor" };
    string y[4] = { "banner", "danvers", "rhodes", "rogers" };
    string z[8];
    assert(meld(x, 4, y, 4, z, 8) == 8 && z[5] == "rogers");
    string u[4] = { "rhodes", "tchalla", "rhodes", "thor" };
    assert(meld(u, 4, y, 4, z, 8) == -1);
    
    assert(split(y, 4, "danvers") == 2);
    assert(split(x, 4, "thor") == 4);
    assert(split(x, 4, "rhodes") == 2);
    assert(split(f, 4, "hello") == 2);
    
    cout << "12 All tests succeeded" << endl;
}
