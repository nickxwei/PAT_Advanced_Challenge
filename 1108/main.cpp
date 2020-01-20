#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(void)
{
    int n = 0;
    string tmpStr;
    int sta = 0;
    int decimalBitLen = 0, legalNum = 0;
    float sum = 0;
    
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> tmpStr;
        decimalBitLen = 0;

        for (int j = 0; j < tmpStr.length(); j++) {
            if (j == 0) {
                if (tmpStr[j] == '+' || tmpStr[j] == '-') {
                    sta = 1;
                } else if(tmpStr[j] >= '0' && tmpStr[j] <= '9') {
                    sta = 2;
                } else {
                    sta = 0;
                }
            } else {
                switch(sta) {
                    case 1:
                        if(tmpStr[j] >= '0' && tmpStr[j] <= '9')
                            sta = 2;
                        else
                            sta = 0;
                        break;
                    case 2:
                        if(tmpStr[j] >= '0' && tmpStr[j] <= '9')
                            sta = 2;
                        else if(tmpStr[j] == '.')
                            sta = 3;
                        else
                            sta = 0;
                        break;
                    case 3:
                        if(tmpStr[j] >= '0' && tmpStr[j] <= '9')
                        {
                            sta = 4;
                            decimalBitLen++;
                        }
                        else
                            sta = 0;
                        break;
                    case 4:
                        if (tmpStr[j] >= '0' && tmpStr[j] <= '9') {
                            decimalBitLen++;
                            if (decimalBitLen > 2) {
                                sta = 0;
                            }                               
                        }
                        else
                            sta = 0;
                        break;
                }
            }

            if (sta == 0) {
                break;
            }
        }

        if (sta == 4 || sta == 2 || sta == 3) {
            if (stof(tmpStr) >= -1000 && stof(tmpStr) <= 1000) {
                legalNum++;
                sum = sum + stof(tmpStr);
            } else {
                printf("ERROR: %s is not a legal number\n", tmpStr.c_str());
            }
        }
        else {
            printf("ERROR: %s is not a legal number\n", tmpStr.c_str());
        }
    }

    switch (legalNum) {
        case 0:
            printf("The average of 0 numbers is Undefined");
            break;
        case 1:
            printf("The average of 1 number is %.2lf", sum);
            break;
        default:
            printf("The average of %d numbers is %.2lf", legalNum, sum / legalNum);
            break;
    }
    return 0;
}