/******************************************************************************
 * Copyright (c) 2007-2013. F. Suter, S. Hunold.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the license (GNU LGPL 2.1) which comes with this package.
 *****************************************************************************/

#ifndef DAGGEN_COMMONS_H_
#define DAGGEN_COMMONS_H_

#ifndef MAX
#  define MAX(x,y) ((x) > (y) ? (x) : (y))
#endif
#ifndef MIN
#  define MIN(x,y) ((x) < (y) ? (x) : (y))
#endif

typedef enum {
  MIXED =0,
  N_2,
  N_LOG_N, /* (n2 log(n2) indeed */
  N_3
} complexity_t;


#define OUTPUT (global.output_file)
#define GIGA 1024*1024*1024

/*********************************/
/** Global variables            **/
/*********************************/

typedef struct {
  int n;          /* number of tasks in the graph       */
  double fat;     /* fatness parameter                    */
  double regular; /* regularity                         */
  int ccr;     /* Communication to computation ratio */
  double density;
  double mindata, maxdata;
  double minalpha, maxalpha; /* Amdahl's law parameter */
  int jump;
  int dot_output;
  FILE *output_file;
} Global;
Global global;

typedef struct _Task *Task;
typedef struct _DAG *DAG;

struct _Task {
  int tag;
  double cost;
  int data_size;
  double alpha;
  int nb_children;
  Task *children;
  double *comm_costs;
  int *transfer_tags;
  complexity_t complexity;
};

struct _DAG {
  int nb_levels;
  int *nb_tasks_per_level;
  Task **levels;
};


int parseOptions(int argc, char *const *argv);

void printUsage(void);

void outputDAG(DAG dag);
void outputDOT(DAG dag);

int getIntRandomNumberAround(int x, double perc);

double getRandomNumberBetween(double x, double y);

#endif /*DAGGEN_COMMONS_H_*/
