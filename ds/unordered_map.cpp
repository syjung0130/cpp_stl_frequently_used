#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

/*
https://www.geeksforgeeks.org/unordered_map-in-cpp-stl/
## unordered_map vs unordered_set :
In unordered_set, we have only key, no value, these are mainly used to see presence/absence in a set. 
For example, consider the problem of counting the frequencies of individual words. 
We can’t use unordered_set (or set) as we can’t store counts.

## unordered_map vs map :
map (like set) is an ordered sequence of unique keys whereas in unordered_map key 
 can be stored in any order, so unordered.
The map is implemented as a balanced tree structure that is why it is possible to maintain order 
 between the elements (by specific tree traversal). 
 The time complexity of map operations is O(log n) while for unordered_map, it is O(1) on average.

## Methods on unordered_map
A lot of functions are available which work on unordered_map. 
 most useful of them are – operator =, operator [], empty and size for capacity, 
 begin and end for the iterator, find and count for lookup, insert and erase for modification.
The C++11 library also provides functions to see internally used bucket count, 
 bucket size, and also used hash function and various hash policies 
 but they are less useful in real applications.
We can iterate over all elements of unordered_map using Iterator. 
 Initialization, indexing, and iteration are shown in below sample code :
*/


int main()
{
	// Declaring umap to be of <string, double> type
	// key will be of string type and mapped value will
	// be of double type
	unordered_map<string, double> umap;

	//inserting values by using [] operator
	umap["PI"] = 3.14;
	umap["root2"] = 1.414;
	umap["root3"] = 1.732;
	umap["log10"] = 2.302;
	umap["loge"] = 1.0;

	//inserting value by insert function.
	umap.insert(make_pair("e", 2.718));

	string key = "PI";

	//If key not found in map iterator to end is returned
	if (umap.find(key) == umap.end())
		cout << key << "not found" << endl << endl;
	else
		cout << "Found " << key << endl << endl;

	key = "lambda";
	if (umap.find(key) == umap.end())
		cout << key << " not found" << endl;
	else
		cout << "Found " << key << endl;

	//iterating over all value of umap
	unordered_map<string, double>::iterator it;
	cout << "All Elements: " << endl;
	for (it = umap.begin(); it != umap.end(); it++)
	{
		// it works as a pointer to pair<string, double>
		// type it->first stores the key part and
		// it->second stores the value part
		cout << it->first << " " << it->second << endl;
	}

	return 0;
}
