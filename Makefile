OBJS	= util/file.o util/sorted_hash_map.o util/sorted_linked_list.o sequence/distance.o sequence/nucleotide.o sequence/sequence.o family/family.o view/view.o main.o
SOURCE	= util/file.c util/sorted_hash_map.c util/sorted_linked_list.c sequence/distance.c sequence/nucleotide.c sequence/sequence.c family/family.c view/view.c main.c
HEADER	= util/file.h util/sorted_hash_map.h util/sorted_linked_list.h sequence/distance.h sequence/nucleotide.h sequence/sequence.h family/family.h view/view.h
OUT	= adn-comparator
LFLAGS	 = -Wall -g3

all: adn-comparator

adn-comparator: $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)