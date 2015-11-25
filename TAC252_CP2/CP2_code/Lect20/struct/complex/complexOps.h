/* file name: complexOps.h*/

#include "complexno.h"
#include "boolean.h"

extern complex_t create_complex();
extern complex_t scan_complex(complex_t c);
extern void print_complex(complex_t c);
extern complex_t add_complex(complex_t c1, complex_t c2);
extern complex_t sub_complex(complex_t c1, complex_t c2);
extern complex_t abs_complex(complex_t c);
extern Boolean IsEqual(complex_t c1, complex_t c2);
