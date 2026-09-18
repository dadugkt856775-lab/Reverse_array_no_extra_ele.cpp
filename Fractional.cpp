#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight;
    int value;
};

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);

    for (auto &item : items)
        cin >> item.weight >> item.value;

    sort(items.begin(), items.end(), [](Item a, Item b) {
        return (double)a.value / a.weight >
               (double)b.value / b.weight;
    });

    double totalValue = 0;

    for (auto item : items) {
        if (capacity >= item.weight) {
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            totalValue +=
                (double)item.value / item.weight * capacity;
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum Value: " << totalValue << endl;

    return 0;
}
