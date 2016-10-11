data_structures_tests.out: data_structures_tests.o | ../lib/libdata_structures.so
	cc -Wl,-rpath=../lib -o $@ $< -L'../lib' -ldata_structures
.PHONY: ../lib/libdata_structures.so

data_structures_tests.o: data_structures_tests.c ../lib/data_structures/data_structures.h
	cc -c -o $@ $<

../lib/libdata_structures.so:
	$(MAKE) -C ../lib/data_structures/
