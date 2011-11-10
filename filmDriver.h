/* 
 * File:   filmDriver.h
 * Author: davis
 *
 * Created on October 31, 2011, 8:30 PM
 */

#ifndef FILMDRIVER_H
#define	FILMDRIVER_H

typedef struct
{
  char title[129];
  char studio[31];
  char rating[6];
  char year[5];
  char genre[18];  
} Movie;

typedef struct
{
  short propertyID;
  char lower[129];
  char upper[129];
} Query;

enum{TITLE, STUDIO, RATING, YEAR, GENRE};
#endif	/* FILMDRIVER_H */

