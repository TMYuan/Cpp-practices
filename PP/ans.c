#include <stdlib.h>
#include <stdio.h>
#include <math.h>
struct pair{
	double dis;
	int node1, node2;
};

void swap(struct pair *xp, struct pair *yp)
{
	struct pair temp = *xp;
	*xp = *yp;
	*yp = temp;
}
 
// A function to implement bubble sort
void bubbleSort(struct pair arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)
			if (arr[j].dis > arr[j+1].dis)
				swap(&arr[j], &arr[j+1]);
}

int check(int arr[], int n, int t){
	int i=0;
	for(i=0; i<n; ++i){
		if(arr[i] == t){
			return 0;
		}
	}
	return 1;
}

double distance(double x1, double x2, double y1, double y2){
	double x_pow, y_pow;
	x_pow = pow(x1-x2, 2);
	y_pow = pow(y1-y2, 2);
	return sqrt(x_pow+y_pow);
}



int main(int argc, char* argv[]){
	int num;
	int *id, *x, *y;
	FILE *input, *output;
	input = fopen(argv[1], "r");
	output = fopen(argv[2], "a");
	fscanf(input, "%d", &num);
	id = malloc(sizeof(int) * num);
	x = malloc(sizeof(int) * num);
	y = malloc(sizeof(int) * num);
	int i=0;
	for(i=0; i<num; ++i){
		fscanf(input, "%d %d %d", &id[i], &x[i], &y[i]);
	}
	//printf("%d %d %d", id[num-1], x[num-1], y[num-1]);
	
	//allocate distance array
	struct pair *pair_arr;
	pair_arr = malloc(sizeof(struct pair)*num*num);
	//initialize distance array
	int j=0, count=0;
	for(i=0; i<num-1; i++){
		for(j=i+1; j<num; j++){
			pair_arr[count].node1 = i;
			pair_arr[count].node2 = j;
			pair_arr[count].dis = distance(x[i], x[j], y[i], y[j]);
			count++;
		}
	}
	bubbleSort(pair_arr, count);
	//printf("node1:%d, node2:%d, dis:%lf\n", pair_arr[0].node1, pair_arr[0].node2, pair_arr[0].dis);
	for(i=0; i<count; i++){
		printf("node1:%d, node2:%d, dis:%lf\n", pair_arr[i].node1+1, pair_arr[i].node2+1, pair_arr[i].dis);
	}
	
	int time=0;
	int *start_node, *end_node;
	struct pair *in_list;
	in_list = malloc(sizeof(struct pair)*(num+1));
	start_node = malloc(sizeof(int) * (num+1));
	end_node = malloc(sizeof(int) * (num+1));
	for(i=0; i<count; i++){
		if(time == 0){
			in_list[0] = pair_arr[i];
			start_node[0] = pair_arr[i].node1;
			end_node[0] = pair_arr[i].node2;
			++time;
		}
		else{
			if(check(start_node, time, pair_arr[i].node1) == 1 && check(end_node, time, pair_arr[i].node2) == 1 || time == num){
				in_list[time] = pair_arr[i];
	                        start_node[time] = pair_arr[i].node1;
        	                end_node[time] = pair_arr[i].node2;
                	        ++time;
			}
			else if(check(end_node, time, pair_arr[i].node1) == 1 && check())
			if(time == num + 1){
				break;
			}
		}
	}
	for(i=0; i<num+1; i++){
		printf("start_node: %d, end_node: %d, dist: %lf\n", start_node[i]+1, end_node[i]+1, in_list[i].dis);
	}

	return 0;
}
