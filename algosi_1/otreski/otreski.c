#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_COUNT_POINTS 1000

typedef struct{
    int start;
    int start_or_end; //if start, equal 0, else - 1
} segment;

int comp(const void* p1, const void* p2){
    return ((segment *)(p1))->start - ((segment *)(p2))->start;
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int main(){
    int count = 0;
    printf("Enter the number of segments\n");
    if((scanf("%d", &count) != 1) || count < 1){
        printf("Incorrect input\n");
        return 0;
    }

    segment points[MAX_COUNT_POINTS] = {};
    int start = 0, end = 0;

    printf("Coordinates of segments in format x y:\n");
    
    for(int i = 0; i < count; i++){
        if(scanf("%d %d", &start, &end) != 2){
            printf("Incorrect input\n");
            return 0;
        }
        if(start < end){ //swap start and end if start < end
            int buff = start;
            start = end;
            end = buff;
        }

        segment segm_start = {start, 0};
        segment segm_end = {end, 1};
        points[2 * i] = segm_start;
        points[2 * i + 1] = segm_end;
    }

    qsort(points, count * 2, sizeof(segment), comp);
    int starts = 0, ends = 0, max_intersec = 0;
    for(int i = 0; i < count * 2; i++){
        if(points[i].start_or_end == 0){
            starts++;
        }
        else{
            ends++;
        }
        max_intersec = max(max_intersec, starts - ends);
    }

    printf("%d\n", max_intersec);
}