/*
** EPITECH PROJECT, 2019
** architect.c
** File description:
** programm file
*/

#include "architect.h"

static const flags_t tab[4] = {
    {&translation, "-t"},
    {&scaling, "-z"},
    {&rotation, "-r"},
    {&reflection, "-s"}
};

double **create_mat(void)
{
    double **mat = malloc(sizeof(double *) * 3);

    for (int i = 0; i < 3; i++) {
        mat[i] = malloc(sizeof(double) * 3);
        mat[i][0] = 0.00;
        mat[i][1] = 0.00;
        mat[i][2] = 0.00;
    }
    mat[0][0] = 1.00;
    mat[1][1] = 1.00;
    mat[2][2] = 1.00;
    return mat;
}

double **multiply_mat(double **mat_2, double ***mat)
{
    double **res = create_mat();

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            res[i][j] = ((*mat)[0][j] * mat_2[i][0])
                + ((*mat)[1][j] * mat_2[i][1])
                + ((*mat)[2][j] * mat_2[i][2]);
        }
    return res;
}

int architect(char **av)
{
    double *v = malloc(sizeof(double) * 3);
    double **mat = create_mat();
    int i;
    double save = atof(av[0]);
    double save_2 = atof(av[1]);

    v[0] = atof(av[0]);
    v[1] = atof(av[1]);
    v[2] = 1.00;
    av += 2;
    while (av[0] != 0) {
        for (i = 0; strcmp(av[0], tab[i].flag) != 0; i++);
        tab[i].fn(v, &mat, &av);
    }
    for (int i = 0; i < 3; i++)
        printf("%.2f %.2f %.2f\n", mat[i][0], mat[i][1], mat[i][2]);
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", save, save_2, v[0], v[1]);
    return 0;
}
