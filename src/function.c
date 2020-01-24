/*
** EPITECH PROJECT, 2019
** function.c
** File description:
** scaling, rotation, translation etc.
*/

#include "architect.h"

void translation(double *v, double ***mat, char ***av)
{
    double i = atof((*av)[1]);
    double j = atof((*av)[2]);
    double x = v[0];
    double y = v[1];
    double **mat_2 = create_mat();

    printf("Translation along vector (%s, %s)\n", (*av)[1], (*av)[2]);
    mat_2[0][2] = i;
    mat_2[1][2] = j;
    for (int i = 0; i < 3; i++)
        v[i] = (mat_2[i][0] * x) + (mat_2[i][1] * y)
            + (mat_2[i][2] * v[2]);
    *mat = multiply_mat(mat_2, mat);
    *av += 3;
    free(mat_2);
}

void scaling(double *v, double ***mat, char ***av)
{
    double m = atof((*av)[1]);
    double n = atof((*av)[2]);
    double x = v[0];
    double y = v[1];
    double **mat_2 = create_mat();

    printf("Scaling by factors %s and %s\n", (*av)[1], (*av)[2]);
    mat_2[0][0] = m;
    mat_2[1][1] = n;
    for (int i = 0; i < 3; i++)
        v[i] = (mat_2[i][0] * x) + (mat_2[i][1] * y)
            + (mat_2[i][2] * v[2]);
    *mat = multiply_mat(mat_2, mat);
    *av += 3;
    free(mat_2);
}

void rotation(double *v, double ***mat, char ***av)
{
    double angle = atof((*av)[1]);
    double x = v[0];
    double y = v[1];
    double **mat_2 = create_mat();

    printf("Rotation by a %s degree angle\n", (*av)[1]);
    mat_2[0][0] = cos(angle * (M_PI / 180));
    mat_2[1][1] = cos(angle * (M_PI / 180));
    mat_2[0][1] = -sin(angle * (M_PI / 180));
    mat_2[1][0] = sin(angle * (M_PI / 180));
    for (int i = 0; i < 3; i++)
        v[i] = (mat_2[i][0] * x) + (mat_2[i][1] * y)
            + (mat_2[i][2] * v[2]);
    *av += 2;
    *mat = multiply_mat(mat_2, mat);
    free(mat_2);
}

void reflection(double *v, double ***mat, char ***av)
{
    double angle = 2 * atof((*av)[1]);
    double x = v[0];
    double y = v[1];
    double **mat_2 = create_mat();

    printf("Reflection over an axis with an inclination angle of %s degrees\n",
           (*av)[1]);
    mat_2[0][0] = cos(angle * (M_PI / 180));
    mat_2[1][1] = -cos(angle * (M_PI / 180));
    mat_2[0][1] = sin(angle * (M_PI / 180));
    mat_2[1][0] = sin(angle * (M_PI / 180));
    for (int i = 0; i < 3; i++)
        v[i] = (mat_2[i][0] * x) + (mat_2[i][1] * y)
            + (mat_2[i][2] * v[2]);
    *av += 2;
    *mat = multiply_mat(mat_2, mat);
    free(mat_2);
}
