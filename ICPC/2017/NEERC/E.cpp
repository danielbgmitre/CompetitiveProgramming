#include <bits/stdc++.h>

using namespace std;

vector<int> food, pack;

bool try_time(int tempo) {
    //cout << "TESTANDO COM "<<tempo<<endl;
    auto _food = food, _pack = pack;

    int leftmost = 0;
    for (int actual=0; actual<_pack.size(); actual++){
        vector<int>::iterator until_right;
        int walk_right;
        if (_pack[actual] < _food[leftmost]) {
            walk_right = tempo;
        } else {
            int delta_left = _pack[actual] - _food[leftmost];
            int delta_right = (tempo-delta_left)/2;
            //cout << "delta_left: "<<delta_left<<endl;
            //cout << "delta_right: "<<delta_right<<endl;
            //cout << "tempo-(2*delta_left): " << tempo-(2*delta_left) <<endl;
            walk_right = max(tempo-(2*delta_left), delta_right);

            if (delta_left > tempo) return false;
        }
        until_right = upper_bound(_food.begin(), _food.end(), _pack[actual]+walk_right);
        //cout << "until_right: "<<until_right-_food.begin() <<endl;
        //cout << "leftmost: "<<leftmost<<endl;
        for (; leftmost < until_right-_food.begin(); leftmost++){
            _food[leftmost] = 0;
            //cout << "o packman "<<actual<<" comeu "<<leftmost<<endl;
        }

        if (leftmost >= _food.size()) return true;
    }
    return leftmost >= _food.size();
}

int main() {
    int N;
    scanf(" %d", &N);

    char temp;
    for (int i=0; i<N; i++) {
        scanf(" %c", &temp);
        if (temp == '*'){
            food.push_back(i);
        } else if (temp == 'P') {
            pack.push_back(i);
        }
    }

    int lo = 0;
    int hi = 2e5 + 15;

    int mid;
    while (lo < hi) {
        mid = (lo+hi)>>1;
        if (try_time(mid)) {
            hi = mid;
            //cout << "comi tudo" << endl;
        } else {
            lo = mid+1;
            //cout << "preciso de mais tempo" <<endl;
        }
    }
    printf("%d\n", hi);

    return 0;
}
