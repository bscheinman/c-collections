all:
	$(MAKE) -C ./hashmap all
	$(MAKE) -C ./queue all
	$(MAKE) -C ./vector all

clean:
	$(MAKE) -C ./hashmap clean
	$(MAKE) -C ./queue clean
	$(MAKE) -C ./vector clean
