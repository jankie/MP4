
#include "quicktime.h"


int quicktime_dimm_init(quicktime_dimm_t *dimm)
{
	dimm->numBytes = 0;
}

int quicktime_dimm_delete(quicktime_dimm_t *dimm)
{
}

int quicktime_dimm_dump(quicktime_dimm_t *dimm)
{
	printf("    total immediate bytes\n");
	printf("     numBytes "U64"\n", dimm->numBytes);
}

int quicktime_read_dimm(quicktime_t *file, quicktime_dimm_t *dimm)
{
	dimm->numBytes = quicktime_read_int64(file);
}

int quicktime_write_dimm(quicktime_t *file, quicktime_dimm_t *dimm)
{
	quicktime_atom_t atom;

	quicktime_atom_write_header(file, &atom, "dimm");

	quicktime_write_int64(file, dimm->numBytes);
	
	quicktime_atom_write_footer(file, &atom);
}

