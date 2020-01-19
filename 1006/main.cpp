#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct _sign_info_t {
    string id;
    int in_time;
    int out_time;
} sign_info_t;

vector<sign_info_t> all_sign_info;

int main(void) 
{
    int n;
    int earlist_index = 0, lastest_index = 0;
    int earlist_time = 0xFFFFFF, lastest_time = 0;
    cin >> n;
    sign_info_t sign_info;
    while (n--) {
        cin >> sign_info.id;
        int hour_0, min_0, sec_0, hour_1, min_1, sec_1;
        scanf("%d:%d:%d %d:%d:%d", &hour_0, &min_0, &sec_0, &hour_1, &min_1, &sec_1);
        sign_info.in_time = hour_0 * 3600 + min_0 * 60 + sec_0;
        sign_info.out_time = hour_1 * 3600 + min_1 * 60 + sec_1;
        all_sign_info.push_back(sign_info);
    }

    for (int i = 0; i < all_sign_info.size(); i++) {
        if (all_sign_info[i].in_time <= earlist_time) {
            earlist_time = all_sign_info[i].in_time;
            earlist_index = i;
        }

        if (all_sign_info[i].out_time >= lastest_time) {
            lastest_time = all_sign_info[i].out_time;
            lastest_index = i;
        }
    }

    cout << all_sign_info[earlist_index].id << ' ' << all_sign_info[lastest_index].id;
    return 0;
}