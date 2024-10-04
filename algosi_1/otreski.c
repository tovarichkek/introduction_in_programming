#include <stdio.h>
#include <stdlib.h>

struct segment{
    int start;
    int start_or_end; //if start, equal 0, else - 1
};

int comp(const void* p1, const void* p2){
    if(((struct segment *)(p1))->start > ((struct segment *)(p2))->start){
        return 1;
    }
    if(((struct segment *)(p1))->start < ((struct segment *)(p2))->start){
        return -1;
    }
    return 0;
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    return b;
}

int main(){
    int count = 0;
    scanf("%d", &count);

    struct segment points[count * 2] = {};
    int start = 0, end = 0;
    for(int i = 0; i < count; i++){
        scanf("%d %d", &start, &end);
        struct segment segm_start = {start, 0};
        struct segment segm_end = {end, 1};
        points[2 * i] = segm_start;
        points[2 * i + 1] = segm_end;
    }

    qsort(points, count * 2, sizeof(struct segment), comp);
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