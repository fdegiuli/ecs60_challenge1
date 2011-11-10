// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <cstring>
#include "filmDriver.h"
#include "database.h"
#include "CPUTimer.h"

using namespace std;


void readFile(const char* filename, Movie **movies2, Query **queries2, 
  int *movieCount, int *queryCount, int **queryCounts2)
{
  ifstream inf(filename);
  char comma;
  inf >> *movieCount >>  *queryCount;
  inf.ignore(100, '\n');
  Movie *movies = new Movie[*movieCount];
  *movies2 = movies;
  Query *queries = new Query[*queryCount];
  *queries2 = queries;
  int *queryCounts = new int[*queryCount];
  *queryCounts2 = queryCounts;
  
  for(int i = 0; i < *queryCount; i++)
  {
    inf >> queries[i].propertyID;
    inf >> comma;
    inf.getline(queries[i].lower, 129, ',');
    inf.getline(queries[i].upper, 129, ',');
    inf >> queryCounts[i];
  }  // for each query
  
  inf.ignore(100, '\n');
  
  for(int i = 0; i < *movieCount; i++)
  {
    inf.getline(movies[i].title, 129, ',');
    inf.getline(movies[i].studio, 31, ',');
    inf.getline(movies[i].rating, 6, ',');
    inf.getline(movies[i].year, 5, ',');
    inf.getline(movies[i].genre, 18, ',');    
    inf.ignore(100, '\n');
  }  // for each movie
  
  inf.close();
} // readFile


int main(int argc, char** argv)
{
  Movie *movies;
  Query *queries;
  int *queryCounts, movieCount, queryCount, count;
  readFile(argv[1], &movies, & queries, &movieCount, &queryCount, &queryCounts);
  CPUTimer ct;
  Database *database = new Database(movies, movieCount);
  delete [] movies;

  for(int i = 0; i < queryCount; i++)
  {
    count = database->search((const Query*) &queries[i]);
    if(count != queryCounts[i])
      cout << "Incorrect count on query #" << i << " yours: " << count
        << " should be " << queryCounts[i] << endl;
  }   // for each query 
  
  cout << "CPUTime: " << ct.cur_CPUTime() << endl;  
  return 0;
} // main()

