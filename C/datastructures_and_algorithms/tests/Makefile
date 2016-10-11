# Set global variables 
HEADERDIR = $(abspath ../headers)
export vpath %.h $(HEADERDIR) # Set search directory for header files for Make
export LIBDIR = $(abspath ../lib) # Specify directory for shared libraries
export CFLAGS += -Wall -Wl,-rpath=$(LIBDIR) -L$(LIBDIR) -I$(HEADERDIR)
# -Wall:	Display all warnings
#  -Wl,-rpath=	Set shared library dir for linker
#  -L		Set shared library dir for compiler
#  -I		Set header dir

all: data_structures_tests ; $(info $$(HEADERDIR) is [${(HEADERDIR)}])echo Hello world
.PHONY: all

.PHONY: data_structures_tests
data_structures_tests:
	$(MAKE) -C data_structures_tests/
