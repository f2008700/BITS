/* file name: figureOps.h */

#include "figure.h"
#include "boolean.h"

extern figure_t get_figure_dimension();
extern figure_t compute_area (figure_t f);
extern figure_t compute_perimeter (figure_t f);
extern Boolean isEqual(figure_t f1, figure_t f2);
extern void print_figure(figure_t f);
