export HEADERDIR = $(abspath ../../headers/)
vpath %.h $(HEADERDIR) # Set search directory for header files for Make
export LIBDIR = $(abspath ../../lib) # Specify directory for shared libraries
export CFLAGS += -Wall -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) -iquote$(HEADERDIR)
# -Wall:	Display all warnings
#  -Wl,-rpath=	Set shared library dir for linker
#  -L		Set shared library dir for compiler
#  -I		Set header dir

data_structures_tests.out: data_structures_tests.o | $(join $(LIBDIR),/libdata_structures.so)
	$(CC) $(CFLAGS) -o $@ $< -ldata_structures

data_structures_tests.o: data_structures_tests.c data_structures.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: $(join $(LIBDIR),/libdata_structures.so)
$(join $(LIBDIR),/libdata_structures.so):
	$(MAKE) -C $(join $(LIBDIR),/data_structures/)
