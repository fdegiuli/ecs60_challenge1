#include "database.h"
#include "filmDriver.h"
#include "LinkedList.h"
#include <iostream>
#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Database::Database(Movie *movies, int movieCount)
{
  List <string> title_adt;
  List <string> studio_adt;
  List <string> rating_adt;
  List <string> year_adt;
  List <string> genre_adt;
  
  ListItr <string> itr = title_adt.zeroth();

  // mass insert
  for (int i = 0; i < movieCount; i++) {
    title_adt.insert(movies[i].title, itr);
    studio_adt.insert(movies[i].studio, itr);
    rating_adt.insert(movies[i].rating, itr);
    year_adt.insert(movies[i].year, itr);
    genre_adt.insert(movies[i].genre, itr);
  } 
  
}  // Database()

/*
void Database::mass_sort(Movie *movies, int movieCount)
{
// use qsort on all of the original arrays
}
*/

int Database::search(const Query* query)
{
  // switch(query.propertyID)
  // {
  // case 0:
  //   title_adt.searchTitles(query);
  //   break;
  // case 1:
  //   studio_adt.searchStudios(query);
  //   break;
  // case 2:
  //   rating_adt.searchRatings(query);
  //   break;
  // case 3:
  //   year_adt.searchYears(query);
  //   break;
  // case 4:
  //   genre_adt.searchGenres(query);
  //   break;
  // default:
  //   break;
  // }
            
  return 0;
} // search

void Database::searchTitles(Query *query) {

    
}

void Database::searchStudios(Query *query) {

   
}

void Database::searchRatings(Query *query) {

   
}

void Database::searchYears(Query *query) {

}

void Database::searchGenres(Query *query) {

   
}
