#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

ll x, n;

/*
note rbegin, rend() are different types from begin, end
what's the Order of operations with --it?
don't try to increment/decrement iterators beyond  bounds, even as a check. it's undefined
Note that VS code debugger will display the dereferenced value of iterators

note doing it1 = it2--; WILL CHANGE THE VALUE OF it2!! Logic blunder.

Big difference between using multiset.erase(value) and multiset.erase(iterator) - one erases all values, the other just the iterator.

Used this to erase just one particular value:
distances.erase(distances.find(curr_dist));

*/

int main() {

    freopen("test_input.txt", "r", stdin);
    freopen("out", "w", stdout);

    cin >> x >> n;

    multiset<ll> distances;
    set<ll> lights;
    
    distances.insert(x);
    
    ll light, curr_dist, new_left, new_right;
    multiset<ll>::iterator above, below;

    for (int i = 0; i < n; i++) {
        cin >> light;

        if (lights.size() == 0) {
            curr_dist = x;
            new_left = light;
            new_right = x - light;
        } else {
            above = lights.upper_bound(light);
            below = --lights.upper_bound(light);;

        // compute new distances

        // edge cases
        if (above == lights.begin()) { // light is new first
            curr_dist = *lights.begin();
            new_left = light;
            new_right = *lights.begin() - light;
        }
        else if (above == lights.end()) { // light is last
            curr_dist = x - *lights.rbegin();
            new_left = light - *lights.rbegin();
            new_right = x - light;
        }
        else {
            curr_dist = *above - *below;
            new_left = light - *below;
            new_right = *above - light;
        }}
        lights.insert(light);
        distances.erase(distances.find(curr_dist));
        distances.insert(new_left);
        distances.insert(new_right);

        cout << *distances.rbegin() << " ";
    }
}