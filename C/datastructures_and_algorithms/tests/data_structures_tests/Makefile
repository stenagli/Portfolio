data_structures_tests.out: data_structures_tests.o | $(LIBDIR)/libdata_structures.so
	cc -o $@ $< -ldata_structures

data_structures_tests.o: data_structures_tests.c data_structures.h
	cc -c -o $@ $<

.PHONY: $(LIBDIR)/libdata_structures.so
$(LIBDIR)/libdata_structures.so:
	$(MAKE) -C $(LIBDIR)/data_structures/
