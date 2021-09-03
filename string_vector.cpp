#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>
#include <string>

using namespace std;

// Print the contents of vector
template < typename T >
void print ( T & vecOfElements, string delimeter = ", " )
  {
  for ( auto elem : vecOfElements )
    { cout << elem << delimeter; }
  cout << endl;
  }

/*
 * Generic function to find duplicates elements in vector.
 * It adds the duplicate elements and their duplication count in given map countMap
 */
template < typename T >
void findDuplicates ( vector < T > & vecOfElements, map < T, int > & countMap )
  {
  // Iterate over the vector and store the frequency of each element in map
  for ( auto & elem : vecOfElements )
    {
    auto result = countMap.insert (pair < string, int > ( elem, 1 ) );
    if ( result.second == false )
      { result.first -> second ++; }
    }
  // Remove the elements from Map which has 1 frequency count
  for ( auto it = countMap.begin (  ); it != countMap.end (  ); )
    {
    if ( it -> second == 1 )
      { it = countMap.erase ( it ); }
    else
      { it ++; }
    }
  }

int main (  )
  {
  // Vector of strings
  vector < string > vecOfStings
    { "at" , "hello", "hi", "there", "where", "now", "is",
      "that" , "hi" , "where", "at", "no", "yes", "at"
    };
  cout << "Loaded Vector: "; print ( vecOfStings );
  // Create a map to store the frequency of each element in vector
  map < string, int > countMap;
  // Iterate over the vector and store the frequency of each element in map
  for ( auto & elem : vecOfStings )
    {
    auto result = countMap.insert ( pair < string, int > ( elem, 1 ) );
    if ( result.second == false )
      { result.first -> second ++; }
    }

/* Debug Start

  cout << "Duplicate elements and their duplication counts:" << endl;
  // Iterate over the map
  for ( auto & elem : countMap )
    {
    // If frequency count is greater than 1 then its a duplicate element
    if ( elem.second > 1 )
      { cout << elem.first << " :: " << elem.second << endl; }
    }

Drbug Ends Here

  /*
  * Finding duplicates in vector using generic function
  */

  map < string, int > duplicateElements;
  // Get the duplicate elements in vector
  findDuplicates ( vecOfStings, duplicateElements );
  cout << "\nDuplicate elements and their duplication counts:\n" << endl;
  for ( auto & elem : duplicateElements )
    { cout << elem.first << " :: " << elem.second << endl; }

  cout << "\n";
  return ( 0 );
}
