#include<stdio.h>

int n, nf, in[100], p[50], hit=0, i, j, k, pgfaultcnt=0;

void getData() {
    printf("\nEnter length of page reference sequence:");
    scanf("%d", &n);
    printf("\nEnter the page reference sequence:");
    for(i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\nEnter no of frames:");
    scanf("%d", &nf);
}

void initialize() {
    pgfaultcnt = 0;
    for(i = 0; i < nf; i++)
        p[i] = 9999;
}

int isHit(int data) {
    hit = 0;
    for(j = 0; j < nf; j++) {
        if(p[j] == data) {
            hit = 1;
            break;
        }
    }
    return hit;
}

int getHitIndex(int data) {
    int hitind;
    for(k = 0; k < nf; k++) {
        if(p[k] == data) {
            hitind = k;
            break;
        }
    }
    return hitind;
}

void dispPages() {
    for (k = 0; k < nf; k++) {
        if(p[k] != 9999)
            printf(" %d", p[k]);
    }
}

void dispPgFaultCnt() {
    printf("\nTotal no of page faults:%d", pgfaultcnt);
}

void lfu() {
    int usedcnt[100] = {0};
    int least, repin, sofarcnt = 0, bn = 0;
    initialize();
    for(i = 0; i < n; i++) {
        printf("\nFor %d :", in[i]);
        if(isHit(in[i])) {
            int hitind = getHitIndex(in[i]);
            usedcnt[hitind]++;
            printf("No page fault!");
        } else {
            pgfaultcnt++;
            if(bn < nf) {
                p[bn] = in[i];
                usedcnt[bn] = 1;
                bn++;
            } else {
                least = 9999;
                for(k = 0; k < nf; k++) {
                    if(usedcnt[k] < least) {
                        least = usedcnt[k];
                        repin = k;
                    }
                }
                p[repin] = in[i];
                sofarcnt = 0;
                for(k = 0; k <= i; k++) {
                    if(in[i] == in[k])
                        sofarcnt++;
                }
                usedcnt[repin] = sofarcnt;
           

