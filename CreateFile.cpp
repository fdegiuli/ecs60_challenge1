// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <set>

using namespace std;
enum{TITLE, STUDIO, RATING, YEAR, GENRE};

typedef struct
{
  string strings[5];	
} Movie;

const int MOVIE_COUNT = 215196;

Movie* readFile(int *count)
{
  *count = 0;
  char line[1000], *ptr;
  Movie *movies = new Movie[MOVIE_COUNT];
  ifstream inf("dvd.csv");
  inf.ignore(10000, '\n'); // heading
  
  while(inf.getline(line, 1000, '\n'))
  {
    movies[*count].strings[TITLE] = strtok(line, ",");
    movies[*count].strings[STUDIO] = strtok(NULL, ",");
    movies[*count].strings[RATING] = strtok(NULL, ",");
    movies[*count].strings[YEAR] = strtok(NULL, ",");
    movies[(*count)++].strings[GENRE] = strtok(NULL, "\0");
  }  // while more to read in file
  
  return movies;
}

  
Movie* selectMovies(Movie *movies, int movieCount, int count,
  set<string> stringSets[])
{
  int pos;
  Movie *movies2 = new Movie[movieCount];
  
  for(int i = 0; i < movieCount; i++)
  {
    pos = rand() % count;
    movies2[i] = movies[pos];

    for(int j = TITLE; j <= GENRE; j++)
      stringSets[j].insert(movies[pos].strings[j]);
    
    movies[pos] = movies[--count];
  } // for i
  
  return movies2;
}  // selectMovies()


void writeQuery(ofstream &outf, Movie *movies, int movieCount, int queryCount,
  set<string> stringSets[])
{
  int i, j, class1, lower, upper, classes[2];
  size_t count;
  set<string>::iterator itr;
  string lowers[2], uppers[2];
  
  for(i = 0; i < 1; i++)
  {
    classes[i] = class1 = rand() % 5;
    count = stringSets[class1].size();
    lower = rand() % count;
    do
    {
      upper = rand() %count;
    } while(upper < lower);

    itr = stringSets[class1].begin();
    
    for(j = 0; j < lower; j++)
        itr++;
    
    lowers[i] = *itr;
    
    for(; j < upper; j++)
      itr++;
    
    uppers[i] = *itr;     
  } // for i
  
  count = 0;
  
  for(i = 0; i < movieCount; i++)
    if(movies[i].strings[classes[0]] >= lowers[0] 
      && movies[i].strings[classes[0]] <= uppers[0])
      count++;
  
  outf << classes[0] << ',' << lowers[0] << ','  << uppers[0] << ','
    << count << endl;
  
}  // writeQuery
  
int main(int argc, char** argv)
{
  int count, queryCount, movieCount, seed;
  char filename[80];
  set<string> stringSets[5];
  
  Movie *movies = readFile(&count);
  cout << "Number of movies (5 - " << count << ") : ";
  cin >> movieCount;
  cout << "Number of queries: ";
  cin >> queryCount;
  cout << "Seed: ";
  cin >> seed;
  sprintf(filename, "film-%d-%d-%d.csv", movieCount, queryCount, seed);
  srand(seed);
  Movie *movies2 = selectMovies(movies, movieCount, count, stringSets);
  ofstream outf(filename);
  outf << movieCount << ' ' << queryCount << endl;

  for(int i = 0; i < queryCount; i++)
    writeQuery(outf, movies2, movieCount, queryCount, stringSets);
  
  for(int i = 0; i < movieCount; i++)
  {
    for(int j = 0; j < 5; j++)
      outf << movies2[i].strings[j] << ',';
    
    outf << endl;
  }  // for each movie
  
  outf.close();
  return 0;
} // main()

