/*
** EPITECH PROJECT, 2019
** architect.h
** File description:
** header for architect project
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

typedef struct {
    void (*fn)(double *v, double ***mat, char ***av);
    char *flag;
} flags_t;

int architect(char **av);
double **create_mat(void);
double **multiply_mat(double **mat_2, double ***mat);
void translation(double *v, double ***mat, char ***av);
void scaling(double *v, double ***mat, char ***av);
void reflection(double *v, double ***mat, char ***av);
void rotation(double *v, double ***mat, char ***av);
