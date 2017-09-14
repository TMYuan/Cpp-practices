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

int check(int arr[], int v1, int v2, int n){
	int i=0;
	if(arr[v1] == 2){
		return 0;
	}
	if(arr[v2] == 2){
		return 0;
	}
	++arr[v1];
	++arr[v2];
	for(i=0; i<n; ++i){
		if(arr[i] == 1){
			return 1;
		}
	}
	--arr[v1];
	--arr[v2];
	return 0;
}

double distance(double x1, double x2, double y1, double y2){
	double x_pow, y_pow;
	x_pow = pow(x1-x2, 2);
	y_pow = pow(y1-y2, 2);
	return sqrt(x_pow+y_pow);
}

double sum(struct pair arr[], int n){
	int i=0, total=0;
	for(i=0; i<n; i++){
		total += arr[i].dis;
	}
	return total;
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
	
	int times=0;
	int *ver_count;
	struct pair *edge;
	ver_count = malloc(sizeof(int)*(num));
	edge = malloc(sizeof(struct pair)*num);
	for(i=0; i<num; ++i){
		ver_count[i] = 0;
	}

	for(i=0; i<count; ++i){
		if(times == num){
			break;
		}
		int v1, v2;
		v1 = pair_arr[i].node1;
		v2 = pair_arr[i].node2;
		if(times == 0 || check(ver_count, v1, v2, num) == 1){
			edge[times] = pair_arr[i];
			if(v1 > v2){
				edge[times].node1 = v2;
				edge[times].node2 = v1;
			}
			if(times == 0){
				++ver_count[v1];
				++ver_count[v2];
			}
			printf("add node1:%d, node2:%d\n", v1+1, v2+1);
			printf("v[%d]: %d, v[%d]: %d\n", v1+1, ver_count[v1], v2+1, ver_count[v2]);
			++times;
		}
		else if(times == num-1){
			if(ver_count[v1] == 1 && ver_count[v2] == 1){
				edge[times] = pair_arr[i];
				if(v1 > v2){
					edge[times].node1 = v2;
					edge[times].node2 = v1;
				}
				++times;
			}
		}
	}

	for(i=0; i<num; i++){
		printf("node1: %d, node2: %d, dist: %lf\n", edge[i].node1+1, edge[i].node2+1, edge[i].dis);
	}

	times = 0;
	fprintf(output, "%lf\n", sum(edge, num));
	fprintf(output, "1\n");
	for(i=0; i<num; ++i){
		ver_count[i] = 0;
	}
	
	int *v1_list, *v2_list;
	v1_list = malloc(sizeof(int)*(num));
	v2_list = malloc(sizeof(int)*(num));
	for(i=0; i<num; i++){
		v1_list[i] = -1;
		v2_list[i] = -1;
	}
	for(i=0; i<num; i++){
		if(v1_list[edge[i].node1] == -1){
			v1_list[edge[i].node1] = edge[i].node2;
		}
		else{
			v2_list[edge[i].node1] = edge[i].node2;
		}
		if(v1_list[edge[i].node2] == -1){
			v1_list[edge[i].node2] = edge[i].node1;
		}
		else{
			v2_list[edge[i].node2] = edge[i].node1;
		}
	}

	for(i=0; i<num; ++i){
		printf("%d ", v1_list[i]+1);
	}
	printf("\n");

	for(i=0; i<num; ++i){
		printf("%d ", v2_list[i]+1);
	}
	printf("\n");

	int point_now=0, point_past=0;
	for(i=0; i<num-1; ++i){
		if(i == 0){
			if(v1_list[0] < v2_list[0]){
				point_now = v1_list[0];
				fprintf(output, "%d\n", v1_list[0]+1);
			}
			else{
				point_now = v2_list[0];
				fprintf(output, "%d\n", v2_list[0]+1);
			}
		}
		else{
			if(v1_list[point_now] != point_past){
				fprintf(output, "%d\n", v1_list[point_now]+1);
				point_past = point_now;
				point_now = v1_list[point_now];
			}
			else{
				fprintf(output, "%d\n", v2_list[point_now]+1);
				point_past = point_now;
				point_now = v2_list[point_now];
			}
		}
	}
	fprintf(output, "end\n");

	return 0;
}
