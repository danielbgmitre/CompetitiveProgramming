#include <bits/stdc++.h>
#define MAX 100007

using namespace std;

struct candidato{
    int cnt;
    int idx;
    int pref[107];
};


candidato cand[MAX];

bool compare(candidato a, candidato b){
    if(a.cnt == b.cnt){
        int i = 0;
        while(i < 100 && a.pref[i] == b.pref[i]) i++;

        if(i < 100) return a.pref[i] > b.pref[i];
        return a.idx < b.idx;
    }
    return a.cnt > b.cnt;
}

bool igual(candidato a, candidato b){
    if(a.cnt == b.cnt){
        int i = 0;
        while(i < 100 && a.pref[i] == b.pref[i]) i++;

        if(i < 100) return false;
        return true;
    }
    return false;
}

int main(){
    int t, n;

    scanf("%d", &t);

    while(t--){
        int n, k, v;
        scanf("%d %d %d", &n, &k, &v);

        for(int i = 0; i <= k; i++) {
            cand[i].idx = i;
            cand[i].cnt = 0;
            memset(cand[i].pref, 0, sizeof cand[i].pref);
        }
        int ith;

        for(int i = 0; i < n; i++){
            int li; scanf("%d", &li);
            for(int j = 0; j < li; j++){
                scanf("%d", &ith);
                if(j >= v || ith <= 0 || ith > k) continue;
                ith--;

                cand[ith].cnt++;
                cand[ith].pref[j]++;
                cand[ith].idx = ith;
            }
        }

        sort(cand, cand+k, compare);
        for(int i = 0; i < v; i++){
            if (i > 0) printf(" ");
            printf("%d", cand[i].idx+1);
        }

        int index = v;
        while (index < k && igual(cand[index], cand[index-1])){
            printf(" %d", cand[index].idx+1);
            index++;
        }
        printf("\n");
    }


    return 0;
}
