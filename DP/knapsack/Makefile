FLAG = -w -O2

all:
	gcc src/knapsack_origin.c $(FLAG) -o bin/origin
	gcc src/knapsack_top_down.c $(FLAG) -o bin/top_down
	gcc src/knapsack_bottom_up.c $(FLAG) -o bin/bottom_up
	gcc src/knapsack_bottom_up2.c $(FLAG) -o bin/one_dim_bottom_up

show:	
	gcc src/knapsack_top_down.c -DSHOW $(FLAG) -o bin/top_down
	gcc src/knapsack_bottom_up.c -DSHOW $(FLAG) -o bin/bottom_up 
	gcc src/knapsack_bottom_up2.c -DSHOW $(FLAG) -o bin/one_dim_bottom_up

clean:
	rm -rf bin/*
	rm -rf origin
	rm -rf top_down
	rm -rf bottom_up
	rm -rf one_dim_bottom_up
	rm -rf *.out
