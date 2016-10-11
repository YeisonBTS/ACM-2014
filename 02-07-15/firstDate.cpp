#include <bits/stdc++.h>
#include <cstdio>
#define db(a) cout << #a << " = " << a << endl
#define db2(a, b) cout << #a << " = " << a \
<< " " << #b << " = " << b << endl
#define db3(a, b, c) cout << #a << " = " << a \
<< " " << #b << " = " << b \
<< " " << #c << " = " << c << endl

using namespace std;

int a[100];
int b[100];
int yyyy, mm, dd;
int arrDiasMeses[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYearJulian() {
    return (yyyy % 4 == 0);
}

bool isLeapYearGregorian() {
    // db(yyyy);
    // return (yyyy%4 == 0 && (!yyyy%100 == 0 || yyyy%400 == 0));
    return (yyyy % 4 == 0 && (yyyy % 100 != 0 || yyyy % 400 == 0));
}
bool isl(int aa) {
    // db(yyyy);
    // return (yyyy%4 == 0 && (!yyyy%100 == 0 || yyyy%400 == 0));
    return (aa % 4 == 0 && (aa % 100 != 0 || aa % 400 == 0));
}



int diasTranscurridos() {
    int dias = 0;
    for (int i = 1; i < mm; i++) {
        dias += arrDiasMeses[i];
        if (i == 2) {
            if (isLeapYearJulian())
                dias += 1;
        }
    }
    dias += dd;
    /*
    cout << "para dias transcurridos: ";
    db(dias);
    */
    return dias;
}

void nextDate(int addDays) {
    int dt = diasTranscurridos();
    int daysNow =  dt + addDays;

    int ndd, nmm = 1, nyyyy = yyyy;
    int MOD = isLeapYearJulian() ? 366 : 365;
    // db3(dt, daysNow, MOD);
    bool checkGregorian = false;
    if (daysNow > MOD) {
        nyyyy++;
        daysNow = daysNow % MOD;
        checkGregorian = true;
    }
    db2(daysNow, dt);
    if (daysNow > 31 + 28 && dt < 31 + 29) {
        checkGregorian = true;
    }
    //db(checkGregorian);
    //checkGregorian = true;
    yyyy = nyyyy;
    //db(daysNow);
    for (int i = 1; i < 13; i++) {
        if (i == 2) {
            if (checkGregorian) {
                if (isLeapYearGregorian()) {
                    if (daysNow > arrDiasMeses[i] + 1) {
                        daysNow -= (arrDiasMeses[i] + 1);
                        nmm++;
                    }
                    else
                        break;
                }
                else {
                    if (daysNow > arrDiasMeses[i]) {
                        daysNow -= arrDiasMeses[i];
                        nmm++;
                    }
                    else
                        break;
                }
            }
            else {
                //no es necesario checkear si el nuevo año estará con las reglas
                //porque la nueva fecha está en el mismo año
                if (isLeapYearJulian()) {
                    if (daysNow > arrDiasMeses[i] + 1) {
                        daysNow -= (arrDiasMeses[i] + 1);
                        nmm++;
                    }
                    else
                        break;
                }
                else {
                    if (daysNow > arrDiasMeses[i]) {
                        daysNow -= arrDiasMeses[i];
                        nmm++;
                    }
                    else
                        break;
                }
            }
        }
        else {
            if (daysNow > arrDiasMeses[i]) {
                daysNow -= arrDiasMeses[i];
                nmm++;
            }
            else
                break;
        }
    }
    ndd = daysNow;
    char fecha[12];
    sprintf(fecha, "%d-%02d-%02d", nyyyy, nmm, ndd);
    cout << fecha << endl;
    //return fecha;
}

int main() {
    #ifdef dennisbot
        freopen("fd.in", "r", stdin);
        freopen("firstDate.out", "w", stdout);
        clock_t _start = clock();
    #endif
    string s;
    while (cin >> s) {
        sscanf(s.c_str(), "%d-%d-%d", &yyyy, &mm, &dd);
        for (int i = 16; i < 100; i++) {
            if (i % 4 != 0)
                a[i] = a[i - 1] + 1;
            else
                a[i] = a[i - 1];
        }
        for (int i = 16; i < 100; i++) {
            if (isl(i * 100))
                b[i] = b[i - 1] + 1;
            else
                b[i] = b[i - 1];
        }

        for (int i = 40; i < 47; i++) {
            cout << a[i] << ", ";
        }
        cout << endl;
        for (int i = 40; i < 47; i++) {
            cout << b[i] << ", ";
        }
        cout << endl;

        /*db3(yyyy, mm, dd);
        for (int i = 16; i < 25; i++) {
            cout << a[i] << ", ";
        }
        cout << endl;
        */
        int index = yyyy / 100;
        int seed = 11;
        int addDays = seed + a[index];
        nextDate(addDays);
        //db(addDays);
//        db2(s, nextDate(addDays));
        //cout << s << " : " << nextDate(addDays) << endl;
    }
    #ifdef dennisbot
            // printf("\ntime=%.3fs\n", (clock() - _start) * 1. / CLOCKS_PER_SEC);
    #endif
    return 0;
}