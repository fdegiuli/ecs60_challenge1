// Author: Sean Davis,  who are you?

#ifndef DATABASE_H
#define	DATABASE_H

#include "filmDriver.h"
#include "LinkedList.h"
#include "mystring.h"


class Database
{
public:
  Database(Movie *movies, int movieCount);
  int search(const Query *query);
// void in_ADTs(Movie *movies, int movieCount);
  // LinkedList *title_adt; 
  //  LinkedList *studio_adt;
  // LinkedList *rating_adt;
  // LinkedList *year_adt;
  // LinkedList *genre_adt;
  void searchTitles(Query *query);
  void searchStudios(Query *query);
  void searchRatings(Query *query);
  void searchYears(Query *query);
  void searchGenres(Query *query);

private:

};

#endif	/* DATABASE_H */

