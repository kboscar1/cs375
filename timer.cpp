#include <vector>
#include <iomanip>
#include <sstream>
#include <sys/time.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

struct timeval tvStart; // struct to represent the starting time
struct timeval tvEnd; //struct to represent the ending time
struct timeval tvDiff; //struct to represent the time difference

/* I do not use this, it's from one of my past programs but it prints the time difference formatted correctly. It receives a char* the file name to print to, and the time difference struct which it prints the seconds and microseconds from.
 */
void timeval_print(char *str, struct timeval *tv)
{
  char buffer[100]; // buffer string to print
  sprintf(buffer, "00%ld sec, %06ld micro sec\n", tv->tv_sec, tv->tv_usec);

  stringstream stream; // stringstream to open output file
  ofstream output2; // stream for output file
  output2.open(str);

  if(!output2.is_open()){
    cout << "Output file won't open" << endl;
    exit(1);
  }  
  output2 << buffer;
}

/* timeval_subtract subtracts the seconds and microseconds from the start timeval struct from the end timeval struct and places this difference into a new struct result.
Inputs are result which the difference time is stored into, t1 which is the end time and t2 which is the start time.
 */
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1)
{
  long int diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec); // this is the difference in times specficied in microseconds
  result->tv_sec = diff / 1000000;
  result->tv_usec = diff % 1000000;

  return (diff<0);
}

/* This starts the timer using the gettimeofday function on the global timeval struct tvStart
 */
void timer_start(){
  gettimeofday(&tvStart, NULL);
}

/*This ends the timer using the gettimeofday function on the global timeval struct tvEnd. It then calls timeval_subtract to get the difference in the times. It uses the times from the difference struct to return to a funciton that wishes to print the seconds andmicroseconds of the time difference.
 */
vector<time_t> timer_end(){
  gettimeofday(&tvEnd, NULL);
  timeval_subtract(&tvDiff, &tvEnd, &tvStart);

  vector<time_t> time; // will hold seconds and microseconds of timeVal result struct
  time.push_back(tvDiff.tv_sec);  
  time.push_back(tvDiff.tv_usec);
  return time;
  //  cout << to_string(tvDiff.tv_sec) << " k" << endl;
  //  timeval_print(out, &tvDiff);
}

